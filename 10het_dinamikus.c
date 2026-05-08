#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynArray;

void da_init(DynArray *self) {
    (*self).data = NULL;
    (*self).size = 0;
    (*self).capacity = 0;
}

void da_clear(DynArray *self) {
    if (self != NULL) {
        free((*self).data);
        (*self).data = NULL;
        (*self).size = 0;
        (*self).capacity = 0;
    }
}


void da_append(DynArray *self, int value) {
    if ((*self).size == (*self).capacity) {
        int new_capacity = ((*self).capacity == 0) ? 1024 : (*self).capacity * 2;
        
        int *new_data = (int *)realloc((*self).data, new_capacity * sizeof(int));
        
        if (new_data == NULL) {
            fprintf(stderr, "Memoriafoglalasi hiba!\n");
            exit(1);
        }
        (*self).data = new_data;
        (*self).capacity = new_capacity;
    }
    (*self).data[(*self).size] = value;
    (*self).size = (*self).size + 1;
}

void quicksort(int a[], int bal, int jobb) {
    int i = bal, j = jobb;
    int x = a[(bal + jobb) / 2];
    int temp;

    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (bal < j) quicksort(a, bal, j);
    if (i < jobb) quicksort(a, i, jobb);
}

int main() {
    const char *fname = "millions.txt";
    FILE *fp = fopen(fname, "r");

    if (fp == NULL) {
        fprintf(stderr, "Hiba! A %s nem talalhato!\n", fname);
        return 1;
    }

    DynArray szamok;
    da_init(&szamok);

    int ideiglenes;
    while (fscanf(fp, "%d", &ideiglenes) == 1) {
        da_append(&szamok, ideiglenes);
    }
    fclose(fp);

    printf("Beolvasva: %d szam.\n", szamok.size);

    if (szamok.size > 0) {
        quicksort(szamok.data, 0, szamok.size - 1);
    }

    for (int i = 0; i < (szamok.size < 5 ? szamok.size : 5); i++) {
        printf("%d. elem: %d\n", i+1, szamok.data[i]);
    }

    da_clear(&szamok);
    printf("Clear utan a meret: %d\n", szamok.size);

    return 0;
}
