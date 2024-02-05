#include "Neuron.h"


Neuron::Neuron(int samplesNum, int parentNum, ActivationFunction* af, DATATYPE rate) :
	samplesNum(samplesNum), parentNum(parentNum), af(af), pOuts(nullptr), rate(rate)
{
	srand(time(NULL));

	weights = new DATATYPE[parentNum]; 

	for (int i = 0; i < parentNum; i++) {
		weights[i] = random();
	}

	bias = random();

	sum = new DATATYPE[samplesNum];
	out = new DATATYPE[samplesNum];
	temp = new DATATYPE[samplesNum];

	parentChange = new DATATYPE * [parentNum];
	for (int i = 0; i < parentNum; i++)
	{
		parentChange[i] = new DATATYPE[samplesNum];
	}
	change = new DATATYPE[samplesNum];
}

Neuron::~Neuron()
{
	if (weights != NULL)
		delete[] weights;
	if (af != NULL)
		delete af;
	if (sum != NULL)
		delete[] sum;
	if (out != NULL)
		delete[] out;
	if (temp != NULL)
		delete[] temp;
	if (parentChange != NULL)
	{
		for (int i = 0; i < parentNum; i++)
		{
			delete[] parentChange[i];
		}
		delete[] parentChange;
	}
	if (parentChange != NULL)
	{
		delete[] change;
	}
}

DATATYPE* Neuron::forwardPropagation(DATATYPE** pOuts)
{
	this->pOuts = pOuts;
	for (int i = 0; i < samplesNum; i++)
	{
		sum[i] = 0;
		for (int j = 0; j < parentNum; j++)
		{
			sum[i] += pOuts[j][i] * weights[j];
		}
		sum[i] += bias;
	}
	for (int i = 0; i < samplesNum; i++)
	{
		out[i] = af->AF(sum[i]);
	}
	return out;
}

DATATYPE** Neuron::backPropagation(DATATYPE* target)
{
	DATATYPE num;

	for (int i = 0; i < samplesNum; i++)
	{
		temp[i] = target[i] * af->ADF(sum[i]);
	}

	for (int i = 0; i < parentNum; i++)
	{
		for (int j = 0; j < samplesNum; j++)
		{
			parentChange[i][j] = temp[j] * weights[i];
		}
	}

	for (int i = 0; i < parentNum; i++) {
		num = 0;
		for (int j = 0; j < samplesNum; j++)
		{
			num += temp[j] * pOuts[i][j];
		}
		weights[i] -= num / samplesNum * rate;
	}

	num = 0;
	for (int i = 0; i < samplesNum; i++)
	{
		num += temp[i];
	}
	bias -= num / samplesNum * rate;

	return parentChange;
}

DATATYPE* Neuron::getChange(DATATYPE* y)
{
	for (int i = 0; i < samplesNum; i++)
	{
		change[i] = (2 * (out[i] - y[i]));
	}
	return change;
}

DATATYPE Neuron::getLoss(DATATYPE* y)
{
	DATATYPE loss = 0;
	for (int i = 0; i < samplesNum; i++)
	{
		loss += pow(out[i] - y[i], 2);
	}
	return loss / samplesNum;
}

DATATYPE Neuron::random()
{
	return (rand() % 10000) / 10000.0;
}

