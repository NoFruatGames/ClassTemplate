#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Counter.h"
int main()
{
	Counter c;
	std::string file_name;
	std::cout << "File name: ";
	std::cin >> file_name;
	int size;
	std::cout << "Enter size: ";
	do
	{
		std::cin >> size;
	} while (size < 20 && size > 50);
	c.setSize(size);
	for (int i = 0; i < size; ++i)
	{
		float num;
		std::cin >> num;
		c.addNumber(num);
	}
	c.show();
	c.saveToFile(file_name);
}