#pragma once
#include "SaleAbstractQ5.h"
class seniorSaleQ5 :
    public SaleAbstractQ5
{
public:
    double getDiscountRate() { return 0.10; };
};

