#include <stdio.h>
/*1 -> 2 -> ... -> n*/


int main() {
    printf("n: \n");
    int n;
    scanf("%d", &n);
    printf("%d", 1);
    for (int i = 2; i <= n; i++) {
        printf(" -> %d", i);
    }
    printf("\n");

    return 0;
}
