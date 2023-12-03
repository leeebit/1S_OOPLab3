#pragma once
//#include "IIterator.h"

class IIterator;

class IIterable
{
public:
	//���������� ��������� ���������
	virtual IIterator* begin() = 0;
	//���������� �������� ���������
	virtual IIterator* end() = 0;
	//��������� ������� �� �������
	virtual bool isEmpty() = 0;
	//���������� ���������� ��������
	virtual int getSize() = 0;
	//�������� ��������� �� �������
	virtual IIterator* at(int index_) = 0;
	//�� ��������� ������� ������� �� ����������
	virtual void remove(IIterator* element) = 0;
	//������� ���������� ����������
	virtual void clear() = 0;
	//�������� � ��������� � ���� ��� ������ �� ������� ����������
	virtual void join(IIterable* container) = 0;
};

