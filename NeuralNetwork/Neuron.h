#pragma once
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
	DATATYPE rate;

	DATATYPE* sum;
	DATATYPE* out;
	DATATYPE* temp;

	ActivationFunction* af;

	Neuron(int num, int parentNum, ActivationFunction* af, DATATYPE rate = 1);
	~Neuron();

	DATATYPE* forwardPropagation(DATATYPE** pOuts);

	DATATYPE** backPropagation(DATATYPE* target);

	DATATYPE* getChange(DATATYPE* y);

	DATATYPE getLoss(DATATYPE* y);
};

