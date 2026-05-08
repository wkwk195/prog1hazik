#include <stdio.h>

int main() {
    int i, j, k, l, m, n;
    long szorzat;
    int osszeg;

    for (i = 1; i <= 40; i++) {
        for (j = i + 1; j <= 41; j++) {
            for (k = j + 1; k <= 42; k++) {
                for (l = k + 1; l <= 43; l++) {
                    for (m = l + 1; m <= 44; m++) {
                        
                        n = 90 - (i + j + k + l + m);

                        if (n > m && n <= 45) {
                            
                            szorzat = (long)i * j * k * l * m * n;
                            
                            if (szorzat == 996300) {
                                printf("Megvannak a szamok: %d, %d, %d, %d, %d, %d\n", i, j, k, l, m, n);
                                return 0; 
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
