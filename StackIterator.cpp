#include "StackIterator.h"

StackIterator::StackIterator(Stack* p, int index)
{
	this->p = p;
	this->index = index;
}

void StackIterator::next()
{
	index++;
}

void StackIterator::prev()
{
	index--;
}

void* StackIterator::get()
{
	return p->get_data(index);
}

bool StackIterator::isEqual(IIterator* iter)
{
	StackIterator* new_iter = (StackIterator*)iter;
	return (this->p == new_iter->p and this->index == new_iter->index);
}
