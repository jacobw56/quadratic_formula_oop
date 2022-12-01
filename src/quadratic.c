/**
 * Copyright (c) 2022 Walter Jacob
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "quadratic.h"

static double discriminant(struct quadratic_polynomial *q)
{
    return q->b * q->b - 4 * q->a * q->c;
}

int quadratic(struct quadratic_polynomial *q, double s[], size_t s_len)
{
    /* Make sure the buffer is big enough. */
    if (s_len < 2)
    {
        return -1;
    }

    double dsc = discriminant(q);
    int ret = 0; /* No real solutions */

    /* One (repeated) real solution */
    if (dsc == 0.0)
    {
        s[0] = -1.0 * q->b / (2.0 * q->a);
        ret = 1;
    }

    /* Two unique (conjugate) real solutions */
    else if (dsc > 0.0)
    {
        double sqrt_dsc = sqrt(dsc);
        s[0] = (-1.0 * q->b + sqrt_dsc) / (2.0 * q->a);
        s[1] = (-1.0 * q->b - sqrt_dsc) / (2.0 * q->a);
        ret = 2;
    }

    return ret;
}

int quadratic_polynomial_constructor(struct quadratic_polynomial *q, double a, double b, double c, int (*root_fn)(double a, double b, double c, double *s, size_t s_len))
{
    if (a == (double)0.0)
    {
        printf("\nThis is a line, not a parabola! Coefficient A cannot be zero!\n\n");
        return -1;
    }

    if (root_fn == NULL)
    {
        printf("\nRoot finding method cannot be null!\n\n");
        return -1;
    }

    q->a = a;
    q->b = b;
    q->c = c;
    q->find_roots = root_fn;
    return 0;
}
