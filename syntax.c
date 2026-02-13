#include <stdio.h>
#include <string.h>

char input[100];
int i = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();

void E() {
    T();
    Eprime();
}

void Eprime() {
    if(input[i] == '+') {
        i++;
        T();
        Eprime();
    }
}

void T() {
    F();
    Tprime();
}

void Tprime() {
    if(input[i] == '*') {
        i++;
        F();
        Tprime();
    }
}

void F() {
    if(input[i] == '(') {
        i++;
        E();
        if(input[i] == ')')
            i++;
        else {
            printf("Invalid Expression\n");
            return;
        }
    }
    else if(input[i] == 'i') {   // 'i' represents id
        i++;
    }
    else {
        printf("Invalid Expression\n");
    }
}

int main() {
    printf("Enter expression (use i for id): ");
    scanf("%s", input);

    E();

    if(input[i] == '\0')
        printf("Valid Expression\n");
    else
        printf("Invalid Expression\n");

    return 0;
}
