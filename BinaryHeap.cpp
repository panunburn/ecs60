#include "BinaryHeap.h"
#include "iostream"
#include <cstdlib>

void BinaryHeap::insert(Vertex x)
{
	if(currentSize == capacity - 1)
	{
		std::cout << "BinaryHeap exceeds the index range!\n";
		exit(0);
	}
	int hole = ++ currentSize;
	for(; hole > 1 && x < array[hole / 2]; hole /= 2)
		array[hole] = array[hole / 2];
	array[hole] = x;
}


bool BinaryHeap::isEmpty()
{
	if(currentSize == 0)
		return true;
	else
		return false;
}


Vertex BinaryHeap::deleteMin()
{
	if(isEmpty())
	{
		std::cout << "This is an empty heap and you deleteMin!\n";
		exit(0);
	}

	Vertex minItem = Vertex();
	minItem = array[1];
	array[1] = array[currentSize--];
	percolateDown(1);
	return minItem;
}


void BinaryHeap::percolateDown(int hole)
{
	int child;
	Vertex tmp = Vertex();
	tmp = array[hole];

	for(; hole*2 <= currentSize; hole = child)
	{
		child = hole*2;
		if(child != currentSize && array[child + 1] < array[child])
			child++;
		if(array[child] < tmp)
			array[hole] = array[child];
		else
			break;
	}
	array[hole] = tmp;
}
