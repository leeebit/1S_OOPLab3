#include "ArrayIterator.h"

ArrayIterator::ArrayIterator(Array* arr, int index_)
{
	ptr = arr;
	index = index_;
}

void ArrayIterator::next()
{
	index++;
}

void ArrayIterator::prev()
{
	index--;
}

void* ArrayIterator::get()
{
	return &ptr->get()[index];
}

bool ArrayIterator::isEqual(IIterator* iter)
{
	ArrayIterator* newArr = (ArrayIterator*)iter;

	return (ptr == newArr->ptr && index == newArr->index);
}