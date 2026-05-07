#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int choice(const int n, const int tomb[]) 
{
    int random_index = rand() % n;

    return tomb[random_index];
}

int main() {
    srand(time(NULL));

    int szamok[] = {10, 20, 30, 40, 50};
    int n = 5;

    int veltlen = choice(n, szamok);
    printf("A valasztott elem: %d\n", veltlen);

    return 0;
}
