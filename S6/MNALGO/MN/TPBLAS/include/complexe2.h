
typedef struct {
    float real;
    float imaginary;
} complexe_float_t;

typedef struct {
    double real;
    double imaginary;
} complexe_double_t;

inline complexe_float_t add_complexe_float(const complexe_float_t c1, const complexe_float_t c2) {
    complexe_float_t r;

    r.real = c1.real + c2.real;
    r.imaginary = c1.imaginary + c2.imaginary;

    return r;
}

inline complexe_double_t add_complexe_double(const complexe_double_t c1, const complexe_double_t c2) {
    complexe_double_t r;

    r.real = c1.real + c2.real;
    r.imaginary = c1.imaginary + c2.imaginary;

    return r;
}


inline complexe_float_t mult_complexe_float(const complexe_float_t c1, const complexe_float_t c2) {
    complexe_float_t r;

    float first = c1.real * c2.real;
    float second = c1.real * c2.imaginary;
    float third = c1.imaginary * c2.real;
    float fourth = c1.imaginary * c2.imaginary;

    r.real = first + fourth * (-1);
    r.imaginary = second + third;

    return r;
}

inline complexe_double_t mult_complexe_double(const complexe_double_t c1, const complexe_double_t c2) {
    complexe_double_t r;

    double first = c1.real * c2.real;
    double second = c1.real * c2.imaginary;
    double third = c1.imaginary * c2.real;
    double fourth = c1.imaginary * c2.imaginary;

    r.real = first + fourth * (-1);
    r.imaginary = second + third;

    return r;
}


inline complexe_float_t div_complexe_float(const complexe_float_t c1, const complexe_float_t c2) {
    complexe_float_t r;
    complexe_float_t conj = c2;
    conj.imaginary = -conj.imaginary;

    complexe_float_t top = mult_complexe_float(c1, conj);
    complexe_float_t bottom = mult_complexe_float(c2, conj);

    r.real = top.real / bottom.real;
    r.imaginary = top.imaginary / bottom.real;

    return r;
}

inline complexe_double_t div_complexe_double(const complexe_double_t c1, const complexe_double_t c2) {
    complexe_double_t r;
    complexe_double_t conj = c2;
    conj.imaginary = -conj.imaginary;

    complexe_double_t top = mult_complexe_double(c1, conj);
    complexe_double_t bottom = mult_complexe_double(c2, conj);

    r.real = top.real / bottom.real;
    r.imaginary = top.imaginary / bottom.imaginary;

    return r;
}




