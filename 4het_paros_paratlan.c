#include <stdio.h>

int is_even(int n) {
    if (n % 2 == 0) {
        return 1; 
    } else {
        return 0; 
    }
}

int is_odd(int n) {
    return !is_even(n);
}


int main() {
    int szam;

    printf("Adj meg egy egesz szamot: ");
    if (scanf("%d", &szam) == 1) {
        
        
        if (is_even(szam)) {
            printf("A %d paros.\n", szam);
        }
        
        if (is_odd(szam)) {
            printf("A %d paratlan.\n", szam);
        }
    }

    return 0;
}

