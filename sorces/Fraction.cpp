#include "Fraction.hpp"
#include <math.h>
using namespace std;
using namespace ariel;

//constructors:
        
       Fraction:: Fraction(int numerator, int denominator): num(numerator) , den(denominator) {
            if ( denominator == 0)
                throw std :: invalid_argument ("This demoninator is illegal");
        }

       Fraction :: Fraction(double num){
        double decimal = num;
        int numerator = decimal * 10;
        int denominator = 10;
        
        int gcf = gcd(numerator, denominator); // find greatest common factor
        numerator /= gcf;
        denominator /= gcf;

        this->num = numerator;
        this->den = denominator ;      
        }
        
    //getters & setters

        void Fraction::setNum(int n){
            this->num = n;
        }
        void Fraction::setDen(int d){
            if (d == 0)
                throw std :: invalid_argument ("This demoninator is illegal");
            
            this->den = d;
        }

        int Fraction::getNum() const{
            return this->num;
        }
        int Fraction:: getDen() const{
            return this->den;
        }
        


        Fraction Fraction:: operator+(Fraction f){
        int denominator = this->den * f.getDen();
        int numerator =(denominator / this->den) + (denominator / f.getDen()) ;
        
        return Fraction(numerator, denominator);
        }

        Fraction Fraction:: operator-(Fraction f){
        int denominator = this->den * f.getDen();
        int numerator =(denominator / this->den) - (denominator / f.getDen()) ;
        
        return Fraction(numerator, denominator);
        }

        Fraction Fraction:: operator-(float num){
            return Fraction(this->num/this->den - num);
        }

        Fraction Fraction:: operator-(int num){
            return Fraction(this->num/this->den - num);
        }

        Fraction Fraction:: operator/(Fraction f){
            int numerator = this->den * f.getNum();
            int denominator = this->num * f.getDen();

            return Fraction(numerator , denominator);
        }

        Fraction Fraction:: operator*(Fraction f){
            int numerator = this->num * f.getNum();
           int denominator = this->den * f.getDen();

            return Fraction(numerator , denominator);
        }

        Fraction Fraction:: operator+(double num){
           Fraction temp = Fraction(num);
            return (*this+temp);
        }

        Fraction Fraction::operator++(int i){
            this->num += i;
            return Fraction(this->num , this->den);
        }
        Fraction Fraction::operator--(int i){
            this->num -=  i;
            return Fraction(this->num , this->den);
        }

        Fraction& Fraction::operator++(){
            this ->num += this ->den;
            return *this;
        }
    
        Fraction& Fraction::operator--(){
            this ->num -= this ->den;
            return *this;
        }

        bool Fraction :: operator>=(const Fraction& f) const{
            if ((this ->num/this->den) >= (f.getNum()/f.getDen() )){
                return true;
            } 
            return false;
            }
        // bool Fraction ::operator>=( const Fraction f) const{
        //     if ((this->num / this->den) >= (f.getNum()/f.getDen() )){
        //         return true;
        //     }
        //     return false;
        // }

        bool Fraction:: operator>(double num) const{
            if ((this->num / this->den) > num){
                return true;
            }
            return false;
        }

        const Fraction operator*(float num , const Fraction f){
            int numerator = num * f.getNum();
            int denominator = f.getDen();
            return Fraction(numerator , denominator);
        }

        std::ostream& operator<<(std::ostream& output, const Fraction& f){
        return output << f.getNum()<< "/" << f.getDen();
        }

        std::istream& operator>>(std::istream& input, Fraction& f){
        char c ;
        int num , den;
         
        input >> num >> c >> den ;
        
        if (input && c == '/' && den != 0) {
        f.setNum(num);
        f.setDen(den);
    }
    else {
        input.setstate(std::ios::failbit);
    }
        return input;
        }

        
int Fraction::gcd(int a, int b) { // function to find greatest common divisor
    if (b == 0)
        return a;
    return gcd(b, a % b);
}