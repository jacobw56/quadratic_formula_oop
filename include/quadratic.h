/**
 * Copyright (c) 2022 Walter Jacob
 *
 * SPDX-License-Identifier: MIT
 *
 */

/**
 * @file    quadratic.c
 * @author  Walter Jacob
 * @date    2022
 *
 * @brief Quadratic root finder library
 *
 * Definitely overkill, but this file contains the functions that are used by
 * the quadratic root finder program. They are refactored into this library
 * to give an example of a program that uses external headers/source files.
 */

#ifndef __QUADRATIC_H
#define __QUADRATIC_H

#include <math.h>
#include <stddef.h>

/**
 * @struct quadratic_polynomial quadratic.h "include/quadratic.h"
 * @brief Quadratic polynomial class.
 */
struct quadratic_polynomial
{
    double a;
    double b;
    double c;
    int (*find_roots)(struct quadratic_polynomial *q, double *s, size_t s_len);
    // We could also add the solutions buffer to the class, and even the print_solutions method - try it!
};

/**
 * @brief Function to compute the roots of the quadratic polynomial.
 *
 * @param[in] a         Quadratic coefficient
 * @param[in] b         Linear coefficient
 * @param[in] c         Constant coefficient
 * @param[out] s        Pointer to output buffer
 * @return int          Number of real solutions
 */
int quadratic(struct quadratic_polynomial *q, double *s, size_t s_len);

int quadratic_polynomial_constructor(struct quadratic_polynomial *q, double a, double b, double c, int (*find_roots)(double a, double b, double c, double *s, size_t s_len));

#endif // __QUADRATIC_H