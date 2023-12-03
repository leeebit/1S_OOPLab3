#pragma once
#include "IIterable.h"
class Set : public IIterable
{
	private:
		double* arr;
		int size;
	public:
		Set();
		~Set();
		double* get();
		//Добавляет элементы в конец массива, увеличивая его размер
		void push(double val);
		//Удаляет элементы с конца массива
		void pop();
		//Возвращает начальный контейнер
		IIterator* begin();
		//Возвращает конечный контейнер
		IIterator* end();
		//Возвращает количество объектов
		int getSize();
		//Проверяет объекты на наличие
		bool isEmpty();
		//Получает контейнер по индексу
		IIterator* at(int index_);
		//Удаляет элемент из контейнера
		void remove(IIterator* element);
		//Очищает содержимое контейнера
		void clear();
		//Копирует и добавляет к себе все данные из другого контейнера
		void join(IIterable* container);
		//Оператор обращения к элементу массива
		double& operator[](int index_);
};

