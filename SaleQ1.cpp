#include "SaleQ1.h"

double SaleQ1::getSubTotal()
{
    double subtotal = 0.0;
    for (auto i = itemList.begin(); i != itemList.end(); ++i)
    {
        subtotal += i->getItemTotal();
    }
    return subtotal;
}

double SaleQ1::getDiscount()
{
    return getSubTotal()*getDiscountRate();
}

double SaleQ1::getDiscountedSubtotal()
{
    return getSubTotal()-getDiscount();
}
