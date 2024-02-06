#pragma once
#include <vector>
#include <fstream>
#include "common.h"
#include "Layer.h"
#include "ActivationFunction.h"


class Model
{
private:
	std::vector<Layer*>* layers;
	DATATYPE loss;
	int sampleSize;
	int inputLayerNum;
public:
	Model(int sampleSize, int inputLayerNum);
	~Model();

	void addLayer(int neuronNumber, ActivationFunction* af, DATATYPE rate = 1);

	DATATYPE** forwardPropagation(DATATYPE** data);

	void backPropagation(DATATYPE** y);

	DATATYPE getLoss();

	DATATYPE** training(DATATYPE** data, DATATYPE** y);

	DATATYPE* prediction(DATATYPE* data);

	std::string to_string();

	void save(const char* path);

	void load(const char* path);
};
