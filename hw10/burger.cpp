// Programmer: Nathan Burlis & Mathew Romine
// Date: 12/04/2018
// Filename: burger.cpp
// Course number & section: 1570 C
// Instructor name: Yeung
// Purpose: This file contains all the nessicary functions to create the names
//          for the burgers, as well as calculate the costs.

#include "burger.h"
#include "customer.h"

/***********CONSTRUCTORS**********/
Burger::Burger(const int pat, const int bac, const int pick,
               const bool isCheese, const bool isSauce, const bool isPathogen)
{
  m_patties=pat;
  m_bacon=bac;
  m_pickles=pick;
  m_isCheese=isCheese;
  m_isSauce=isSauce;
  m_isPathogen=isPathogen;
  Burger::createName();
  m_price=0.75*m_patties+0.5*m_bacon+0.25*m_pickles+0.5+m_isCheese*0.25+
        m_isSauce*0.1;
  if(!Burger::validEntry())
  {
    cout<<"Invalid burger entry!"<<endl;
  }
}

Burger::Burger()
{
  m_patties=(rand()%4)+1;
  m_bacon=rand()%5;
  m_pickles=rand()%5;
  m_isCheese=rand()%2;
  m_isSauce=rand()%2;
  Burger::pathogen();
  Burger::createName();
  m_price=0.75*m_patties+0.5*m_bacon+0.25*m_pickles+0.5+m_isCheese*0.25+
          m_isSauce*0.1;
}
//****************************************/

//-----------GETTER FUNCTIONS------------
int Burger::getPatties() const
{
  return (m_patties);
}

int Burger::getBacon() const
{
  return (m_bacon);
}

int Burger::getPickles() const
{
  return (m_pickles);
}

double Burger::getPrice() const
{
  return (m_price);
}

bool Burger::isCheese() const
{
  return (m_isCheese);
}

bool Burger::isSauce() const
{
  return (m_isSauce);
}

bool Burger::isPathogen() const
{
  return (m_isPathogen);
}

string Burger::getName() const
{
  return(m_name);
}
//---------------------------------


//Private functions
// 10% chance for burger pathogen
void Burger::pathogen()
{
  int x=rand()%10;
  if(x==5)
  {
    m_isPathogen=1;
  }
  else
  {
    m_isPathogen=0;
  }
  return;
}

// Checks to make sure burger is valid entry (if user entered)
bool Burger::validEntry() const
{
  bool isValid;
  if(m_patties>0&&m_patties<5&&m_bacon>-1&&m_bacon<5&&m_pickles>-1&&
     m_pickles<5)
  {
    isValid=true;
  }
  else
  {
    isValid=false;
  }
  return (isValid);
}

//Creates the name of the burger
void Burger::createName()
{
  string pattyName;
  string baconName;
  string pickleName;
  string cheeseName;
  string sauceName;

  switch (m_patties)
  {
    case 1:
      pattyName=ONE_PATTY;
      break;
    case 2:
      pattyName=TWO_PATTY;
      break;
    case 3:
      pattyName=THREE_PATTY;
      break;
    case 4:
      pattyName=FOUR_PATTY;
      break;
  }

  switch (m_bacon)
  {
    case 0:
      baconName=ZERO_BACON;
      break;
    case 1:
      baconName=ONE_BACON;
      break;
    case 2:
      baconName=TWO_BACON;
      break;
    case 3:
      baconName=THREE_BACON;
      break;
    case 4:
      baconName=FOUR_BACON;
      break;
  }

  switch (m_pickles)
  {
    case 0:
      pickleName=ZERO_PICKLE;
      break;
    case 1:
      pickleName=ONE_PICKLE;
      break;
    case 2:
      pickleName=TWO_PICKLE;
      break;
    case 3:
      pickleName=THREE_PICKLE;
      break;
    case 4:
      pickleName=FOUR_PICKLE;
      break;
  }

  switch (m_isCheese)
  {
    case 0:
      cheeseName=ZERO_CHEESE;
      break;
    case 1:
      cheeseName=ONE_CHEESE;
      break;
  }

  switch (m_isSauce)
  {
    case 0:
      sauceName=ZERO_SAUCE;
      break;
    case 1:
      sauceName=ONE_SAUCE;
      break;
  }

  m_name="Krusty "+cheeseName+" "+sauceName+" "+pattyName+" "+baconName+" "
         +pickleName+" Burger";
  
  if(m_pickles>=(m_patties+m_bacon))
  {
    m_name=VEGGIE_CASE;
  }
  if((m_patties+m_bacon)==6 && (m_pickles == 0 || m_pickles ==1))
  {
    m_name=KORONARY_CASE;
  }
  return;
}

//Insertion operator overload for Burger
ostream& operator<<(ostream& os, const Burger& rhs)
{
  if(rhs.validEntry())
  {
    os<<rhs.getName()<<",("<<rhs.getPatties()<<","<<rhs.getBacon()<<","
      <<rhs.getPickles()<<","<<rhs.isCheese()<<","<<rhs.isSauce()<<","
      <<rhs.isPathogen()<<")$"<<rhs.getPrice();
  }
  else
  {
    os<<"Invalid burger!";
  }
  return os;
}
