#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char word[]) {
    char keywords[][10] = {
        "int","float","if","else","while","return","for","char","double","void"
    };

    for(int i = 0; i < 10; i++) {
        if(strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[200];
    char token[50];
    int i = 0, j = 0;

    printf("Enter a line of C code:\n");
    fgets(input, sizeof(input), stdin);

    while(input[i] != '\0') {

        if(isalnum(input[i])) {
            token[j++] = input[i];
        }
        else {
            if(j != 0) {
                token[j] = '\0';
                j = 0;

                if(isKeyword(token))
                    printf("%s : Keyword\n", token);
                else if(isdigit(token[0]))
                    printf("%s : Number\n", token);
                else
                    printf("%s : Identifier\n", token);
            }

            if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'||
               input[i]=='='||input[i]=='<'||input[i]=='>')
                printf("%c : Operator\n", input[i]);

            if(input[i]=='('||input[i]==')'||input[i]=='{'||input[i]=='}'||
               input[i]==';'||input[i]==',')
                printf("%c : Special Symbol\n", input[i]);
        }
        i++;
    }

    return 0;
}
