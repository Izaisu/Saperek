#include "MSBoardView.h"
#include "MSBoard.h"
#include <iostream>

using namespace std;

MSBoardView::MSBoardView(MSBoard &gameboard) : view (gameboard)
{

}

void MSBoardView::game_display() {
    int board_height=view.getBoardHeight();
    int board_width=view.getBoardWidth();
    for (int idx_y = 0; idx_y<board_height; idx_y++) {
        for (int idx_x = 0; idx_x < board_width; idx_x++) {
            cout<<"["<<view.getFieldInfo(idx_x,idx_y)<<"]";

        }
        cout<<endl;
    }
}


