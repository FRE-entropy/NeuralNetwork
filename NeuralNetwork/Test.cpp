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

	Layer* l1 = new Layer(4, 3, 2, new sigmoid);
	Layer* l2 = new Layer(4, 1, 3, new sigmoid);

	while (true)
	{
		int x;
		std::cin >> x;
		if (x == 0)
		{
			break;
		}
		for (int i = 0; i < 100; i++)
		{
			DATATYPE** temp = l1->forwardPropagation(TestData);
			DATATYPE** out = l2->forwardPropagation(temp);

			temp = l2->backPropagation(l2->getChange(y));
			l1->backPropagation(temp);

			std::cout << "out: " << out[0][0] << out[0][1] << out[0][2] << out[0][3] << std::endl;
			std::cout << "loss: " << l2->getLoss(y) << std::endl;
		}
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

		DATATYPE** temp = l1->forwardPropagation(TestData2);
		DATATYPE** out = l2->forwardPropagation(temp);

		std::cout << "out: " << out[0][0] << std::endl;
	}
}
