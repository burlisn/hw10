#include "helper.h"

void chainReaction(Customer customer[], const int SIZE, int j,
                   Burgermeister& krusty)
{
  //Walking up the array
  for(int i=j+1; i<SIZE&&i!=-1; i++)
  {
    if(rand()%2==1&&customer[i].isAlive())
    {
      customer[i].vomit();
      krusty.payVomit(); //Krusty pays for vomiting
    }
    else if(rand()%10<=6&&customer[i].isAlive())
    {
      i=foodFight(customer, SIZE, i,krusty);
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
      customer[i].vomit();
      krusty.payVomit(); //Krusty pays for vomiting
    }
    else if(rand()%10<=6&&customer[i].isAlive()) //If they don't vomit but
    {                                            //start food fight
      i=foodFight(customer, SIZE, i,krusty);
    }
    else
    {
      i=-1;
    }
    customer[i].allClear();
  }
  return;
}

int foodFight(Customer customer[], const int SIZE, int j,
              Burgermeister& krusty)
{
  int p=SIZE;
  bool fight=1;
  while(fight)
  {
    Burger a;
    int target=rand()%16;
    if(target==15&&customer[j].canChuck(a)) //Krusty is hit
    {
      customer[j].chuck(a);
      krusty+=customer[j].cashMoney();
      customer[j].setCashMoney(0);
      customer[j].disqualify();
      cout<<customer[j].name()<<" hits Krusty!"<<endl;
      fight=0;
    }
    else if(customer[target].isAlive()&&customer[j].canChuck(a))
    {
      customer[j].chuck(a);
      cout<<customer[j].name()<<" hits "<<customer[target].name()<<endl;
      j=target;
      if(rand()%10<=1)
      {
        fight=0;
      }
    }
    else
    {
      fight=0;
    } 
  }
  p=-1;
  return p;
}

/*void declareWinner(Customer customer[], const int SIZE)
{
  int burgEatWin=0;
  int maxBurgEat=0;
  bool needWeightGain=0;
  double maxWeightGain=0;
  
  if(numAliveCont(customer,SIZE)>1)
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
        }
      }
    }
  }
  cout<<"Customer "<<customer[burgEatWin].name()<<" is the Winner!";
  return;
}

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
*/