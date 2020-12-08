#pragma once
#include <vector>
#include "ItemQ1.h"

using namespace std;
class SaleQ1
{
protected:
	const double DISCOUNT_RATE = .05;
	vector<ItemQ1> itemList;
public:
	void addItem(ItemQ1 item) { itemList.push_back(item); };
	//returns transaction subtotal
	double getSubTotal();
	//returns transaction discount
	double getDiscount();
	//returns the current discount rate
	double getDiscountRate() { return DISCOUNT_RATE; }
	//returns the final discounted total
	double getDiscountedSubtotal();

};

