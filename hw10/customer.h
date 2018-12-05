// Programmer: Nathan Burlis & Mathew Romine
// Date: 11/08/2018
// Filename: customer.h
// Course number & section: 1570 C
// Instructor name: Yeung
// Purpose: customer.h holds the prototypes for all the functions and variables
//          that are held within the Customer class

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

    // Description: Determins whether a Customer can eat a Burger depending on
    //              the Burger stats and the customers stats
    // Pre: Customer must be alive, must be able to pay for the Burger, and
    //      must still be a contestant to eat
    // Post: Returns a boolean value determining whether or not a Customer can
    //       eat the given Burger
    bool canEat(const Burger burg) const;

    // Description: The customer vomits, and they make a vomit noise and lose
    //              half of their health
    // Pre: None
    // Post: Customer exclaims a vomit sound and loses half of their health
    void vomit();

    // Description: The grimReaper function decides the fate of the Customer
    //              depending on their stats. When called the grimReaper may
    //              kill the Customer if their cholesterol is over 300, or their
    //              weight exceeds their max weight, or if they are infected
    //              with a pathogen. It will also set them to a non-contestant
    //              if they die, or are already dead. It also has krusty pay 
    //              for their death.
    // Pre: krusty object must be passed in as a pass by reference argument
    // Post: If successful, the customer is dead, no longer a contestant,
    //       and krusty pays
    void grimReaper(Burgermeister& krusty);

    // Description: This function subtracts hp from eating a Burger. Was
    //              created so that your hp doensn't go below 0 when eating
    //              Burgers.
    // Pre: None
    // Post: hp is subtracted by 2, or becomes 0
    void hpLoss();

    // Description: Clears the Customer of their pathogen infection whether
    //              they vomit or die (vomit it gets expelled, die it dies too)
    // Pre: None
    // Post: Customer is cleared of pathogen
    void allClear();

    // Description: This function simulates the Customer throwing a Burger.
    //              When the Customer throws a Burger they gain 2 hp but must
    //              pay for the burger.
    // Pre: The Burger the Customer is going to throw should be passed in as
    //      the argument
    // Post: Customer's hp is increased by 2 and they pay for the Burger.
    void chuck(const Burger burg);
    
    // Description: This function returns a boolean value determining whether
    //              or not the Customer can throw the Burger. The customer 
    //              can throw the Burger if they can pay for it.
    // Pre: The Burger the Customer is going to throw should be passed in as
    //      the argument.
    // Post: The boolean value determining whether
    //       or not the Customer can throw the Burger is returned.
    bool canChuck(const Burger burg) const;

    //Setter functions
    // Description: Sets the values for the m_cashMoney variable
    // Pre: A money amount must be passed in as an argument
    // Post: Customer's cash money is that value
    void setCashMoney(double money);
    // Description: Set's the value m_contestant to 0, disqualifying them
    // Pre: None
    // Post: Customer is disqualified
    void disqualify();

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
    bool isContestant() const;
    int get_numEat() const;
    double get_weightGain() const;
    string statusOutput() const; //Outputs the string of DEAD or ALIVE rather
                                 //than bool value

    //insertion operator overlaod
    //Description: Overloads the insertion operator to output status of
    //            member variables of Customer
    //Pre: Customer is created
    //Post: Status of member variables is outputed
    friend ostream& operator<<(ostream& os, const Customer& rhs);

  private:
    double m_weightGain;
    string m_name;
    double m_cashMoney;
    double m_weight;
    short m_chol; //Cholesterol level
    bool m_isAlive; //Is the Customer alive?
    int m_hp; //Customers health points
    bool m_isContestant; //Is the Customer still a contestant?
    bool m_isPath; //True if no pathogen
    bool m_isVomiting;
    int m_numEat; //Amount of burgers eaten

    int m_maxWeight; //Get's initialized to the customers original weight+80

    int m_nameCount=0;//Where the count is on the name file

    //Description: Gets a "random" name for the Customer from the file
    //Pre: None
    //Post: Random name from the file is pulled for a new Customer
    void randomName();
};

#endif