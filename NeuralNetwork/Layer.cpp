#include "Layer.h"


Layer::Layer(int sampleSize, int parentNum, int neuronNum, ActivationFunction* af, DATATYPE rate):
	sampleSize(sampleSize), neuronNumber(neuronNum), parentNumber(parentNum), out(nullptr), y(nullptr)
{
	neurons = new Neuron * [neuronNum];
	for (int i = 0; i < neuronNum; i++)
	{
		neurons[i] = new Neuron(sampleSize, parentNum, af, rate);
	}

	out = new DATATYPE * [neuronNumber];
	parentChanges = new DATATYPE * [parentNumber];
	changes = new DATATYPE * [neuronNumber];
}

Layer::~Layer()
{
	if (neurons != NULL)
		delete[] neurons;
	if (out != NULL)
		delete[] out;
	if (parentChanges != NULL)
		delete[] parentChanges;
	if (changes != NULL)
		delete[] changes;
}

DATATYPE** Layer::forwardPropagation(DATATYPE** pOuts)
{
	for (int i = 0; i < neuronNumber; i++)
	{
		out[i] = neurons[i]->forwardPropagation(pOuts);
	}
	return out;
}

DATATYPE** Layer::backPropagation(DATATYPE** y)
{
	DATATYPE** temp;
	for (int i = 0; i < parentNumber; i++)
	{
		parentChanges[i] = new DATATYPE[sampleSize];
		for (int j = 0; j < sampleSize; j++)
		{
			parentChanges[i][j] = 0;
		}
	}
	for (int i = 0; i < neuronNumber; i++)
	{
		temp = neurons[i]->backPropagation(y[i]);
		for (int j = 0; j < parentNumber; j++)
		{
			for (int k = 0; k < sampleSize; k++)
			{
				parentChanges[j][k] += temp[j][k];
			}
		}
	}
	return parentChanges;
}

DATATYPE** Layer::getChange(DATATYPE** y)
{
	this->y = y;
	for (int i = 0; i < neuronNumber; i++)
	{
		changes[i] = neurons[i]->getChange(y[i]);
	}
	return changes;
}

DATATYPE Layer::getLoss()
{
	DATATYPE Loss = 0;
	for (int i = 0; i < neuronNumber; i++)
	{
		Loss += neurons[i]->getLoss(y[i]);
	}
	return Loss / neuronNumber;
}
