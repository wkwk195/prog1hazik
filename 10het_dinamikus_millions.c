#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 1024

void quicksort(int a[], int bal, int jobb) {
    int x, temp;
    int i = bal;
    int j = jobb;
    x = a[(bal + jobb) / 2];

    while (i <= j) {
        while (a[i] < x) ++i;
        while (a[j] > x) --j;
        if (i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            ++i; --j;
        }
    }
    if (bal < j) quicksort(a, bal, j);
    if (i < jobb) quicksort(a, i, jobb);
}

int main() {
    const char *fname = "millions.txt";
    FILE *fp = fopen(fname, "r");

    if (fp == NULL) {
        fprintf(stderr, "Hiba! A %s nem nyitható meg!\n", fname);
        return 1;
    }
  
    int capacity = INITIAL_CAPACITY;
    int count = 0;
    int *szamok = malloc(capacity * sizeof(int));

    if (szamok == NULL) {
        fprintf(stderr, "Memóriafoglalási hiba!\n");
        return 1;
    }

    int aktualis_szam;

    while (fscanf(fp, "%d", &aktualis_szam) == 1) {
        if (count == capacity) {
            capacity *= 2;
            int *uj_tomb = realloc(szamok, capacity * sizeof(int));
            if (uj_tomb == NULL) {
                fprintf(stderr, "Nem sikerült bővíteni a memóriát!\n");
                free(szamok);
                fclose(fp);
                return 1;
            }
            szamok = uj_tomb;
        }
        szamok[count++] = aktualis_szam;
    }

    fclose(fp);

    if (count > 0) {
        quicksort(szamok, 0, count - 1);
        for (int i = 0; i < count; i++) {
            printf("%d\n", szamok[i]);
        }
    }

    free(szamok);

    return 0;
}
