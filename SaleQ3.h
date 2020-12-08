#pragma once
#include <vector>
#include "ItemQ3.h"
#include "Enum.h"

using namespace std;
class SaleQ3
{
protected:
	const double STANDARD_DISCOUNT_RATE = .05;
	int weekday = 1;
	vector<ItemQ3> itemList;
public:
	void addItem(ItemQ3 item) { itemList.push_back(item); };
	//returns transaction subtotal
	double getSubTotal();
	//returns transaction discount
	double getDiscount(DiscountType type);
	//returns the current discount rate. Changes depending on passed parameter
	double getDiscountRate(DiscountType type);
	//returns the final discounted total
	double getDiscountedSubtotal(DiscountType type);
	//returns weekday integer
	int getWeekday() { return weekday; }
	//sets weekday integer
	void setWeekday(int w);

};


