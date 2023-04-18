#include "doctest.h"
#include "sources/Fraction.hpp"
#include<iostream>

using namespace std;

TEST_CASE("checking if constructors are working") {
    Fraction f1(7,4);
    Fraction f2(1,3);

    CHECK(f1.getNum() == 7);
    CHECK(f1.getDen() == 4);

    CHECK(f2.getNum() == 1);
    CHECK(f2.getDen() == 3); 
}

TEST_CASE(""){

}

TEST_CASE(""){
    
}

TEST_CASE(""){
    
}

TEST_CASE(""){
    
}
