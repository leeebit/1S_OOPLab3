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
		//��������� �������� � ����� �������, ���������� ��� ������
		void push(double val);
		//������� �������� � ����� �������
		void pop();
		//���������� ��������� ���������
		IIterator* begin();
		//���������� �������� ���������
		IIterator* end();
		//���������� ���������� ��������
		int getSize();
		//��������� ������� �� �������
		bool isEmpty();
		//�������� ��������� �� �������
		IIterator* at(int index_);
		//������� ������� �� ����������
		void remove(IIterator* element);
		//������� ���������� ����������
		void clear();
		//�������� � ��������� � ���� ��� ������ �� ������� ����������
		void join(IIterable* container);
		//�������� ��������� � �������� �������
		double& operator[](int index_);
};

