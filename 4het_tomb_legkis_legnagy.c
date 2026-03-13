#include <stdio.h>


int legkisebb_elem(int n, int tomb[]) {
    int min = tomb[0]; 
    for (int i = 1; i < n; i++) {
        if (tomb[i] < min) {
            min = tomb[i]; 
        }
    }
    return min;
}


int legnagyobb_elem(int n, int tomb[]) {
    int max = tomb[0]; 
    for (int i = 1; i < n; i++) {
        if (tomb[i] > max) {
            max = tomb[i]; 
        }
    }
    return max;
}

int main() {
 
    int szamok[] = {12, 5, 8, 21, 3, 17};
    int meret = 6;

    int min = legkisebb_elem(meret, szamok);
    int max = legnagyobb_elem(meret, szamok);

    printf("A tomb elemei: 12, 5, 8, 21, 3, 17\n");
    printf("A legkisebb elem: %d\n", min);
    printf("A legnagyobb elem: %d\n", max);

    return 0;
}
