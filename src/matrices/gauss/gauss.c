#include <stdlib.h>

#include <matrices/matrix.h>

#include "gauss_result.h"

ind_t gauss_maxrow(struct matrix *mat, ind_t n);


struct gauss_result *matrix_solvegauss(struct matrix *pmat) {
    if (!matrix_issquare(pmat)) {
        return NULL;
    }

    ind_t n = pmat->n_rows;

    struct gauss_result *res = malloc(sizeof *res);

    struct matrix *mat = matrix_cpy(pmat);
    struct matrix *inv = matrix_id(n);
    
    data_t det, fact;

    det = 1.0;
    
    // for each variable:
    matrix_foreach_row(i, mat) { 
        ind_t max_i = gauss_maxrow(mat, i);

        matrix_rowswap(mat, i, max_i);
        matrix_rowswap(inv, i, max_i);
        if (i != max_i) {
            // swapping two rows negates the determinant
            det *= -1.0; 
        }

        data_t orig = matrix_at(mat, i, i);
        
        // reduce each row one by one from the last one
        for (mind_t k = n - 1; k >= i; --k) {
            fact = matrix_at(mat, k, i) / orig;

            matrix_rowadd(mat, k, i, fact);
            matrix_rowadd(inv, k, i, fact);
        }

        det /= orig;
    }

    // now it's in reduced row echelon form.
    // backtrack until it's reduced to the identity matrix.
   
    for (mind_t i = n; i-- > 0; ) { // for each column
        for (mind_t k = i - 1; k >= 1; --k) { // reduce it above
            fact = -matrix_at(mat, k, i);
            matrix_rowadd(mat, i, k, fact);
            matrix_rowadd(inv, i, k, fact);
        }
    }

    res->det = det;
    res->orig = mat;
    res->inv = inv;

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


