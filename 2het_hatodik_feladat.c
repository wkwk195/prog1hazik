#include <stdio.h>

// ASCII kód[32,126]

int main() {
    for (int i = 32; i <= 126; i++) {
        printf("%d: %c\n", i, i);
    }
    return 0;
}
