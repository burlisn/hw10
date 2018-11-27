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

  cout<<"---------Customers with default constructor----------"<<endl;
  Customer customers[24];
  for(int i=0;i<24;i++)
  {
    cout<<customers[i]<<endl;
  }
  cout<<endl;

  return 0;
}
