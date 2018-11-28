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

using namespace std;

int main()
{
  srand(time(NULL));

  cout.setf(ios::fixed); 
  cout.setf(ios::showpoint); 
  cout.precision(2);
  cout.setf(ios::boolalpha);

  Burgermeister krusty("Krusty",100);
  int roundNumber=0;
  Customer customers[15];
  
  for(int i=0;i<20;i++)
  {
    cout<<customers[0]<<endl;
    Burger a;
    cout<<a<<endl;
    customers[0].eat(a,krusty);
    cout<<krusty.getCashMoney()<<endl;
  }

  return 0;
}
