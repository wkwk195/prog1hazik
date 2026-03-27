#include <stdio.h>


void feltoltAbece(char tomb[]) {
    int i;
    for (i = 0; i < 26; i++) {
        tomb[i] = 'a' + i;
    }
    
    tomb[26] = '\0';
}

int main() {  
    char abeceSztring[27];
  
    feltoltAbece(abeceSztring);

    printf("Az angol ábécé kisbetűi: %s\n", abeceSztring);

    return 0;
}
