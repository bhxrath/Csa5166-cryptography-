#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to generate cipher text using a keyword
void generate_cipher(char keyword[], char cipher[]) {
    int i, j = 0, used[ALPHABET_SIZE] = {0};

    // Convert keyword to uppercase and remove duplicates
    for (i = 0; keyword[i] != '\0'; i++) {
        char c = toupper(keyword[i]);
        if (!used[c - 'A']) {
            cipher[j++] = c;
            used[c - 'A'] = 1;
        }
    }

    // Fill the remaining characters
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (!used[i]) {
            cipher[j++] = 'A' + i;
        }
    }
    cipher[j] = '\0';
}

// Function to encrypt a plain text
void encrypt(char plaintext[], char cipher[], char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char c = plaintext[i];
        if (c >= 'A' && c <= 'Z') {
            ciphertext[i] = cipher[c - 'A'];
        } else if (c >= 'a' && c <= 'z') {
            ciphertext[i] = cipher[c - 'a'];
        } else {
            ciphertext[i] = c;  // Non-alphabet characters remain unchanged
        }
    }
    ciphertext[i] = '\0';
}

int main() {
    char keyword[] = "CIPHER";
    char cipher[ALPHABET_SIZE + 1];
    char plaintext[] = "This is an example plaintext";
    char ciphertext[256];

    generate_cipher(keyword, cipher);
    printf("Cipher: %s\n", cipher);

    encrypt(plaintext, cipher, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);

    return 0;
}

