//
// Created by Gherasie Gabriel Catalin  on 5/1/2024.
//
#ifndef FISHERMAN_H
#define FISHERMAN_H
struct lobster{
    int id;
    int size;
    int value;
};

struct a_matrix{
    int no_rows;
    int no_cols;
    int *matrix;
};
void scan_lobster(struct lobster *lobster, int no_lobster);
void generate_lobster(struct lobster *lobster, int no_lobster);
void print_lobster(struct lobster *lobster, int no_lobster);
void set_matrix_value(struct a_matrix matrix, int row_index, int column_index, int element_value);
void dynamic_programming_knapsack_discrete(struct lobster *lobster, int no_lobster, int centimeters);
void print_matrix(struct a_matrix matrix);
int get_matrix_value(struct a_matrix matrix, int row_index, int column_index);
int get_max(int val1, int val2);
#endif //CODE_FISHERERMAN_H
