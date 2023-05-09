#pragma once
#include <iostream>
#include <string>
using namespace std;


namespace ariel{

class Fraction {

    private:

        int numerator;
        int denominator;

    public:
        // Constructors:
        Fraction();
        Fraction(int numerator, int denominator);
        Fraction(float other);

        // Getters:
        int getNumerator();
        int getDenominator();
        Fraction getFraction();
        
        // Setters:
        void setNumerator(int anumerator);
        void setDenominator(int denominator);

        // To string:
        string toString() const;

        // Return fraction in reduced form:
        void reduce();

        // The + operators to add two fractions and return their sum as another fraction in reduced form:
        friend Fraction operator+(const Fraction& , const Fraction&);
        friend Fraction operator+(float , const Fraction&);
        friend Fraction operator+(const Fraction& , float);

        // The - operators to subtract two fractions and return their difference as another fraction in reduced form:
        friend Fraction operator-(const Fraction& , const Fraction&);
        friend Fraction operator-(float , const Fraction&);
        friend Fraction operator-(const Fraction&, float);

        // The * operators to multiply two fractions and return their product as another fraction in reduced form:
        friend Fraction operator*(const Fraction& , const Fraction&);
        friend Fraction operator*(float , const Fraction&);
        friend Fraction operator*(const Fraction& , float);

        // The / operators to divide two fractions and return their quotient as another fraction in reduced form:
        friend Fraction operator/(const Fraction& , const Fraction&) ;
        friend Fraction operator/(float , const Fraction&);
        friend Fraction operator/(const Fraction& , float);

        // The == operators to compare two fractions for equality and return true or false:
        friend bool operator==(const Fraction& , const Fraction&);
        friend bool operator==(const Fraction& , float);
        friend bool operator==(float , const Fraction&);

        // The > operators to compare two fractions and return true or false:
        friend bool operator>(const Fraction& , const Fraction&);
        friend bool operator>(const Fraction& , float);
        friend bool operator>(float , const Fraction&);

        // The >= operators to compare two fractions and return true or false:
        friend bool operator>=(const Fraction& , const Fraction&);
        friend bool operator>=(const Fraction& , float);
        friend bool operator>=(float , const Fraction&);

        // The < operators to compare two fractions and return true or false:
        friend bool operator<(const Fraction& , const Fraction&);
        friend bool operator<(const Fraction& , float);
        friend bool operator<(float , const Fraction&);

        // The <= operators to compare two fractions and return true or false:
        friend bool operator<=(const Fraction& , const Fraction&);
        friend bool operator<=(const Fraction& , float);
        friend bool operator<=(float , const Fraction&);

        // The prefix ++ operator that adds 1 to the fraction:
        Fraction& operator++();

        // The prefix -- operator that substracts 1 from the fraction:
        Fraction& operator--();

        // The postfix ++ operator that adds 1 to the fraction:
        Fraction operator++(int);

        // The postfix -- operator that substracts 1 from the fraction:
        Fraction operator--(int);

        // The << operator to print a fraction to an output stream in the format “numerator/denominator”:
        friend std::ostream &operator<<(std::ostream &stream, const Fraction &fruc);

        // The >> operator to read a fraction from an input stream by taking two integers as input:
        friend std::istream& operator>>(std::istream& strem, Fraction& frac);
    };
}