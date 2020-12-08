#pragma once
#include <vector>
#include "ItemQ2.h"
#include "Enum.h"

using namespace std;
class SaleQ2
{
protected:
	const double STANDARD_DISCOUNT_RATE = .05;
	vector<ItemQ2> itemList;
public:
	void addItem(ItemQ2 item) { itemList.push_back(item); };
	//returns transaction subtotal
	double getSubTotal();
	//returns transaction discount
	double getDiscount(DiscountType type);
	//returns the current discount rate. Changes depending on passed parameter
	double getDiscountRate(DiscountType type);
	//returns the final discounted total
	double getDiscountedSubtotal(DiscountType type);

};


