#include "Neuron.h"

Neuron::Neuron(int num, int parentNum, ActivationFunction* af, DATATYPE rate) :
	num(num), parentNum(parentNum), af(af), pOuts(nullptr), rate(rate)
{
	std::default_random_engine e;
	std::uniform_int_distribution<int> u(0, 100000000);
	e.seed((unsigned long)time(0));

	weights = new DATATYPE[parentNum];

	for (int i = 0; i < parentNum; i++) {
		weights[i] = (u(e) / 100000000.0);
	}

	bias = (u(e) / 100000000.0);

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
}

DATATYPE* Neuron::forwardPropagation(DATATYPE** pOuts)
{
	this->pOuts = pOuts;
	for (int i = 0; i < num; i++)
	{
		sum[i] = 0;
		for (int j = 0; j < parentNum; j++)
		{
			sum[i] += pOuts[j][i] * weights[j];
		}
		sum[i] += bias;
	}
	for (int i = 0; i < num; i++)
	{
		out[i] = af->AF(sum[i]);
	}
	return out;
}

DATATYPE** Neuron::backPropagation(DATATYPE* target)
{
	DATATYPE** parent_y_s = new DATATYPE*[parentNum];

	DATATYPE change, * changes;

	for (int i = 0; i < num; i++)
	{
		temp[i] = target[i] * af->ADF(sum[i]);
	}

	for (int i = 0; i < parentNum; i++)
	{
		changes = new DATATYPE[num];
		for (int j = 0; j < num; j++)
		{
			changes[j] = temp[j] * weights[i];
		}
		parent_y_s[i] = changes;
	}


	for (int i = 0; i < parentNum; i++) {
		change = 0;
		for (int j = 0; j < num; j++)
		{
			change += temp[j] * pOuts[i][j];
		}
		weights[i] -= change / num * rate;
	}

	change = 0;
	for (int i = 0; i < num; i++)
	{
		change += temp[i];
	}
	bias -= change / num * rate;

	return parent_y_s;
}

DATATYPE* Neuron::getChange(DATATYPE* y)
{
	DATATYPE* change = new DATATYPE[num];
	for (int i = 0; i < num; i++)
	{
		change[i] = (2 * (out[i] - y[i]));
	}
	return change;
}

DATATYPE Neuron::getLoss(DATATYPE* y)
{
	DATATYPE loss = 0;
	for (int i = 0; i < num; i++)
	{
		loss += pow(out[i] - y[i], 2);
	}
	return loss / num;
}

