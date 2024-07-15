//
//  slot.hpp
//  tictactoe
//
//  Created by tamta asatiani on 29.06.24.
//

#pragma once

class Slot {
    private:
        char symbol;
        int weight;
    
    public:
        char getSymbol();
        void setSymbol(char symbol);
        
        int getWeight();
        void setWeight(int weight);
};
