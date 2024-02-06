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
	layers->push_back(new Layer(sampleSize, layers->size() == 0? inputLayerNum: layers->back()->getNeuronNumber(),
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

std::string Model::to_string()
{
	std::string s = "";
	for (int i = 0; i < layers->size() - 1; i++)
	{
		s += layers->at(i)->to_string();
		s += "\n";
	}
	s += layers->at(layers->size() - 1)->to_string();
	return s;
}

void Model::save(const char* path)
{
	std::ofstream f;
	f.open(path);
	f << to_string();
	f.close();
}

void Model::load(const char* path)
{
	std::string s;
	std::ifstream f;
	f.open(path);
	int i = 0;
	while (getline(f, s))
	{
		layers->at(i)->load(s);
		i++;
	}
	f.close();
}


