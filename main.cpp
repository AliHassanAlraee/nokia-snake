#include <iostream>
#include <windows.h> // Sleep()
#include <conio.h> // getch()
#include <ctime> // time(0)
#include <stdlib.h> // srand() and rand()
#include "snik.h"
using namespace std;

int main()
{
    system("color 5F");
    snik play;
    char choice;

    while(1)
    {
        system("cls");

        cout << "\n\t\t\tPress 1 for play\n";
        cout << "\t\t\tPress 2 for help\n";
        cout << "\t\t\tPress 3 for keys\n";
        cout << "\t\t\tPress 4 for exit\n";
        cout << "\t\t\tPlease enter your choice\t";
        choice = getch();

        switch(choice)
        {
        case '1':
            play.o = '\0';
            play.playground();
            while(play.o != 'e')
            {
                play.turn();

                play.moveOn();
                play.playground();

                if(play.level == 1)
                    Sleep(100);
                else if(play.level == 2)
                    Sleep(80);
                else if(play.level == 3)
                    Sleep(60);
                else if(play.level == 4)
                    Sleep(50);
                else if(play.level == 5)
                    Sleep(45);
                else if(play.level == 6)
                    Sleep(40);
                else if(play.level == 7)
                    Sleep(35);
                else if(play.level == 8)
                    Sleep(30);
                else if(play.level == 9)
                    Sleep(25);
                else if(play.level == 10)
                    Sleep(20);
                else if(play.level == 11)
                    Sleep(15);

                if(play.o == 'e')
                {
                    system("cls");
                    cout << "\n\t\t\t    GAME OVER!!!";
                    cout << "\n\t\t\tYour level is    = " << play.level;
                    cout << "\n\t\t\tYour points are  = " << play.points;
                }
            }
            break;

        case '2':
            system("cls");
            cout << "\n\t\t\tRules are:\n";
            cout << "\n\t\t\t1- It's simple snake game.\n";
            cout << "\n\t\t\t2- You can walk through wall where it is broken.\n";
            cout << "\n\t\t\t3- Snake will be speedup on every level-up.\n";
            break;

        case '3':
            system("cls");
            cout << "\n\t\t\tKeys are:\n";
            cout << "\n\t\t\t\tW = Move Upward\n";
            cout << "\n\t\t\t\tA = Move Leftward\n";
            cout << "\n\t\t\t\tS = Move Downward\n";
            cout << "\n\t\t\t\tD = Move Rightward\n";
            cout << "\n\t\t\t\tE = Exit\n";
            cout << "\n\t\t\t\tQ = Pause\n";
            break;

        case '4':
            exit(0);

        default:
            cout << "\n\t\t\tInvalid choice\n";
        }
        cout << "\n\n\t\t\t";
        system("pause");
    }

    return 0;
}
