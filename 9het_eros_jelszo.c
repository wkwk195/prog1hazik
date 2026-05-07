#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void shuffle_str(char *s, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main() {
    srand(time(NULL));

    
    const char *kisbetuk = "abcdefghijklmnopqrstuvwxyz";
    const char *nagybetuk = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *szamok = "0123456789";
    const char *specialis = ".,;'";
    const char *osszes = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,;'";

    int hossz = 8 + rand() % 5; 
    char jelszo[13]; // Max 12 karakter + lezáró nulla

    jelszo[0] = kisbetuk[rand() % strlen(kisbetuk)];
    jelszo[1] = nagybetuk[rand() % strlen(nagybetuk)];
    jelszo[2] = szamok[rand() % strlen(szamok)];
    jelszo[3] = specialis[rand() % strlen(specialis)];

    for (int i = 4; i < hossz; i++) {
        jelszo[i] = osszes[rand() % strlen(osszes)];
    }
    jelszo[hossz] = '\0'; // Sztring lezárása

    // hogy ne típusonként csoportosítva (kis, nagy, szám, spec) jöjjenek
    shuffle_str(jelszo, hossz);

    printf("%s\n", jelszo);

    return 0;
}
