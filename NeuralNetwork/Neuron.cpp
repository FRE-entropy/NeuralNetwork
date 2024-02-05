#include "Neuron.h"


Neuron::Neuron(int num, int parentNum, ActivationFunction* af, DATATYPE rate) :
	samplesNum(num), parentNum(parentNum), af(af), pOuts(nullptr), rate(rate)
{
	srand(time(NULL));

	weights = new DATATYPE[parentNum];

	for (int i = 0; i < parentNum; i++) {
		weights[i] = random();
	}

	bias = random();

	sum = new DATATYPE[num];
	out = new DATATYPE[num];
	temp = new DATATYPE[num];
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
	DATATYPE** parent_y_s = new DATATYPE*[parentNum];

	DATATYPE change, * changes;

	for (int i = 0; i < samplesNum; i++)
	{
		temp[i] = target[i] * af->ADF(sum[i]);
	}

	for (int i = 0; i < parentNum; i++)
	{
		changes = new DATATYPE[samplesNum];
		for (int j = 0; j < samplesNum; j++)
		{
			changes[j] = temp[j] * weights[i];
		}
		parent_y_s[i] = changes;
	}

	for (int i = 0; i < parentNum; i++) {
		change = 0;
		for (int j = 0; j < samplesNum; j++)
		{
			change += temp[j] * pOuts[i][j];
		}
		weights[i] -= change / samplesNum * rate;
	}

	change = 0;
	for (int i = 0; i < samplesNum; i++)
	{
		change += temp[i];
	}
	bias -= change / samplesNum * rate;

	return parent_y_s;
}

DATATYPE* Neuron::getChange(DATATYPE* y)
{
	DATATYPE* change = new DATATYPE[samplesNum];
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

