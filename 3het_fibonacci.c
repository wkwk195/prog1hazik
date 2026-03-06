#include <stdio.h>

unsigned long long fibonacci(int n) {
    if (n <= 1) return n;

    unsigned long long a = 0, b = 1, temp;
    
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    
    return b;
}

int main() {
    printf("Az elso 100 Fibonacci szam:\n");

    for (int i = 0; i < 100; i++) {
       
        printf("%d: %llu\n", i + 1, fibonacci(i));
    }

    return 0;
}
