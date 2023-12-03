#include "Stack.h"
#include "StackIterator.h"

void Stack::push(double data)
{
	Data* d = new Data;
	d->data = data;
	d->next = nullptr;
	d->prev = nullptr;

	if (head == nullptr) {
		head = d;
	}
	else {
		d->next = head;
		head->prev = d;
		head = d;
	}

	size++;
}

double Stack::pop()
{
	if (isEmpty())
		return INT_MIN;

	Data* tmp = head;
	double val = tmp->data;
	head = head->next;
	if (head != nullptr)
		head->prev = nullptr;

	delete tmp;
	size--;
	return val;
}

IIterator* Stack::begin()
{
	StackIterator* a = new StackIterator(this, 0);
	return (IIterator*)a;
}

IIterator* Stack::end()
{
	StackIterator* a = new StackIterator(this, size);
	return (IIterator*)a;
}

int Stack::getSize()
{
	return size;
}

bool Stack::isEmpty()
{
	return head == nullptr;
}

double* Stack::get_data(int index)
{
	Data* cur = head;
	for (int i = 0; i < index && cur != nullptr; i++)
		cur = cur->next;

	if (cur == nullptr) {
		return nullptr;
	}

	return &cur->data;
}

IIterator* Stack::at(int index_)
{
	if (index_ < 0 || index_ >= size)
		return nullptr;

	StackIterator* a = new StackIterator(this, index_);
	return (IIterator*)a;
}

void Stack::remove(IIterator* element) {
	StackIterator* iter = (StackIterator*)element;
	int index = iter->getIndex();

	if (index < 0 || index >= size) {
		return;
	}

	// Если элемент первый
	if (index == 0) {
		Data* tmp = head;
		head = head->next;
		if (head != nullptr) {
			head->prev = nullptr;
		}
		delete tmp;
	}
	else {
		// Если элемент не первый, ищем элемент по индексу
		Data* current = head;
		for (int i = 0; i < index && current != nullptr; ++i) {
			current = current->next;
		}
		if (current == nullptr) {
			return;
		}
		//Удаление элемента
		if (current->prev != nullptr) {
			current->prev->next = current->next;
		}
		if (current->next != nullptr) {
			current->next->prev = current->prev;
		}
		delete current;
	}
	size--;
}

void Stack::clear() {
	while (head != nullptr) {
		Data* temp = head;
		head = head->next;
		delete temp;
	}
	size = 0;
}

void Stack::join(IIterable* container) {
	IIterator* iter = container->begin();
	while (!iter->isEqual(container->end())) {
		double* value = (double*)iter->get();
		this->push(*value);
		iter->next();
	}
	delete iter;
}

double& Stack::operator[](int index_) {

	/*Data* node = head;
	for (int i = 0; i < index_; i++) {
		node = node->prev;
	}
	return node->data;*/

	Data* e = head;
	for (int i = 0; i < index_; i++) {
		if (e == nullptr) {
			static double error;
			return error;
		}
		e = e->next;
	}
	if (e == nullptr) {
		static double error;
		return error;
	}
	return e->data;
}


