#ifndef H_MATRIX_H
#define H_MATRIX_H


#include "../types.h"


struct matrix {
    ind_t n_rows;
    ind_t n_cols;
    ind_t n_cells;

    data_t cells[];
};


/*--- Instance functions ---*/

/**
 * Allocates a new Matrix structure with size (n_rows, n_cols)
 */
struct matrix *matrix_alloc(ind_t n_rows, ind_t n_cols);

/**
 * Frees a Matrix structure
 */
void matrix_free(struct matrix *mat);

/**
 * Clones a Matrix structure
 */
struct matrix *matrix_cpy(struct matrix *src);


/*--- Basic functions---*/

/**
 * Accesses the element at (row, col) = (i, j)
 */
#define matrix_at(mat, i, j) ((mat)->cells[(i) * (mat)->n_rows + (j)])

/**
 * Returns true if the matrix is square.
 */
#define matrix_issquare(mat) ((mat)->n_rows == (mat)->n_cols)

/**
 * Returns true if the matrix is a vector (1 column) 
 */
#define matrix_isvector(mat) ((mat)->n_cols == 1)

/*--- Initialisation ---*/

/**
 * Fills an existing Matrix with the same value
 */
void matrix_fill(data_t x, struct matrix *mat);

/**
 * Returns a zero-filled matrix.
 */
struct matrix *matrix_zero(ind_t n_rows, ind_t n_cols);

/**
 * Returns a new Matrix filled with the same value
 */
struct matrix *matrix_filled(data_t x, ind_t n_rows, ind_t n_cols);

/**
 * Returns an identity Matrix.
 */
struct matrix *matrix_id(ind_t n_dim);


/*--- Operations ---*/

/**
 * Foreach row (variable, matrix)
 */
#define matrix_foreach_row(i, mat) \
    for (mind_t i = 0; i < (mat)->n_rows; ++i)

/**
 * Foreach column (variable, matrix)
 */
#define matrix_foreach_col(j, mat) \
    for (mind_t j = 0; j < (mat)->n_cols; ++j)


#include "matrices/matrix_basic_ops.h"

/*--- Line-wise operations ---*/

#include "matrices/matrix_line_ops.h"

#endif // H_MATRIX_H
