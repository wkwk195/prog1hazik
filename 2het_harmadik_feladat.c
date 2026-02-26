#include <stdio.h>
/*Írjunk egy programot, amely beolvas egy pozitív
egész számot (n), majd kiírja 1-től n-ig
(zárt intervallum) az összes néggyel osztható számot!*/
int main()
{
    int n;
    printf("Kerek egy n szamot(intervallum vege):\n");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        if (i%4==0)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
