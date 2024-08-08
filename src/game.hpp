//
//  game.hpp
//  tictactoe
//
//  Created by tamta asatiani on 29.06.24.
//

#pragma once

#include "util.hpp"

#include "board.hpp"
#include "player.hpp"
#include "slot.hpp"

class Game {
    private:
        bool running = true;
    
        int winningNumbers[8] = {30, 238, 506, 627, 935, 1001, 1495, 7429};
        Player* player1;
        Player* player2;
        Player* turn;
        Player* winner;
    
        Board* board;
    
        std::string gameState = "start";
    
    public:
        Game();
        ~Game();
        
    
        Player* changeTurn();
        bool isRunning();
        void gameOver();
        bool win(Player* potentialWinner);
    
        void run();
    
        
        
};
