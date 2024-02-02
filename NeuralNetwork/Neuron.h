#pragma once
#include <vector>
#include <random>
#include "common.h"
#include "ActivationFunction.h"


class Neuron
{
public:
	int num;

	int parentNum;
	DATATYPE** pOuts;
	DATATYPE* weights;
	DATATYPE bias;

	DATATYPE* sum;
	DATATYPE* out;

	ActivationFunction* af;

	Neuron(int num, int parentNum, ActivationFunction* af);
	~Neuron();

	DATATYPE* forwardPropagation(DATATYPE** pOuts);

	DATATYPE* backPropagation(DATATYPE* y);

	DATATYPE getLoss(DATATYPE* y);
};

