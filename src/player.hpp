//
//  player.hpp
//  tictactoe
//
//  Created by tamta asatiani on 29.06.24.
//

#pragma once

class Player {
    private:
        int score = 1;
        char symbol;
    
    public:
    
        char getSymbol();
        int getScore();
        
        void addScore(int amount);
    
        Player(char symbol);
};
