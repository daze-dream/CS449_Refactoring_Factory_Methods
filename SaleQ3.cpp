#include "SaleQ3.h"

double SaleQ3::getSubTotal()
{
    double subtotal = 0.0;
    for (auto i = itemList.begin(); i != itemList.end(); ++i)
    {
        subtotal += i->getItemTotal();
    }
    return subtotal;
}

double SaleQ3::getDiscount(DiscountType type)
{
    return getSubTotal() * getDiscountRate(type);
}

double SaleQ3::getDiscountRate(DiscountType type)
{
    switch (type)
    {
    case senior:
    {
        if (this->weekday == 3)
            return .10;
        else
            return STANDARD_DISCOUNT_RATE;
    }
    case preferred:
        return .15;
    case standard:
        return STANDARD_DISCOUNT_RATE;
    default:
        return STANDARD_DISCOUNT_RATE;
    }
}

double SaleQ3::getDiscountedSubtotal(DiscountType type)
{
    return getSubTotal() - getDiscount(type);
}

void SaleQ3::setWeekday(int w)
{
    //error checking
    if (w >= 1 || w <= 7)
    {
        weekday = w;
    }
    //default to 1
    else
    {
        weekday = 1;
    }
}
