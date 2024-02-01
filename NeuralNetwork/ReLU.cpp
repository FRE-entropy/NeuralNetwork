#include "ReLU.h"

DATATYPE ReLU::AF(DATATYPE x)
{
    return x > 0 ? x : 0;
}

DATATYPE ReLU::ADF(DATATYPE x)
{
    return x > 0 ? 1 : 0;
}
