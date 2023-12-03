#pragma once
#include "IIterator.h"
#include "Stack.h"
class StackIterator : public IIterator
{
	Stack* p;
	int index;
public:
	StackIterator(Stack* p, int index);
	int getIndex()
	{
		return index;
	}
	//~Queue_Iterator();
	//Переходит на следующий элемент
	void next();
	//Переходит на предыдущий элемент
	void prev();
	//Возвращает данные этого итератора
	void* get();
	//Сравнивает данные двух итераторов, указывают ли они на один и тот же элемент в одном и том же контейнере
	bool isEqual(IIterator* iter);
};


