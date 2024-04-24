#pragma once

#include <string>
#include <iostream>

template<typename T, typename T_funct>
void iter(T *array, int len, T_funct f)
{
	for (int i = 0; i < len; i++)
		f(array[i]);
}