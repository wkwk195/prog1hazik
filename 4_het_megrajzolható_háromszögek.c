#include <stdio.h>

int valid_triangle(double a, double b, double c);

int main() {
    double oldal1, oldal2, oldal3;

    printf("Kerlek, add meg a harom oldal hosszat (szokozzel elvalasztva): ");

    if (scanf("%lf %lf %lf", &oldal1, &oldal2, &oldal3) != 3) {
        printf("Hiba: Kerlek, szamokat adj meg!\n");
        return 1; 
    }

    if (valid_triangle(oldal1, oldal2, oldal3)) {
        printf("\nAz oldalak: %.2f, %.2f, %.2f\n", oldal1, oldal2, oldal3);
        printf("EREDMENY: A haromszog megszerkesztheto!\n");
    } else {
        printf("\nAz oldalak: %.2f, %.2f, %.2f\n", oldal1, oldal2, oldal3);
        printf("EREDMENY: A haromszog NEM szerkesztheto.\n");
    }

    return 0;
}

int valid_triangle(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 0;  
    }

    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        return 1; 
    } else {
        return 0; 
    }
}
