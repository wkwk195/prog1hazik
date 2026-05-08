#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void my_strfry(char *s) {
    if (s == NULL) return;

    int n = strlen(s);
    if (n <= 1) return;

    for (int i = 0; i < n - 1; i++) {
        int j = i + rand() % (n - i);

        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main() {
    srand(time(NULL));

    char szo[] = "Programozas";

    printf("Eredeti szo: %s\n", szo);

    my_strfry(szo);
    printf("Elso keveres: %s\n", szo);

    return 0;
}
