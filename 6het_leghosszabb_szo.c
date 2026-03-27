#include <stdio.h>
#include <string.h>

int main() {
    char szo[100];
    int darab = 0;
    int max_hossz = 0;

    printf("Adj meg szavakat '*' vegjelig!\n");

    while (1) {
        printf("Szo: ");
        if (fgets(szo, sizeof(szo), stdin) == NULL){
          break;
        }
        size_t hossz = strlen(szo);
        if (hossz > 0 && szo[hossz - 1] == '\n') {
            szo[hossz - 1] = '\0';
            hossz--; 
        }

        if (strcmp(szo, "*") == 0) {
            break;
        }

        darab++;
        if (hossz > max_hossz) {
            max_hossz = hossz;
        }
    }

    printf("\n%d db szot adtal meg. A leghosszabb szo %d karakterbol all.\n", darab, max_hossz);

    return 0;
}
