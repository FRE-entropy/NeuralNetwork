#include "MatrixUtils.h"
#include "common.h"


int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 1, 1, 1, 1, 1 };
	int o[5];
	auto f = [](int x, int y) {return x + y; };
	MatrixUtils::add(a, b, o);
	
	for (int i = 0; i < 5; i++)
	{
		std::cout << o[i] << " ";
	}
}
//[](double a, double b) {return a + b; }
