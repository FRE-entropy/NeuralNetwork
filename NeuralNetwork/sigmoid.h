#pragma once
#include "ActivationFunction.h"


class sigmoid: public ActivationFunction
{
public:
	// Í¨¹ý ActivationFunction ¼Ì³Ð
	DATATYPE AF(DATATYPE x) override;
	DATATYPE ADF(DATATYPE x) override;
};

