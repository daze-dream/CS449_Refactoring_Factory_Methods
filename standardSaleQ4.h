#pragma once
#include "SaleAbstractQ4.h"
class standardSaleQ4 :
    public SaleAbstractQ4
{
public:
    double getDiscountRate() { return .05; }
};

