#include "Shop_Counter.h"
Shop_Counter::Shop_Counter()
{
	this->count = 0;
	this->description = "";
	this->name = "";
	this->price = 0.;
	this->type = "";
	this->discount = 0;
}

int Shop_Counter::getCount()
{
	return this->count;
}
std::string Shop_Counter::getDescription()
{
	return this->description;
}
std::string Shop_Counter::getName()
{
	return this->name;
}
std::string Shop_Counter::getType()
{
	return this->type;
}
float Shop_Counter::getPrice()
{
	return this->price;
}
int Shop_Counter::getDiscount()
{
	return this->discount;
}

void Shop_Counter::setCount(int count)
{
	if (count >= 0)
		this->count = count;
}
void Shop_Counter::setPrice(float price)
{
	if (price >= 0)
		this->price = price;
}
void Shop_Counter::setName(std::string name)
{
	this->name = name;
}
void Shop_Counter::setDescription(std::string description)
{
	this->description = description;
}
void Shop_Counter::setType(std::string type)
{
	this->type = type;
}
void Shop_Counter::setDiscount(int discount)
{
	if (discount >= 0)
	{
		this->discount = discount;
	}
}

void Shop_Counter::showFullInfo()
{
	std::cout << type << '\n';
	std::cout << name << '\n';
	std::cout << "Count: " << count << '\n';
	std::cout << "Price(1 piece): " << price << '\n';
	std::cout << "Price: " << price * count << '\n';
	std::cout << "Discount: " << discount << "%\n";
	std::cout << "Total Price: " << (price * count) * (discount / 100.);
	std::cout << description;
}
void Shop_Counter::showShortInfo()
{
	if (count > 0)
	{
		std::cout << type << '\n';
		std::cout << name << '\n';
		std::cout << "Count: " << count << '\n';
		std::cout << "Price: " << (price * count) * (discount / 100.);
	}
}