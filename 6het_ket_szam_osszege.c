#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("hibas, mert két paraméter szamot kell megadj!!!\n");
        return 1; 
    }
    int szam1 = atoi(argv[1]);
    int szam2 = atoi(argv[2]);

    int osszeg = szam1 + szam2;
    printf("%d\n", osszeg);

    return 0;
}
