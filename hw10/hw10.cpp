// Programmer: Nathan Burlis & Mathew Romine
// Date: 12/05/2018
// Filename: hw10.cpp
// Course number & section: 1570 C
// Instructor name: Yeung
// Purpose: Potato man sam

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

  cout<<"-------------------ORIGIANAL CONTESTANTS-------------------"<<endl;
  for(int i=0;i<SIZE;i++)
  {
    cout<<customer[i]<<endl;
  }
  cout<<"-----------------------------------------------------------"<<endl;

  cout<<endl;

  while(contest)
  {
    contest=0; //Ready to end contest for every round
    cout<<"------------------Round"<<roundNumber<<"------------------"<<endl;
    for(int i=0;i<SIZE;i++)
    {
      Burger a;
      if(customer[i].canEat(a))
      {
        cout<<customer[i].name()<<" eats "<<a.getName()<<". ";
        customer[i].eat(a,krusty);
        if(customer[i].getVomiting())
        {
          chainReaction(customer,SIZE,i,krusty);
          krusty.payVomit(); //Krusty pays $5 for customer vomiting
          customer[i].allClear();
        }
        contest=1;
      }
    }
    if(!contest)
    {
      cout<<"No one can eat a burger! The contest is over!"<<endl;
    }
    cout<<"------------------------------------------"<<endl;
    roundNumber++;
  }

  

  cout<<"-------------------SURVIVING CONTESTANTS-------------------"<<endl;
  for(int i=0;i<SIZE;i++)
  {
    if(customer[i].isAlive())
    cout<<customer[i].name()<<", Burgers eaten "<<customer[i].get_numEat()
        <<", wt gained "<<customer[i].get_weightGain()<<", Contestant: "
        <<customer[i].isContestant()<<endl;
  }
  declareWinner(customer,SIZE);
  cout<<endl;
  cout<<"-------------------------------------------------------------"<<endl;

  cout<<"------------------------KRUSTY------------------------"<<endl
      <<"Final money: $"<<krusty.getCashMoney()<<endl;
  if(krusty.getCashMoney()<100)
  {
    cout<<"Krusty lost: $"<<(krusty.getCashMoney()-100)*-1<<endl;
  }
  else if(krusty.getCashMoney()>100)
  {
    cout<<"Krusty gained: $"<<(krusty.getCashMoney()-100)<<endl;
  }
  else if(krusty.getCashMoney()==0)
  {
    cout<<"Krusty went broke!"<<endl;
  }
  else if(krusty.getCashMoney()==100)
  {
    cout<<"Krusty broke even!"<<endl;
  }
  cout<<"------------------------------------------------------"<<endl;

  return 0;
}
