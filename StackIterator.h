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
	//��������� �� ��������� �������
	void next();
	//��������� �� ���������� �������
	void prev();
	//���������� ������ ����� ���������
	void* get();
	//���������� ������ ���� ����������, ��������� �� ��� �� ���� � ��� �� ������� � ����� � ��� �� ����������
	bool isEqual(IIterator* iter);
};


