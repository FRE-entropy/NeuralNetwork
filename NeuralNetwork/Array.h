#pragma once
#include <iostream>


template<class T>
class Array
{
	int len;
	int* shape;
	T* data;

public:
	Array(std::initializer_list<int> args)
	{
		shape = new int[args.size()];
		int num;
		for (int i = 0; i < args.size(); i++)
		{
			num = *(args.begin() + i);
			*(shape + i) = num;
			len = (i == 0 ? num : len * num);
		}
		std::cout << len << std::endl;
		data = new T[len];
	}

	~Array()
	{
		if (shape != NULL)
			delete[] shape;

		if (data != NULL)
			delete[] data;
	}
};

