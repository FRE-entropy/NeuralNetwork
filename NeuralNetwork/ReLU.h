#pragma once
#include "ActivationFunction.h"


class ReLU: ActivationFunction
{
	// Í¨¹ý ActivationFunction ¼Ì³Ð
	DATATYPE AF(DATATYPE x) override;
	DATATYPE ADF(DATATYPE x) override;
};

