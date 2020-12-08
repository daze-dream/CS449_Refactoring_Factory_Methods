#include "catch.hpp"
#include "Enum.h"
#include "ItemQ1.h"
#include "SaleQ1.h"
#include "ItemQ2.h"
#include "SaleQ2.h"
#include "ItemQ3.h"
#include "SaleQ3.h"
#include "ItemQ4.h"
#include "ItemQ5.h"
#include "saleCreator.h"
#include "SaleAbstractQ4.h"
#include "SaleAbstractQ5.h"
#include "saleCreatorQ5.h"

using namespace std;

TEST_CASE("Question 1", "[Q1]")
{
	//creating item
	ItemQ1 test("test", 5.00, 2);
	SaleQ1 sale;
	//test item properties
	REQUIRE(test.getName() == "test");
	REQUIRE(test.getQuantity() == 2);
	REQUIRE(test.getUnitPrice() == 5.00);
	REQUIRE(test.getItemTotal() == 10.00);
	sale.addItem(test);
	//test sale properties
	REQUIRE(sale.getDiscountRate() == .05);
	REQUIRE(sale.getSubTotal() == 10.00);
	REQUIRE(sale.getDiscount() == .50);
	REQUIRE(sale.getDiscountedSubtotal() == 9.50);
}

TEST_CASE("Question 2", "[Q2]")
{
	//creating item
	ItemQ2 test("test", 5.00, 2);
	SaleQ2 sale;
	sale.addItem(test);
	//test various rates according to DiscountType
	REQUIRE(sale.getDiscountRate(senior) == .10);
	REQUIRE(sale.getDiscountRate(standard) == .05);
	REQUIRE(sale.getDiscountRate(preferred) == .15);
	REQUIRE(sale.getDiscount(senior) == 1.00);
	REQUIRE(sale.getDiscount(preferred) == 1.50);
	REQUIRE(sale.getDiscount(standard) == .50);
	
}
TEST_CASE("Question 3", "[Q3]")
{
	//creating item
	ItemQ3 test("test", 5.00, 2);
	SaleQ3 sale;
	sale.addItem(test);
	sale.setWeekday(3);
	REQUIRE(sale.getWeekday() == 3);
	REQUIRE(sale.getDiscountRate(senior) == .10);
	sale.setWeekday(2);
	REQUIRE(sale.getDiscountRate(senior) != .10);
	REQUIRE(sale.getDiscountRate(senior) == .05);
}

TEST_CASE("Question 4", "[Q4]")
{
	//creating item
	ItemQ4 test("test", 5.00, 2);
	// sale factory
	saleCreator creator;
	//make item
	SaleAbstractQ4* saleTest1 = creator.create(senior, 3);		SaleAbstractQ4* saleTest2 = creator.create(senior, 2);
	SaleAbstractQ4* saleTest3 = creator.create(preferred, 3);	SaleAbstractQ4* saleTest4 = creator.create(standard, 3);
	saleTest1->addItem(test); saleTest2->addItem(test);	saleTest3->addItem(test);saleTest4->addItem(test);
	//test senior object creation
	REQUIRE(saleTest1->getDiscountRate() == .10);	REQUIRE(saleTest2->getDiscountRate() == .05); 
	REQUIRE(saleTest3->getDiscountRate() == .15);	REQUIRE(saleTest4->getDiscountRate() == .05);
	//does the final discount work?
	REQUIRE(saleTest1->getDiscountedSubtotal() == 9.00);


}

TEST_CASE("Question 5", "[Q5]")
{
	//create sales map of the day
	map<string, pair<int, double>> todaysDiscounts;
	todaysDiscounts.insert(make_pair("test",make_pair(2, .5)));
	//factory start
	saleCreatorQ5 creator;
	SaleAbstractQ5* saleTest = creator.create(senior, 3);
	saleTest->setItemsOnSale(todaysDiscounts);
	SECTION("item exists in discount map")
	{
		ItemQ5 test("test", 5.00, 3);
		saleTest->addItem(test);
		//the subtotal should now reflect the 3 initial items, and then the 1 discounted item.
		REQUIRE(saleTest->getSubTotal() == 12.50);
		//and the final total should be discounted by the senior discount
		REQUIRE(saleTest->getDiscountedSubtotal() == 11.25);
	}
	SECTION("item does not exist in discount map")
	{
		ItemQ5 test("noexist", 5.00, 3);
		saleTest->addItem(test);
		//the subtotal should now reflect the 3 initial items, and then the 1 discounted item.
		REQUIRE(saleTest->getSubTotal() == 15.00);
	}
	SECTION("item exists but quantity is exactly the threshold")
	{
		ItemQ5 test("test", 5.00, 2);
		saleTest->addItem(test);
		//the subtotal should now reflect the 3 initial items, and then the 1 discounted item.
		REQUIRE(saleTest->getSubTotal() == 10.00);
	}
	SECTION("item exists but quantity is below the threshold")
	{
		ItemQ5 test("test", 5.00, 1);
		saleTest->addItem(test);
		//the subtotal should now reflect the 3 initial items, and then the 1 discounted item.
		REQUIRE(saleTest->getSubTotal() == 5.00);
	}
	

}