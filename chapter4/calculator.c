/* A simple calculator receives reverse polish expression:
 * It includes:
 * the basic framework of chapter 4.3
 * - exercise 4-3: add the modulus operator
 * - exercise 4-5: 
 * - exercise 4-11: use internal static variable
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "utilities.h"

#define MAXLEN 100 // max length of an operand
#define NUMBER 0 // type of a number
#define STKSIZE 1000 
#define BUFSIZE 1000 

double stack[STKSIZE];
int top = 0; // next free position for placing decimal values

int getop(char s[]);
void push(double x);
double pop();

static char buf[BUFSIZE];
char getch(int* bufp);

int main() {
    // read a rpn from the standard input
    // each time read an operand or an operator
    // when encountering an operand, store it into the stack
    // when an operator, get the operands and calculate the result
    // then store back
    // when terminate, return the result(the only element in the stack) 

    char s[MAXLEN]; // store operand or operator
    int type;
    double op2;

    while ((type = getop(s)) != EOF) {
        if (type == NUMBER)
            push(atof(s));
        else {
            switch (type) {
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 == 0.0) {
                    printf("zero divisor!\n");
                    return EXIT_FAILURE;
                }
                push(pop() / op2);
                break;
            case '%':
                op2 = pop();
                if (op2 == 0.0) {
                    printf("zero divisor!\n");
                    return EXIT_FAILURE;
                }
                push((int)pop() % (int)op2);
                break;
            case '\n':
                printf("%.8g\n", pop());
                break;
            default:
                printf("Invalid input!\n");
                return EXIT_FAILURE;
            }
        }
    }

    // handling input from file
    if (top != 0)
        printf("%.8g\n", pop());

    return 0;
}

int getop(char s[]) {
    static int bufp = 0; // next free position for placing a character into the buffer

    int i, c; // i: next opsition for storing characters, c: character

    // use getch to get the characters from own buffer

    // skip white spaces
    while ((s[0] = c = getch(&bufp)) == ' ' || c == '\t')
        ;
    
    s[1] = '\0';
    if (!isdigit(c) && c != '.') // without varifying the operators
        return c;
    // read integral part
    i = 0;
    while ((isdigit(s[++i] = c = getch(&bufp))))
        ;
    
    if (c == '.')
        // collect decimal part
        while ((isdigit(s[++i] = c = getch(&bufp))))
            ;
    if (c != EOF) {
        buf[bufp++] = c;
    }
    return NUMBER;
}

double pop() {
    if (top <= 0) {
        printf("stack is empty!\n");
        return 0.0;
    }
    return stack[--top];
}

void push(double x) {
    if (top == STKSIZE)
        printf("stack is full!\n");
    stack[top++] = x;
}

char getch(int* bufp) {
    return *bufp > 0 ? buf[--*bufp] : getchar();
}