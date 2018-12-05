// Programmer: Nathan Burlis & Mathew Romine
// Date: 12/04/2018
// Filename: burgermeister.h
// Course number & section: 1570 C
// Instructor name: Yeung
// Purpose: burgermeister.h holds the prototypes for all the functions
//          and variables that are held within the Burgermeister class (Krusty)

#ifndef BURGERMEISTER_H
#define BURGERMEISTER_H

#include <iostream>

using namespace std;

class Burgermeister
{
  public:
    // Description: Constructor that creates a Burgermeister
    // Pre: Name of Burgermeister and money should be arguments (in this
    //      program the name should be Krusty)
    // Post: Burgermeister is created
    Burgermeister(const string name, const double money);

    // Description: += operator overload for Burgermeister class. Should be
    //              used only with a double on the rhs and a burgermeister
    //              on the left hand side. Adds the double's value to the 
    //              Burgermeister's money
    // Pre: Burgermeister on the left hand side, double on the righthand side
    // Post: rhs money is added to the Burgermeister's money
    void operator+=(const double rhs);

    // Description: -= operator overload for Burgermeister class. Should be
    //              used only with a double on the rhs and a burgermeister
    //              on the lhs. Subtracts the doubl'e value from the
    //              Burgermeister's money
    // Pre: Burgermeister on the lhs, double on the rhs
    // Post: rhs money is subtracted from the Burgermeister's money
    void operator-=(const double rhs);

    // Getter functions
    // Description: getCashMoney will obtain the current amount of money either
    //              the customer or Krusty has.
    // Pre: None
    // Post: Will output the total amount of money of the subject
    double getCashMoney() const;
    
    // Description: getName is the function that outputs Krusty's name
    // Pre: None
    // Post: Will output Krusty's name when called
    string getName() const;

    // Description: This function's role is to subtract the amount from Krusty
    //              when one of his customer's vomits.
    // Pre:
    // Post: Will subtract $5 from Krusty's total money amount
    void payVomit();

    // Description: This function's role is to subtract the amount from Krusty
    //              when one of his customer's dies.
    // Pre: None
    // Post: Will subtract $5 from Krusty's total money amount
    void payDeath();

  private:
    string m_name;
    double m_cashMoney;
};

#endif