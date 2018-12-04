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
#include "helper.h"

#include <iostream>

using namespace std;

int main()
{
  srand(time(NULL));

  cout.setf(ios::fixed); 
  cout.setf(ios::showpoint); 
  cout.precision(2);
  cout.setf(ios::boolalpha);

  const int SIZE=15;
  Burgermeister krusty("Krusty",100);
  int roundNumber=1;
  bool contest=1; //While contest is true, the contest goes on!
  Customer customer[SIZE];

  for(int i=0;i<SIZE;i++)
  {
    cout<<customer[i]<<endl;
  }

  cout<<endl;

  while(contest)
  {
    contest=0; //Ready to end contest for every round
    cout<<"Round "<<roundNumber<<endl;
    for(int i=0;i<SIZE;i++)
    {
      Burger a;
      if(customer[i].canEat(a))
      {
        cout<<customer[i]<<" eats "<<a.getName()<<endl;
        customer[i].eat(a,krusty);
        // cout<<customer[i]<<endl;
        if(customer[i].getVomiting())
        {
          chainReaction(customer,SIZE,i,krusty);
          krusty.payVomit(); //Krusty pays $5 for customer vomiting
          customer[i].allClear();
        }
        contest=1; //Since a customer ate, contest still runs
      }
    }
    roundNumber++;
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
