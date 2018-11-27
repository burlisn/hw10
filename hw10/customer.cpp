// Programmer: Nathan Burlis & Mathew Romine
// Date: 11/08/2018
// Filename: customer.cpp
// Course number & section: 1570 C
// Instructor name: Yeung
// Purpose: wowie zowie

#include "customer.h"
#include "burger.h"

using namespace std;

//Constructor
Customer::Customer()
{
  Customer::randomName();
  m_cashMoney=(rand()%51)+25;
  m_weight=(rand()%161)+90;
  m_chol=(rand()%271)+30;
  m_isAlive=1;
}

//Eat function
void Customer::eat(const Burger mystery)
{
  if(mystery.validEntry())
  {
    //Cash money dolla dolla bills yall
    m_cashMoney=m_cashMoney-mystery.getPrice();

    //Cholesterol gain
    m_chol=m_chol+2.5*mystery.getBacon()+(PI/2)*mystery.getPatties()+m_weight 
    /((mystery.getPickles()+1)*10);

    //Weight increase
    m_weight=m_weight+0.5*pow(mystery.getPatties(),2)+(1/8)*
    pow(mystery.getBacon(),2)-mystery.getPickles()/4+1.2*mystery.isCheese()+
    2.1*mystery.isSauce();

    //Dead boy?
    if(mystery.isPathogen())
    {
      m_isAlive=0;
    }
    else
    {
      m_isAlive=1;
    }
  }
  else
  {
    cout<<"You are nothing!"<<endl;
  }
  return;
}

//insertion operator overload
ostream& operator<<(ostream& os, const Customer rhs)
{
  string deadAlive;
  if(rhs.isAlive())
  {
    deadAlive="ALIVE";
  }
  else
  {
    deadAlive="DEAD";
  }
  os<<rhs.name()<<" weighs "<<rhs.weight()<<" lbs, has $"<<rhs.cashMoney()
    <<","<<rhs.chol()<<" IBU and is "<<deadAlive<<".";
  return os;
}

/*********Getter functions******************/
double Customer::cashMoney() const
{
  return(m_cashMoney);
}

double Customer::weight() const
{
  return(m_weight);
}

short Customer::chol() const
{
  return(m_chol);
}

bool Customer::isAlive() const
{
  return(m_isAlive);
}

string Customer::name() const
{
  return(m_name);
}
/************************************************/

//Private functions
//Get's a random name from the names list
void Customer::randomName()
{
  ifstream names;
  static int numRun=0;
  names.open("simpson_names.dat");
  for(int i=0;i<=numRun;i++)
  {
    getline(names,m_name);
  }
  numRun++;
  names.close();
  return;
}