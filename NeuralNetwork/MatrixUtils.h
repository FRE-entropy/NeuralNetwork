#pragma once


class MatrixUtils
{
public:
	template<class T, size_t size>
	static void add(T(&arrA)[size], T(&arrB)[size], T(&arrOut)[size])
	{
		for (int i = 0; i < size; i++)
		{
			arrOut[i] = arrA[i] + arrB[i];
		}
	}

	template<class T, size_t size>
	static void sub(T(&arrA)[size], T(&arrB)[size], T(&arrOut)[size])
	{
		for (int i = 0; i < size; i++)
		{
			arrOut[i] = arrA[i] + arrB[i];
		}
	}
	template<class T, size_t size>
	static void mul(T(&arrA)[size], T(&arrB)[size], T(&arrOut)[size])
	{
		for (int i = 0; i < size; i++)
		{
			arrOut[i] = arrA[i] + arrB[i];
		}
	}
	template<class T, size_t size>
	static void div(T(&arrA)[size], T(&arrB)[size], T(&arrOut)[size])
	{
		for (int i = 0; i < size; i++)
		{
			arrOut[i] = arrA[i] + arrB[i];
		}
	}
};

