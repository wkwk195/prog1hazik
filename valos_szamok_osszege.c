#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fajl = fopen("valos_szamok.txt", "r");
    char puffer[100];
    long double osszeg = 0.0;

    if (fajl == NULL) {
        printf("HIBA: A 'valos_szamok.txt' nem talalhato a program mellett!\n");
        return 1;
    }

    
    while (fscanf(fajl, "%s", puffer) != EOF) {
        for (int i = 0; puffer[i]; i++) {
            if (puffer[i] == ',') puffer[i] = '.';
        }
        
        osszeg += strtold(puffer, NULL);
    }

    fclose(fajl);

    printf("Az osszeg: %.20Lf\n", osszeg);

    return 0;
}
