#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "fisherman.h"

void scan_lobster(struct lobster *lobster, int no_lobster)
{
    int iterator, size, value;
    for (iterator = 0; iterator < no_lobster; iterator++) {
        printf("\nIntroduceti dimensiunea homarului %d: ", iterator + 1);
        scanf("%d", &size);

        if (size <= 0) {
            printf("\nDimensiunea introdusa nu este corecta. Va rog sa reintroduceti dimensiunea homarului.");
            iterator--;
            continue;
        } else {
            lobster[iterator].size = size;

            printf("\nIntroduceti valoarea homarului %d: ", iterator + 1);
            scanf("%d", &value);

            if (value <= 0) {
                printf("\nValoarea introdusa nu este corecta. Va rog sa reintroduceti dimensiunea si valoarea homarului!");
                iterator--;
                continue;
            } else {
                lobster[iterator].value = value;
            }
        }
    }
}

void generate_lobster(struct lobster *lobster, int no_lobster){
    int iterator,value_limit,dimension_limit;
    time_t t;
    printf("In ce interval de la 1 la n(numarul introdus) doriti sa se afle dimensiunea homariilor?");
    scanf("%d",&dimension_limit);
    dimension_limit--;
    if(dimension_limit <=0)
    {
        printf("\nDimensiune introdusa necorespunzatoare,se va actualiza automat la 20");
        dimension_limit=20;
    }
    printf("In ce interval de la 1 la m(numarul introdus) doriti sa se afle valoarea homariilor?");
    scanf("%d",&value_limit);
    value_limit--;
    if(value_limit <=0)
    {
        printf("\nValoare introdusa necorespunzatoare,se va actualiza automat la 20");
        value_limit=20;
    }
    srand((unsigned) time(&t));
    for(iterator = 0; iterator < no_lobster; iterator++){
        lobster[iterator].id = iterator+1;
        lobster[iterator].size = rand()%dimension_limit + 1;
        lobster[iterator].value = rand()%value_limit+ 1;
    }
}

void print_lobster(struct lobster *lobster, int no_lobster){
    int iterator;

    printf("\n Homari:");
    for (iterator = 0; iterator < no_lobster ; iterator++) {
        printf("\n id: %d Dimensiune: %d Valoare: %d monede de aur",iterator + 1, lobster[iterator].size, lobster[iterator].value);
    }
}

void set_matrix_value(struct a_matrix matrix, int row_index, int column_index, int element_value){
    int position;
    if (column_index == 0){
        printf("da");
    }
    position = row_index * matrix.no_cols + column_index;
    *(matrix.matrix + position) = element_value;
}

int get_matrix_value(struct a_matrix matrix, int row_index, int column_index){
    int position;

    position = row_index * matrix.no_cols + column_index;
    return *(matrix.matrix + position);
}

void print_matrix(struct a_matrix matrix){
    int iterator_rows;
    int iterator_columns;

    printf("\n === Matrice === \n");
    for(iterator_rows = 0; iterator_rows < matrix.no_rows; iterator_rows++){
        for(iterator_columns = 0; iterator_columns < matrix.no_cols; iterator_columns++){
            printf("%d ",matrix.matrix[iterator_rows * matrix.no_cols + iterator_columns]);
        }
        printf("\n");
    }
}

int get_max(int val1, int val2){
    if (val1 > val2){
        return val1;
    }else{
        return val2;
    }
}

void lobster_descrete(struct lobster *lobster, int no_lobster, int centimeters)
{
    struct a_matrix matrix;
    int lobster_value;

    matrix.no_rows = no_lobster + 1;
    matrix.no_cols = centimeters + 1;
    matrix.matrix = (int *)calloc(matrix.no_rows * matrix.no_cols, sizeof(int));

    for (int iterator_cols = 0; iterator_cols <= no_lobster; iterator_cols++) {
        for (int iterator_rows = 0; iterator_rows <= centimeters; iterator_rows++) {
            if (iterator_cols == 0 || iterator_rows == 0) {
                matrix.matrix[iterator_cols * matrix.no_cols + iterator_rows] = 0;
            } else if (lobster[iterator_cols - 1].size <= iterator_rows) {
                int exclude_lobster = matrix.matrix[(iterator_cols - 1) * matrix.no_cols + iterator_rows];
                int include_lobster = lobster[iterator_cols - 1].value + matrix.matrix[(iterator_cols - 1) * matrix.no_cols + (iterator_rows - lobster[iterator_cols - 1].size)];
                matrix.matrix[iterator_cols * matrix.no_cols + iterator_rows] = get_max(exclude_lobster, include_lobster);
            } else {
                matrix.matrix[iterator_cols * matrix.no_cols + iterator_rows] = matrix.matrix[(iterator_cols - 1) * matrix.no_cols + iterator_rows];
            }
        }
    }

    lobster_value = get_matrix_value(matrix, matrix.no_rows - 1, matrix.no_cols - 1);
    free(matrix.matrix);
    printf("\n=== Valoare maxima de monede de aur: %d ===\n", lobster_value);
}
