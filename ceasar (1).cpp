#include <stdio.h>
#include <string.h>

void caesarCipher(char *text, int k) {
    int i;
    char ch;
    for (i = 0; text[i] != '\0'; i++) {
        ch = text[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch + k;

            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            text[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + k;

            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            text[i] = ch;
        }
    }
}

int main() {
    char text[100];
    int k;

    printf("Enter a string: ");
    gets(text);

    printf("Enter the shift (k): ");
    scanf("%d", &k);

    caesarCipher(text, k);

    printf("Encrypted message: %s\n", text);

    return 0;
}

