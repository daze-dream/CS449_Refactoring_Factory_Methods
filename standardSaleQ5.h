#pragma once
#include "SaleAbstractQ5.h"
class standardSaleQ5 :
    public SaleAbstractQ5
{
public:
    double getDiscountRate() { return .05; }
};

