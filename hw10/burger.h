// Programmer: Nathan Burlis & Mathew Romine
// Date: 11/08/2018
// Filename: burger.h
// Course number & section: 1570 C
// Instructor name: Yeung
// Purpose: potato123

#ifndef BURGER_H
#define BURGER_H

#include <iostream>

using namespace std;


/**************DECLARATIONS*******************************/

const string ONE_PATTY = "Single";
const string TWO_PATTY = "Double";
const string THREE_PATTY = "Triumph";
const string FOUR_PATTY = "Quad";

const string ZERO_BACON = "Health-Master";
const string ONE_BACON = "Bacon";
const string TWO_BACON = "Wilber";
const string THREE_BACON = "Klogger";
const string FOUR_BACON = "Godly";

const string ZERO_PICKLE = "Tasteless";
const string ONE_PICKLE = "Pickly";
const string TWO_PICKLE = "Garden-Fresh";
const string THREE_PICKLE = "Kermit";
const string FOUR_PICKLE = "Too-Green";

const string ZERO_SAUCE = "Sauceless";
const string ONE_SAUCE = "Sauce-Boss";

const string ZERO_CHEESE = "Crime-Against-Humanity";
const string ONE_CHEESE = "Cheesy";

const string VEGGIE_CASE = "Krusty Veggie Burger";
const string KORONARY_CASE = "Krusty Koronary Burger";


//Class declaration
class Burger 
{
  public:
    // Cunstructors
    // Description: If user wants to create specific burger, this function
    //              allows that
    // Pre: User enters patty, bacon, pickle amounts, states whether cheese,
    //      sauce, and pathogen are on burger
    // Post: Burger with specifications is created
    Burger(const int pat, const int bac, const int pick,
           const bool isCheese, const bool isSauce, const bool isPathogen);
    
    //Description: Creates random burger
    //Pre: None
    //Post: Random burger is created
    Burger();

    //Getter functions
    //Description: Gets ingredient amount for the listed ingredient
    //Pre: None
    //Post: Ingredient amount is returned
    int getPatties() const;
    int getBacon() const;
    int getPickles() const;
    
    //Description: Gets the price of the burger
    //Pre: None
    //Post: Price is returned
    double getPrice() const;

    //Description: States whether the burger has the given ingredient
    //Pre: None
    //Post: Ingredient status is returned
    bool isCheese() const;
    bool isSauce() const;
    bool isPathogen() const;

    //Description: Gets the name of the burger
    //Pre: None
    //Post: Name of burger is returned
    string getName() const;

    //Description: States whether the burger is valid based on its contents
    //Pre: None
    //Post: Valid status is returned
    bool validEntry() const;

    //insertion operator overload
    //Description: Overloads the insertion operator to output burger
    //             ingredients
    //Pre: Created burger exist
    //Post: Burger ingredients are outputed 
    friend ostream& operator<<(ostream& os, const Burger& rhs);

  private:
    //variables that correlate with the burger specs
    int m_patties;
    int m_bacon;
    int m_pickles;
    bool m_isCheese;
    bool m_isSauce;
    bool m_isPathogen;
    double m_price;
    string m_name;
    
    //private functions
    //Description: Name of burger is generated based on its attributes
    //Pre: Burger is valid
    //Post: Burger name is created
    void createName();

    //Description: Determines if the burger has a pathogen
    //Pre: None
    //Post: Pathogen status is applied to m_isPathogen;
    void pathogen();
};

#endif