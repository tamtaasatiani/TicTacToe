//
//  slot.cpp
//  tictactoe
//
//  Created by tamta asatiani on 29.06.24.
//

#include "slot.hpp"
#include <iostream>

void Slot::setSymbol(char symbol)
{
    this -> symbol = symbol;
}

char Slot::getSymbol()
{
    return symbol;
}

int Slot::getWeight()
{
    return weight;
}

void Slot::setWeight(int weight)
{
    this -> weight = weight;
}
