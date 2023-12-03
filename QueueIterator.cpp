#include "QueueIterator.h"
QueueIterator::QueueIterator(Queue* p, int index)
{
	this->p = p;
	this->index = index;
}

void QueueIterator::next()
{
	index++;
}

void QueueIterator::prev()
{
	index--;
}

void* QueueIterator::get()
{
	return p->get_data(index);
}

bool QueueIterator::isEqual(IIterator* iter)
{
	QueueIterator* new_iter = (QueueIterator*)iter;
	return (this->p == new_iter->p and this->index == new_iter->index);
}
