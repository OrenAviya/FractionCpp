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

TEST_CASE("check operator =="){
    Fraction f1(7,4);
    Fraction f2(1,3);

    CHECK((Fraction(1,2) == Fraction(2,4)));
    CHECK_FALSE(f1 == f2);
}

TEST_CASE("check reduction "){
    Fraction f1(4,8);

    CHECK(f1 == Fraction(1,2)) ;  
}

TEST_CASE("check + operator fraction"){
    Fraction f1(8,9);
    Fraction f2(5,2);

    CHECK((f1+f2) == Fraction(53, 18));

}

TEST_CASE("check  operator - fraction"){
    Fraction f1(7,2);
    Fraction f2(5,2);
    CHECK((f1-f2) == Fraction(2,2));
}


TEST_CASE("check the > , >= operators"){
    
    CHECK(Fraction (5,2) >= Fraction (5,2));
    CHECK(Fraction(7,2) > 1.3 );
    CHECK_FALSE (Fraction (5,2)> 2.1);

}

TEST_CASE("check operator - number"){
    Fraction f1(4,8);
    int integ = 1;
    double doub = 0.5;

    CHECK((f1 - integ) == -0.5);
    CHECK((Fraction(4,8)-doub) == 0);
}

TEST_CASE("check getters "){
     Fraction f1(4,8);

    CHECK( f1.getNum() ==1)  ;
    CHECK( f1.getDen()== 2 )   ;
    
}

TEST_CASE("check setters"){
   Fraction f1(4,8);

    f1.setNum(3);
    f1.setDen(5);

    CHECK(f1.getNum()==3);
    CHECK(f1.getDen()==5);
    
}

TEST_CASE(" check operator/ "){
    Fraction f1(4,8);
    Fraction f2(4,8);

    CHECK(f1/f2 == Fraction(1,1));
    
}

TEST_CASE("check  operator* "){
    Fraction f1(4,8);
    Fraction f2(2,6);

    CHECK(f1*f2 == Fraction(8,48));
    
}

TEST_CASE("check the denominator cannot be zero") {
    Fraction f(1,1);
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(f.setDen(0));

}

TEST_CASE("check the ++ , ++(int)"){
    Fraction f(1,2);

    CHECK(f++ == Fraction(3,2));
    
    CHECK( ++f == Fraction(3,2));
}

TEST_CASE("check the -- , --(int) operators"){
    Fraction f(4,5);

    f--;
    CHECK(f == Fraction(-1,5));
    --f;
    CHECK( f == Fraction(-1,5));
}

TEST_CASE("testing input >>"){
    // create an std::istringstream and intilaize it with string
    // then use the operator >> to enter a string into it (fraction represented as string)
    std:: isstringstream iss("8/9");
    Fraction f;
    iss >> f;
    CHECK(f == Fraction(8,9));


}

TEST_CASE("testing output <<"){
     //create an std::ostringstream object oss, and use the << operator to write a formatted string to it.
     std::ostringstream oss;
     Fraction f(4,5);
     oos<< f;
    CHECK (oos.str() == "4/5");

}

TEST_CASE(""){
    
}

TEST_CASE(""){
    
}

TEST_CASE(""){
    
}

TEST_CASE(""){
    
}

TEST_CASE(""){
    
}
