//
//  board.cpp
//  tictactoe
//
//  Created by tamta asatiani on 29.06.24.
//

#include "board.hpp"
#include "util.hpp"

#include <string>
#include <iostream>


Board::Board(int width, int height)
{
    this -> width = width;
    this -> height = height;
}


void Board::initSlots()
{
    for (int i = 0; i < 9; i++)
    {
        int symbol = i + 1;
        slots[i].setWeight(primes[i]);
        slots[i].setSymbol(symbol + '0');
    }
}

bool Board::slotsFull()
{
    for (int i = 0; i < 9; i++)
    {
        if (slots[i].getSymbol() != 'X' && slots[i].getSymbol() != 'O')
        {
            return false;
        }
    }
    
    return true;
}

bool Board::playTurn(char symbol, int spot)
{
    spot -= 1;
    
    if (slots[spot].getSymbol() == 'X' || slots[spot].getSymbol() == 'O' || spot < 0 || spot > 8)
    {
        return false;
    }
    
    slots[spot].setSymbol(symbol);
    return true;
}


static std::string drawHorizontal(int width)
{
    std::string output;
    for(int w = 0; w < width; w++)
    {
        output += "-";
    }
    output += "\n";
    return output;
}

static std::string drawVertical(int width, Slot slots[], int slotIndex)
{
    std::string output;
    bool symbolFlag = false;
    for(int w = 0; w < width; w++)
    {
        if (symbolFlag)
        {
            std::string s(1, slots[slotIndex].getSymbol());
            //output += std::to_string(slots[slotIndex].getSymbol());
            output += s;
            slotIndex++;
            symbolFlag = false;
            continue;
        }
        
        symbolFlag = true;
        output += "|";
    }
    output += "\n";
    return output;
}

std::string Board::draw()
{
    std::string output;
    int slotIndex = 0;
    bool horizontalFlag = true;
    for(int h = 0; h < height; h++)
    {
        if(horizontalFlag)
        {
            output += drawHorizontal(width);
            horizontalFlag = false;
            continue;
        }
        
        horizontalFlag = true;
        output += drawVertical(width, slots, slotIndex);
        slotIndex += 3;
    }
    
    return output;
}

