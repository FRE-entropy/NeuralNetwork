#include "common.h"
#include "Neuron.h"
#include "ReLU.h"
#include "sigmoid.h"
#include "Array.h"
#include "Layer.h"


int main()
{
	//Neuron* n = new Neuron(4, 2, new sigmoid);

	//DATATYPE* pOuts[2];
	//DATATYPE a[] = { 0, 0, 1, 1 };
	//DATATYPE b[] = { 0, 1, 0, 1 };
	//pOuts[0] = a;
	//pOuts[1] = b;

	//DATATYPE y[] = { 0, 0, 0, 1 };

	//DATATYPE* out;

	//while (true)
	//{
	//	int x;
	//	std::cin >> x;
	//	if (x == 0)
	//	{
	//		break;
	//	}
	//	for (int i = 0; i < 100; i++)
	//	{
	//		out = n->forwardPropagation(pOuts);
	//		n->backPropagation(n->getChange(y));
	//		std::cout << "out: " << out[0] << out[1] << out[2] << out[3] << std::endl;
	//		std::cout << "loss: " << n->getLoss(y) << std::endl;
	//	}
	//}
	//DATATYPE* pOuts2[2];
	//pOuts2[0] = new DATATYPE[1];
	//pOuts2[1] = new DATATYPE[1];
	//
	//while (true)
	//{
	//	std::cout << "data: ";
	//	std::cin >> pOuts2[0][0] >> pOuts2[1][0];
	//	n->num = 1;
	//	out = n->forwardPropagation(pOuts2);
	//	std::cout << "out: " << out[0] << std::endl;
	//}

	DATATYPE* TestData[2];
	DATATYPE a[] = { 0, 0, 1, 1 };
	DATATYPE b[] = { 0, 1, 0, 1 };
	TestData[0] = a;
	TestData[1] = b;

	DATATYPE* y[1];
	DATATYPE x[] = { 0, 0, 0, 1 };
	y[0] = x;

	Layer* l1 = new Layer(4, 2, 5, new ReLU);
	Layer* l2 = new Layer(4, 5, 10, new sigmoid);
	Layer* l3 = new Layer(4, 10, 5, new sigmoid);
	Layer* l4 = new Layer(4, 5, 1, new sigmoid);

	DATATYPE r = 1;
	while (r > 0.001)
	{
		DATATYPE** temp = l1->forwardPropagation(TestData);
		temp = l2->forwardPropagation(temp);
		temp = l3->forwardPropagation(temp);
		DATATYPE** out = l4->forwardPropagation(temp);

		temp = l4->backPropagation(l4->getChange(y));
		temp = l3->backPropagation(temp);
		temp = l2->backPropagation(temp);
		l1->backPropagation(temp);

		r = l4->getLoss(y);

		std::cout << "out: " << out[0][0] << " " << out[0][1] << " " << out[0][2] << " " << out[0][3] << std::endl;
		std::cout << "loss: " << r << std::endl;
	}

	DATATYPE* TestData2[2];
	DATATYPE a2[] = { 0, 0, 0, 0 };
	DATATYPE b2[] = { 0, 0, 0, 0 };
	TestData2[0] = a2;
	TestData2[1] = b2;

	DATATYPE* y2[1];
	DATATYPE x2[] = { 0, 0, 0, 1 };
	y2[0] = x2;

	while (true)
	{
		std::cout << "data: ";
		std::cin >> TestData2[0][0] >> TestData2[1][0];

		DATATYPE** temp = l1->forwardPropagation(TestData);
		temp = l2->forwardPropagation(temp);
		temp = l3->forwardPropagation(temp);
		DATATYPE** out = l4->forwardPropagation(temp);

		std::cout << "out: " << out[0][0] << std::endl;
	}
}
