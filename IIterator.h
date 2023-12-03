#pragma once

class IIterator
{
public:
	//��������� �� ��������� �������
	virtual void next() = 0;
	//��������� �� ���������� �������
	virtual void prev() = 0;
	//���������� ������ ����� ���������
	virtual void* get() = 0;
	//���������� ������ ���� ����������, ��������� �� ��� �� ���� � ��� �� ������� � ����� � ��� �� ����������
	virtual bool isEqual(IIterator* iter) = 0;
};

