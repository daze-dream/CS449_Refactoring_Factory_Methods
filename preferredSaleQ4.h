#pragma once
#include "SaleAbstractQ4.h"
class preferredSaleQ4 :
    public SaleAbstractQ4
{
public:
    double getDiscountRate() { return .15; }
};

