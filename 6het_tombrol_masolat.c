#include <stdio.h>

int main() {
    int n;
    int eredeti[100]; 
    int masolat[100];
  
    printf("Hany db szamot szeretnel bevinni?\n");
    scanf("%d", &n);
      
    for (int i = 0; i < n; i++) {
        printf("%d. szam: ", i + 1);
        scanf("%d", &eredeti[i]);
    }
    for (int i = 0; i < n; i++) {
        if (eredeti[i] < 0) {
            masolat[i] = -eredeti[i]; // Ha negatív, megfordítjuk az előjelet
        } else {
            masolat[i] = eredeti[i];  // Ha pozitív, marad ugyanaz
        }
    }

    
    printf("\nA bevitt szamok abszolutertekei: ");
    for (int i = 0; i < n; i++) {
        printf("%d", masolat[i]);
        if (i < n - 1) {
            printf(", "); // Csak az elemek közé teszünk vesszőt
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d", eredeti[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n"); // A végén egy sortörés

    return 0;
}
