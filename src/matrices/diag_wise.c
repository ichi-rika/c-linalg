#include <matrices/matrix.h>

data_t matrix_diagprod(struct matrix *mat) {
    data_t x = 1.0;

    matrix_foreach_row(i, mat) {
        x *= matrix_at(mat, i, i);
    }

    return x;
}

data_t matrix_diagsum(struct matrix *mat) {
    data_t x = 0.0;

    matrix_foreach_row(i, mat) {
        x += matrix_at(mat, i, i);
    }

    return x;
}
