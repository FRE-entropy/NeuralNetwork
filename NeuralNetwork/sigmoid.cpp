#include "sigmoid.h"

DATATYPE sigmoid::AF(DATATYPE x)
{
    return 1 / (1 + exp(-x));
}

DATATYPE sigmoid::ADF(DATATYPE x)
{
    return AF(x) * (1 - AF(x));
}
