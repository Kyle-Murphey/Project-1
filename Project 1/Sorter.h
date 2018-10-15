// Signature must be retained. Implementation must be added.
#ifndef SORT_H
#define SORT_H

#include "Exceptions.h"
#include "TemplatedArray.h"
#include "Comparator.h"

template <typename T>
class Sorter {
private:
	// additional member functions (methods) and variables (fields) may be added
	static long partition(TemplatedArray<T> &tempArray, const Comparator<T>& comparator, long low, long high);
	static void quicksort(TemplatedArray<T> &tempArray, const Comparator<T>& comparator, long i, long k);
public:
	static void sort(TemplatedArray<T>& array, const Comparator<T>& comparator);
};

// implementation goes here

//Quicksort and Partition were copied and revised from ZyBooks section 16.4


template <typename T>
long Sorter<T>::partition(TemplatedArray<T> &tempArray, const Comparator<T>& comparator, long low, long high)
{
	long l = 0;
	long h = 0;
	long midpoint = 0;
	T pivot;
	//T temp;
	bool done = false;

	// Pick middle element as pivot
	midpoint = low + (high - low) / 2;
	//pivot = tempArray.get(midpoint);
	pivot = tempArray[midpoint];

	l = low;
	h = high;



	while (!done) 
	{
		// Increment l while numbers[l] < pivot
		//while (tempArray.get(l) < pivot) 
		while (comparator.compare(tempArray[l], pivot) == -1)
		{
			++l;
		}

		// Decrement h while pivot < numbers[h]
		//while (pivot < tempArray.get(h)) 
		while (comparator.compare(pivot, tempArray[h]) == -1)
		{
			--h;
		}

		// If there are zero or one elements remaining,
		// all numbers are partitioned. Return h
		if (l >= h) 
		{
			done = true;
		}
		else 
		{
			// Swap numbers[l] and numbers[h],
			// update l and h
			///temp = tempArray.get(l);
			///tempArray.get(l) = tempArray.get(h);
			///tempArray.get(h) = temp;
			tempArray.swap(h, l);
			//tempArray.data[l] = tempArray.data[h];
			//tempArray.data[h] = temp;
			++l;
			--h;
		}
	}
	return h;
}

template <typename T>
void Sorter<T>::quicksort(TemplatedArray<T> &tempArray, const Comparator<T>& comparator, long i, long k)
{
	long j = 0;

	// Base case: If there are 1 or zero elements to sort,
	// partition is already sorted
	if (i >= k) 
	{
		return;
	}

	// Partition the data within the array. Value j returned
	// from partitioning is location of last element in low partition.
	j = partition(tempArray, comparator, i, k);

	// Recursively sort low partition (i to j) and
	// high partition (j + 1 to k)
	quicksort(tempArray, comparator, i, j);
	quicksort(tempArray, comparator, j + 1, k);
}


template<typename T>
void Sorter<T>::sort(TemplatedArray<T>& array, const Comparator<T>& comparator)
{
	quicksort(array, comparator, 0, array.getSize() - 1);

}

#endif