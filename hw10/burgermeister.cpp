// Programmer: Nathan Burlis & Mathew Romine
// Date: 11/08/2018
// Filename: burgermeister.cpp
// Course number & section: 1570 C
// Instructor name: Yeung
// Purpose:

#include "burgermeister.h"

Burgermeister::Burgermeister(const string name, const double money)
{
  m_name=name;
  m_cashMoney=money;
}

void Burgermeister::operator+=(const double rhs)
{
  m_cashMoney+=rhs;
  return;
}

void Burgermeister::operator-=(const double rhs)
{
  m_cashMoney-=rhs;
  return;
}

/********************GETTER FUNCTIONS***********************/
double Burgermeister::getCashMoney() const
{
  return m_cashMoney;
}

string Burgermeister::getName() const
{
  return m_name;
}