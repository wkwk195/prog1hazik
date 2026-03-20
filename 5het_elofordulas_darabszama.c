#include <stdio.h>


int char_count(char* s, char c) {
    int db = 0; // Számláló inicializálása
    
 
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            db++; 
        }
    }
    
    return db;
}

int main() {
    
    printf("char_count(\"Abba\", 'b') -> %d\n", char_count("Abba", 'b')); 
    printf("char_count(\"Abba\", 'a') -> %d\n", char_count("Abba", 'a')); 
    printf("char_count(\"Abba\", 'x') -> %d\n", char_count("Abba", 'x')); 

    return 0;
}
