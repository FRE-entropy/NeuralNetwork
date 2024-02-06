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
	//// 训练数据
	//DATATYPE* trainingData[2];
	//DATATYPE a[] = { 0, 0, 1, 1 };
	//DATATYPE b[] = { 0, 1, 0, 1 };
	//trainingData[0] = a;
	//trainingData[1] = b;

	//DATATYPE* y[1];
	//DATATYPE x[] = { 0, 0, 0, 1 };
	//y[0] = x;

	//// 创建模型
	//Model* m = new Model(4, 2);
	//m->addLayer(10, new ReLU, 0.1);
	//m->addLayer(20, new ReLU, 0.1);
	//m->addLayer(10, new ReLU, 0.1);
	//m->addLayer(1, new sigmoid);

	//// 开始训练
	//DATATYPE loss = 1;
	//DATATYPE** out = nullptr;
	//int n = 100000;
	//auto start = std::chrono::system_clock::now();
	////while (n--)
	//while (loss > 0.001)
	//{
	//	//out = m->training(trainingData, y);
	//	for (int i = 0; i < 100; i++)
	//	{
	//		out = m->training(trainingData, y);
	//	}
	//	loss = m->getLoss();
	//	std::cout << "out: " << out[0][0] << " " << out[0][1] << " " << out[0][2] << " " << out[0][3] << std::endl;
	//	std::cout << "loss: " << loss << std::endl;
	//	//int a;
	//	//std::cin >> a;
	//}
	//auto end = std::chrono::system_clock::now();
	//auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	//std::cout << "耗时: " << duration.count() << std::endl;

	//std::cout << "out: " << out[0][0] << " " << out[0][1] << " " << out[0][2] << " " << out[0][3] << std::endl;
	//std::cout << "loss: " << loss << std::endl;
	//std::cout << "wb: " << m->to_string() << std::endl;
	//m->save("./model.txt");

	//DATATYPE testData[2];

	//while (true)
	//{
	//	std::cout << "test data: ";
	//	std::cin >> testData[0] >> testData[1];

	//	DATATYPE* testOut = m->prediction(testData);

	//	std::cout << "out: " << testOut[0] << std::endl;
	//}

	Layer l(1, 2, 3, new sigmoid);

	l.load("1.111 2.222,3.333;1.111 2.222,3.333;1.111 2.222,3.333");
	std::cout << l.to_string() << std::endl;

}
