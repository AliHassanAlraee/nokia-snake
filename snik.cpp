#include <iostream>
#include <windows.h>            // Sleep()
#include <conio.h>              // getch()
#include <ctime>                // time(0)
#include <stdlib.h>             // srand() and rand()
#include "snik.h"

using namespace std;


snik::snik()                    // Constructor
{
        o = '\0';
        level = 1;
        points = 0;
        for(int i=0;i<6;i++)
            {
                for(int j=0;j<20;j++)
                {
                    arr[i][j] = '\0';
                }
            }

        srand(time(0));


        food = (rand() % 6);
        snake = (rand() % 20);

        arr[food][snake] = '*'; //food position

        food = (rand() % 6);
        snake = (rand() % 20);

        arr[food][snake] = '0'; // snake starting position

       // attaching tale //

        if(food == 0)  // first row
        {
            if(snake == 0)
            {
                arr[food + 1][snake] = 'o';
            }
            else
            {
                arr[food][snake-1] = 'o';
            }
        }

        else if(food == 5)   // last row
        {
            if(snake == 0)
            {
                arr[food - 1][snake] = 'o';
            }
            else
            {
                arr[food][snake-1] = 'o';
            }
        }
        else
        {
            arr[food + 1][snake] = 'o';
        }

}

void snik :: playground()
    {
        system("cls");

        cout << "\t\t\t --  ----  -----  ---\n";

        for(int i = 0; i < 6; i++)
            {
                if(i == 0 || i == 2 || i == 3 || i == 5)
                    cout << "\t\t\t|";
                else
                    cout << "\t\t\t ";

                for(int j = 0; j < 20; j++)
                {
                    //Sleep(10);
                    cout << arr[i][j];
                }
                if(i == 0 || i == 2 || i == 3 || i == 5)
                    cout << "|";
                else
                    cout << " ";
                cout << endl;

                if(i == 2 && o == 'q')
                {
                    cout << "\t\t|====================================|\n";
                    cout << "\t\t|==============| PAUSE |=============|\n";
                    cout << "\t\t|====================================|\n";

                }
            }
        cout << "\t\t\t --  ----  -----  ---\n";

        cout << "\n\t\t\tYour level is    = " << level;
        cout << "\n\t\t\tYour points are  = " << points;
    }
void snik :: turn()
    {
        if(kbhit())
        {
            switch(getch())
            {

            case 'w':
            case 'W':

                for(int i = 0; i < 6; i++)
                {
                    for(int j = 0; j < 20; j++)
                    {
                        switch(arr[i][j])
                        {
                       case '0':
                           food = i;
                           snake = j;
                           break;
                        }
                    }
                }

                if(food == 0 && arr[5][snake] == 'o')
                    break;

                else if(food != 0 && arr[food-1][snake] == 'o')
                    break;

                else
                {
                    o = '1'; // upward
                    break;
                }


            case 'a':
            case 'A':

                for(int i = 0; i < 6; i++)
                {
                    for(int j = 0; j < 20; j++)
                    {
                        switch(arr[i][j])
                        {
                       case '0':
                           food = i;
                           snake = j;
                           break;
                        }
                    }
                }

                if(snake == 0 && arr[food][19] == 'o')
                    break;

                else if(snake != 0 && arr[food][snake-1] == 'o')
                    break;

                else
                {
                    o = '2'; // leftward
                    break;
                }

            case 's':
            case 'S':

                for(int i = 0; i < 6; i++)
                {
                    for(int j = 0; j < 20; j++)
                    {
                        switch(arr[i][j])
                        {
                       case '0':
                           food = i;
                           snake = j;
                           break;
                        }
                    }
                }

                if(food == 5 && arr[0][snake] == 'o')
                    break;

                else if(food != 5 && arr[food+1][snake] == 'o')
                    break;

                else
                {
                    o = '3'; // downward
                    break;
                }

            case 'd':
            case 'D':

                for(int i = 0; i < 6; i++)
                {
                    for(int j = 0; j < 20; j++)
                    {
                        switch(arr[i][j])
                        {
                       case '0':
                           food = i;
                           snake = j;
                           break;
                        }
                    }
                }

                if(snake == 19 && arr[food][0] == 'o')
                    break;

                else if(snake != 19 && arr[food][snake+1] == 'o')
                    break;

                else
                {
                    o = '4'; // rightward
                    break;
                }

            case 'Q':
            case 'q':
                o = 'q'; //Game Pause
                break;

            case 'E':
            case 'e':
                o = 'e'; //Game exit
                break;
            }
        }
    }

void snik :: moveOn()
    {
        switch(o)
            {

            case '1':  // upward
                for(int i = 0; i < 6; i++)
                    {
                        for(int j = 0; j < 20; j++)
                        {
                            switch(arr[i][j])
                            {
                                case '0': // face founded
                                    switch(i)
                                        {
                                            case 0:   // face at first line

                                                // Replacing face with tale

                                                if(j == 2 || j == 3 || j == 8 || j == 9 || j == 15 || j == 16) // face through holes
                                                {
                                                    if(arr[i+1][j] == 'o')
                                                    {
                                                        arr[i+1][j] = '\0';
                                                        arr[i][j] = 'o';
                                                    }

                                                    else if(arr[i][j-1] == 'o')
                                                    {
                                                        arr[i][j-1] = '\0';
                                                        arr[i][j] = 'o';
                                                    }

                                                    else if(arr[i][j+1] == 'o')
                                                    {
                                                        arr[i][j+1] = '\0';
                                                        arr[i][j] = 'o';
                                                    }

                                                    // Regenerating food after eat

                                                    switch(arr[5][j])
                                                    {
                                                    case '*':
                                                        srand(time(0));

                                                        food = (rand() % 6);
                                                        snake = (rand() % 20);

                                                        if(arr[food][snake] == '\0')
                                                            arr[food][snake] = '*';
                                                        else
                                                        {
                                                            food = (rand() % 6);
                                                            snake = (rand() % 20);

                                                            arr[food][snake] = '*';
                                                        }
                                                         // points
                                                        points = points + 2;
                                                        if(points >= 20)
                                                        {
                                                            level++;
                                                            points = 0;
                                                        }
                                                    }

                                                    arr[5][j] = '0';
                                                }

                                                else
                                                {
                                                    o = 'e';
                                                }

                                                i = 7;
                                                break;

                                            case 5: // Face at last line

                                                // Replacing face with tale
                                                if(j == 0) // Face at lower left corner
                                                {
                                                    if(arr[0][j] == 'o')
                                                    {
                                                        arr[0][j] = '\0';
                                                        arr[i][j] = 'o';
                                                    }

                                                    else if(arr[i][j+1] == 'o')
                                                    {
                                                        arr[i][j+1] = '\0';
                                                        arr[i][j] = 'o';
                                                    }

                                                    else if(arr[i][19] == 'o')
                                                    {
                                                        arr[i][19] = '\0';
                                                        arr[i][j] = 'o';
                                                    }
                                                }

                                                else if(j == 19) // Face at lower right corner
                                                {
                                                    if(arr[0][j] == 'o')
                                                    {
                                                        arr[0][j] = '\0';
                                                        arr[i][j] = 'o';
                                                    }

                                                    else if(arr[i][j-1] == 'o')
                                                    {
                                                        arr[i][j-1] = '\0';
                                                        arr[i][j] = 'o';
                                                    }

                                                    else if(arr[i][0] == 'o')
                                                    {
                                                        arr[i][0] = '\0';
                                                        arr[i][j] = 'o';
                                                    }
                                                }

                                                else // face at last line but not on corners
                                                {
                                                    if(arr[0][j] == 'o')
                                                    {
                                                        arr[0][j] = '\0';
                                                        arr[i][j] = 'o';
                                                    }

                                                    else if(arr[i][j-1] == 'o')
                                                    {
                                                        arr[i][j-1] = '\0';
                                                        arr[i][j] = 'o';
                                                    }

                                                    else if(arr[i][j+1] == 'o')
                                                    {
                                                        arr[i][j+1] = '\0';
                                                        arr[i][j] = 'o';
                                                    }
                                                }

                                                // Regenerating food after eat
                                                switch(arr[i-1][j])
                                                {
                                                case '*':
                                                    srand(time(0));

                                                    food = (rand() % 6);
                                                    snake = (rand() % 20);

                                                    if(arr[food][snake] == '\0')
                                                        arr[food][snake] = '*';
                                                    else
                                                    {
                                                        food = (rand() % 6);
                                                        snake = (rand() % 20);

                                                        arr[food][snake] = '*';
                                                    }

                                                    points = points + 2;
                                                    if(points >= 20)
                                                    {
                                                        level++;
                                                        points = 0;
                                                    }

                                                }
                                                arr[i-1][j] = '0';
                                                break;

                                            default:
                                                // Replacing face with tale
                                                if(j == 0) // Face at 1st column
                                                {
                                                    if(arr[i+1][j] == 'o')
                                                    {
                                                        arr[i+1][j] = '\0';
                                                        arr[i][j] = 'o';
                                                    }

                                                    else if(arr[i][j+1] == 'o')
                                                    {
                                                        arr[i][j+1] = '\0';
                                                        arr[i][j] = 'o';
                                                    }

                                                    else if(arr[i][19] == 'o')
                                                    {
                                                        arr[i][19] = '\0';
                                                        arr[i][j] = 'o';
                                                    }
                                                }

                                                else if(j == 19) // Face at last column
                                                {
                                                    if(arr[i+1][j] == 'o')
                                                    {
                                                        arr[i+1][j] = '\0';
                                                        arr[i][j] = 'o';
                                                    }

                                                    else if(arr[i][j-1] == 'o')
                                                    {
                                                        arr[i][j-1] = '\0';
                                                        arr[i][j] = 'o';
                                                    }

                                                    else if(arr[i][0] == 'o')
                                                    {
                                                        arr[i][0] = '\0';
                                                        arr[i][j] = 'o';
                                                    }
                                                }

                                                else // face is not at edges
                                                {
                                                    if(arr[i+1][j] == 'o')
                                                    {
                                                        arr[i+1][j] = '\0';
                                                        arr[i][j] = 'o';
                                                    }

                                                    else if(arr[i][j-1] == 'o')
                                                    {
                                                        arr[i][j-1] = '\0';
                                                        arr[i][j] = 'o';
                                                    }

                                                    else if(arr[i][j+1] == 'o')
                                                    {
                                                        arr[i][j+1] = '\0';
                                                        arr[i][j] = 'o';
                                                    }
                                                }

                                                // Regenerating food after eat
                                                switch(arr[i-1][j])
                                                {
                                                case '*':
                                                    srand(time(0));

                                                    food = (rand() % 6);
                                                    snake = (rand() % 20);

                                                    if(arr[food][snake] == '\0')
                                                        arr[food][snake] = '*';
                                                    else
                                                    {
                                                        food = (rand() % 6);
                                                        snake = (rand() % 20);

                                                        arr[food][snake] = '*';
                                                    }

                                                    // points
                                                    points = points + 2;
                                                    if(points >= 20)
                                                    {
                                                        level++;
                                                        points = 0;
                                                    }

                                                }
                                                arr[i-1][j] = '0';
                                                break;
                                        }

                            }
                        }
                    }
                    break;

            case '2': // leftward
                for(int i = 0; i < 6; i++)
                {
                    for(int j = 0; j < 20; j++)
                    {
                        switch(arr[i][j])
                        {
                        case '0':
                            switch(j)
                            {
                            case 0:// 1st column
                                // Replacing face with tale
                                if(i == 1 || i == 4) // face at 1st column through holes
                                {
                                    if(arr[i+1][j] == 'o')
                                    {
                                        arr[i+1][j] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i-1][j] == 'o')
                                    {
                                        arr[i-1][j] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][j+1] == 'o')
                                    {
                                        arr[i][j+1] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    // Regenerating food after eat
                                    switch(arr[i][19])
                                    {
                                    case '*':
                                        srand(time(0));

                                        food = (rand() % 6);
                                        snake = (rand() % 20);

                                        if(arr[food][snake] == '\0')
                                            arr[food][snake] = '*';
                                        else
                                        {
                                            food = (rand() % 6);
                                            snake = (rand() % 20);

                                            arr[food][snake] = '*';
                                        }

                                        // points
                                        points = points + 2;
                                        if(points >= 20)
                                        {
                                            level++;
                                            points = 0;
                                        }

                                    }
                                    arr[i][19] = '0';
                                }

                                else
                                {
                                    o = 'e';
                                }
                                break;

                            case 19:// last column
                                // Replacing face with tale
                                if(i == 0) // Face at upper right corner
                                {
                                    if(arr[i+1][j] == 'o')
                                    {
                                        arr[i+1][j] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][0] == 'o')
                                    {
                                        arr[i][0] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[5][j] == 'o')
                                    {
                                        arr[5][j] = '\0';
                                        arr[i][j] = 'o';
                                    }
                                }

                                else if(i == 5) // Face at lower right corner
                                {
                                    if(arr[i-1][j] == 'o')
                                    {
                                        arr[i-1][j] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][0] == 'o')
                                    {
                                        arr[i][0] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[0][j] == 'o')
                                    {
                                        arr[0][j] = '\0';
                                        arr[i][j] = 'o';
                                    }
                                }

                                else // face at last column but not on corners
                                {
                                    if(arr[i+1][j] == 'o')
                                    {
                                        arr[i+1][j] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i-1][j] == 'o')
                                    {
                                        arr[i-1][j] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][0] == 'o')
                                    {
                                        arr[i][0] = '\0';
                                        arr[i][j] = 'o';
                                    }
                                }

                                // Regenerating food after eat
                                switch(arr[i][j-1])
                                {
                                case '*':
                                    srand(time(0));

                                    food = (rand() % 6);
                                    snake = (rand() % 20);

                                    if(arr[food][snake] == '\0')
                                        arr[food][snake] = '*';
                                    else
                                    {
                                        food = (rand() % 6);
                                        snake = (rand() % 20);

                                        arr[food][snake] = '*';
                                    }

                                    // points
                                    points = points + 2;
                                    if(points >= 20)
                                    {
                                        level++;
                                        points = 0;
                                    }

                                }
                                arr[i][j-1] = '0';
                                break;

                            default:
                                // Replacing face with tale
                                if(i == 0) // Face at 1st row
                                {
                                    if(arr[i+1][j] == 'o')
                                    {
                                        arr[i+1][j] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][j+1] == 'o')
                                    {
                                        arr[i][j+1] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[5][j] == 'o')
                                    {
                                        arr[5][j] = '\0';
                                        arr[i][j] = 'o';
                                    }
                                }

                                else if(i == 5) // Face at last column
                                {
                                    if(arr[i-1][j] == 'o')
                                    {
                                        arr[i-1][j] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][j+1] == 'o')
                                    {
                                        arr[i][j+1] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[0][j] == 'o')
                                    {
                                        arr[0][j] = '\0';
                                        arr[i][j] = 'o';
                                    }
                                }

                                else // face is not at edges
                                {
                                    if(arr[i+1][j] == 'o')
                                    {
                                        arr[i+1][j] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i-1][j] == 'o')
                                    {
                                        arr[i-1][j] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][j+1] == 'o')
                                    {
                                        arr[i][j+1] = '\0';
                                        arr[i][j] = 'o';
                                    }
                                }

                                // Regenerating food after eat
                                switch(arr[i][j-1])
                                {
                                case '*':
                                    srand(time(0));

                                    food = (rand() % 6);
                                    snake = (rand() % 20);

                                    if(arr[food][snake] == '\0')
                                        arr[food][snake] = '*';
                                    else
                                    {
                                        food = (rand() % 6);
                                        snake = (rand() % 20);

                                        arr[food][snake] = '*';
                                    }

                                    // points
                                    points = points + 2;
                                    if(points >= 20)
                                    {
                                        level++;
                                        points = 0;
                                    }
                                }
                                arr[i][j-1] = '0';
                                break;
                            }

                        }
                    }
                }
                break;

            case '3': // downward
                for(int i=0;i<6;i++)
                {
                    for(int j=0;j<20;j++)
                    {
                        switch(arr[i][j])
                        {
                        case '0': // face founded
                            switch(i)
                            {
                            case 5: // face on last row
                                // Replacing face with tale

                                if(j == 2 || j == 3 || j == 8 || j == 9 || j == 15 || j == 16) // face through holes

                                {
                                    if(arr[i-1][j] == 'o')
                                    {
                                        arr[i-1][j] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][j+1] == 'o')
                                    {
                                        arr[i][j+1] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][j-1] == 'o')
                                    {
                                        arr[i][j-1] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    // Regenerating food after eat
                                    switch(arr[0][j])
                                    {
                                    case '*':
                                        srand(time(0));

                                        food = (rand() % 6);
                                        snake = (rand() % 20);

                                        if(arr[food][snake] == '\0')
                                            arr[food][snake] = '*';
                                        else
                                        {
                                            food = (rand() % 6);
                                            snake = (rand() % 20);

                                            arr[food][snake] = '*';
                                        }

                                        // points
                                        points = points + 2;
                                        if(points >= 20)
                                        {
                                            level++;
                                            points = 0;
                                        }
                                    }

                                    arr[0][j] = '0';
                                }

                                else
                                {
                                    o = 'e';
                                }

                                break;

                            case 0: // face on 1st row
                                // Replacing face with tale
                                if(j == 0) // Face at upper left corner
                                {
                                    if(arr[5][j] == 'o')
                                    {
                                        arr[5][j] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][j+1] == 'o')
                                    {
                                        arr[i][j+1] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][19] == 'o')
                                    {
                                        arr[i][19] = '\0';
                                        arr[i][j] = 'o';
                                    }
                                }

                                else if(j == 19) // Face at upper right corner
                                {
                                    if(arr[5][j] == 'o')
                                    {
                                        arr[5][j] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][j-1] == 'o')
                                    {
                                        arr[i][j-1] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][0] == 'o')
                                    {
                                        arr[i][0] = '\0';
                                        arr[i][j] = 'o';
                                    }
                                }

                                else // face at 1st row but not on corners
                                {
                                    if(arr[5][j] == 'o')
                                    {
                                        arr[5][j] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][j+1] == 'o')
                                    {
                                        arr[i][j+1] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][j-1] == 'o')
                                    {
                                        arr[i][j-1] = '\0';
                                        arr[i][j] = 'o';
                                    }
                                }

                                // Regenerating food after eat
                                switch(arr[i+1][j])
                                {
                                case '*':
                                    srand(time(0));

                                    food = (rand() % 6);
                                    snake = (rand() % 20);

                                    if(arr[food][snake] == '\0')
                                        arr[food][snake] = '*';
                                    else
                                    {
                                        food = (rand() % 6);
                                        snake = (rand() % 20);

                                        arr[food][snake] = '*';
                                    }

                                    // points
                                    points = points + 2;
                                    if(points >= 20)
                                    {
                                        level++;
                                        points = 0;
                                    }
                                }

                                arr[i+1][j] = '0';
                                i = 10;
                                break;

                            default:
                                // Replacing face with tale
                                if(j == 0) // Face at 1st column
                                {
                                    if(arr[i-1][j] == 'o')
                                    {
                                        arr[i-1][j] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][j+1] == 'o')
                                    {
                                        arr[i][j+1] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][19] == 'o')
                                    {
                                        arr[i][19] = '\0';
                                        arr[i][j] = 'o';
                                    }
                                }

                                else if(j == 19) // Face at last column
                                {
                                    if(arr[i-1][j] == 'o')
                                    {
                                        arr[i-1][j] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][j-1] == 'o')
                                    {
                                        arr[i][j-1] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][0] == 'o')
                                    {
                                        arr[i][0] = '\0';
                                        arr[i][j] = 'o';
                                    }
                                }

                                else // face not at edges
                                {
                                    if(arr[i-1][j] == 'o')
                                    {
                                        arr[i-1][j] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][j+1] == 'o')
                                    {
                                        arr[i][j+1] = '\0';
                                        arr[i][j] = 'o';
                                    }

                                    else if(arr[i][j-1] == 'o')
                                    {
                                        arr[i][j-1] = '\0';
                                        arr[i][j] = 'o';
                                    }
                                }

                                switch(arr[i+1][j])  // Regenerating food after eat
                                {
                                case '*':
                                    srand(time(0));

                                    food = (rand() % 6);
                                    snake = (rand() % 20);

                                    if(arr[food][snake] == '\0')
                                        arr[food][snake] = '*';
                                    else
                                    {
                                        food = (rand() % 6);
                                        snake = (rand() % 20);

                                        arr[food][snake] = '*';
                                    }

                                    // points
                                    points = points + 2;
                                    if(points >= 20)
                                    {
                                        level++;
                                        points = 0;
                                    }
                                }
                                arr[i+1][j] = '0';
                                i = 10;
                                break;
                            }

                        }
                    }
                }
                break;

            case '4': // rightward
                for(int i=0;i<6;i++)
                {
                    for(int j=0;j<20;j++)
                    {
                        switch(arr[i][j])
                        {
                            case '0':
                                switch(j)
                                {
                                case 19: // face at last column
                                    // Replacing face with tale
                                    if(i == 1 || i == 4) // face at last column but not on corners
                                    {
                                        if(arr[i+1][j] == 'o')
                                        {
                                            arr[i+1][j] = '\0';
                                            arr[i][j] = 'o';
                                        }

                                        else if(arr[i-1][j] == 'o')
                                        {
                                            arr[i-1][j] = '\0';
                                            arr[i][j] = 'o';
                                        }

                                        else if(arr[i][j-1] == 'o')
                                        {
                                            arr[i][j-1] = '\0';
                                            arr[i][j] = 'o';
                                        }

                                        // Regenerating food after eat
                                        switch(arr[i][0])
                                            {
                                            case '*':
                                                srand(time(0));

                                                food = (rand() % 6);
                                                snake = (rand() % 20);

                                                if(arr[food][snake] == '\0')
                                                    arr[food][snake] = '*';
                                                else
                                                {
                                                    food = (rand() % 6);
                                                    snake = (rand() % 20);

                                                    arr[food][snake] = '*';
                                                }

                                                // points
                                                points = points + 2;
                                                if(points >= 20)
                                                {
                                                    level++;
                                                    points = 0;
                                                }
                                            }
                                        arr[i][0] = '0';
                                    }

                                    else
                                    {
                                        o = 'e';
                                    }
                                    break;

                                case 0: // face at 1st column
                                    // Replacing face with tale
                                    if(i == 0) // Face at upper left corner
                                    {
                                        if(arr[i+1][j] == 'o')
                                        {
                                            arr[i+1][j] = '\0';
                                            arr[i][j] = 'o';
                                        }

                                        else if(arr[i][19] == 'o')
                                        {
                                            arr[i][19] = '\0';
                                            arr[i][j] = 'o';
                                        }

                                        else if(arr[5][j] == 'o')
                                        {
                                            arr[5][j] = '\0';
                                            arr[i][j] = 'o';
                                        }
                                    }

                                    else if(i == 5) // Face at lower left corner
                                    {
                                        if(arr[i-1][j] == 'o')
                                        {
                                            arr[i-1][j] = '\0';
                                            arr[i][j] = 'o';
                                        }

                                        else if(arr[i][19] == 'o')
                                        {
                                            arr[i][19] = '\0';
                                            arr[i][j] = 'o';
                                        }

                                        else if(arr[0][j] == 'o')
                                        {
                                            arr[0][j] = '\0';
                                            arr[i][j] = 'o';
                                        }
                                    }

                                    else // face at 1st column but not on corners
                                    {
                                        if(arr[i+1][j] == 'o')
                                        {
                                            arr[i+1][j] = '\0';
                                            arr[i][j] = 'o';
                                        }

                                        else if(arr[i-1][j] == 'o')
                                        {
                                            arr[i-1][j] = '\0';
                                            arr[i][j] = 'o';
                                        }

                                        else if(arr[i][19] == 'o')
                                        {
                                            arr[i][19] = '\0';
                                            arr[i][j] = 'o';
                                        }
                                    }

                                    // Regenerating food after eat
                                    switch(arr[i][j+1])
                                        {
                                        case '*':
                                            srand(time(0));

                                            food = (rand() % 6);
                                            snake = (rand() % 20);

                                            if(arr[food][snake] == '\0')
                                                arr[food][snake] = '*';
                                            else
                                            {
                                                food = (rand() % 6);
                                                snake = (rand() % 20);

                                                arr[food][snake] = '*';
                                            }

                                            // points
                                            points = points + 2;
                                            if(points >= 20)
                                            {
                                                level++;
                                                points = 0;
                                            }
                                        }
                                    arr[i][j+1] = '0';
                                    j = 20;
                                    break;

                                default:
                                    // Replacing face with tale
                                    if(i == 0) // Face at 1st row
                                    {
                                        if(arr[i+1][j] == 'o')
                                        {
                                            arr[i+1][j] = '\0';
                                            arr[i][j] = 'o';
                                        }

                                        else if(arr[i][j-1] == 'o')
                                        {
                                            arr[i][j-1] = '\0';
                                            arr[i][j] = 'o';
                                        }

                                        else if(arr[5][j] == 'o')
                                        {
                                            arr[5][j] = '\0';
                                            arr[i][j] = 'o';
                                        }
                                    }

                                    else if(i == 5) // Face at last row
                                    {
                                        if(arr[i-1][j] == 'o')
                                        {
                                            arr[i-1][j] = '\0';
                                            arr[i][j] = 'o';
                                        }

                                        else if(arr[i][j-1] == 'o')
                                        {
                                            arr[i][j-1] = '\0';
                                            arr[i][j] = 'o';
                                        }

                                        else if(arr[0][j] == 'o')
                                        {
                                            arr[0][j] = '\0';
                                            arr[i][j] = 'o';
                                        }
                                    }

                                    else // face is not at edges
                                    {
                                        if(arr[i+1][j] == 'o')
                                        {
                                            arr[i+1][j] = '\0';
                                            arr[i][j] = 'o';
                                        }

                                        else if(arr[i-1][j] == 'o')
                                        {
                                            arr[i-1][j] = '\0';
                                            arr[i][j] = 'o';
                                        }

                                        else if(arr[i][j-1] == 'o')
                                        {
                                            arr[i][j-1] = '\0';
                                            arr[i][j] = 'o';
                                        }
                                    }

                                    switch(arr[i][j+1]) // Regenerating food after eat
                                    {
                                    case '*':
                                        srand(time(0));

                                        food = (rand() % 6);
                                        snake = (rand() % 20);

                                        if(arr[food][snake] == '\0')
                                            arr[food][snake] = '*';
                                        else
                                        {
                                            food = (rand() % 6);
                                            snake = (rand() % 20);

                                            arr[food][snake] = '*';
                                        }

                                        // points
                                        points = points + 2;
                                        if(points >= 20)
                                        {
                                            level++;
                                            points = 0;
                                        }
                                    }

                                    arr[i][j+1] = '0';
                                    j = 20;
                                    break;
                                }

                        }
                    }
                }
                break;
            case 'q':
                break;

            }
    }

