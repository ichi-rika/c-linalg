#include <matrices/matrix.h>


struct matrix *matrix_zero(ind_t n_rows, ind_t n_cols) {
    struct matrix *mat = matrix_alloc(n_rows, n_cols);
    if (mat == NULL) return NULL;

    matrix_fill(0.0, mat);

    return mat;
}


void matrix_fill(data_t x, struct matrix *mat) {
    if (mat == NULL) return;

    for (mind_t c = 0; c < mat->n_cells; ++c) {
        mat->cells[c] = x;
    }
}

struct matrix *matrix_filled(data_t x, ind_t n_rows, ind_t n_cols) {
    struct matrix *mat = matrix_alloc(n_rows, n_cols);
    if (mat == NULL) return NULL;

    matrix_fill(x, mat);

    return mat;
}

struct matrix *matrix_id(ind_t n_dim) {
    struct matrix *mat = matrix_alloc(n_dim, n_dim);
    if (mat == NULL) return NULL;
    
    matrix_foreach_row(i, mat) {
        matrix_at(mat, i, i) = 1;
    }
    
    return mat;
}

