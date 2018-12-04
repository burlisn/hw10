
#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include "customer.h"

using namespace std;

const string NOISE[4] = {"*pukes in German*","*pukes in English*",
                         "*pukes in Russian*","*pukes in Latin*"};

void chainReaction(Customer customer[], const int SIZE, int j,
                   Burgermeister& krusty);

int foodFight(Customer customer[], const int SIZE, int j,
              Burgermeister& krusty);

void declareWinner(Customer customer[], const int SIZE);

int numAliveCont(Customer customer[], const int SIZE);


#endif