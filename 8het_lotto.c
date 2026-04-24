#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, also, felso;

    printf("Hany db random szamot kersz? ");
    scanf("%d", &n);
    printf("Also hatar: ");
    scanf("%d", &also);
    printf("Felso hatar (zart intervallum): ");
    scanf("%d", &felso);

    int tartomany = felso - also + 1;

    if (n > tartomany) {
        printf("Hiba: Nem lehet %d db kulonbozo szamot generalni!\n", n);
        return 1;
    }

    int szamok[n];
    int db = 0;


    srand(time(NULL));


    while (db < n) {
        int veletlen = (rand() % tartomany) + also;
        
        int benne_van = 0;
        for (int i = 0; i < db; i++) {
            if (szamok[i] == veletlen) {
                benne_van = 1;
                break;
            }
        }


        if (!benne_van) {
            szamok[db] = veletlen;
            db++;
        }
    }

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (szamok[j] > szamok[j + 1]) {
                int seged = szamok[j];
                szamok[j] = szamok[j + 1];
                szamok[j + 1] = seged;
            }
        }
    }

    
    printf("A generalt szamok: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", szamok[i]);
    }
    printf("\n");

    return 0;
}
