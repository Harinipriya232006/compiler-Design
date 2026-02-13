#include <stdio.h>
#include <string.h>

int main() {
    char expr[50];
    char op1, op2, operator;
    char temp = 'A';   // Temporary variable names

    printf("Enter expression (e.g., a=b+c*d): ");
    scanf("%s", expr);

    printf("\nThree Address Code:\n");

    // Find operator with highest precedence (* or /)
    for(int i = 0; expr[i] != '\0'; i++) {
        if(expr[i] == '*' || expr[i] == '/') {
            op1 = expr[i-1];
            op2 = expr[i+1];
            operator = expr[i];

            printf("%c = %c %c %c\n", temp, op1, operator, op2);

            expr[i+1] = temp;  // Replace subexpression
            temp++;
        }
    }

    // Then handle + or -
    for(int i = 0; expr[i] != '\0'; i++) {
        if(expr[i] == '+' || expr[i] == '-') {
            op1 = expr[i-1];
            op2 = expr[i+1];
            operator = expr[i];

            printf("%c = %c %c %c\n", temp, op1, operator, op2);

            expr[i+1] = temp;
            temp++;
        }
    }

    printf("%c = %c\n", expr[0], temp-1);

    return 0;
}
