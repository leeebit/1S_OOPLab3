#pragma once
//#include "IIterator.h"

class IIterator;

class IIterable
{
public:
	//Возвращает начальный контейнер
	virtual IIterator* begin() = 0;
	//Возвращает конечный контейнер
	virtual IIterator* end() = 0;
	//Проверяет объекты на наличие
	virtual bool isEmpty() = 0;
	//Возвращает количество объектов
	virtual int getSize() = 0;
	//Получает контейнер по индексу
	virtual IIterator* at(int index_) = 0;
	//По итератору удаляет элемент из контейнера
	virtual void remove(IIterator* element) = 0;
	//Очищает содержимое контейнера
	virtual void clear() = 0;
	//Копирует и добавляет к себе все данные из другого контейнера
	virtual void join(IIterable* container) = 0;
};

