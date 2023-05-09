#include <iostream>
#include <string>
#include <stdio.h>
#include "Fraction.hpp"

namespace ariel{

    // Constructors:
    Fraction::Fraction(){
        this->numerator = 0;
        this->denominator = 1;
    }

    Fraction::Fraction(int numerator, int denominator){
        if (denominator == 0) throw std::runtime_error("Error: Divide By Zero");
        //need to perform
        this->numerator = 0;
        this->denominator = 1;
    }

    Fraction::Fraction(float other){
        //need to perform
        this->numerator = 0;
        this->denominator = 1;;
    }

    // Getters:
    int Fraction::getNumerator(){
        return this->numerator;
    }
    
    int Fraction::getDenominator(){
        return this->denominator;
    }

    Fraction Fraction::getFraction(){
        return Fraction(this->getNumerator(), this->getDenominator());
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
        //need to perform
        return "";
    }

    // Return fraction in reduced form:
    void Fraction::reduce(){
        //need to perform
    }

    // The + operators to add two fractions and return their sum as another fraction in reduced form:
    Fraction operator+(const Fraction &frac1, const Fraction &frac2){
        //need to perform
        Fraction franction;
        return franction;
    }
    
    Fraction operator+(float f_frac, const Fraction &frac){
        //need to perform
        Fraction franction;
        return franction;
    }

    Fraction operator+(const Fraction &frac, float f_frac){
        //need to perform
        Fraction franction;
        return franction;
    }

    // The - operators to subtract two fractions and return their difference as another fraction in reduced form:
    Fraction operator-(const Fraction &frac1, const Fraction &feac2){
        //need to perform
        Fraction franction;
        return franction;
    }

    Fraction operator-(float f_frac, const Fraction &frac){
        //need to perform
        Fraction franction;
        return franction;
    }

    Fraction operator-(const Fraction &frac, float f_frac){
        //need to perform
        Fraction franction;
        return franction;
    }

    // The * operators to multiply two fractions and return their product as another fraction in reduced form:
    Fraction operator*(const Fraction &frac1, const Fraction &frac2){
        //need to perform
        Fraction franction;
        return franction;
    }
    
    Fraction operator*(float f_frac, const Fraction &frac){
        //need to perform
        Fraction franction;
        return franction;
    }

    Fraction operator*(const Fraction &frac, float f_frac){
        //need to perform
        Fraction franction;
        return franction;
    }

    // The / operators to divide two fractions and return their quotient as another fraction in reduced form:
    Fraction operator/(const Fraction &frac1, const Fraction &frac2){
        //need to perform
        Fraction franction;
        return franction;
    }

    Fraction operator/(float f_frac, const Fraction &frac){
        //need to perform
        Fraction franction;
        return franction;
    }

    Fraction operator/(const Fraction &frac, float f_frac){
        //need to perform
        Fraction franction;
        return franction;
    }

    // The == operators to compare two fractions for equality and return true or false:
    bool operator==(const Fraction &frac1, const Fraction &frac2){
        //need to perform
        return false;
    }

    bool operator==(const Fraction &frac, float f_frac){
        //need to perform
        return false;
    }

    bool operator==(float f_frac, const Fraction &frac){
        //need to perform
        return false;
    }

    // The > operators to compare two fractions and return true or false:
    bool operator>(const Fraction &frac1, const Fraction &frac2){
        //need to perform
        return false;
    }

    bool operator>(const Fraction &frac, float f_frac){
        //need to perform
        return false;
    }
    
    bool operator>(float f_frac, const Fraction &frac){
        //need to perform
        return false;
    }

    // The >= operators to compare two fractions and return true or false:
    bool operator>=(const Fraction &frac1, const Fraction &frac2){
        //need to perform
        return false;
    }

    bool operator>=(const Fraction &frac, float f_frac){
        //need to perform
        return false;
    }

    bool operator>=(float f_frac, const Fraction &frac){
        //need to perform
        return false;
    }

    // The < operators to compare two fractions and return true or false:
    bool operator<(const Fraction &frac1, const Fraction &frac2){
        //need to perform
        return false;
    }

    bool operator<(const Fraction &frac, float f_frac){
        //need to perform
        return false;
    }

    bool operator<(float f_frac, const Fraction &frac){
        //need to perform
        return false;
    }

    // The <= operators to compare two fractions and return true or false:
    bool operator<=(const Fraction &frac1, const Fraction &frac2){
        //need to perform
        return false;
    }

    bool operator<=(const Fraction &frac, float f_frac){
        //need to perform
        return false;
    }

    bool operator<=(float f_frac, const Fraction &frac){
        //need to perform
        return false;
    }

    // The prefix ++ operator that adds 1 to the fraction:
    Fraction &Fraction::operator++(){
        //need to perform
        return *this;
    }

    // The prefix -- operator that substracts 1 from the fraction:
    Fraction &Fraction::operator--(){
        //need to perform
        return *this;
    }

    // The postfix ++ operator that adds 1 to the fraction:
    Fraction Fraction::operator++(int num){
        //need to perform
        Fraction franction;
        return franction;
    }

    // The postfix -- operator that substracts 1 from the fraction:
    Fraction Fraction::operator--(int num){
        //need to perform
        Fraction franction;
        return franction;
    }

    // The << operator to print a fraction to an output stream in the format “numerator/denominator”:
    std::ostream &operator<<(std::ostream &stream, const Fraction &fruc){
        //need to perform
        return stream;
    }

    // The >> operator to read a fraction from an input stream by taking two integers as input:
    std::istream& operator>>(std::istream& stream, Fraction& frac){
        //need to perform
        return stream;
    }
}