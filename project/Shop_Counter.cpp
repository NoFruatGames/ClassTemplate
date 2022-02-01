#include "Shop_Counter.h"
Shop_Counter::Shop_Counter()
{
	this->count = 0;
	this->description = " ";
	this->name = " ";
	this->price = 0.;
	this->type = " ";
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

float Shop_Counter::calculatePriceWithoutDiscount()
{
	return price * count;
}
float Shop_Counter::calculatePriceWithDiscount()
{
	return (price * count) * (discount / 100.);
}

void Shop_Counter::showFullInfo()
{
	std::cout << type << '\n';
	std::cout << name << '\n';
	std::cout << "Count: " << count << '\n';
	std::cout << "Price(1 piece): " << price << '\n';
	std::cout << "Price: " << calculatePriceWithoutDiscount() << '\n';
	std::cout << "Discount: " << discount << "%\n";
	std::cout << "Total Price: " << calculatePriceWithDiscount() << '\n';
	std::cout << description << '\n';
}
void Shop_Counter::showShortInfo()
{
	if (count > 0)
	{
		std::cout << type << '\n';
		std::cout << name << '\n';
		std::cout << "Count: " << count << '\n';
		std::cout << "Price: " << calculatePriceWithDiscount() << '\n';
	}
}

void Shop_Counter::readFullInfo(std::ifstream& f)
{
	std::string text = "";
	f >> this->type;
	while (text != "Count:")
	{
		f >> text;
		if(text != "Count:")
			name += text + " ";
	}
	if (name.length() > 0 && name[0] == ' ')
		name.erase(0, 1);
	if (name[name.length() - 1] == ' ')
		name.erase(name.length() - 1, 1);

	while (text != "Price(1")
	{
		f >> text;
		if (text != "Price(1")
		{
			if (text.length() > 0 && text[0] == ' ')
				text.erase(0, 1);
			if (text[text.length() - 1] == ' ')
				text.erase(text.length() - 1, 1);
			count = std::stoi(text);
		}
	}
	while (text != "Price:")
	{
		f >> text;
		if (text != "piece):" && text != "Price:")
		{
			if (text.length() > 0 && text[0] == ' ')
				text.erase(0, 1);
			if (text[text.length() - 1] == ' ')
				text.erase(text.length() - 1, 1);
			price = std::stod(text);
		}
	}
	while (text != "Total")
	{
		f >> text;
		if (text != "Discount:" && text != "Total")
		{
			if (text.length() > 0 && text[0] == ' ')
				text.erase(0, 1);
			if (text[text.length() - 1] == ' ')
				text.erase(text.length() - 1, 1);
			if (text[text.length() - 1] == '%')
				text.erase(text.length() - 1, 1);
			discount = std::stoi(text);
		}
	}
	f >> description;
	f >> description;
	f >> description;
	if (description == "-")
		description = "";
}
void Shop_Counter::saveFullInfoToFile(std::string fileName)
{
	std::fstream f;
	f.open(fileName, std::ios_base::app);
	f << type << '\n' << name << '\n' << "Count: " << count << '\n' << "Price(1 piece): " << 
		price << '\n' << "Price: " << calculatePriceWithoutDiscount() << '\n' << 
		"Discount: " << discount << "%\n" << "Total Price: " << calculatePriceWithDiscount() << '\n';
	if (description.length() == 0)
		f << "-\n";
	else
		f << description << "\n";
}
void Shop_Counter::saveShortInfoToFile(std::string fileName)
{
	if (count > 0)
	{
		std::fstream f;
		f.open(fileName, std::ios_base::app);
		f << type << '\n' << name << '\n' << "Count: " << count << '\n' << "Price: " << calculatePriceWithDiscount() << "\n\n";
	}
	
}