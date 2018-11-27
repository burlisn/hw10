// Programmer: Nathan Burlis & Mathew Romine
// Date: 12/05/2018
// Filename: hw10.cpp
// Course number & section: 1570 C
// Instructor name: Yeung
// Purpose:

#include "burger.h"
#include "customer.h"
#include "burgermeister.h"

using namespace std;

int main()
{
  Burgermeister a("Krusty",3.50);
  a-=5.00;
  cout << a.getCashMoney() << endl;
  cout << a.getName() << endl;

  return 0;
}
