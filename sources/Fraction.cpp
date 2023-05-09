#include <iostream>
#include <string>
#include <stdio.h>
#include <limits> // For numeric_limits
#include <stdexcept> // For overflow_error
#include <numeric> // For gcd
#include "Fraction.hpp"
using namespace std;

namespace ariel{

    // Constructors:
    Fraction::Fraction(){
        this->numerator = 0;
        this->denominator = 1;
    }

    Fraction::Fraction(int numerator, int denominator){
        if (denominator == 0) throw std::invalid_argument("Error: division by zero");
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

    // Setters:
    void Fraction::setNumerator(int numerator){
        this->numerator = numerator;
    }
    
    void Fraction::setDenominator(int denominator){
        if (denominator == 0) throw std::invalid_argument("Error: division by zero");
        this->denominator = denominator;
    }

    // To string:
    string Fraction::toString() const{
        return to_string(this->numerator) + " / " + to_string(this->denominator) ;
    }

    // Return fraction in reduced form:
    void Fraction::reduce() {

        // If numerator is 0, set denominator to 1 and return
        if (this->numerator == 0) {
            this->denominator = 1;
            return;
        }

        // If denominator is negative, flip sign of both numerator and denominator
        if(this->denominator < 0){
            this->numerator = -( this->numerator);
            this->denominator = -( this->denominator);
        }

        int numerator_sign = 1; // Initialize variable to hold sign of numerator
        int denominator_sign = 1; // Initialize variable to hold sign of denominator

        // If numerator is negative, store its sign and make it positive
        if (this->numerator < 0){
            numerator_sign = -1;
            this->numerator = -(this->numerator);
        }
        
        // If denominator is negative, store its sign and make it positive
        if (this->denominator < 0){
            denominator_sign = -1;
            this->denominator = -(this->denominator);
        }

        // Calculate the GCD of numerator and denominator
        int gcd = std::gcd(this->numerator, this->denominator);

        // Divide numerator and denominator by the GCD and store the signs
        this->numerator = numerator_sign * (this->numerator / gcd);
        this->denominator = denominator_sign * (this->denominator / gcd);
    }



    // The + operators to add two fractions and return their sum as another fraction in reduced form:
    Fraction operator+(const Fraction &frac1, const Fraction &frac2){

        // Multiply the numerators and denominators separately to prevent overflow
        long long num1 = static_cast<long long>(frac1.numerator) * static_cast<long long>(frac2.denominator);
        long long num2 = static_cast<long long>(frac2.numerator) * static_cast<long long>(frac1.denominator);

        // Calculate the new numerator and check for overflow
        long long new_num = num1 + num2;
        if (new_num > std::numeric_limits<int>::max() || new_num < std::numeric_limits<int>::min()) throw std::overflow_error("Error: overflow");

        // Calculate the new denominator
        int new_den = frac1.denominator * frac2.denominator;

        // Create a new Fraction object with the new numerator and denominator
        Fraction result = Fraction(static_cast<int>(new_num), new_den);

        // Return the new Fraction object
        return result;
    }
    
    Fraction operator+(float f_frac, const Fraction &frac){

        // Creates a new fraction from the given float
        Fraction new_Fraction(f_frac);

        // Calculate the sum of two fractions
        return new_Fraction + frac;
    }

    Fraction operator+(const Fraction &frac, float f_frac){

        // Creates a new fraction from the given float
        Fraction new_Fraction(f_frac);

        // Calculate the sum of two fractions
        return new_Fraction + frac;
    }

    // The - operators to subtract two fractions and return their difference as another fraction in reduced form:
    Fraction operator-(const Fraction &frac1, const Fraction &frac2){

        // Multiply the numerators and denominators separately to prevent overflow
        long long num1 = static_cast<long long>(frac1.numerator) * static_cast<long long>(frac2.denominator);
        long long num2 = static_cast<long long>(frac2.numerator) * static_cast<long long>(frac1.denominator);

        // Calculate the new numerator and check for overflow
        long long new_num = num1 - num2;
        if (new_num > std::numeric_limits<int>::max() || new_num < std::numeric_limits<int>::min()) throw std::overflow_error("Error: overflow");

        // Calculate the new denominator
        int new_den = frac1.denominator * frac2.denominator;

        // Create a new Fraction object with the new numerator and denominator
        Fraction result = Fraction(static_cast<int>(new_num), new_den);

        // Return the new Fraction object
        return result;
    }


    Fraction operator-(float f_frac, const Fraction &frac){

        // Creates a new fraction from the given float
        Fraction new_Fraction(f_frac);

        // Calculate the subtraction of two fractions
        return new_Fraction - frac;
    }

    Fraction operator-(const Fraction &frac, float f_frac){

        // Creates a new fraction from the given float
        Fraction new_Fraction(f_frac);

        // Calculate the subtraction of two fractions
        return frac - new_Fraction;
    }

    // The * operators to multiply two fractions and return their product as another fraction in reduced form:
    Fraction operator*(const Fraction &frac1, const Fraction &frac2){

        // Calculate the new numerator
        long long new_num = static_cast<long long>(frac1.numerator) * static_cast<long long>(frac2.numerator);

        // Calculate the new denominator
        long long new_den = static_cast<long long>(frac1.denominator) * static_cast<long long>(frac2.denominator);

        // Check for overflow in both the numerator and denominator
        if (new_num > std::numeric_limits<int>::max() || new_num < std::numeric_limits<int>::min() || new_den > std::numeric_limits<int>::max() || new_den < std::numeric_limits<int>::min()) throw std::overflow_error("Error: overflow");

        // Create a new Fraction object with the new numerator and denominator
        Fraction result = Fraction(static_cast<int>(new_num), static_cast<int>(new_den));

        // Return the new Fraction object
        return result;
    }

    
    Fraction operator*(float f_frac, const Fraction &frac){

        // Creates a new fraction from the given float
        Fraction new_Fraction(f_frac);

        // Calculate the multiplication of two fractions
        return new_Fraction * frac;
    }

    Fraction operator*(const Fraction &frac, float f_frac){

        // Creates a new fraction from the given float
        Fraction new_Fraction(f_frac);

        // Calculate the multiplication of two fractions
        return frac * new_Fraction;
    }

    // The / operators to divide two fractions and return their quotient as another fraction in reduced form:
    Fraction operator/(const Fraction &frac1, const Fraction &frac2){

        // Check if the denominator of the second fraction is zero
        if (frac2.numerator == 0) throw std::runtime_error("Error: division by zero");
        
        // Calculate the new numerator and denominator
        long long new_num = static_cast<long long>(frac1.numerator) * static_cast<long long>(frac2.denominator);
        long long new_den = static_cast<long long>(frac1.denominator) * static_cast<long long>(frac2.numerator);

        // Check for overflow in both the numerator and denominator
        if (new_num > std::numeric_limits<int>::max() || new_num < std::numeric_limits<int>::min() || new_den > std::numeric_limits<int>::max() || new_den < std::numeric_limits<int>::min()) throw std::overflow_error("Error: overflow");

        // Create a new Fraction object with the new numerator and denominator
        Fraction result = Fraction(static_cast<int>(new_num), static_cast<int>(new_den));

        // Return the new Fraction object
        return result;
    }

    Fraction operator/(float f_frac, const Fraction &frac){
        if (frac.numerator == 0) throw std::runtime_error("Error: Divide By Zero");

        // Creates a new fraction from the given float
        Fraction new_Fraction(f_frac);

        // Calculate the division of two fractions
        return new_Fraction / frac;
    }

    Fraction operator/(const Fraction &frac, float f_frac){
        if (f_frac == 0) throw std::runtime_error("Error: Divide By Zero");

        // Creates a new fraction from the given float
        Fraction newFraction(f_frac);

        // Calculate the division of two fractions
        return frac / newFraction;
    }

    // The == operators to compare two fractions for equality and return true or false:
    bool operator==(const Fraction &frac1, const Fraction &frac2){

        // Calculate the numerator and denominator of the difference between the two fractions
        int numerator = frac1.numerator * frac2.denominator - frac2.numerator * frac1.denominator;
        int denominator = frac1.denominator * frac2.denominator;

        // If the numerator is zero, the fractions are equal
        if (numerator == 0) return true;

        // Calculate the greatest common divisor of the numerator and denominator
        int gcd = std::gcd(numerator, denominator);

        // Reduce the numerator and denominator by their GCD
        numerator /= gcd;
        denominator /= gcd;

        // Return true if the numerator and denominator are equal to 1, false otherwise
        return numerator == 1 && denominator == 1;
    }


    bool operator==(float f_frac, const Fraction &frac){

        // Creates a new fraction from the given float
        Fraction newFraction(f_frac);

        // Performs a comparison between 2 fractions
        return newFraction == frac;
    }

    bool operator==(const Fraction &frac, float f_frac){

        // Creates a new fraction from the given float
        Fraction newFraction(f_frac);

        // Performs a comparison between 2 fractions
        return frac == newFraction;
    }

    bool operator!=(const Fraction& frac1, const Fraction& frac2){

        // Calculate the decimal value of each fraction by dividing the numerator by the denominator.
        double fraction_Value1 = static_cast<double>(frac1.numerator) / static_cast<double>(frac1.denominator);
        double fraction_Value2 = static_cast<double>(frac2.numerator) / static_cast<double>(frac2.denominator);

        // Define a tolerance level for floating-point comparisons
        double tolerance = 0.0001;

        // Check if the absolute difference between the two decimal values is greater than the tolerance level
        return std::abs(fraction_Value1 - fraction_Value2) > tolerance;
    }


    // The > operators to compare two fractions and return true or false:
    bool operator>(const Fraction &frac1, const Fraction &frac2){
        
        // Calculates the numerators after performing a common denominator
        int frac1Size = frac1.numerator * frac2.denominator;
        int frac2Size = frac2.numerator * frac1.denominator;

        // Compare the numerators of the two fractions
        return frac1Size > frac2Size;
    }
    
    bool operator>(float f_frac, const Fraction &frac){

        // Creates a new fraction from the given float
        Fraction newFraction(f_frac);

        // Compare between two fractions
        return newFraction > frac;
    }

    bool operator>(const Fraction &frac, float f_frac){

        // Creates a new fraction from the given float
        Fraction newFraction(f_frac);

        // Compare between two fractions
        return frac > newFraction;
    }

    // The >= operators to compare two fractions and return true or false:
    bool operator>=(const Fraction &frac1, const Fraction &frac2){

        // Calculates the numerators after performing a common denominator
        int frac1Size = frac1.numerator * frac2.denominator;
        int frac2Size = frac2.numerator * frac1.denominator;

        // Compare the numerators of the two fractions
        return frac1Size >= frac2Size;
    }

    bool operator>=(float f_frac, const Fraction &frac){

        // Creates a new fraction from the given float
        Fraction newFraction(f_frac);

        // Compare between two fractions
        return newFraction >= frac;
    }

    bool operator>=(const Fraction &frac, float f_frac){

        // Creates a new fraction from the given float
        Fraction newFraction(f_frac);

        // Compare between two fractions
        return frac >= newFraction;
    }

    // The < operators to compare two fractions and return true or false:
    bool operator<(const Fraction &frac1, const Fraction &frac2){

        // Calculates the numerators after performing a common denominator
        int frac1Size = frac1.numerator * frac2.denominator;
        int frac2Size = frac2.numerator * frac1.denominator;

        // Compare the numerators of the two fractions
        return frac1Size < frac2Size;
    }

    bool operator<(float f_frac, const Fraction &frac){

        // Creates a new fraction from the given float
        Fraction newFraction(f_frac);

        // Compare between two fractions
        return newFraction < frac;
    }

    bool operator<(const Fraction &frac, float f_frac){

        // Creates a new fraction from the given float
        Fraction newFraction(f_frac);

        // Compare between two fractions
        return frac < newFraction;
    }

    // The <= operators to compare two fractions and return true or false:
    bool operator<=(const Fraction &frac1, const Fraction &frac2){
        
        // Calculates the numerators after performing a common denominator
        int frac1Size = frac1.numerator * frac2.denominator;
        int frac2Size = frac2.numerator * frac1.denominator;

        // Compare the numerators of the two fractions
        return frac1Size <= frac2Size;
    }

    bool operator<=(float f_frac, const Fraction &frac){

        // Creates a new fraction from the given float
        Fraction newFraction(f_frac);

        // Compare between two fractions
        return newFraction <= frac;
    }

    bool operator<=(const Fraction &frac, float f_frac){

        // Creates a new fraction from the given float
        Fraction newFraction(f_frac);

        // Compare between two fractions
        return frac <= newFraction;
    }

    // The prefix ++ operator that adds 1 to the fraction:
    Fraction &Fraction::operator++() {

       // Increment the numerator by the denominator and update the fraction
        this->numerator += this->denominator;

        // Calculate the GCD of the numerator and denominator
        int gcd = std::gcd(this->numerator, this->denominator);

        // Reduce the numerator and denominator by their GCD
        this->numerator /= gcd;
        this->denominator /= gcd;

        // Return the updated fraction
        return *this;
    }


    // The prefix -- operator that substracts 1 from the fraction:
    Fraction &Fraction::operator--() {
        // Decrement the numerator by the denominator and update the fraction
        this->numerator -= this->denominator;

        // Calculate the GCD of the numerator and denominator
        int gcd = std::gcd(this->numerator, this->denominator);

        // Reduce the numerator and denominator by their GCD
        this->numerator /= gcd;
        this->denominator /= gcd;

        // Return the updated fraction
        return *this;
    }


    // The postfix ++ operator that adds 1 to the fraction:
    Fraction Fraction::operator++(int) {
        // Create a copy of the original fraction
        Fraction copy = *this;

        // Increment the fraction and return the old fraction
        ++(*this);
        return copy;
    }

    // The postfix -- operator that substracts 1 from the fraction:
    Fraction Fraction::operator--(int) {
        // Create a copy of the original fraction
        Fraction copy = *this;

        // Decrement the fraction and return the old fraction
        --(*this);
        return copy;
    }

    // The << operator to print a fraction to an output stream in the format “numerator/denominator”:
    std::ostream &operator<<(std::ostream &stream, const Fraction &frac) {

        // Create a copy of the fraction
        Fraction copy = frac;

        // If the denominator is negative, flip the signs of the numerator and denominator
        if (copy.getDenominator() < 0) {
            copy.setNumerator(-(copy.getNumerator()));
            copy.setDenominator(-(copy.getDenominator()));
        }

        // Output the fraction to the output stream
        stream << copy.getNumerator() << "/" << copy.getDenominator();
        return stream;
    }


    // The >> operator to read a fraction from an input stream by taking two integers as input:
    std::istream& operator>>(std::istream& stream, Fraction& frac){

        // Initialize variables for the numerator, denominator, and sign
        int numerator = 0;
        int denominator = 1;
        int sign = 1; // Positive

        // Read the numerator
        if (!(stream >> numerator)) throw std::runtime_error("Error: Failed to read numerator");

        // Check for negative sign
        char c = stream.peek(); 
        if (c == '-'){
            sign = -1; // Negative
            stream.ignore(1);
        }

        // Read the denominator
        if (!(stream >> denominator)) throw std::runtime_error("Error: Failed to read denominator");

        // Check for zero denominator
        if (denominator == 0) throw std::runtime_error("Error: Divide By Zero");

        // Set the numerator and denominator of the fraction
        frac.setNumerator(numerator * sign);
        frac.setDenominator(denominator);

        // Output stream
        return stream;
    }
}