#pragma once
#include "ActivationFunction.h"


class ReLU: ActivationFunction
{
	// ͨ�� ActivationFunction �̳�
	DATATYPE AF(DATATYPE x) override;
	DATATYPE ADF(DATATYPE x) override;
};

