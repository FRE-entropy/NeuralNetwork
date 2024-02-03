#include "common.h"
#include "Neuron.h"
#include "ReLU.h"
#include "sigmoid.h"


int main()
{
	Neuron* n = new Neuron(4, 2, new ReLU, 0.1);

	DATATYPE* pOuts[2];
	DATATYPE a[] = { 0, 0, 1, 1 };
	DATATYPE b[] = { 0, 1, 0, 1 };
	pOuts[0] = a;
	pOuts[1] = b;

	DATATYPE y[] = { 0, 0, 0, 1 };

	DATATYPE* out;

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
			out = n->forwardPropagation(pOuts);
			n->backPropagation(y);
			std::cout << "out: " << out[0] << out[1] << out[2] << out[3] << std::endl;
			std::cout << "loss: " << n->getLoss(y) << std::endl;
		}
	}
	DATATYPE* pOuts2[2];
	pOuts[0] = new DATATYPE[1];
	pOuts[1] = new DATATYPE[1];
	
	while (true)
	{
		std::cout << "data: ";
		std::cin >> pOuts2[0][0] >> pOuts2[1][0];
		n->num = 1;
		out = n->forwardPropagation(pOuts2);
		std::cout << "out: " << out[0] << std::endl;
	}
}
