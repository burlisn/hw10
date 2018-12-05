// Programmer: Nathan Burlis & Mathew Romine
// Date: 12/04/2018
// Filename: helper.h
// Course number & section: 1570 C
// Instructor name: Yeung
// Purpose: This file contains the prototypes for all of the functions
//          nessicary to the competition, and interactions between the
//          the competitiors.

#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include "customer.h"

using namespace std;

const string NOISE[4] = {"*pukes in German*","*pukes in English*",
                         "*pukes in Russian*","*pukes in Latin*"};

// Description: Simulates the chain reaction after a contestant pukes from
//              eating a pathogen
// Pre: A customer should have puked and the customer array, the location 
//      of the original puking customer(j), and the burgermeister should be
//      entered as arguments
// Post: All chain reaction processes from a puking customer as a result of
//       eating a pathogen are complete
void chainReaction(Customer customer[], const int SIZE, int j,
                   Burgermeister& krusty);

// Description: Simulates the food fight between customers
// Pre: Should only be called inside of chainReaction function and the
//      customer array, the location of customer who starts the food fight(j),
//      and the burgermeister should all be passed in as parameters
// Post: A food fight is simulated
int foodFight(Customer customer[], const int SIZE, int j,
              Burgermeister& krusty);

// Description: Declares a winner from the possibilites
// Pre: The customer array and its size should be included as arguments
// Post: Winner is declared (or none...)
void declareWinner(Customer customer[], const int SIZE);

// Description: Returns the number of alive contestants (meaning they must be
//              alive and a contestant i.e. not disqualified)
// Pre: The customer array and its size shoudl be included as arguments
// Post: The number of alive contestants is returned
int numAliveCont(Customer customer[], const int SIZE);

#endif