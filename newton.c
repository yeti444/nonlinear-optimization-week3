#include <stdio.h>

double f(double x) {
    return (x - 1) * (x - 3) * (x - 5);
}

double df(double x) {
    return 3 * x * x - 18 * x + 23;
}

int main() {
    double x;
    int i, k;

    for (i = 0; i < 10; i++) {
        x = -1.1 + i;
        printf("x0 = %f\t", x);

        for (k = 0; k < 50; k++) {
            if (f(x) > -1e-10 && f(x) < 1e-10) break;
            if (df(x) == 0) break;

            x = x - f(x) / df(x);
        }

        if (f(x) > -1e-10 && f(x) < 1e-10)
            printf("root = %f\tk = %d\n", x, k);
        else
            printf("no convergence\n");
    }

    return 0;
}
