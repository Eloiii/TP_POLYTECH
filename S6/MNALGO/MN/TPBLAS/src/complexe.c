#include "complexe.h"

complexe_float_t add_complexe_float(const complexe_float_t c1, const complexe_float_t c2) {
    complexe_float_t r;

    r.real = c1.real + c2.real;
    r.imaginary = c1.imaginary + c2.imaginary;

    return r;
}

complexe_double_t add_complexe_double(const complexe_double_t c1, const complexe_double_t c2) {
    complexe_double_t r;

    r.real = c1.real + c2.real;
    r.imaginary = c1.imaginary + c2.imaginary;

    return r;
}

complexe_float_t mult_complexe_float(const complexe_float_t c1, const complexe_float_t c2) {
    complexe_float_t r;

    float first = c1.real * c2.real;
    float second = c1.real * c2.imaginary;
    float third = c1.imaginary * c2.real;
    float fourth = c1.imaginary * c2.imaginary;

    r.real = first + fourth * (-1);
    r.imaginary = second + third;

    return r;
}

complexe_double_t mult_complexe_double(const complexe_double_t c1, const complexe_double_t c2) {
    complexe_double_t r;

    double first = c1.real * c2.real;
    double second = c1.real * c2.imaginary;
    double third = c1.imaginary * c2.real;
    double fourth = c1.imaginary * c2.imaginary;

    r.real = first + fourth * (-1);
    r.imaginary = second + third;

    return r;
}
  


