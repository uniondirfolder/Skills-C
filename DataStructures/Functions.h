#pragma once


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

constexpr size_t MaxLengthTArray{ 256 };

template<typename T>
size_t LengthOfArray(const T* array = nullptr) 
{

	size_t si = 0;
	if (array != nullptr) 
	{
		while (array[si] || si<MaxLengthTArray)
		{
			++si;
		}
		if (si == MaxLengthTArray)
			si = 0;
	}
	return si;
}



#endif // !FUNCTIONS_H

