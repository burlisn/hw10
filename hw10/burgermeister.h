// Programmer: Nathan Burlis & Mathew Romine
// Date: 11/08/2018
// Filename: burgermeister.h
// Course number & section: 1570 C
// Instructor name: Yeung
// Purpose: test

#ifndef BURGERMEISTER_H
#define BURGERMEISTER_H

#include <iostream>

using namespace std;

class Burgermeister
{
  public:
    Burgermeister(const string name, const double money);
    void operator+=(const double rhs);
    void operator-=(const double rhs);

    double getCashMoney() const;
    string getName() const;

    void payVomit();
    void payDeath();

  private:
    string m_name;
    double m_cashMoney;
};

#endif