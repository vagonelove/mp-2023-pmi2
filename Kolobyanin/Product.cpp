#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Product.h"

using namespace std;

Product::Product(string Name, int ID, Category category, double price, double discount, int count) : name(Name), ID(ID), category(category), price(price), discount(discount), count(count)
{
}

Product::Product()
{
}

Product::Product(string name) : name(name)
{
}

Product::~Product()
{
}

Product::Product(const Product& other) : name(other.name), ID(other.ID), category(other.category), price(other.price), discount(other.discount), count(other.count)
{
}

string Product::GetName() const
{
	return name;
}

int Product::GetID() const
{
	return ID;
}

Category Product::GetCategory() const
{
	return category;
}

double Product::GetPrice() const
{
	return price;
}

double Product::GetDiscount() const
{
	return discount;
}

int Product::GetCount() const
{
	return count;
}

string Product::CategoryString() const
{
	switch (category)
	{
	case Category::Fruits:
		return "Fruits";
	case Category::Vegetables:
		return "Vegetables";
	case Category::Grocery:
		return "Grocery";
	case Category::Dairy:
		return "Dairy";
	default:
		return "Unknown Type";
	}
}

ostream& operator<<(ostream& os, const Product& other)
{
	os << "Name: " << other.name << endl;
	os << "Category: " << other.CategoryString() << endl;
	os << "ID: " << other.ID << endl;
	os << "Old Price: " << other.price << endl;
	os << "Price with discount : " << (other.price - other.price * (other.discount / 100.0)) << endl;
	os << "Count: " << other.count << endl;
	return os;
}

Product& Product::operator++()
{
	count++;
	return *this;
}

bool Product::operator==(const Product& other)
{
	return name == other.name;
}

bool Product::operator<(const Product& other)
{
	double valueThis = (price - price * (discount / 100.0)) * count;
	double valueOther = (other.price - other.price * (other.discount / 100.0)) * other.count;

	if (valueThis < valueOther)
	{
		return true;
	}
	else if (valueThis > valueOther)
	{
		return false;
	}
}

Product Product::operator+(const Product& other)
{
	if (ID == other.ID)
	{
		count += other.count;
	}
	return *this;
}

Product Product::operator-(const Product& other)
{
	if (ID == other.ID)
	{
		count = abs(count - other.count);
	}
	return *this;
}