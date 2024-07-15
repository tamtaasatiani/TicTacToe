//
//  board.hpp
//  tictactoe
//
//  Created by tamta asatiani on 29.06.24.
//

#pragma once
#include <string>
#include "slot.hpp"

class Board {
    public:
        Slot slots[9];
    
    private:
        int width;
        int height;
    
    public:
        Board(int width, int height);
        std::string draw();
        bool slotsFull();
        bool playTurn(char symbol, int spot);
        void initSlots();
        
};
