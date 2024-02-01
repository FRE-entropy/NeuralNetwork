#pragma once
#include <math.h>
#include "common.h"


class ActivationFunction
{
public:
	virtual DATATYPE AF(DATATYPE x) = 0;
	virtual DATATYPE ADF(DATATYPE x) = 0;
};

