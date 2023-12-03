#include "Queue.h"
#include "QueueIterator.h"

void Queue::push(double data)
{
	Data* d = new Data;
	d->data = data;
	d->next = NULL;
	if (head == NULL)
	{
		head = d;
		tail = d;
	}
	else
	{
		tail->next = d;
		tail = d;
	}
	size++;
}

double Queue::pop()
{
	if (head == NULL)
		return INT_MIN;
	int tmp = head->data;
	if (head == tail)
		tail = NULL;
	Data* d = head;
	head = head->next;
	delete d;
	size--;
	return tmp;
}

IIterator* Queue::begin()
{
	QueueIterator* a = new QueueIterator(this, 0);
	return (IIterator*)a;
}

IIterator* Queue::end()
{
	QueueIterator* a = new QueueIterator(this, size);
	return (IIterator*)a;
}

int Queue::getSize()
{
	return size;
}

bool Queue::isEmpty()
{
	return head == nullptr;
}

double* Queue::get_data(int index)
{
	Data* cur = head;
	if (index > 0)
		for (int i = 0; i < index and cur->next != nullptr; i++)
			cur = cur->next;
	return &cur->data;
}

IIterator* Queue::at(int index_)
{
	if (index_ < 0 || index_ >= size)
		return nullptr;

	QueueIterator* a = new QueueIterator(this, index_);
	return (IIterator*)a;
}

void Queue::remove(IIterator* element)
{
	QueueIterator* iter = (QueueIterator*)element;
	int index = iter->getIndex();

	if (index < 0 || index >= size)
		return;

	Data* current = head;
	Data* previous = nullptr;

	for (int i = 0; i < index; ++i) {
		previous = current;
		current = current->next;
	}

	if (current == head) {
		// Если удаляемый элемент - первый в очереди
		head = current->next;
		if (head == nullptr)
			tail = nullptr;
	}
	else if (current == tail) {
		// Если удаляемый элемент - последний в очереди
		tail = previous;
		tail->next = nullptr;
	}
	else {
		// Если удаляемый элемент находится в середине очереди
		previous->next = current->next;
	}

	--size;
	delete current;
}

void Queue::clear() {
	while (head != nullptr) {
		Data* temp = head;
		head = head->next;
		delete temp;
	}
	tail = nullptr;
	size = 0;
}

void Queue::join(IIterable* container) {
	IIterator* iter = container->begin();

	while (iter->isEqual(container->end()) == false) {
		double* value = (double*)iter->get();
		this->push(*value);
		iter->next();
	}

	delete iter;
}

double& Queue::operator[](int index_) {
	Data* cur = head;
	for (int i = 0; i < index_; i++) {
		cur = cur->next;
	}
	return cur->data;
}
