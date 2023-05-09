#include <iostream>
#include <string>
#include <stdio.h>
#include "Fraction.hpp"
using namespace std;

namespace ariel{

    // Constructors:
    Fraction::Fraction(){
        this->numerator = 0;
        this->denominator = 1;
    }

    Fraction::Fraction(int numerator, int denominator){
        if (denominator == 0) throw std::runtime_error("Error: Divide By Zero");
        this->numerator = numerator;
        this->denominator = denominator;
        this->reduce();
    }

    Fraction::Fraction(float other){
        this->numerator = other * 1000;
        this->denominator = 1000;
        this->reduce();
    }

    // Getters:
    int Fraction::getNumerator(){
        return this->numerator;
    }
    
    int Fraction::getDenominator(){
        return this->denominator;
    }

    Fraction Fraction::getFraction(){
        int newNumerator = this->getNumerator();
        int newDenominator = this->getDenominator();
        return Fraction(newNumerator,newDenominator);
    }

    // Setters:
    void Fraction::setNumerator(int numerator){
        this->numerator = numerator;
    }
    
    void Fraction::setDenominator(int denominator){
        if (denominator == 0) throw std::runtime_error("Error: Divide By Zero");
        this->denominator = denominator;
    }

    // To string:
    string Fraction::toString() const{
        return to_string(this->numerator) + " / " + to_string(this->denominator) ;
    }

    /*// Returns the largest positive integer that divides two numbers without leaving a remainder
    // Calculated using "Euclidean" algorithm that repeatedly divides the larger number by the smaller number and takes the remainder
    // This process is repeated until the remainder is zero
    int Fraction::gcd(int num1, int num2) {
        if (num2 == 0) return num1; // If num2 == 0, the GCD is num1
        return gcd(num2, num1 % num2); // Else calculate the GCD of num2 and (num1 % num2)
    }*/

    // Return fraction in reduced form:
    void Fraction::reduce(){
        if(this->numerator == 0) this->denominator = 1;

        // Initialize variables for the numerator and denominator
        int numerator = this->numerator;
        int denominator = this->denominator;
        
        // Continue dividing the numerator and denominator by 2 until neither is even
        while (numerator % 2 == 0 && denominator % 2 == 0) {
            numerator /= 2;
            denominator /= 2;
        }

        // Continue dividing the numerator and denominator by odd numbers until they cannot be divided further
        for (int i = 3; i <= min(numerator, denominator); i += 2) {
            while (numerator % i == 0 && denominator % i == 0) {
                numerator /= i;
                denominator /= i;
            }
        }
        
        // Update the numerator and denominator of the Fraction object
        this->numerator = numerator;
        this->denominator = denominator;
    }


    // The + operators to add two fractions and return their sum as another fraction in reduced form:
    Fraction operator+(const Fraction &frac1, const Fraction &frac2){
        int newNumerator = (frac1.numerator * frac2.denominator) + (frac1.denominator * frac2.numerator);
        int newDenominator = frac1.denominator * frac2.denominator;
        Fraction newFraction = Fraction(newNumerator, newDenominator);
        return newFraction;
    }
    
    Fraction operator+(float f_frac, const Fraction &frac){
        Fraction newFraction(f_frac);
        return newFraction + frac;
    }

    Fraction operator+(const Fraction &frac, float f_frac){
        Fraction newFraction(f_frac);
        return newFraction + frac;
    }

    // The - operators to subtract two fractions and return their difference as another fraction in reduced form:
    Fraction operator-(const Fraction &frac1, const Fraction &frac2){
        int newNumerator = (frac1.numerator * frac2.denominator) - (frac1.denominator * frac2.numerator);
        int newDenominator = frac1.denominator * frac2.denominator;
        Fraction newFraction = Fraction(newNumerator, newDenominator);
        return newFraction;
    }

    Fraction operator-(float f_frac, const Fraction &frac){
        Fraction newFraction(f_frac);
        return newFraction - frac;
    }

    Fraction operator-(const Fraction &frac, float f_frac){
        Fraction newFraction(f_frac);
        return frac - newFraction;
    }

    // The * operators to multiply two fractions and return their product as another fraction in reduced form:
    Fraction operator*(const Fraction &frac1, const Fraction &frac2){
        int newNumerator = frac1.numerator * frac2.numerator ;
        int newDenominator = frac1.denominator * frac2.denominator;
        Fraction newFraction = Fraction(newNumerator, newDenominator);
        return newFraction;
    }
    
    Fraction operator*(float f_frac, const Fraction &frac){
        Fraction newFraction(f_frac);
        return newFraction * frac;
    }

    Fraction operator*(const Fraction &frac, float f_frac){
        Fraction newFraction(f_frac);
        return frac * newFraction;
    }

    // The / operators to divide two fractions and return their quotient as another fraction in reduced form:
    Fraction operator/(const Fraction &frac1, const Fraction &frac2){
        if (frac2.numerator == 0) throw std::runtime_error("Error: Divide By Zero");
        int newNumerator = frac1.numerator * frac2.denominator;
        int newDenominator = frac1.denominator * frac2.numerator;
        Fraction newFraction(newNumerator, newDenominator);
        return newFraction;
    }

    Fraction operator/(float f_frac, const Fraction &frac){
        if (frac.numerator == 0) throw std::runtime_error("Error: Divide By Zero");
        Fraction newFraction(f_frac);
        return newFraction / frac;
    }

    Fraction operator/(const Fraction &frac, float f_frac){
        if (f_frac == 0) throw std::runtime_error("Error: Divide By Zero");
        Fraction newFraction(f_frac);
        return frac / newFraction;
    }

    // The == operators to compare two fractions for equality and return true or false:
    bool operator==(const Fraction &frac1, const Fraction &frac2){
        return (frac1.numerator == frac2.numerator) && (frac1.denominator == frac2.denominator);
    }

    bool operator==(float f_frac, const Fraction &frac){
        Fraction newFraction(f_frac);
        return newFraction == frac;
    }

    bool operator==(const Fraction &frac, float f_frac){
        Fraction newFraction(f_frac);
        return frac == newFraction;
    }

    // The > operators to compare two fractions and return true or false:
    bool operator>(const Fraction &frac1, const Fraction &frac2){
        int frac1Size = frac1.numerator * frac2.denominator;
        int frac2Size = frac2.numerator * frac1.denominator;

        // Compare the numerators of the two fractions
        return frac1Size > frac2Size;
    }
    
    bool operator>(float f_frac, const Fraction &frac){
        Fraction newFraction(f_frac);
        return newFraction > frac;
    }

    bool operator>(const Fraction &frac, float f_frac){
        Fraction newFraction(f_frac);
        return frac > newFraction;
    }

    // The >= operators to compare two fractions and return true or false:
    bool operator>=(const Fraction &frac1, const Fraction &frac2){
        int frac1Size = frac1.numerator * frac2.denominator;
        int frac2Size = frac2.numerator * frac1.denominator;

        // Compare the numerators of the two fractions
        return frac1Size >= frac2Size;
    }

    bool operator>=(float f_frac, const Fraction &frac){
        Fraction newFraction(f_frac);
        return newFraction >= frac;
    }

    bool operator>=(const Fraction &frac, float f_frac){
        Fraction newFraction(f_frac);
        return frac >= newFraction;
    }

    // The < operators to compare two fractions and return true or false:
    bool operator<(const Fraction &frac1, const Fraction &frac2){
        int frac1Size = frac1.numerator * frac2.denominator;
        int frac2Size = frac2.numerator * frac1.denominator;

        // Compare the numerators of the two fractions
        return frac1Size < frac2Size;
    }

    bool operator<(float f_frac, const Fraction &frac){
        Fraction newFraction(f_frac);
        return newFraction < frac;
    }

    bool operator<(const Fraction &frac, float f_frac){
        Fraction newFraction(f_frac);
        return frac < newFraction;
    }

    // The <= operators to compare two fractions and return true or false:
    bool operator<=(const Fraction &frac1, const Fraction &frac2){
        int frac1Size = frac1.numerator * frac2.denominator;
        int frac2Size = frac2.numerator * frac1.denominator;

        // Compare the numerators of the two fractions
        return frac1Size <= frac2Size;
    }

    bool operator<=(float f_frac, const Fraction &frac){
        Fraction newFraction(f_frac);
        return newFraction <= frac;
    }

    bool operator<=(const Fraction &frac, float f_frac){
        Fraction newFraction(f_frac);
        return frac <= newFraction;
    }

    // The prefix ++ operator that adds 1 to the fraction:
    Fraction &Fraction::operator++(){
        Fraction temp(this->numerator,this->denominator);
        temp = temp + 1;
        this->numerator = temp.getNumerator();
        this->denominator = temp.getDenominator();

        return *this;
    }

    // The prefix -- operator that substracts 1 from the fraction:
    Fraction &Fraction::operator--(){
        Fraction temp(this->numerator,this->denominator);
        temp = temp - 1;
        this->numerator = temp.getNumerator();
        this->denominator = temp.getDenominator();

        return *this;
    }

    // The postfix ++ operator that adds 1 to the fraction:
    Fraction Fraction::operator++(int num){
        Fraction temp(this->numerator,this->denominator);
        temp = temp + 1;
        this->numerator = temp.getNumerator();
        this->denominator = temp.getDenominator();

        return temp;
    }

    // The postfix -- operator that substracts 1 from the fraction:
    Fraction Fraction::operator--(int num){
        Fraction temp(this->numerator,this->denominator);
        temp = temp - 1;
        this->numerator = temp.getNumerator();
        this->denominator = temp.getDenominator();

        return temp;
    }

    // The << operator to print a fraction to an output stream in the format “numerator/denominator”:
    std::ostream &operator<<(std::ostream &stream, const Fraction &frac){
        stream << frac.toString() << endl;
        return stream;
    }

    // The >> operator to read a fraction from an input stream by taking two integers as input:
    std::istream& operator>>(std::istream& stream, Fraction& frac){
        char c;
        stream >> frac.numerator >> c >> frac.denominator;
        if (c != '/') cout << "Error: Invalid character" << endl;
        return stream;
    }
}