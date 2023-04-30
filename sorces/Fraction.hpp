#pragma once
#include <iostream>
namespace ariel {}
class Fraction{
    private:
        int num; //numerator
        int den; //denominator
    
    public:
    //constructors:
        Fraction();

        Fraction(int numerator, int denominator);

        Fraction(double num);

    //getters & setters

        void setNum(int);
        void setDen(int);

        int getNum() const;
        int getDen() const;
        
    // operators
        Fraction operator+(Fraction f);
        Fraction operator+(double num);
        friend const Fraction operator+(double num , const Fraction f);

        Fraction operator-(Fraction f);
        Fraction operator-(double num);
        // Fraction operator-(int num);
        friend const Fraction operator-(double num , const Fraction f);

        Fraction operator/(Fraction f);
        Fraction operator/(double number);
        friend const Fraction operator/(double num , const Fraction f);

        Fraction operator*(Fraction f);
        Fraction operator*(double number);
        friend const Fraction operator*(double num , const Fraction f);
        
        Fraction& operator++();
    
        Fraction& operator--();
    
        Fraction operator++(int);
    
        Fraction operator--(int);

        bool operator>=(const Fraction &f) const;
        bool operator>=(double number) const ;
        friend const bool operator>=(double num , const Fraction f);
        
        bool operator <=(const Fraction &f) const;
        bool operator<=(double number) const ;
        friend const bool operator<=(double num , const Fraction f);

        bool operator <(const Fraction &f) const;
        bool operator < (double number) const;
        friend const bool operator <(double num , const Fraction f);

        bool operator >(const Fraction &f) const;
        bool operator>(float number) const;
        friend const bool operator >(double number , const Fraction f);

        bool operator==(const Fraction& other) const;
        bool operator == (double number)const;
        friend const bool operator ==(double num , const Fraction f);

        friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
    
        friend std::istream& operator>>(std::istream& in, Fraction& fraction);

        int gcd (int a , int b);
        void reduce();


};

    
   
    
   
   
    
