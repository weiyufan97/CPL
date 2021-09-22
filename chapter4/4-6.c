#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER 0
#define OPERATOR 1
#define COMMAND 2

int getop();
int getch();
void ungetch(int c);

void push(double f);
double pop();

void execute(char s[]);
double top();
double clear();

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
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
        case COMMAND:
            execute(s);
            break;
        default:
            printf("error: unknown command: %s", s);
            break;
        }
    }
}

int getop(char s[]) {
    // collect characters and check its type
    int i, c;
    // skip white spaces
    while (isspace(s[0] = c = getch()))
        ;
    s[1] = '\0';

    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        return c;

    // check if it is a number
    i = 0;
    if (!isdigit(c) && c != '.') {
        // read command or operator
        while (isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';

        if (c != EOF)
            ungetch(c);
        return COMMAND;
    }
    
    // collect numbers, note: the first digit has been added into s
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    // now s[i] is the first character not a digit
    // so it should be '\0'
    s[i] = '\0';
    if (c != EOF && !isspace(c))
        ungetch(c);
    return NUMBER;
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

#define BUFLEN 1024
int bufp = 0;
char buf[BUFLEN];

int getch() {
    return bufp == 0 ? getchar() : buf[--bufp];
}

void ungetch(char c) {
    if (bufp == BUFLEN)
        printf("error: buf is full\n");
    else
        buf[bufp++] = c;
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


