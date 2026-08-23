#include <math.h>
#include <assert.h>
#include <stdio.h>

enum amount_real_roots_enum
{
    two_roots = 2,
    one_root = 1,
    no_roots = 0,
    infinity_roots = -1
};
#include "solving.h"

int solving_quadratic(double a, double b, double c, double* x1, double* x2)
{
    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));
    assert(!isinf(a));
    assert(!isinf(b));
    assert(!isinf(c));

    double dis = b * b - 4 * a * c;
    if (compare_doubles(a, 0.0))
    {
        return solving_linear(b, c, x1);
    }
    else if (compare_doubles(dis, 0.0))
    {
        *x1 = *x2 = -b/(2 * a);
        return one_root;
    }
    else if (dis > 0.0)
    {
        *x1 = (-b + sqrt(dis))/(2 * a);
        *x2 = (-b - sqrt(dis))/(2 * a);
        return two_roots;
    }
    else
        return no_roots;
}

int compare_doubles(double var1, double var2)
{
    return (fabs(var1 - var2) < DELTA);
}

int solving_linear(double a, double b, double* x1)
{
    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isinf(a));
    assert(!isinf(b));

    if (!compare_doubles(a, 0.0))
    {
        *x1 = -b / a;
        return one_root;
    }
    else if (compare_doubles(b, 0.0))
        return infinity_roots;
    else
    {
        *x1 = NAN;
        return no_roots;
    }
}

void bufer_cleaning(void)
{
    int ch = 0;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
