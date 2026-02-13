#include <stdio.h>

int main() {
    char var;
    int num1, num2;
    char op;

    printf("Enter expression (example: a = 2 + 3): ");
    scanf(" %c = %d %c %d", &var, &num1, &op, &num2);

    int result;

    switch(op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': result = num1 / num2; break;
        default:
            printf("Invalid operator\n");
            return 0;
    }

    printf("\nOptimized Code:\n");
    printf("%c = %d\n", var, result);

    return 0;
}
