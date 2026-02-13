#include <stdio.h>
#include <string.h>

struct symbol {
    char name[20];
    char type[10];
} table[20];

int count = 0;

// Add variable to symbol table
void add(char name[], char type[]) {
    strcpy(table[count].name, name);
    strcpy(table[count].type, type);
    count++;
}

// Find variable in symbol table
int find(char name[]) {
    for(int i = 0; i < count; i++) {
        if(strcmp(table[i].name, name) == 0)
            return i;
    }
    return -1;
}

int main() {
    char var1[20], var2[20];
    char type1[10], type2[10];

    // Example declarations
    add("a", "int");
    add("b", "float");

    printf("Enter assignment (example: a b): ");
    scanf("%s %s", var1, var2);

    int i1 = find(var1);
    int i2 = find(var2);

    if(i1 == -1 || i2 == -1) {
        printf("Semantic Error: Undeclared variable\n");
    }
    else {
        strcpy(type1, table[i1].type);
        strcpy(type2, table[i2].type);

        if(strcmp(type1, type2) != 0) {
            printf("Semantic Error: Type Mismatch (%s = %s)\n", type1, type2);
        }
        else {
            printf("Semantic Analysis Successful — No Error\n");
        }
    }

    return 0;
}
