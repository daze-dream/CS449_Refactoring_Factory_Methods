#pragma once
#include <vector>
#include "ItemQ4.h"
using namespace std;
class SaleAbstractQ4
{
public:
	virtual ~SaleAbstractQ4() {};
	virtual double getDiscountRate() = 0;
	void addItem(ItemQ4 item) { itemList.push_back(item); };
	//returns transaction subtotal
	double getSubTotal();
	//returns transaction discount
	double getDiscount();
	//returns the final discounted total
	double getDiscountedSubtotal();
protected:
	vector<ItemQ4> itemList;
	
};

