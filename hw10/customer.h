// Programmer: Nathan Burlis & Mathew Romine
// Date: 11/08/2018
// Filename: customer.h
// Course number & section: 1570 C
// Instructor name: Yeung
// Purpose:

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "burger.h"
#include "burgermeister.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

//CONSTANT DECLARATION
const double PI=3.14159;

class Customer
{
  public:
    //Constructors
    //Description: Creates a random Customer
    //Pre: Nothing
    //Post: Random Customer with various attributes is created (note, only
    //     24 Customers possible)
    Customer();
    
    //Eat function
    //Descrition: Customer eats a burger and attributes are affected
    //Pre: Customer is created and burger is created
    //Post: Customer money, weight, cholesterol, and Alive status is affected
    //      by the eaten burger
    void eat(const Burger mystery, Burgermeister& krusty);

    bool canEat(const Burger burg) const;

    void vomit();

    void grimReaper();

    void hpLoss();

    void allClear();

    void chuck(const Burger burg);
    
    bool canChuck(const Burger burg) const;

    //Getter functions
    //Descriptions: Functions return the status of the attributes when called
    //Pre: Nothing
    //Post: Wanted attribute is returned
    double cashMoney() const;
    double weight() const;
    short chol() const;
    bool isAlive() const;
    string name() const;
    int hp() const;
    bool getVomiting() const;

    //insertion operator overlaod
    //Description: Overloads the insertion operator to output status of
    //            member variables of Customer
    //Pre: Customer is created
    //Post: Status of member variables is outputed
    friend ostream& operator<<(ostream& os, const Customer& rhs);

  private:
    string m_name;
    double m_cashMoney;
    double m_weight;
    short m_chol; //Cholesterol level
    bool m_isAlive; //Is the Customer alive?
    int m_hp; //Customers health points
    bool m_isContestant; //Is the Customer still a contestant?
    bool m_isPath; //True if no pathogen
    bool m_isVomiting;

    int m_maxWeight; //Get's initialized to the customers original weight+80

    int m_nameCount=0;//Where the count is on the name file

    //Description: Gets a "random" name for the Customer from the file
    //Pre: None
    //Post: Random name from the file is pulled for a new Customer
    void randomName();
};

#endif