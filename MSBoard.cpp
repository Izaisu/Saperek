#include "MSBoard.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

MSBoard::MSBoard(){

    board_Width=10;
    board_Height=10;
    mode=DEBUG;
    setBoard();
};

MSBoard::MSBoard(int width, int height, GameMode g_mode ) {

    board_Width = width;
    board_Height = height;
    mode = g_mode;
    state=RUNNING;
    mineBoardCounter=0;
   // emptyField=0;
    setBoard();
};

 void MSBoard::setField(int idx_x, int idx_y, bool hasMine, bool hasFlag, bool isRevealed){

    board[idx_y][idx_x] = {hasMine, hasFlag, isRevealed};
}

int MSBoard::gameFields(int width, int height) {
    int area = width*height;
    return area;
 }

 void MSBoard::setBoard() {

     if(mode==DEBUG)
     {
         for (int idx_y=0, idx_x=0; idx_y<board_Height and idx_x<board_Width ; idx_y++, idx_x++)
             setField(idx_x,idx_y,true,false,false);
         for (int idx_y=0, idx_x=0; idx_x<board_Width; idx_x++)
             setField(idx_x,idx_y,true,false,false);
         for (int idx_x=0, idx_y=0; idx_y<board_Height; idx_y++)
             if(idx_y%2==0)
                 setField(idx_x,idx_y,true,false,false);

     }
     if(mode==EASY)
     {
         {
             for (int idx_y = 0; idx_y < board_Height; idx_y++) {
                 for (int idx_x = 0; idx_x < board_Width; idx_x++) {
                     setField(idx_x, idx_y, false, false, false);
                 }
             }
         }
         double difficulty = 0.1*gameFields(board_Width,board_Height);
         for (int counter=1; counter<=difficulty; ++counter)
         {
             int rand_x = (rand() % board_Width)+ 0;
             int rand_y = (rand() % board_Height) + 0;
             if (board[rand_y][rand_x].hasMine==0)
             {
                 board[rand_y][rand_x].hasMine=true;
                 mineBoardCounter++;
             }
             else
                 counter--;
         }
         emptyField=gameFields(board_Width,board_Height)-mineBoardCounter;
     }

     if(mode==NORMAL)
     {
         {
             for (int idx_y = 0; idx_y < board_Height; idx_y++) {
                 for (int idx_x = 0; idx_x < board_Width; idx_x++) {
                     setField(idx_x, idx_y, false, false, false);
                 }
             }
         }
         double difficulty = 0.2*gameFields(board_Width,board_Height);
         for (int counter=1; counter<=difficulty; ++counter)
         {
             int rand_x = (rand() % board_Width)+ 0;
             int rand_y = (rand() % board_Height) + 0;
             if (board[rand_y][rand_x].hasMine==0)
             {
                 board[rand_y][rand_x].hasMine=true;
                 mineBoardCounter++;
             }
             else
                 counter--;
         }
         emptyField=gameFields(board_Width,board_Height)-mineBoardCounter;
     }

     if(mode==HARD)
     {
         {
             for (int idx_y = 0; idx_y < board_Height; idx_y++) {
                 for (int idx_x = 0; idx_x < board_Width; idx_x++) {
                     setField(idx_x, idx_y, false, false, false);
                 }
             }
         }
         double difficulty = 0.3*gameFields(board_Width,board_Height);
         for (int counter=1; counter<=difficulty; ++counter)
         {
             int rand_x = (rand() % board_Width)+ 0;
             int rand_y = (rand() % board_Height) + 0;
             if (board[rand_y][rand_x].hasMine==0)
             {
                 board[rand_y][rand_x].hasMine=true;
                 mineBoardCounter++;
             }
             else
                 counter--;
         }
         emptyField=gameFields(board_Width,board_Height)-mineBoardCounter;
     }
 }
 void MSBoard::debug_display() const {
     std::string display;
     for (int idx_y = 0; idx_y<board_Height; idx_y++)
     {
         for (int idx_x = 0; idx_x<board_Width; idx_x++) {
             display+="[";
             if (board[idx_y][idx_x].hasMine)
                 display+="M";
             else
                 display+=".";
             if (board[idx_y][idx_x].isRevealed)
                 display+="o";
             else
                 display+=".";
             if (board[idx_y][idx_x].hasFlag)
                 display+="f";
             else
                 display+=".";
             display+="] ";

         } display+= "\n";
     }
     std::cout << display;
 }
int MSBoard::getBoardWidth() const {

    return board_Width;
 }

 int MSBoard::getBoardHeight() const {

     return board_Height;
 }

int MSBoard::getMineCount() const {

    return mineBoardCounter;
 }

 int MSBoard::countMines(int idx_x, int idx_y) {
     mineFieldCounter = 0;

     if (!onBoard(idx_x, idx_y))
         return -1;

     else
         {
             for (int iy = idx_y - 1; iy <= idx_y + 1; iy++) {
                 for (int ix = idx_x - 1; ix <= idx_x+ 1; ix++)
                     if (ix >= 0 and ix < board_Width and iy >= 0 and iy < board_Height) {
                         if (iy == idx_y and ix == idx_x)
                             mineFieldCounter += 0;
                         if (board[iy][ix].hasMine and (iy!= idx_y or ix!= idx_x))
                             mineFieldCounter += 1;
                     }
             }
         }
         return mineFieldCounter;
 }

 bool MSBoard::hasMine(int idx_x, int idx_y) const {
     if (!onBoard(idx_x,idx_y))
         return false;
     if (board[idx_y][idx_x].hasMine)
         return true;
     else return false;
 }

 bool MSBoard::hasFlag(int idx_x, int idx_y) const {
     if (!onBoard(idx_x,idx_y))
         return false;
     if (board[idx_y][idx_x].hasFlag)
         return true;
     else return false;
 }

 bool MSBoard::isRevealed(int idx_x, int idx_y) const {
     if (!onBoard(idx_x,idx_y))
         return false;
     if (board[idx_y][idx_x].isRevealed)
         return true;
     else return false;
 }

 void MSBoard::toggleFlag(int idx_x, int idx_y) {

     ++moves;
     if (board[idx_y][idx_x].isRevealed)
         return;
     if (!onBoard(idx_x, idx_y))
         return;
     if (state==FINISHED_WIN or state==FINISHED_LOSS)
         return;
     if (!board[idx_y][idx_x].isRevealed and board[idx_y][idx_x].hasMine)
     {
         board[idx_y][idx_x].hasFlag=true;
         mineBoardCounter--;
     }
     else
         board[idx_y][idx_x].hasFlag=true;
     if (mineBoardCounter==0)
         state=FINISHED_WIN;
 }

 void MSBoard::revealField(int idx_x, int idx_y) {
     if (board[idx_x][idx_y].isRevealed) { cout << "To pole jest odsloniete" << endl; }
     else if (!onBoard(idx_x,idx_y)) {
         cout << "Nie ma takiego pola :C" << endl;
     } else if (state == FINISHED_WIN || state == FINISHED_LOSS) { cout << "Gra jest już skończona" << endl; }
     else if (board[idx_x][idx_y].hasFlag) { cout << "To pole jest oflagowane" << endl; }
     else if (!board[idx_x][idx_y].isRevealed && !board[idx_x][idx_y].hasMine) {
         board[idx_x][idx_y].isRevealed = true;
         emptyField = emptyField-1;

     }
     else if (!board[idx_x][idx_y].isRevealed && board[idx_x][idx_y].hasMine) {
         board[idx_x][idx_y].isRevealed = true;
         state = FINISHED_LOSS;
         cout << "PRZEGRALES!" << endl;
     }
     else if ( isWon()){
         cout  <<" GRATULACJE WYGRALES!" << endl;
     }

    }


bool MSBoard::onBoard(int idx_x, int idx_y) const{
    if(idx_x < 0 || idx_x > board_Width || idx_y < 0 || idx_y > board_Height)
        return false;
    return true;
 }

GameState MSBoard::getGameState() const {
    return state;
}

char MSBoard::getFieldInfo(int idx_x, int idx_y) {
    char info;
    if (idx_x<0 or idx_x>=board_Width or idx_y<0 or idx_y>=board_Height)
    {
        info='#';
        return info;
    }
    if (!board[idx_y][idx_x].isRevealed and board[idx_y][idx_x].hasFlag)
    {
        info='F';
        return info;
    }
    if (!board[idx_y][idx_x].isRevealed and !board[idx_y][idx_x].hasFlag)
    {
        info='_';
        return info;
    }
    if (board[idx_y][idx_x].isRevealed and board[idx_y][idx_x].hasMine)
    {
        info='x';
        return info;
    }
    if (board[idx_y][idx_x].isRevealed and countMines(idx_x,idx_y)==0)
    {
        info='N';
        return info;
    }
    if (board[idx_y][idx_x].isRevealed and countMines(idx_x,idx_y)!=0)
    {
        int number = countMines(idx_x,idx_y);
        info='0'+number;
        return info;
    }
}

void MSBoard::untoggleFlag(int idx_x, int idx_y) {

     ++moves;
    if (!onBoard(idx_x,idx_y))
        {cout << "Nie ma takiego pola" << endl;}
    if (state==FINISHED_WIN or state==FINISHED_LOSS)
        return;
    if (board[idx_y][idx_x].hasFlag)
    {
        board[idx_y][idx_x].hasFlag=false;
        mineBoardCounter++;
        {cout << "oflagowales pole" << endl;}
    }
    else
        cout <<"To pole nie jest oflagowane!" << endl;
 }
 bool MSBoard::isWon(){

     int mines = 0;
     for(int idx_y = 0; idx_y < board_Height; idx_y++){
         for(int idx_x = 0; idx_x < board_Width; idx_x++){
             if(!board[idx_x][idx_y].isRevealed && board[idx_x][idx_y].hasFlag && board[idx_x][idx_y].hasMine )
                 mines++;
         }
     }
     if (mines == mineBoardCounter && emptyField == 0)
         state = FINISHED_WIN;

     else
         return false;

 }
