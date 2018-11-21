#ifndef H_MATRIX_LINE_OPS_H
#define H_MATRIX_LINE_OPS_H

#include <matrices/matrix.h>

/* Swaps two rows in place. */
void matrix_rowswap(struct matrix *mat, ind_t i1, ind_t i2);

/* Adds one row to another with a scalar factor. */
void matrix_rowadd(struct matrix *mat, ind_t i1, ind_t i2, data_t scalar);

/* Computes the product of diagonal elements. */
data_t matrix_diagprod(struct matrix *mat);

/* Computes the sum of diagonal elements. 
 */
data_t matrix_diagsum(struct matrix *mat);

#endif // H_MATRIX_LINE_OPS_H
