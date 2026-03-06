#include <stdio.h>


int legnagyobb_oszto(int n) {
  for (int i = n / 2; i >= 1; i--) {
        if (n % i == 0) {
            return i; 
        }
  }
    return 1;
}

int main() {
    printf("Az elso 50 szam legnagyobb osztoja:\n");

    for (int i = 1; i <= 50; i++) {
        int oszto = legnagyobb_oszto(i);
      
        printf("%2d legnagyobb osztoja: %2d\n", i, oszto);
    }

    return 0;
}
