// Signature must be retained. Implementation must be added.

#ifndef SEARCH_H
#define SEARCH_H

#include "Exceptions.h"
#include "TemplatedArray.h"
#include "Comparator.h"

// returns FIRST array location matching the given item (based on the comparator)
template <typename T>
long long binarySearch(const T& item, const TemplatedArray<T>& array, const Comparator<T>& comparator) 
{
	unsigned long low = 0;
	long mid = 0;
	unsigned long high = array.getSize() - 1;

	while (high >= low)
	{
		mid = (high + low) / 2;
		if (comparator.compare(array[mid], item) == -1)
		{
			low = mid + 1;
		}
		else if (comparator.compare(array[mid], item) == 1)
		{
			if (high == 0)
			{
				return -1;
			}
			high = mid - 1;
		}
		else
		{
			if (mid > 0) 
			{
				while (comparator.compare(array[mid], array[mid - 1]) == 0)
				{
					--mid;
					if (mid == 0) break;
				}
			}
			return mid;
		}
	}
	return -mid;
}

//linear search ##################################################################################################################
template <typename T>
void linearSearch(const T& item, const TemplatedArray<T>& array, const Comparator<T>& comparator, TemplatedArray<unsigned long> &indeces, bool &found)
{
	found = false;

	for (unsigned long index = 0; index < array.getSize(); ++index)
	{
		if (comparator.compare(array[index], item) == 0)
		{
			indeces.add(&index);
			found = true;
		}
	}
}

#endif