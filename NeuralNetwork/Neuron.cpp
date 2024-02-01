#include "Neuron.h"

Neuron::Neuron(int parentNum, Neuron* parentNeurons, ActivationFunction* af): parentNum(parentNum), parentNeurons(parentNeurons), af(af)
{
	std::default_random_engine e;
	std::uniform_int_distribution<double> u(0, 1);
	e.seed(time(0));

	bias = u(e);

	weights = new DATATYPE[parentNum];

	for (int i = 0; i < parentNum; i++) {
		weights[i] = u(e);
	}
}

Neuron::~Neuron()
{
	delete[parentNum] weights;
}

DATATYPE Neuron::forwardPropagation()
{
	sum = 0;
	for (int i = 0; i < parentNum; i++)
	{
		sum += parentNeurons[i].out * weights[i];
	}
	out = af->AF(sum + bias);
	return out;
}

std::vector<DATATYPE> Neuron::backPropagation(DATATYPE y)
{
	std::vector<DATATYPE> parent_y_s;

	DATATYPE temp = (2 * (out - y)) * af->ADF(sum);

	for (int i = 0; i < parentNum; i++)
	{
		parent_y_s.push_back(temp * weights[i]);
	}

	DATATYPE loss = pow(out - y, 2);
	for (int i = 0; i < parentNum; i++) {
		weights[i] += temp * parentNeurons[i].out;
	}

	bias += temp;

	return parent_y_s;
}

