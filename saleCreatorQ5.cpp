#include "saleCreatorQ5.h"

SaleAbstractQ5* saleCreatorQ5::create(DiscountType type, int weekday)
{
    switch (type)
    {
    case senior:
    {
        if (weekday == 3)
            return new seniorSaleQ5();
        else
            return new standardSaleQ5();
    }
    case preferred:
        return new preferredSaleQ5();
    case standard:
        return new standardSaleQ5();
    default:
        return new standardSaleQ5();
    }
}
