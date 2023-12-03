#pragma once

class IIterator
{
public:
	//Переходит на следующий элемент
	virtual void next() = 0;
	//Переходит на предыдущий элемент
	virtual void prev() = 0;
	//Возвращает данные этого итератора
	virtual void* get() = 0;
	//Сравнивает данные двух итераторов, указывают ли они на один и тот же элемент в одном и том же контейнере
	virtual bool isEqual(IIterator* iter) = 0;
};

