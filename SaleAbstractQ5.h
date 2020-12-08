#pragma once
#include <set>
#include <map>
#include <vector>
#include "ItemQ5.h"


using namespace std;
class SaleAbstractQ5
{
public:
    map<string, pair<int, double>> getItemsOnSale() { return this->itemsOnSale; }
    void addItem(ItemQ5 item) { itemList.push_back(item); };
    virtual double getDiscountRate() = 0;
    void setItemsOnSale(map<string, pair<int, double>>currentSaleItems) { this->itemsOnSale = currentSaleItems; }
    double getSubTotal();
    double getDiscount();
    //returns the final discounted total
    double getDiscountedSubtotal();
protected:
    /*the sales object will get the sale items for the day / whatever period from the server
        the mapping goes: item, quantity to discount, discount to apply when applied*/
    map<string, pair<int, double>> itemsOnSale;
    vector<ItemQ5> itemList;


};

