#include <stdio.h>
#include <stdlib.h>
#include "fisherman.h"

int read_lobster_from_file(struct lobster *lobster, int no_lobster, const char *filename);

int main() {
    struct lobster *lobster;
    int no_lobster,exit;
    int centimeters;
    char aleatoriu;

    printf("------Knapsack in homari------\n");
    printf("Capacitatea plasei: ");
    scanf("%d", &centimeters);

    printf("Numarul de homari: ");
    scanf("%d", &no_lobster);

    lobster = malloc(no_lobster * sizeof(struct lobster));
    if (lobster == NULL) {
        fprintf(stderr, "Alocarea de memorie a eșuat\n");
        return 1;
    }

    printf("------Va rog sa introduceti (m) pentru date introduse manual, (a) pentru date alese aleatoriu------\n");

    while (1)
    {
        scanf(" %c", &aleatoriu);
        if (aleatoriu == 'm')
        {
            scan_lobster(lobster, no_lobster);
            break;
        }
        else if (aleatoriu == 'a')
        {
            generate_lobster(lobster, no_lobster);
            break;
        }
        else
        {
            printf("Caracter invalid. Va rog sa introduceti (m) pentru date introduse manual, (a) pentru date alese aleatoriu!\n");
        }
    }
    print_lobster(lobster, no_lobster);
    lobster_descrete(lobster, no_lobster, centimeters);

    free(lobster);

    return 0;
}
