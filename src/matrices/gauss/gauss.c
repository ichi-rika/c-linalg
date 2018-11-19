#include <stdlib.h>

#include "matrices/matrix.h"

#include "gauss_result.h"

ind_t gauss_maxrow(struct matrix *mat, ind_t n);


struct gauss_result *matrix_solvegauss(struct matrix *mat) {
    if (!matrix_issquare(mat)) {
        return NULL;
    }

    ind_t n = mat->n_rows;

    struct gauss_result *res = malloc(sizeof *res);

    struct matrix *inv = matrix_id(n);

    matrix_foreach_row(i, mat) { 
        ind_t max_i = gauss_maxrow(mat, i);
        matrix_rowswap(mat, i, max_i);


    }

    return res;
}


ind_t gauss_maxrow(struct matrix *mat, ind_t n) {
    mind_t max_i;
    data_t max, x;

    max_i = n;
    max = matrix_at(mat, n, n);
    
    for (mind_t i = n + 1; i < mat->n_rows; ++i){
        x = matrix_at(mat, i, n);
        if (x > max) {
            max_i = i;
            max = x;
        }
    }

    return max_i;
}


