#pragma once
#include <vector>
#include <random>
#include "common.h"
#include "ActivationFunction.h"



class Neuron
{
public:
	int parentNum;
	Neuron* parentNeurons;
	DATATYPE* weights;
	DATATYPE bias;

	DATATYPE sum;
	DATATYPE out;

	ActivationFunction* af;

	Neuron(int parentNum, Neuron* parentNeurons, ActivationFunction* af);
	~Neuron();

	DATATYPE forwardPropagation();

	std::vector<DATATYPE> backPropagation(DATATYPE y);
};

