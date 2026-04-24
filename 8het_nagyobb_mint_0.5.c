#include <stdio.h>

int main() {
    FILE *be, *ki;
    double szam;
    int db = 0;

    be = fopen("in.txt", "r");
    if (be == NULL) {
        printf("# Hiba: in.txt nem talalhato!\n");
        return 1;
    }
    printf("# in.txt sikeresen megnyitva\n");

    ki = fopen("out.txt", "w");
    if (ki == NULL) {
        fclose(be);
        return 1;
    }

    printf("# 0,5-nél nagyobb számok szűrése...\n");

    while (fscanf(be, "%lf", &szam) != EOF) {
        if (szam > 0.5) {
            fprintf(ki, "%f\n", szam);
            db++;
        }
    }

    printf("# szűrés vége\n");

    fclose(be);
    fclose(ki);
    printf("# out.txt bezárva\n");

    printf("# out.txt-be kiírt számok mennyisége: %d db\n", db);

    return 0;
}
