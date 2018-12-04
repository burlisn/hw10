// Programmer: Nathan Burlis & Mathew Romine
// Date: 11/08/2018
// Filename: customer.cpp
// Course number & section: 1570 C
// Instructor name: Yeung
// Purpose: test test

#include "customer.h"
#include "burger.h"
#include "burgermeister.h"

using namespace std;

/***************Constructor********************************/
Customer::Customer()
{
  Customer::randomName();
  m_cashMoney=(rand()%51)+25;
  m_weight=(rand()%161)+90;
  m_chol=(rand()%271)+30;
  m_isAlive=1;
  m_hp=rand()%100+1;
  m_isContestant=1;
  m_maxWeight=m_weight+80;
  m_isPath=0;
  m_isVomiting=0;
}
/**********************************************************/

/*******************Public functions(but not getters)*****************/
//Eat function
void Customer::eat(const Burger mystery, Burgermeister& krusty)
{
  if (mystery.validEntry())
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

    //HP loss from eating burger
    hpLoss();

    //Dead boy?
    if(mystery.isPathogen())
    {
      int diceRoll=rand()%102+1;
      if(diceRoll>m_hp)
      {
        m_isPath=1;
      }
      else
      {
        vomit();
      }
    }
    grimReaper(krusty);

    //Pay Krusty
    krusty+=mystery.getPrice();
  }
  else
  {
    cout<<"You are nothing!"<<endl;
  }
  return;
}

//Determins if the customer can eat the burger based upon their stats
bool Customer::canEat(const Burger burg) const
{
  return(m_isAlive&&m_cashMoney>=burg.getPrice()&&m_isContestant);
}

//Vomits
void Customer::vomit()
{
  cout<<m_name<<"*vomits*"<<endl;
  if(m_hp/2>0) //Accounts for the specific case where their hp is 1 and
  {            //vomiting would make their hp=0
    m_hp=m_hp/2;
  }
  else
  {
    m_hp=1;  
  }
  m_isVomiting=1;
  return;
}

//If conditions are right, customer dies!
void Customer::grimReaper(Burgermeister& krusty)
{
  if(m_chol>300||m_weight>=m_maxWeight||m_isPath||m_hp==0)
  {
    m_isAlive=0;
    m_hp=0;
    m_isContestant=0;
    krusty.payDeath();
  }
  return;
}

//Subtracts hp for eating burger, doesn't let hp go below 0
void Customer::hpLoss()
{
  if(m_hp-2>=0)
  {
    m_hp=m_hp-2;
  }
  else
  {
    m_hp=0;
  }
  return;
}

void Customer::allClear()
{
  m_isVomiting=0;
  return;
}

void Customer::chuck(const Burger burg)
{
  m_hp+=2;
  m_cashMoney-=burg.getPrice();
  return;
}

bool Customer::canChuck(const Burger burg) const
{
  return(m_cashMoney>=burg.getPrice());
}

//insertion operator overload
ostream& operator<<(ostream& os, const Customer& rhs)
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
    <<", "<<rhs.chol()<<" IBU and is "<<deadAlive<<" with "<<rhs.hp()
    <<" health.";
  return os;
}
/*******************************************************/

/***********Setter functions*****************/
void Customer::setCashMoney(double money)
{
  m_cashMoney=money;
}

void Customer::disqualify()
{
  m_isContestant=0;
}
/********************************************/

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

int Customer::hp() const
{
  return(m_hp);
}

bool Customer::getVomiting() const
{
  return(m_isVomiting);
}
/************************************************/

/********Private functions************************/
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
/*****************************************************/