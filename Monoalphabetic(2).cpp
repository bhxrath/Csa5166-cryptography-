#include <stdio.h>
#include <string.h>

void monoalphabeticCipher(char *text, char *key) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = key[text[i] - 'a'];
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = key[text[i] - 'A'] - ('a' - 'A');
        }
    }
}

int main() {
    char text[100];
    char key[] = "QWERTYUIOPLKJHGFDSAZXCVBNM";  // Example key

    printf("Enter a string: ");
    gets(text);

    monoalphabeticCipher(text, key);

    printf("Encrypted message: %s\n", text);

    return 0;
}

