#pragma once
#include "saleAbstractQ5.h"
#include "saleCreator.h"
#include "seniorSaleQ5.h"
#include "preferredSaleQ5.h"
#include "standardSaleQ5.h"

class saleCreatorQ5
{
public:
    SaleAbstractQ5* create(DiscountType type, int weekday);
};

