#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Hiba: Add meg a fájlnevet!\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Hiba: A fájl nem nyitható meg!\n");
        return 1;
    }

    int szamok[2000]; 
    int n = 0;

    while (fscanf(f, "%d", &szamok[n]) == 1) {
        n++;
    }
    fclose(f);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (szamok[j] > szamok[j + 1]) {
                
                int seged = szamok[j];
                szamok[j] = szamok[j + 1];
                szamok[j + 1] = seged;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", szamok[i]);
    }

    return 0;
}
