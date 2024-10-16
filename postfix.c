#include <stdio.h>
char stack[100];
int top = -1;
void push(char ch) {
    stack[++top] = ch;
}
char pop() {
    return stack[top--];
}
char peek() {
    return stack[top];
}
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
void Postfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    while (infix[i] != '\0') {
        char ch = infix[i];
        if ((ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z')||(ch >= '0' && ch <= '9')) {
            postfix[k++] = ch;
        } 
        else if (ch == '(') {
            push(ch);
        } 
        else if (ch == ')') {
            while (peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); 
        } 
        else { 
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
        i++;
    }
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; 
    
}
int main() {
    char infix[100], postfix[100];

    printf("Enter a  expression: ");
    scanf("%s", infix);

    Postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

