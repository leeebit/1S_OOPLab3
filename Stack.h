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
	//��������� ������� �����
	void push(double data);
	//������� ������� �����
	double pop();
	//���������� ��������� ���������
	IIterator* begin();
	//���������� �������� ���������
	IIterator* end();
	//���������� ���������� ��������
	int getSize();
	//��������� ������� �� �������
	bool isEmpty();
	//������������� ������ � ������ �����
	double* get_data(int index);
	//�������� ��������� �� �������
	IIterator* at(int index_);
	//������� ������� �� ����������
	void remove(IIterator* element);
	//������� ���������� ����������
	void clear();
	//�������� � ��������� � ���� ��� ������ �� ������� ����������
	void join(IIterable* container);
	//�������� ��������� � �������� �����
	double& operator[](int index_);

};



