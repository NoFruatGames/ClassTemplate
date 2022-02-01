#pragma once
#ifndef SHOP_COUNTER_DEF
#define SHOP_COUNTER_DEF
#include <string>
#include <iostream>
class Shop_Counter
{
private:
	int count;
	int discount;
	float price;
	std::string name;
	std::string description;
	std::string type;
public:
	Shop_Counter();

	int getCount();
	float getPrice();
	std::string getName();
	std::string getDescription();
	std::string getType();
	int getDiscount();

	void setCount(int count);
	void setPrice(float price);
	void setName(std::string name);
	void setDescription(std::string description);
	void setType(std::string type);
	void setDiscount(int discount);

	void showFullInfo();
	void showShortInfo();
};

#endif



