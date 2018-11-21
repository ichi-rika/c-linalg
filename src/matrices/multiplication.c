#include <matrices/matrix.h>

struct matrix *matrix_mul(struct matrix *mat_a, struct matrix *mat_b) {
    if (mat_a->n_cols != mat_b->n_rows)
        return NULL;
   
    struct matrix *res = matrix_alloc(mat_a->n_cols, mat_b->n_rows);

    data_t x;

    matrix_foreach_row(i, mat_a) {
        matrix_foreach_col(j, mat_b) {
            x = 0.0;

            matrix_foreach_col(k, mat_a) {
                x += matrix_at(mat_a, i, k) * matrix_at(mat_b, k, j);
            }

            matrix_at(res, i, j) = x; 
        }
    }
    
    return res;
}
