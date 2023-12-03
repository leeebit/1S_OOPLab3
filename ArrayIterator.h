#pragma once
#include "Array.h"
#include "IIterator.h"

class ArrayIterator: public IIterator
{
private:
	Array* ptr;
	int index;
public:
	ArrayIterator(Array* arr, int index);
	int getIndex()
	{
		return index;
	}
	//Переходит на следующий элемент
	void next();
	//Переходит на предыдущий элемент
	void prev();
	//Возвращает данные этого итератора
	void* get();
	//Сравнивает данные двух итераторов, указывают ли они на один и тот же элемент в одном и том же контейнере
	bool isEqual(IIterator* iter);
};

