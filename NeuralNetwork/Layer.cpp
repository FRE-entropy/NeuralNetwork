#include "Layer.h"

Layer::Layer(int sampleSize, int parentNum, int neuronNum, ActivationFunction* af, DATATYPE rate):
	sampleSize(sampleSize), neuronNumber(neuronNum), parentNumber(parentNum), out(nullptr), y(nullptr)
{
	neurons = new Neuron * [neuronNum];
	for (int i = 0; i < neuronNum; i++)
	{
		neurons[i] = new Neuron(sampleSize, parentNum, af, rate);
	}
}

Layer::~Layer()
{
	if (neurons != NULL)
		delete[] neurons;
	if (out != NULL)
		delete[] out;
}

DATATYPE** Layer::forwardPropagation(DATATYPE** pOuts)
{
	out = new DATATYPE * [neuronNumber];
	for (int i = 0; i < neuronNumber; i++)
	{
		*(out + i) = neurons[i]->forwardPropagation(pOuts);
	}
	return out;
}

DATATYPE** Layer::backPropagation(DATATYPE** y)
{
	DATATYPE** changes = new DATATYPE * [parentNumber];
	DATATYPE** temp;
	for (int i = 0; i < parentNumber; i++)
	{
		changes[i] = new DATATYPE[sampleSize];
		for (int j = 0; j < sampleSize; j++)
		{
			changes[i][j] = 0;
		}
	}
	for (int i = 0; i < neuronNumber; i++)
	{
		temp = neurons[i]->backPropagation(y[i]);
		for (int j = 0; j < parentNumber; j++)
		{
			for (int k = 0; k < sampleSize; k++)
			{
				changes[j][k] += temp[j][k];
			}
		}
	}
	return changes;
}

DATATYPE** Layer::getChange(DATATYPE** y)
{
	this->y = y;
	DATATYPE** changes = new DATATYPE * [neuronNumber];
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
