#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int n, int a[]) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int main() {
    srand(time(NULL));
    
    int szamok[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 8;

    shuffle(n, szamok);

    for(int i = 0; i < n; i++) {
        printf("%d ", szamok[i]);
    }
    printf("\n");

    return 0;
}
