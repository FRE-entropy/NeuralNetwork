#pragma once
#include "common.h"
#include "ActivationFunction.h"


class Neuron
{
private:
	int samplesNum;
	int parentNum;
	DATATYPE** pOuts;
	DATATYPE* weights;
	DATATYPE bias;
	DATATYPE rate;

	DATATYPE* sum;
	DATATYPE* out;
	DATATYPE* temp;

	DATATYPE** parentChange;
	DATATYPE* change;

	ActivationFunction* af;

public:
	Neuron(int num, int parentNum, ActivationFunction* af, DATATYPE rate = 1);
	~Neuron();

	DATATYPE* forwardPropagation(DATATYPE** pOuts);

	DATATYPE** backPropagation(DATATYPE* target);

	DATATYPE* getChange(DATATYPE* y);

	DATATYPE getLoss(DATATYPE* y);
private:
	DATATYPE random();
};

