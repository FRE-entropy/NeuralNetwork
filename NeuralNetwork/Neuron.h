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
	DATATYPE sum;
	DATATYPE out;
	DATATYPE* weights;
	DATATYPE bias;

	ActivationFunction* af;

	Neuron(int parentNum, Neuron* parentNeurons, ActivationFunction* af);
	~Neuron();

	DATATYPE forwardPropagation();

	std::vector<DATATYPE> backPropagation(DATATYPE y);
};

