#include "SaleAbstractQ5.h"

double SaleAbstractQ5::getSubTotal()
{
    double subtotal = 0.0;
    //iterate through item list
    for (auto i = itemList.begin(); i != itemList.end(); ++i)
    {

        //see if the item exists in the sale map
        auto temp2 = itemsOnSale.find(i->getName());
        //item found in sale map for the day
        if (temp2 != itemsOnSale.end())
        {
            //if item quantity matches or exceeds
            if (i->getQuantity() >= temp2->second.first)
            {

                //see if the quantity of the item object matches the discount requirement
                int discountThreshold = temp2->second.first;
                //temp variable for the current quantity
                int tempItemQuantity = i->getQuantity();
                //get the total if items before quantity discount kciks in
                subtotal += discountThreshold * i->getUnitPrice();
                //get the remnaining quantity
                tempItemQuantity -= discountThreshold;
                //if there are still quantities remaining
                if (tempItemQuantity > 0)
                {
                    //add them to the subtotal but now with the discount applied
                    subtotal += (tempItemQuantity * i->getUnitPrice()) * temp2->second.second;
                }
                else
                {
                    //if not, continue to next item
                    continue;
                }
            }
            else
            {
                //if quantity doesnt match, simply add to subtotal
                subtotal += i->getItemTotal();
            }
            
               
        }
        else
        {
            //if it is not in the discount catalog, simply add to subtotal
            subtotal += i->getItemTotal();
        }

        
    }
    return subtotal;
}

double SaleAbstractQ5::getDiscount()
{
    return getSubTotal() * getDiscountRate();
}

double SaleAbstractQ5::getDiscountedSubtotal()
{
    return getSubTotal() - getDiscount();
}
