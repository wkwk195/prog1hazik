#include <stdio.h>

int main() {
    int cellak[601];

    for (int i = 1; i <= 600; i++) {
        cellak[i] = 0;
    }


    for (int lepes = 1; lepes <= 600; lepes++) {
        for (int j = lepes; j <= 600; j += lepes) {
            if (cellak[j] == 0) {
                cellak[j] = 1;
            } else {
                cellak[j] = 0;
            }
        }
    }

    printf("A nyitva maradt cellak:\n");
    int elso = 1;
    for (int i = 1; i <= 600; i++) {
        if (cellak[i] == 1) {
            if (!elso) printf(", ");
            printf("%d", i);
            elso = 0;
        }
    }
puts("");

    return 0;
}
