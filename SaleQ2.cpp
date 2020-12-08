#include "SaleQ2.h"

double SaleQ2::getSubTotal()
{
    double subtotal = 0.0;
    for (auto i = itemList.begin(); i != itemList.end(); ++i)
    {
        subtotal += i->getItemTotal();
    }
    return subtotal;
}

double SaleQ2::getDiscount(DiscountType type)
{
    return getSubTotal() * getDiscountRate(type);
}

double SaleQ2::getDiscountRate(DiscountType type)
{
    switch (type)
    {
    case senior:
        return .10;
    case preferred:
        return .15;
    case standard:
        return STANDARD_DISCOUNT_RATE;
    default:
        return STANDARD_DISCOUNT_RATE;
    }
}

double SaleQ2::getDiscountedSubtotal(DiscountType type)
{
    return getSubTotal() - getDiscount(type);
}
