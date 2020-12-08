// CS449_HW2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include "catch.hpp"
#include "ItemQ1.h"
#include "SaleQ1.h"

using namespace std;

int main()
{
    int result = Catch::Session().run();

    cout << "Wew\n";
    system("pause");
    return 0;

}

