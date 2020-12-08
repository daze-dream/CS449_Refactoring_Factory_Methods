#pragma once
#include "SaleAbstractQ4.h"
class seniorSaleQ4 :
    public SaleAbstractQ4
{
public:
    double getDiscountRate() { return 0.10; };
};

