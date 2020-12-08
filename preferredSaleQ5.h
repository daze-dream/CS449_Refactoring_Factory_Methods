#pragma once
#include "SaleAbstractQ5.h"
class preferredSaleQ5 :
    public SaleAbstractQ5
{
public:
    double getDiscountRate() { return .15; }
};

