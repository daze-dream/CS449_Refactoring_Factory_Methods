#include "saleCreator.h"

SaleAbstractQ4* saleCreator::create(DiscountType type, int weekday)
{
    switch (type)
    {
    case senior:
    {
        if (weekday == 3)
            return new seniorSaleQ4();
        else
            return new standardSaleQ4();
    }
    case preferred:
        return new preferredSaleQ4();
    case standard:
        return new standardSaleQ4();
    default:
        return new standardSaleQ4();
    }
}
