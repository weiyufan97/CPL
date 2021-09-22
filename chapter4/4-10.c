#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXOP 100

int getline(char s[], int lim);

void push(double f);
double pop();

void execute(char s[]);
double top();
double clear();
int isOperator(char s[], int* ind);
void operate(char c);
double readNumber(char s[], int* ind);
void readCommand(char s[], char command[], int* ind);

int main() {
    int type, count;
    double op2;
    char s[MAXOP];
    char command[MAXOP];

    printf("my_calc> ");
    while ((count = getline(s, MAXOP)) != 0) {
        // parse the line
        int i = 0;
        while (s[i] != '\0') {
            if (isspace(s[i])) {
                i++;
                continue;
            }
            if (isOperator(s, &i))
                operate(s[i-1]);
            else if (isdigit(s[i])) {
                double opnd = readNumber(s, &i);
                push(opnd);
            }
            else {
                readCommand(s, command, &i);
                execute(command);
            }
        }
        printf("my_calc> ");
    }
}

#define MAXELE 1000

int sp = 0; // next position to put element
double val[MAXELE];

void push(double f) {
    if (sp < MAXELE)
        val[sp++] = f;
    else
        printf("error: stack is full\n");
}

double pop() {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack is empty\n");
        return 0.0;
    }
}

double top() {
    if (sp > 0)
        return val[sp-1];
    else {
        printf("error: stack is empty\n");
        return 0.0;
    }
}

double clear() {
    sp = 0;
}

int isOperator(char s[], int* ind) {
    char c = s[*ind];
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        return s[(*ind)++];
    return 0;
}

void operate(char c) {
    double op2;
    switch (c) {
    case '+':
        push(pop() + pop());
        break;
    case '*':
        push(pop() * pop());
        break;
    case '-':
        op2 = pop();
        push(pop() - op2);
        break;
    case '/':
        op2 = pop();
        if (op2 != 0.0) {
            push(pop() / op2);
            break;
        }
        else {
            printf("error: divided by zero\n");
            break;
        }
    case '%':
        op2 = pop();
        if (op2 != 0.0) {
            push((int)op2 % (int)pop());
            break;
        }
        else {
            printf("error: divided by zero\n");
            break;
        }
    }
}

double readNumber(char s[], int* ind) {
    // now s[*ind] is a digit
    char* num = (char*)calloc(MAXOP, sizeof(char));
    int i = 0;
    while (isdigit(s[*ind]))
        num[i++] = s[(*ind)++];
    num[i] = '\0';

    double res = atof(num);
    free(num);

    return res;
}

void readCommand(char s[], char command[], int* ind) {
    // now s[*ind] may be a lower-case letter
    int i = 0;
    while (islower(s[*ind]))
        command[i++] = s[(*ind)++];
    command[i] = '\0';
}

double recent = 0.0;

void execute(char s[]) {
    if (!strcmp(s, "clear"))
        clear();
    else if (!strcmp(s, "print"))
        printf("%f\n", (recent = top()));
    else if (!strcmp(s, "sin"))
        push(sin(pop()));
    else if (!strcmp(s, "exp"))
        push(exp(pop()));
    else if (!strcmp(s, "pow")) {
        int power = pop();
        push(pow(pop(), power));
    }
    else if (!strcmp(s, "recent"))
        printf("%f\n", recent);
    else if (!strcmp(s, "quit"))
        exit(0);
    else
        printf("error: unknown command: %s\n", s);
}

int getline(char s[], int lim) {
    // lim is the number of all characters, including '\0'
    char c;
    int i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}
