#pragma once
#include <vector>
#include "common.h"
#include "Neuron.h"
#include "ActivationFunction.h"


class Layer
{
public:
	int sampleSize;
	int neuronNum;
	int parentNum;
	Neuron** neurons;

	Layer(int sampleSize, int parentNum, int neuronNum, ActivationFunction* af, DATATYPE rate = 1);
	~Layer();

	DATATYPE** forwardPropagation(DATATYPE** pOuts);

	DATATYPE** backPropagation(DATATYPE** y);

	DATATYPE** getChange(DATATYPE** y);

	DATATYPE getLoss(DATATYPE** y);
};

