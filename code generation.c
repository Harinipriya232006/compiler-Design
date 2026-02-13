#include <stdio.h>

int main() {
    char dest, src1, src2, op;

    printf("Enter expression (example: a=b+c): ");
    scanf("%c=%c%c%c", &dest, &src1, &op, &src2);

    printf("\nTarget Code (Assembly Instructions):\n");

    printf("MOV R1, %c\n", src1);

    switch(op) {
        case '+':
            printf("ADD R1, %c\n", src2);
            break;
        case '-':
            printf("SUB R1, %c\n", src2);
            break;
        case '*':
            printf("MUL R1, %c\n", src2);
            break;
        case '/':
            printf("DIV R1, %c\n", src2);
            break;
        default:
            printf("Invalid operator\n");
            return 0;
    }

    printf("MOV %c, R1\n", dest);

    return 0;
}
