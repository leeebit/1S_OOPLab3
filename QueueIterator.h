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
	//��������� �� ��������� �������
	void next();
	//��������� �� ���������� �������
	void prev();
	//���������� ������ ����� ���������
	void* get();
	//���������� ������ ���� ����������, ��������� �� ��� �� ���� � ��� �� ������� � ����� � ��� �� ����������
	bool isEqual(IIterator* iter);
};

