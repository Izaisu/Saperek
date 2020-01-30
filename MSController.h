#ifndef SAPERPO_MSCONTROLLER_H
#define SAPERPO_MSCONTROLLER_H

#include "MSBoard.h"
#include "MSBoardView.h"

class MSController {

    MSBoard &board;
    MSBoardView &view;

public:
    MSController(MSBoard&board, MSBoardView&view);
    void play();

};


#endif //SAPERPO_MSCONTROLLER_H
