#include "MSBoard.h"
#include "MSBoardView.h"
#include "MSController.h"
#include <iostream>
#include <ctime>


GameMode getMode();

using namespace std;

int main() {

    srand( time(NULL));
    cout <<"WITAJ W GRZE SAPER!" << endl;
    GameMode mode = getMode();
    cout << "Podaj rozmiar planszy!" << endl;
    int x,y;
    cin >> x;
    cin >> y;

    MSBoard saper(x,y, mode);
    saper.debug_display();
    MSBoardView view(saper);
    view.game_display();
    MSController ctrl(saper, view);
    ctrl.play();

    return 0;
}

GameMode getMode() {
    cout << "Wybierz poziom trudności (1.EASY/ 2.NORMAL/ 3.HARD)" << endl;
    int poziom;
    GameMode mode;
    cin >> poziom;
    if (poziom == 1){
        mode = EASY;
    }
    else if(poziom == 2){
        mode = NORMAL;
    }
    else if(poziom == 3){
        mode = HARD;
    }
    else
        cout << "Nie ma takiego poziomu :<" << endl;
    return mode;
}
