#include <stdio.h>
#include <stdlib.h>


struct Statisztika {
    int min;
    int max;
    double atlag;
};

struct Statisztika elemez(int tomb[], int meret) {
    struct Statisztika s;
    int osszeg = 0;

    s.min = tomb[0];
    s.max = tomb[0];
    osszeg = tomb[0];

    for (int i = 1; i < meret; i++) {
        if (tomb[i] < s.min) s.min = tomb[i];
        if (tomb[i] > s.max) s.max = tomb[i];
        osszeg += tomb[i];
    }

    s.atlag = (double)osszeg / meret;
    return s;
}

int main() {
    srand(2021); 

    int szamok[10];
    int meret = 10;

    printf("A tomb elemei: ");
    for (int i = 0; i < meret; i++) {
        szamok[i] = rand() % (99 - 10 + 1) + 10;
        printf("%d%s", szamok[i], (i == meret - 1) ? "" : ", ");
    }
    printf("\n");

    struct Statisztika eredmeny = elemez(szamok, meret);

    printf("Legkisebb elem: %d\n", eredmeny.min);
    printf("Legnagyobb elem: %d\n", eredmeny.max);
    printf("Az elemek atlaga: %.1f\n", eredmeny.atlag);

    return 0;
}
