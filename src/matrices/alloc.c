#include <stdlib.h>
#include <memory.h>

#include "matrices/matrix.h"


struct matrix *matrix_alloc(const size_t n_rows, const size_t n_cols) {
    const size_t n_cells = n_rows * n_cols;
    // Allocate static size + enough for the data
    struct matrix *mat = malloc(sizeof *mat + n_cells * sizeof(data_t));
    if (mat == NULL) return NULL;

    // Copy from a static structure to keep const 
    struct matrix smat = {
        .n_rows = n_rows,
        .n_cols = n_cols,
        .n_cells = n_cells
    };
    memcpy(mat, &smat, sizeof smat);

    return mat;
}

void matrix_free(struct matrix *mat) {
    // There isn't anything to do for now,
    // but it's here for future compatibility
    free(mat);
}

struct matrix *matrix_cpy(struct matrix *src) {
    if (src == NULL) return NULL;

    struct matrix *dest;
    
    dest = matrix_alloc(src->n_rows, src->n_cols);
    memcpy(dest, src, sizeof *src);

    return dest;
}
