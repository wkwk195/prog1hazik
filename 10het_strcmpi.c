#include <stdio.h>
#include <ctype.h> 

int strcmpi(const char* s1, const char* s2) {

    while (*s1 && (tolower((unsigned char)*s1) == tolower((unsigned char)*s2))) {
        s1++;
        s2++;
    }

    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}

int main() {

    const char *szoveg1 = "Alma";
    const char *szoveg2 = "ALMA";

    if (strcmpi(szoveg1, szoveg2) == 0) {
        printf("'%s' es '%s' egyformak!\n", szoveg1, szoveg2);
    }


    if (strcmpi("ez", "EZAZ") != 0) {
        printf("'ez' es 'EZAZ' nem egyformak.\n");
    }

    return 0;
}
