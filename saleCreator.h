#pragma once
#include "SaleAbstractQ4.h"
#include "seniorSaleQ4.h"
#include "preferredSaleQ4.h"
#include "standardSaleQ4.h"
#include "Enum.h"

using namespace std;
class saleCreator
{
public:
	SaleAbstractQ4* create(DiscountType type, int weekday);
};

