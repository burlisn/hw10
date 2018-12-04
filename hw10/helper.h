
#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include "customer.h"

using namespace std;

void chainReaction(Customer customer[], const int SIZE, int j,
                   Burgermeister& krusty);

int foodFight(Customer customer[], const int SIZE, int j,
              Burgermeister& krusty);


#endif