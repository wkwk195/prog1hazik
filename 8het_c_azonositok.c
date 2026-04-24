#include <stdio.h>
#include <string.h>

/**
A C nyelvben egy azonosítóra a következők teljesülnek:

    csak alfanumerikus karakterek (a-z, A-Z, 0-9) szerepelnek benne, ill. az aláhúzás jel ('_')
    betűvel (a-z, A-Z) vagy aláhúzás jellel ('_') kezdődik [azaz nem szerepelhet számjegy az elején]
    legalább egy karakter hosszú
Írjunk egy programot, ami '*' végjelig sztringeket olvas, s minden sztringről eldönti, hogy azonosító-e vagy sem.

Az azonosító tesztelését egy függvénnyel végezzük el! A függvény deklarációja így nézzen ki:

int is_valid_c_identifier(const char* input);
A kimenetben a YES egy igaz értéket, a NO egy hamis értéket jelöl 

(aszerint, hogy a sztring szabályos C azonosító-e vagy sem).
 */

int is_valid_c_identifier(const char* input) {

    if (input == NULL || input[0] == '\0') {
        return 0;
    }

    char c = input[0];
    if (!((c >= 'a' && c <= 'z') || 
          (c >= 'A' && c <= 'Z') || 
          (c == '_'))) {
        return 0;
    }

    
    for (int i = 1; input[i] != '\0'; i++) {
        c = input[i];
        if (!((c >= 'a' && c <= 'z') || 
              (c >= 'A' && c <= 'Z') || 
              (c >= '0' && c <= '9') || 
              (c == '_'))) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char buffer[256];

    printf("Adj meg sztrinkeket '*' vegjelig!\n");

    while (1) {
        printf("\nInput: ");
        if (scanf("%255s", buffer) != 1) break;

        if (strcmp(buffer, "*") == 0) {
            break;
        }

        if (is_valid_c_identifier(buffer)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
