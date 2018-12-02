#include "helper.h"

void chainReaction(Customer customer[], const int SIZE, int j)
{
  //Walking up the array
  for(int i=j+1; i<SIZE&&i!=-1; i++)
  {
    if(rand()%2==1&&customer[i].isAlive())
    {
      customer[i].vomit();
    }
    else if(rand()%10<=6&&customer[i].isAlive())
    {
      i=foodFight(customer, SIZE, i);
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
    if(rand()%2==1&&customer[i].isAlive())
    {
      customer[i].vomit();
    }
    else if(rand()%10<=6&&customer[i].isAlive())
    {
      i=foodFight(customer, SIZE, i);
    }
    else
    {
      i=-1;
    }
    customer[i].allClear();
  }
  return;
}

int foodFight(Customer customer[], const int SIZE, int j)
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
      cout<<customer[j].name()<<" hits Krusty!"<<endl;
      fight=0;
    }
    else if(customer[target].isAlive()&&customer[j].canChuck(a))
    {
      customer[j].chuck(a);
      cout<<customer[j].name()<<" hits "<<customer[target].name();
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
