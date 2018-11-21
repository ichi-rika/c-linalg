#include <matrices/matrix.h>

void matrix_rowswap(struct matrix *mat, ind_t i1, ind_t i2) {
    data_t x;

    matrix_foreach_col(j, mat) {
        x = matrix_at(mat, i1, j);
        matrix_at(mat, i1, j) = matrix_at(mat, i2, j);
        matrix_at(mat, i2, j) = x;
    }
}

void matrix_rowadd(struct matrix *mat, ind_t i1, ind_t i2, data_t scalar) {
    matrix_foreach_col(j, mat) {
        matrix_at(mat, i1, j) += scalar * matrix_at(mat, i2, j);
    }
}
