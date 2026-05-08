#include <stdio.h>

#define MERET 6

void mellekatlo_kiirasa(int matrix[MERET][MERET]) {
    printf("A matrix mellekatlojanak elemei:\n");
    for (int i = 0; i < MERET; i++) {
        printf("%d ", matrix[i][MERET - 1 - i]);
    }
    printf("\n");
}

int main() {
    int matrix[MERET][MERET];
    int szamlalo = 1;

    printf("A teljes matrix:\n");
    for (int i = 0; i < MERET; i++) {
        for (int j = 0; j < MERET; j++) {
            matrix[i][j] = szamlalo++;
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    mellekatlo_kiirasa(matrix);

    return 0;
}
