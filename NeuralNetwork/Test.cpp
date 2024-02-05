#include "common.h"
#include "Neuron.h"
#include "ReLU.h"
#include "sigmoid.h"
#include "Array.h"
#include "Layer.h"
#include "Model.h"
#include <chrono>


int main()
{
	DATATYPE* trainingData[2];
	DATATYPE a[] = { 0, 0, 1, 1 };
	DATATYPE b[] = { 0, 1, 0, 1 };
	trainingData[0] = a;
	trainingData[1] = b;

	DATATYPE* y[1];
	DATATYPE x[] = { 0, 0, 0, 1 };
	y[0] = x;


	Model* m = new Model(4, 2);
	m->addLayer(1, new sigmoid);
	DATATYPE loss = 1;
	DATATYPE** out = nullptr;
	int n = 100000;
	auto start = std::chrono::system_clock::now();
	//while (loss > 0.01)
	while (n--)
	{
		out = m->training(trainingData, y);
	}
	loss = m->getLoss();

	std::cout << "out: " << out[0][0] << " " << out[0][1] << " " << out[0][2] << " " << out[0][3] << std::endl;
	std::cout << "loss: " << loss << std::endl;

	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << "ºÄÊ±: " << duration.count() << std::endl;

	DATATYPE testData[2];

	while (true)
	{
		std::cout << "test data: ";
		std::cin >> testData[0] >> testData[1];

		DATATYPE* testOut = m->prediction(testData);

		std::cout << "out: " << testOut[0] << std::endl;
	}
}
