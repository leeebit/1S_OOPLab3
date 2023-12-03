#pragma once
#include "IIterable.h"
#include <iostream>
class Stack : public IIterable
{
private:
	class Data
	{
	public:
		double data;
		Data* next;
		Data* prev;
	};
	Data* head = nullptr;
	int size = 0;
public:
	//Добавляет элемент стека
	void push(double data);
	//Удаляет элемент стека
	double pop();
	//Возвращает начальный контейнер
	IIterator* begin();
	//Возвращает конечный контейнер
	IIterator* end();
	//Возвращает количество объектов
	int getSize();
	//Проверяет объекты на наличие
	bool isEmpty();
	//Предоставляет доступ к данным стека
	double* get_data(int index);
	//Получает контейнер по индексу
	IIterator* at(int index_);
	//Удаляет элемент из контейнера
	void remove(IIterator* element);
	//Очищает содержимое контейнера
	void clear();
	//Копирует и добавляет к себе все данные из другого контейнера
	void join(IIterable* container);
	//Оператор обращения к элементу стека
	double& operator[](int index_);

};



