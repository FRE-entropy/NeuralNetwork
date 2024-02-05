#pragma once
#include "common.h"
#include "Neuron.h"
#include "ActivationFunction.h"


class Layer
{
public:
	int sampleSize;
	int neuronNumber;
	int parentNumber;
	Neuron** neurons;
	DATATYPE** out;
	DATATYPE** parentChanges;
	DATATYPE** changes;
	DATATYPE** y;

	Layer(int sampleSize, int parentNum, int neuronNum, ActivationFunction* af, DATATYPE rate = 1);
	~Layer();

	DATATYPE** forwardPropagation(DATATYPE** pOuts);

	DATATYPE** backPropagation(DATATYPE** y);

	DATATYPE** getChange(DATATYPE** y);

	DATATYPE getLoss();
};

