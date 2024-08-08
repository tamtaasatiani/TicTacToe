//
//  game.cpp
//  tictactoe
//
//  Created by tamta asatiani on 29.06.24.
//

#include "game.hpp"
#include <iostream>

Game::Game()
{
    player1 = new Player('X');
    player2 = new Player('O');
    turn = player1;
    winner = NULL;
    
    board = new Board(7, 7);
    board -> initSlots();
    
//no idea why this doesn't work, or why i had to make pointers to instances:
//    Player player1('X');
//    Player player2('O');
//    Player& turn = player1;
    
//    Board board(7, 7);
//    board.initSlots();
}

bool Game::isRunning()
{
    return running;
}

bool Game::win(Player* potentialWinner)
{
    int length = sizeof(winningNumbers) / sizeof(int);
    
    for (int i = 0; i < length; i++)
    {
        if (potentialWinner -> getScore() % winningNumbers[i] != 0)
        {
            continue;
        }
        
        winner = potentialWinner;
        return true;
    }
    
    return false;
}

void Game::gameOver()
{
    gameState = "win";
}

Player* Game::changeTurn()
{
    if (turn == player1)
    {
        return player2;
    }
    
    return player1;
}



void Game::run()
{
    if(gameState == "start")
    {
        std::cout << "Welcome to tic-tac-toe, made with C++ by Tamta Asatiani.\nYou need to have 2 players to play, so make sure there's two of you!\nPress enter to start." << std::endl;
        
        std::cin.get();
        gameState = "play";
    }
    else if (gameState == "play")
    {
        std::cout << std::endl;
        std::cout << "It's " << turn -> getSymbol() << "'s turn, pick a place!" << std::endl;
        std::cout << board -> draw() << std::endl;
        
        char input;
        std::cin >> input;
        
        if (!(board -> playTurn(turn -> getSymbol(), (int)input - 48)))
        {
            std::cout << "Invalid input. Try again!" << std::endl;
            std::cout << std::endl;
            return;
        }
        
        turn -> addScore(board -> slots[(int)input - 49].getWeight());
//      std::cout << turn -> getSymbol() << "'s score: " << turn -> getScore() << std::endl;
        
        if (win(turn))
        {
            gameOver();
        }
        else if (board -> slotsFull())
        {
            gameOver();
        }
        
        turn = changeTurn();
        
        
        
    }
    else if(gameState == "win")
    {
        running = false;
        
        if (winner == NULL)
        {
            std::cout << board -> draw() << std::endl;
            std::cout << "It's a tie! Nobody wins." << std::endl;
            return;
        }
        
        std::cout << board -> draw() << std::endl;
        std::cout << "Game Over. Player " << winner -> getSymbol() << " has won." << std::endl;
    }
    
}
