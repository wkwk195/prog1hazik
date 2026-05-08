#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FAJLNEV "teszt.txt"

void generator(int sorok_szama, int min_hossz, int max_hossz) {
    FILE *f = fopen(FAJLNEV, "w");
    if (!f) {
        perror("Hiba a fajl letrehozasakor");
        return;
    }

    srand(time(NULL));
    

    for (int i = 0; i < sorok_szama; i++) {
        int aktualis_hossz = rand() % (max_hossz - min_hossz + 1) + min_hossz;
        
        for (int j = 0; j < aktualis_hossz; j++) {
            char c = (char)(rand() % (126 - 33 + 1) + 33);
            fputc(c, f);   
            putchar(c);    
        }
        fputc('\n', f);    
        putchar('\n');     
    }

    fclose(f);
    
}


void elemzo(const char *be_fajlnev) {
    FILE *f = fopen(be_fajlnev, "r");
    if (!f) {
        perror("Hiba a fajl megnyitasakor");
        return;
    }

    int max_hossz = -1;
    int leghosszabb_sor_indexe = 0;
    int aktualis_sor_szama = 1;
    int aktualis_hossz = 0;
    int c;

    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            if (aktualis_hossz > max_hossz) {
                max_hossz = aktualis_hossz;
                leghosszabb_sor_indexe = aktualis_sor_szama;
            }
            aktualis_hossz = 0;
            aktualis_sor_szama++;
        } else {
            aktualis_hossz++;
        }
    }

    if (aktualis_hossz > 0 && aktualis_hossz > max_hossz) {
        max_hossz = aktualis_hossz;
        leghosszabb_sor_indexe = aktualis_sor_szama;
    }

    if (max_hossz != -1) {
        printf("%d %d\n", leghosszabb_sor_indexe, max_hossz);
    } else {
        printf("A fajl ures.\n");
    }

    fclose(f);
}

int main(int argc, char *argv[]) {
    if (argc == 4) {
        generator(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    } 
    else if (argc == 2) {
        elemzo(argv[1]);
    } 
    else {
        printf("Hasznalat:\n");
        printf("  Generalas: %s <sorok> <min> <max>\n", argv[0]);
        printf("  Elemzes:   %s <fajlnev>\n", argv[0]);
    }
    return 0;
}
