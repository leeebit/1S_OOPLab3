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
	//��������� �� ��������� �������
	void next();
	//��������� �� ���������� �������
	void prev();
	//���������� ������ ����� ���������
	void* get();
	//���������� ������ ���� ����������, ��������� �� ��� �� ���� � ��� �� ������� � ����� � ��� �� ����������
	bool isEqual(IIterator* iter);
};

