#include <stdio.h>
#include <stdbool.h>

int main() {
    bool elofordult[100] = {false};
    int szam;
    int kulonbozo_db = 0;

    printf("Adj meg 0 vegjelig egesz szamokat az [1, 99] intervallumbol!\n");

    while (1) {
        printf("Szam: ");
        if (scanf("%d", &szam) != 1) break;

        if (szam == 0) break;
      
        if (szam < 1 || szam > 99) {
            printf("Ez a szam kivul esik az elfogadhato intervallumon!\n");
            continue;
        }

        if (!elofordult[szam]) {
            elofordult[szam] = true;
            kulonbozo_db++;
        }
    }

    printf("\n%d db kulonbozo szam lett megadva.\n", kulonbozo_db);
    
    if (kulonbozo_db > 0) {
        printf("Ezek (novekvo sorrendben): ");
        bool elso = true;
        for (int i = 1; i <= 99; i++) {
            if (elofordult[i]) {
                if (!elso) printf(", ");
                printf("%d", i);
                elso = false;
            }
        }
        printf("\n");
    }

    return 0;
}
