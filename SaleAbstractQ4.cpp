#include "SaleAbstractQ4.h"

double SaleAbstractQ4::getSubTotal()
{
    double subtotal = 0.0;
    for (auto i = itemList.begin(); i != itemList.end(); ++i)
    {
        subtotal += i->getItemTotal();
    }
    return subtotal;
}

double SaleAbstractQ4::getDiscount()
{
    return getSubTotal() * getDiscountRate();
}

double SaleAbstractQ4::getDiscountedSubtotal()
{
    return getSubTotal() - getDiscount();
}