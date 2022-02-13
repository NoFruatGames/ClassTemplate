#include "Counter.h"
Counter::Counter()
{
	this->size = 1;
	this->arr = new float[this->size]{};
	this->summ = 0;
	this->average = 0;
	this->pos = 0;
}
Counter::Counter(int size)
{
	this->size = size;
	this->arr = new float [this->size]{};
	this->summ = 0;
	this->average = 0;
	this->pos = 0;
}
Counter::~Counter()
{
	delete[] arr;
}
void Counter::setSize(int size)
{
	float* newArr = new float[size] {};
	for (int i = 0; i < (size>this->size?this->size:size); ++i)
	{
		newArr[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = newArr;
	this->size = size;
	if (this->pos > this->size)
		this->pos = this->size - 1;
}
int Counter::getSize()
{
	return size;
}
float* Counter::getArr()
{
	return arr;
}
int Counter::getSumm()
{
	return summ;
}
float Counter::getAverage()
{
	return average;
}
void Counter::addNumber(float number)
{
	if (this->pos < this->size)
	{
		arr[pos] = number;
		pos += 1; 
		summ += number;
		average = summ / pos;
	}
}
void Counter::removeLastElement()
{
	if (this->pos > 0)
	{
		arr[pos] = 0;
		pos -= 1;
		summ -= arr[pos + 1];
		average = summ / pos;
	}
}
void Counter::show()
{
	for (int i = 0; i < this->pos; ++i)
	{
		std::cout << this->arr[i] << ' ';
	}
	std::cout << '\n';
}
void Counter::saveToFile(std::string fileName)
{
	std::fstream f;
	f.open(fileName, std::ios_base::app);
	if (f.is_open())
	{
		for (int i = 0; i < this->pos; ++i)
		{
			f << arr[i];
			if (i < this->pos - 1)
				f << ' ';
		}
		f << "\n " << this->summ << " " << this->average << '\n';
	}
}