// Programmer: Nathan Burlis & Mathew Romine
// Date: 12/04/2018
// Filename: helper.cpp
// Course number & section: 1570 C
// Instructor name: Yeung
// Purpose: This file contains the functions nessicary to run all of the
//          interactions between customers, and holds the process for
//          the competition. ex. Puking, Throwing Burgers, Krusty interactions

#include "helper.h"

//Starts the chain reaction that is the first vomit
void chainReaction(Customer customer[], const int SIZE, int j,
                   Burgermeister& krusty)
{
  //Walking up the array &&i!=-1
  for(int i=j+1; i<SIZE; i++)
  {
    if(rand()%2==1&&customer[i].isAlive())
    {
      cout<<"\t";
      customer[i].vomit();
      cout<<endl;
      krusty.payVomit(); //Krusty pays for vomiting
    }
    else if(rand()%10<=6&&customer[i].isAlive())
    {
      foodFight(customer, SIZE, i,krusty);
      i=SIZE;
    }
    else
    {
      i=SIZE;
    }
    customer[i].allClear();
  }

  //Walking down the array
  for(int i=j-1; i>=0; i--)
  {
    if(rand()%2==1&&customer[i].isAlive()) //If true they vomit
    {
      cout<<"\t";
      customer[i].vomit();
      cout<<endl;
      krusty.payVomit(); //Krusty pays for vomiting
    }
    else if(rand()%10<=6&&customer[i].isAlive()) //If they don't vomit but
    {                                            //start food fight
      foodFight(customer,SIZE,i,krusty);
      i=-1;
    }
    else
    {
      i=-1;
    }
    customer[i].allClear();
  }
  return;
}


//Simulates the food fight
int foodFight(Customer customer[], const int SIZE, int j,
              Burgermeister& krusty)
{
  int p=SIZE;
  bool fight=1;
  int target=rand()%16;
  while(fight)
  {
    Burger a;
    if(target==15&&customer[j].canChuck(a)) //Krusty is hit
    {
      customer[j].chuck(a);
      krusty+=customer[j].cashMoney();
      customer[j].setCashMoney(0);
      customer[j].disqualify();
      cout<<"\t\t"<<customer[j].name()<<" hits Krusty!"<<endl;
      fight=0;
    }
    else if(customer[target].isAlive()&&customer[j].canChuck(a))
    {
      customer[j].chuck(a);
      cout<<"\t\t"<<customer[j].name()<<" hits "<<customer[target].name()<<endl;
      j=target;
      target=rand()%16;
      if(rand()%10<=1)
      {
        cout<<"\t\t"<<customer[j].name()<<" decides not to chuck."<<endl;
        fight=0;
      }
    }
    else
    {
      fight=0;
      cout<<"\t\t"<<customer[j].name()<<" decides not to chuck."<<endl;
    } 
  }
  p=-1;
  return p;
}


//Declares the winner depending on the conditions
void declareWinner(Customer customer[], const int SIZE)
{
  int burgEatWin=15;
  int maxBurgEat=0;
  bool needWeightGain=0;
  double maxWeightGain=0;
  
  if(numAliveCont(customer,SIZE)>=1)
  {
    for(int i=0;i<SIZE;i++)
    {
      if(customer[i].isAlive()&&customer[i].isContestant())
      {
        if(customer[i].get_numEat()>maxBurgEat)
        {
          maxBurgEat=customer[i].get_numEat();
          burgEatWin=i;
          needWeightGain=0;
        }
        else if(customer[i].get_numEat()==maxBurgEat)
        {
          needWeightGain=1;
        }
      }
    }
  }
  if(needWeightGain)
  {
    for(int i=0;i<SIZE;i++)
    {
      if(customer[i].isAlive()&&customer[i].isContestant())
      {
        if(customer[i].get_weightGain()>maxWeightGain)
        {
          burgEatWin=i;
          maxWeightGain=customer[i].get_weightGain();
        }
      }
    }
  }
  if(burgEatWin!=15)
  {
    cout<<"Customer "<<customer[burgEatWin].name()<<" is the Winner!";
  }
  else
  {
    cout<<"THEY'RE ALL DEAD!(or disqualified...)";
  }
  return;
}

//Counts the number of alive contestants (aren't disqualified)
int numAliveCont(Customer customer[], const int SIZE)
{
  int numAliveCont=0;
  for(int i=0;i<SIZE;i++)
  {
    if(customer[i].isAlive()&&customer[i].isContestant())
    {
      numAliveCont++;
    }
  }
  return (numAliveCont);
}
