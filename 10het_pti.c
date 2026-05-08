#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SOR 100
#define NEV_MAX_HOSSZ 50

int main() {
    FILE *fp = fopen("nevek.csv", "r");
    if (!fp) {
        fprintf(stderr, "Hiba: A nevek.csv fajl nem talalhato!\n");
        return 1;
    }

    char nevek_tara[MAX_SOR * NEV_MAX_HOSSZ];
    int pti_szamlalo = 0;
    char sor[128];

    while (fgets(sor, sizeof(sor), fp)) {
        sor[strcspn(sor, "\n\r")] = 0;

        char *nev_token = strtok(sor, ",");   
        char *kor_token = strtok(NULL, ",");  
        char *szak_token = strtok(NULL, ",");

        if (nev_token && szak_token) {
            int pti_e = 1;
            char keresett[] = "pti";
            for (int i = 0; i < 3; i++) {
                if (tolower((unsigned char)szak_token[i]) != keresett[i]) {
                    pti_e = 0;
                    break;
                }
            }
            if (szak_token[3] != '\0' && !isspace(szak_token[3])) {
                pti_e = 0;
            }

            if (pti_e) {
                int index = pti_szamlalo * NEV_MAX_HOSSZ;

                nevek_tara[index] = (char)toupper((unsigned char)nev_token[0]);
                int j = 1;
                while (nev_token[j] != '\0' && j < NEV_MAX_HOSSZ - 1) {
                    nevek_tara[index + j] = (char)tolower((unsigned char)nev_token[j]);
                    j++;
                }
                nevek_tara[index + j] = '\0'; // Sztring lezárása
                pti_szamlalo++;
            }
        }
    }
    fclose(fp);

    for (int i = 0; i < pti_szamlalo - 1; i++) {
        for (int j = 0; j < pti_szamlalo - i - 1; j++) {
            char *p1 = &nevek_tara[j * NEV_MAX_HOSSZ];
            char *p2 = &nevek_tara[(j + 1) * NEV_MAX_HOSSZ];

            if (strcmp(p1, p2) > 0) {
                for (int k = 0; k < NEV_MAX_HOSSZ; k++) {
                    char ideiglenes = p1[k];
                    p1[k] = p2[k];
                    p2[k] = ideiglenes;
                }
            }
        }
    }

    for (int i = 0; i < pti_szamlalo; i++) {
        printf("%s", &nevek_tara[i * NEV_MAX_HOSSZ]);
        if (i < pti_szamlalo - 1) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}
