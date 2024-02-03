#include "Layer.h"

Layer::Layer(int sampleSize, int parentNum, int neuronNum, ActivationFunction* af, DATATYPE rate):
	sampleSize(sampleSize), neuronNum(neuronNum), parentNum(parentNum)
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
		delete neurons;
}

DATATYPE** Layer::forwardPropagation(DATATYPE** pOuts)
{
	DATATYPE** out = new DATATYPE * [neuronNum];
	for (int i = 0; i < neuronNum; i++)
	{
		*(out + i) = neurons[i]->forwardPropagation(pOuts);
	}
	return out;
}

DATATYPE** Layer::backPropagation(DATATYPE** y)
{
	DATATYPE** changes = new DATATYPE * [parentNum];
	DATATYPE** temp;
	for (int i = 0; i < parentNum; i++)
	{
		changes[i] = new DATATYPE[sampleSize];
		for (int j = 0; j < sampleSize; j++)
		{
			changes[i][j] = 0;
		}
	}
	for (int i = 0; i < neuronNum; i++)
	{
		temp = neurons[i]->backPropagation(y[i]);
		for (int j = 0; j < parentNum; j++)
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
	DATATYPE** changes = new DATATYPE * [neuronNum];
	for (int i = 0; i < neuronNum; i++)
	{
		changes[i] = neurons[i]->getChange(y[i]);
	}
	return changes;
}

DATATYPE Layer::getLoss(DATATYPE** y)
{
	DATATYPE Loss = 0;
	for (int i = 0; i < neuronNum; i++)
	{
		Loss += neurons[i]->getLoss(y[i]);
	}
	return Loss / neuronNum;
}
