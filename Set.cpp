#include "Set.h"
#include "ArrayIterator.h"
using namespace std;

/*OK*/Set::Set()
{
	size=0;
	arr=nullptr;
}

/*OK*/Set::~Set()
{
	delete[] arr;
	arr=nullptr;
}

/*OK*/double* Set::get()
{
	return arr;
}

/*OK*/void Set::push(double val)
{
	bool num_dont_exist=true;
	for(int i=0; i<size; i++)
	{
		if (arr[i]==val)
		{
			num_dont_exist=false;
			break;
		}
	}
	if(num_dont_exist)
	{
		double* newArr=new double[size+1];

		for(int i=0; i<size; i++)
			newArr[i]=arr[i];
		newArr[size]=val;

		delete[] arr;
		arr=newArr;
		size++;
	}
}

/*OK*/void Set::pop()
{
	double* newArr=new double[size-1];

	for(int i=0; i<size-1; i++)
		newArr[i]=arr[i];

	delete[] arr;
	arr=newArr;
	size--;
}

/*OK*/IIterator* Set::begin()
{
	return new ArrayIterator((Array*)this, 0);
}

/*OK*/IIterator* Set::end()
{
	return new ArrayIterator((Array*)this, size);
}

/*OK*/int Set::getSize()
{
	return size;
}

/*OK*/bool Set::isEmpty()
{
	return size==0;
}

/*OK*/IIterator* Set::at(int index_)
{
	if(index_<0||index_>=size)
		return nullptr;

	return new ArrayIterator((Array*)this, index_);
}

/*OK*/void Set::remove(IIterator* element)
{
	ArrayIterator* iter=(ArrayIterator*)element;
	int index=iter->getIndex();

	if(index<0||index>=size)
		return;

	double* newArr=new double[size-1];

	for(int i=0; i<index; i++)
		newArr[i]=arr[i];

	for(int i=index+1; i<size; i++)
		newArr[i-1]=arr[i];

	delete[] arr;
	arr=newArr;
	size--;
}

/*OK*/void Set::clear()
{
	delete[] arr;
	arr=nullptr;

	size=0;
}

/*OK*/void Set::join(IIterable* container)
{
	int newSize=size+container->getSize();
	double* newArr=new double[newSize];

	for(int i=0; i<size; i++)
		newArr[i]=arr[i];

	IIterator* iter=container->begin();
	int index=size;
	while(!iter->isEqual(container->end()))
	{
		newArr[index]=*(double*)iter->get();
		iter->next();
		index++;
	}

	delete[] arr;
	arr=newArr;
	size=newSize;
}

/*OK*/double& Set::operator[](int index_)
{
	return arr[index_];
}