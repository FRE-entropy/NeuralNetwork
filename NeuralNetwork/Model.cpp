#include "Model.h"


Model::Model(int sampleSize, int inputLayerNum): 
	layers(new std::vector<Layer*>), loss(0), sampleSize(sampleSize), inputLayerNum(inputLayerNum)
{
}

Model::~Model()
{
	if (layers != NULL)
		delete layers;
}

void Model::addLayer(int neuronNumber, ActivationFunction* af, DATATYPE rate)
{
	layers->push_back(new Layer(sampleSize, layers->size() == 0? inputLayerNum: layers->back()->neuronNumber, 
		neuronNumber, af, rate));
}

DATATYPE** Model::forwardPropagation(DATATYPE** data)
{
	DATATYPE** temp = layers->at(0)->forwardPropagation(data);
	for (int i = 1; i < layers->size(); i++)
	{
		temp = layers->at(i)->forwardPropagation(temp);
	}
	return temp;
}

void Model::backPropagation(DATATYPE** y)
{
	DATATYPE** temp = layers->back()->backPropagation(layers->back()->getChange(y));
	for (int i = layers->size() - 1; i >= 0; i--)
	{
		temp = layers->at(i)->backPropagation(temp);
	}
}

DATATYPE Model::getLoss()
{
	return layers->back()->getLoss();
}

DATATYPE** Model::training(DATATYPE** data, DATATYPE** y)
{
	DATATYPE** out = forwardPropagation(data);
	backPropagation(y);
	return out;
}

DATATYPE* Model::prediction(DATATYPE* data)
{
	DATATYPE** datas = new DATATYPE * [inputLayerNum];
	for (int i = 0; i < inputLayerNum; i++)
	{
		datas[i] = data + i;
	}
	DATATYPE** outs = this->forwardPropagation(datas);
	return outs[0];
}


