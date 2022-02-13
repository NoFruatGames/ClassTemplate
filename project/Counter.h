#pragma once
#include <iostream>
#include <string>
#include <fstream>
class Counter
{
private:
	int size;
	float* arr;
	int summ;
	float average;
	int pos;
public:
	Counter();
	Counter(int size);
	~Counter();
	void setSize(int size);
	int getSize();
	float* getArr();
	int getSumm();
	float getAverage();
	void addNumber(float number);
	void removeLastElement();
	void show();
	void saveToFile(std::string fileName);

};

