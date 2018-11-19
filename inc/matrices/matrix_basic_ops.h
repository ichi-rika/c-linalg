#ifndef H_MATRIX_BASIC_OPS_H
#define H_MATRIX_BASIC_OPS_H

#include "matrix.h"

/* In-place matrix addition */
void matrix_radd(struct matrix *mat_a, struct matrix *mat_b);

/* In-place matrix subtraction */
void matrix_rsub(struct matrix *mat_a, struct matrix *mat_b);

/* In-place matrix negation */
void matrix_rneg(struct matrix *mat);

/* Matrix multiplication */
struct matrix *matrix_mul(struct matrix *mat_a, struct matrix *mat_b);

/* In-place cell-wise matrix-scalar addition */
void matrix_rsadd(struct matrix *mat, data_t scalar);

/* In-place cell-wise matrix-scalar subtraction */
void matrix_rssub(struct matrix *mat, data_t scalar);

/* In-place matrix scaling */
void matrix_rsmul(struct matrix *mat, data_t scalar);


#endif // H_MATRIX_BASIC_OPS_H

