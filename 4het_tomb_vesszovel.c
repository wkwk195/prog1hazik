#include <stdio.h>


void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    int n;

    
    printf("Hany darab szamot szeretnel megadni? ");
    scanf("%d", &n);

    
    int szamok[n];

    
    for (int i = 0; i < n; i++) {
        printf("% d. elem: ", i + 1);
        scanf("%d", &szamok[i]);
    }

    
    printf("\nA tomb elemei: ");
    print_array(szamok, n);

    return 0;
}
