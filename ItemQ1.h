#pragma once
#include <string>

using namespace std;
class ItemQ1
{
protected:
	string title = "";
	double unitPrice = 0.0;
	double quantity= 0.0;
public:
	ItemQ1(string n, double p, double q);
	//getters

	string getName() { return title; }
	double getUnitPrice() { return unitPrice; }
	double getQuantity() {return quantity; }
	//setters

	void setName(string n) { this->title = n; }
	void setUnitPrice(double x) { this->unitPrice = x; }
	void setQuantity(double x) { this->quantity = x; }

	//functions
	/*I assume each Item object is an instance of a purcahse, and not
		the individual items themselves.*/
	double getItemTotal() { return unitPrice * quantity; }

};

