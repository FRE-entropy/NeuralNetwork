#pragma once
#include "ActivationFunction.h"


class ReLU: public ActivationFunction
{
public:
	// ͨ�� ActivationFunction �̳�
	DATATYPE AF(DATATYPE x) override;
	DATATYPE ADF(DATATYPE x) override;
};

