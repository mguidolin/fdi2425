#include <stdio.h>
#include <complex.h>

int main()
{
    double real = 1.3;
    double imag = 4.9;

    double complex z = real + imag * I;
    double complex z_conj = conj(z);

    printf("z* = %.1f + %.1fi\n", creal(z_conj), cimag(z_conj));

    return 0;
}
