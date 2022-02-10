#pragma once

#include <cmath>
#include <cctype>
#include <string>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

//Write prototypes here


void shuffleArray( int array[], int size);

bool arraySorted( int array[], int size);

void displayArray( int array[], int size );


void copyArray(int array[], int size, int dest[]);

bool compareArray(int array1[], int array2[], int size);

bool arraySortedBogo(int array[], int size);

void bogoBogo(int array[], int size);