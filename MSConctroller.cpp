#include "MSController.h"
#include "MSBoard.h"
#include "MSBoardView.h"
#include <iostream>

using namespace std;

MSController::MSController(MSBoard &board, MSBoardView &view) : board (board), view (view){

};

void MSController::play()
{

    while(board.getGameState() == RUNNING){
        int choice;
        cout <<"Wybierz opcje: " << endl;
        cout<< "1. Odkryj pole" <<endl;
        cout<< "2. Oflaguj pole" <<endl;
        cout<< "3. Odflaguj pole" << endl;
        cin>>choice;

        if(choice==1)
        {
            int x, y;
            cout<<"Wybierz współrzędną x" << endl;
            cin>>x;cout<<endl;
            x = x-1;
            cout<<"Wybierz współrzędną y" << endl;
            cin>>y;cout<<endl;
            y = y-1;



            board.revealField(x,y);
            view.game_display();

        }
        else if(choice==2){

            int x, y;
            cout<<"Wybierz współrzędną x" << endl;
            cin>>x;cout<<endl;
            x = x -1;
            cout<<"Wybierz współrzędną y" << endl;
            cin>>y;cout<<endl;
            y = y -1;
            board.toggleFlag(x,y);
            view.game_display();


        }
        else if(choice==3){
            int x, y;
            cout<<"Wybierz współrzędną x" << endl;
            cin>>x;cout<<endl;
            x = x-1;
            cout<<"Wybierz współrzędną y" << endl;
            cin>>y;cout<<endl;
            y = y-1;

            board.untoggleFlag(x,y);
            view.game_display();
        }

    }

}
