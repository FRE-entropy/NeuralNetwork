#pragma once
#include "ActivationFunction.h"


class sigmoid: ActivationFunction
{
	// ͨ�� ActivationFunction �̳�
	DATATYPE AF(DATATYPE x) override;
	DATATYPE ADF(DATATYPE x) override;
};

