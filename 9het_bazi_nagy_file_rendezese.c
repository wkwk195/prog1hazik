#include <stdio.h>
#include <stdlib.h>

#define BUFFER 1000


void quicksort(int a[],int bal,int jobb){
    int x,temp;
    int i,j;

    i = bal;
    j = jobb;
    x = a[(bal+jobb)/2];

    while (i<=j)
    {
        while (a[i]<x) ++i;
        while (a[j]>x) --j;
        if (i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            ++i;
            --j;
        }
    }
    
    if (bal<j) quicksort(a,bal,j);
    if (i<jobb) quicksort(a,i,jobb);
}

void tomb_kiiratasa(int n,int tomb[]){
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", tomb[i]);
    }
    
}

int get_sorok_szama(const char* fname)
{
    FILE *fp = fopen(fname, "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Hiba! A %s nevű file-t nem sikerült megnyitni!\n", fname);
        exit(1);
    }

    int counter = 0;
    char line[BUFFER];

    while(fgets(line, BUFFER, fp) != NULL)
    {
        ++counter;
    }

    fclose(fp);

    return counter;
}

int *szamok_beolvasasa(const char* fname, int sorok_szama){
    int *tomb=malloc(sorok_szama * sizeof(int));
    int index=0;

    FILE *fp = fopen(fname, "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Hiba! A %s nevű file-t nem sikerült megnyitni!\n", fname);
        exit(1);
    }
    char line[BUFFER];

    while(fgets(line, BUFFER, fp) != NULL)
    {
        tomb[index]=atoi(line);
        ++index;
    }

    fclose(fp);

    return tomb;
}

int main(){
    const char *fname = "millions.txt";
    int sorok_szama=get_sorok_szama(fname);

    int *szamok=szamok_beolvasasa(fname, sorok_szama);

    quicksort(szamok,0,sorok_szama-1);
    tomb_kiiratasa(sorok_szama, szamok);
    
    free(szamok);
    return 0;
}


