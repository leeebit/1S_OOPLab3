#pragma once
#include "Queue.h"
#include "IIterator.h"
class QueueIterator : public IIterator
{
	Queue* p;
	int index;
public:
	QueueIterator(Queue* p, int index);
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

