#include "prog1.h"
#include <stdio.h>
#include <string.h>


int match_ends(int n, string words[]) {
    int db = 0;
    
    for (int i = 0; i < n; i++) {
        string s = words[i];
        int len = strlen(s);
        
        
        if (len >= 2 && s[0] == s[len - 1]) {
            db++;
        }
    }
    
    return db;
}

int main() {
    
    string szavak1[] = { "aba", "xyz", "aa", "x", "bbb" };
    int szavak1_meret = 5;
    printf("Eredmeny 1: %d (elvart: 3)\n", match_ends(szavak1_meret, szavak1));

    
    string szavak2[] = { "", "x", "xy", "xyx", "xx" };
    int szavak2_meret = 5;
    printf("Eredmeny 2: %d (elvart: 2)\n", match_ends(szavak2_meret, szavak2));

    
    string szavak3[] = { "aaa", "be", "abc", "hello" };
    int szavak3_meret = 4;
    printf("Eredmeny 3: %d (elvart: 1)\n", match_ends(szavak3_meret, szavak3));

    return 0;
}
