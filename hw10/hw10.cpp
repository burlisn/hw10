// Programmer: Nathan Burlis & Mathew Romine
// Date: 12/05/2018
// Filename: hw10.cpp
// Course number & section: 1570 C
// Instructor name: Yeung
// Purpose:

#include <iostream>
#include "burger.h"
#include "customer.h"
#include "burgermeister.h"

#include <iostream>

using namespace std;

int main()
{
  srand(time(NULL));

  cout.setf(ios::fixed); 
  cout.setf(ios::showpoint); 
  cout.precision(2);
  cout.setf(ios::boolalpha);

  Burgermeister krusty("Krusty",100);
  int roundNumber=1;
  bool contest=1; //While contest is true, the contest goes on!
  Customer customer[15];

  for(int i=0;i<15;i++)
  {
    cout<<customer[i]<<endl;
  }

  while(contest)
  {
    cout<<"Round "<<roundNumber<<endl;
    for(int i=1;i<15;i++)
    {
      Burger a;
      if(customer[i].canEat(a))
      {
        cout<<customer[i].name()<<" eats "<<a.getName()<<endl;
        customer[i].eat(a,krusty);
      }
    }
    roundNumber++;
    if(roundNumber==5)
    {
      contest=0;
    }
  }


  /*
  for(int i=0;i<20;i++)
  {
    cout<<customer[0]<<endl;
    Burger a;
    cout<<a<<endl;
    customer[0].eat(a,krusty);
    cout<<krusty.getCashMoney()<<endl;
  }
  */
  return 0;
}
