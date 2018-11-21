#ifndef H_GAUSS_RESULT_H
#define H_GAUSS_RESULT_H

#include <matrices/matrix.h>

struct gauss_result {
    data_t det;
    struct matrix *orig;
    struct matrix *inv;
};

#endif // H_GAUSS_RESULT_H
