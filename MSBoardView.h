#ifndef SAPERPO_MSBOARDVIEW_H
#define SAPERPO_MSBOARDVIEW_H

#include "MSBoard.h"
#include <iostream>

using namespace std;

class MSBoardView {

    MSBoard &view;

public:
    MSBoardView (MSBoard &gameboard);
    void game_display();

};


#endif //SAPERPO_MSBOARDVIEW_H
