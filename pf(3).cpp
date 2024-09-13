#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void createMatrix(char key[], char matrix[SIZE][SIZE]) {
    int used[26] = {0};
    int x = 0, y = 0;

    for (int i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if (ch == 'J') ch = 'I';  // Replace 'J' with 'I'
        if (!used[ch - 'A']) {
            matrix[x][y++] = ch;
            used[ch - 'A'] = 1;
            if (y == SIZE) {
                y = 0;
                x++;
            }
        }
    }

    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch == 'J') continue;
        if (!used[ch - 'A']) {
            matrix[x][y++] = ch;
            used[ch - 'A'] = 1;
            if (y == SIZE) {
                y = 0;
                x++;
            }
        }
    }
}

void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void playfairEncrypt(char plaintext[], char matrix[SIZE][SIZE], char ciphertext[]) {
    int length = strlen(plaintext);
    int i, row1, col1, row2, col2;
    char digraph[2];

    for (i = 0; i < length; i += 2) {
        digraph[0] = toupper(plaintext[i]);
        if (i + 1 < length && toupper(plaintext[i + 1]) != digraph[0]) {
            digraph[1] = toupper(plaintext[i + 1]);
        } else {
            digraph[1] = 'X';  // Use 'X' as a filler if letters are the same or odd number of letters
            i--;  // Adjust index to check next letter again
        }

        if (digraph[0] == 'J') digraph[0] = 'I';
        if (digraph[1] == 'J') digraph[1] = 'I';

        findPosition(matrix, digraph[0], &row1, &col1);
        findPosition(matrix, digraph[1], &row2, &col2);

        if (row1 == row2) {
            ciphertext[i] = matrix[row1][(col1 + 1) % SIZE];
            ciphertext[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            ciphertext[i] = matrix[(row1 + 1) % SIZE][col1];
            ciphertext[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        } else {
            ciphertext[i] = matrix[row1][col2];
            ciphertext[i + 1] = matrix[row2][col1];
        }
    }
    ciphertext[length] = '\0';
}

int main() {
    char key[] = "KEYWORD";
    char matrix[SIZE][SIZE];
    char plaintext[100];
    char ciphertext[100];

    printf("Enter plaintext: ");
    gets(plaintext);

    createMatrix(key, matrix);

    printf("Playfair Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    playfairEncrypt(plaintext, matrix, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    return 0;
}

