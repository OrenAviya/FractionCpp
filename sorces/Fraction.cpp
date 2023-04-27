#include "Fraction.hpp"
#include <math.h>
using namespace std;
using namespace ariel;

//constructors:
        Fraction:: Fraction (): num(0) , den(1){

        }    

        Fraction:: Fraction(int numerator, int denominator)/*num(numerator) , den(denominator)*/ {
            if ( denominator == 0)
                throw std :: invalid_argument ("This demoninator is illegal");
            
            //reduce the fraction
            int gcf = gcd(numerator, denominator); // find greatest common factor
            numerator /= gcf;
            denominator /= gcf;
            this->num = numerator;
            this->den = denominator;
        }

       Fraction :: Fraction(double num){
        double decimal = num;
        int numerator = (int)(decimal * 1000);
        int denominator = 1000;
        
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
            if (d == 0.0)
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
        int numerator = ((f.getDen() * this->num) +(this->den * f.getNum())) ;
        Fraction frac=Fraction(numerator, denominator); //reducing by constructor
        return frac;
        }

        const Fraction operator+(double num , const Fraction f){
            Fraction temp(num);
            Fraction frac= (temp+f);
            frac.reduce();
            return (frac);
        }

        Fraction Fraction:: operator+(double num){
           Fraction temp = Fraction(num);
            Fraction frac=*this+temp;
            frac.reduce();
            return (frac);
        }

        Fraction Fraction:: operator-(Fraction f){
        
        int denominator = this->den * f.getDen();
        int numerator = (this->num * f.getDen()) - (f.getNum() * this->den) ;
        Fraction frac=Fraction(numerator, denominator);
        frac.reduce();
        return frac;
        }

        Fraction Fraction:: operator-(double num){
        Fraction frac1 =  Fraction(num);
        frac1 = *this - frac1;
        frac1.reduce();
        return frac1;
        }

        Fraction Fraction:: operator-(int num){
        Fraction frac1 =  Fraction(num);
        frac1 = *this - frac1;
        frac1.reduce();
        return frac1;
        }

        const Fraction operator-(double num , const Fraction f){
            Fraction temp(num);
            return (temp-f);
        }

        Fraction Fraction:: operator/(Fraction f){
            int numerator = this->den * f.getNum();
            int denominator = this->num * f.getDen();
            Fraction frac = Fraction(numerator , denominator);
             frac.reduce();
             return frac;
        }

        const Fraction operator/(double num , const Fraction f){
            Fraction temp(num);
            return (temp/f);
        }

        Fraction Fraction:: operator/(double number) {
            if (number == 0.0){
                throw std :: invalid_argument ("devision by zero is illegal");
            }
            //make fraction from the number , then use / with two fractions
            Fraction f(number); 
            return *this / f; 

        }
        Fraction Fraction:: operator*(Fraction f){
            int numerator = this->num * f.getNum();
           int denominator = this->den * f.getDen();
          Fraction frac = Fraction(numerator , denominator);
          frac.reduce();
            return frac;
        }
        const Fraction operator*(double num , const Fraction f){
            Fraction frac = Fraction(num);
            frac.reduce();
            return frac*f;
        }
        Fraction Fraction:: operator*(double number){
            Fraction temp(number);
            return (*this * temp);
        }

        Fraction& Fraction::operator++(){
            this ->num += this ->den; // add 1 to the fraction
            this->reduce(); //reduce
            return *this;
        }
    
        Fraction& Fraction::operator--(){
            this ->num -= this ->den; // minus 1 to the fraction
            this ->reduce(); // reduce
            return *this;
        }

        Fraction Fraction::operator++(int i){
            Fraction frac = *this; 
            ++(*this);
            return frac;
        }
        Fraction Fraction::operator--(int i){
            Fraction frac = *this; 
            --(*this);
            return frac;
        }


        bool Fraction :: operator>=(const Fraction& f) const{
            if ((this ->num/this->den) >= (f.getNum()/f.getDen() )){
                return true;
            } 
            return false;
            }
         bool Fraction ::operator>=(double number) const{
            Fraction temp(number);
            return (*this >= temp);
         }

        const bool operator>=(double num , const Fraction f){
            Fraction temp(num);
            return (temp >= f);
        }

        bool Fraction ::operator <=(const Fraction &f) const{
            if (*this < f || *this == f)
                return true;
            return false;
        }
        bool Fraction ::operator<=(double number) const{
            Fraction temp(number);
            return (*this <= temp);
        }
        const bool operator<=(double num , const Fraction f){
            Fraction temp(num);
            return (temp <= f);
        }

        bool Fraction :: operator <(const Fraction &f) const{
            return this->num * f.getDen() < f.getNum() * this->den; 
        }
         bool Fraction :: operator < (double number) const{
            Fraction temp(number);
            return (*this < temp);
         }
         const bool operator<(double num , const Fraction f){
            Fraction temp(num);
            return (temp < f);
        }

        bool Fraction:: operator>(double num) const{
            if ((this->num / this->den) > num){
                return true;
            }
            return false;
        }
        
        bool Fraction::operator >(const Fraction &f) const{
            return ((this->num / this->den) > (f.getNum()/f.getDen()));
        }

        const bool operator>(double num , const Fraction f){
            Fraction temp(num);
            return (temp > f);
        }

        bool Fraction:: operator==(const Fraction& f) const{
            if (num == f.getNum()  && den == f.getDen()){
                return true;
            }
            return false;
        }
        bool Fraction:: operator == (double number)const{
            Fraction temp(number);
            return (*this == temp);
        }

        std::ostream& operator<<(std::ostream& output, const Fraction& f)
        {
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

   // for reduction     
int Fraction::gcd(int a, int b) { // function to find greatest common divisor
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void Fraction:: reduce(){
    int gcf = Fraction:: gcd(this->num,this->den); 
            this->num/= gcf;
            this->den /= gcf;
            
}