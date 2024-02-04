#pragma once
#include <vector>
#include "common.h"
#include "Layer.h"
#include "ActivationFunction.h"


class Model
{
public:
	std::vector<Layer*>* layers;
	DATATYPE loss;
	int sampleSize;
	int inputLayerNum;

	Model(int sampleSize, int inputLayerNum);
	~Model();

	void addLayer(int neuronNumber, ActivationFunction* af, DATATYPE rate = 1);

	DATATYPE** forwardPropagation(DATATYPE** data);

	void backPropagation(DATATYPE** y);

	DATATYPE getLoss();

	DATATYPE** training(DATATYPE** data, DATATYPE** y);

	DATATYPE* prediction(DATATYPE* data);
};
