//
//  player.cpp
//  tictactoe
//
//  Created by tamta asatiani on 29.06.24.
//

#include "player.hpp"

Player::Player(char symbol)
{
    this -> symbol = symbol;
}

int Player::getScore()
{
    return score;
}

void Player::addScore(int amount)
{
    score *= amount;
}

char Player::getSymbol()
{
    return symbol;
}
