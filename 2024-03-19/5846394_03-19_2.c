#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double power_iter(double x, int n);
double power_rec(double x, int n);

int main(void) {
    double result_iter = power_iter(13, 21);
    double result_rec = power_rec(13, 21);
    printf("%f", result_iter);
    return 0;
}

double power_iter(double x, int n) {
    int i;
    double result = 1.0;
    for (i = 0; i < n; i++)
        result = result * x;
    return(result);
}

double power_rec(double x, int n) {
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return power_rec(x * x, n / 2);
    else
        return x * power_rec(x * x, (n - 1) / 2);
}