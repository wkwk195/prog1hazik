#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void statisztika(int tomb[], int meret, int *min, int *max, double *atlag) {
    *min = tomb[0];
    *max = tomb[0];
    int osszeg = 0;

    for (int i = 0; i < meret; i++) {
        if (tomb[i] < *min) *min = tomb[i];
        if (tomb[i] > *max) *max = tomb[i];
        osszeg += tomb[i];
    }
    *atlag = (double)osszeg / meret;
}

int main() {

    int szamok[10];
    int legkisebb, legnagyobb;
    double atlag;

    printf("A tomb elemei: ");
    for (int i = 0; i < 10; i++) {
        szamok[i] = rand() % 90 + 10; // [10, 99] intervallum
        printf("%d ", szamok[i]);
    }
    printf("\n");


    statisztika(szamok, 10, &legkisebb, &legnagyobb, &atlag);

    printf("Legkisebb elem: %d\n", legkisebb);
    printf("Legnagyobb elem: %d\n", legnagyobb);
    printf("Az elemek atlaga: %.1f\n", atlag);

    return 0;
}
