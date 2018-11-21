#include <matrices/matrix.h>


void matrix_radd(struct matrix *mat_a, struct matrix *mat_b) {
    if (mat_a->n_rows != mat_b->n_rows
            || mat_a->n_cols != mat_b->n_cols)
        return;

    matrix_foreach_row(i, mat_a) {
        matrix_foreach_col(j, mat_a) {
            matrix_at(mat_a, i, j) += matrix_at(mat_b, i, j);
        }
    }
}

void matrix_rsub(struct matrix *mat_a, struct matrix *mat_b) {
    if (mat_a->n_rows != mat_b->n_rows
            || mat_a->n_cols != mat_b->n_cols)
        return;

    matrix_foreach_row(i, mat_a) {
        matrix_foreach_col(j, mat_a) {
            matrix_at(mat_a, i, j) -= matrix_at(mat_b, i, j);
        }
    }
}

void matrix_rneg(struct matrix *mat) {
    matrix_foreach_row(i, mat) {
        matrix_foreach_col(j, mat) {
            matrix_at(mat, i, j) *= -1.0;
        }
    }
}

void matrix_rsadd(struct matrix *mat, data_t scalar) {
    matrix_foreach_row(i, mat) {
        matrix_foreach_col(j, mat) {
            matrix_at(mat, i, j) += scalar;
        }
    }
}

void matrix_rssub(struct matrix *mat, data_t scalar) {
    matrix_foreach_row(i, mat) {
        matrix_foreach_col(j, mat) {
            matrix_at(mat, i, j) -= scalar;
        }
    }
}

void matrix_rsmul(struct matrix *mat, data_t scalar) {
    matrix_foreach_row(i, mat) {
        matrix_foreach_col(j, mat) {
            matrix_at(mat, i, j) *= scalar;
        }
    }
}

