#include <stdio.h>
/*Írjunk egy programot, amely beolvas egy pozitív
egész számot (n), majd kiírja n-től
1-ig (zárt intervallum) visszafelé az összes páratlan számot!*/

int main()
{
    int n;
    printf("Kerek egy n szamot(intervallum vege):\n");
    scanf("%d",&n);
    for (int i =1 ; i <= n; n--)
    {
        if (n%2==1)
        {
            printf("%d\n",n);
        }
    }
    return 0;
}
