#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

using namespace std;

void welcomescreen();
void maingame();
void helpscreen();

void welcomescreen()
{
    cout << "A High/Low Number Guessing game as project" << endl;
    cout << "Made by: Rahul shaw \n" << endl;
    cout << "Press any key and get started...." << endl;
    getch();
}
void helpscreen()
{
    system("cls");
    cout << "In this high/low game you are meant to guess the number decided by your computer by trial and error method and by following the hints you receive after each failure telling you if your no. you entered was higher than the actual number or lower than it. You gave 20 chances, use them cautiously! " << endl;                         //how to play instructions
    cout << "\nPress any key to return to the main menu...." << endl;
    getch();
}

void maingame()
{
    srand(time(NULL));
    while (true)
    {
        system("cls");
        int number = rand()%99 + 2;
        int guess;
        int tries = 0;
        char response;
        while (true)
        {
            cout << "Enter a number between 1 and 100. You have " << 20 - tries << " tries left" << endl;
            cin >> guess;
            if (tries >= 20)
            {
                break;
            }
            if (guess > number)
            {
                cout << "Oh! it seems too high! Try again!!" << endl;
            }
            else if (guess < number)
            {
                cout << "Oh! it seems too low! Try again!!" << endl;
            }
            else
            {
                break;
            }
            tries++;
        }
        if (tries >= 20)
        {
            cout << "Sorry! but don't worry you can try again!" << endl;
        }
        else
        {
            cout << "Congrats!! You guessed right in " << tries + 1 << " tries!" << endl;
            if (tries <= 5)
            {cout<< "You are a senior detective";
            }
            else
            {cout<< "you are quite a rookie detective";
            }
        }
        cout << "Do you want to play again??? Press 'Y' for yes and any other key for no" << endl;
        response = toupper(getch());
        if (response == 'Y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    welcomescreen();
    do
    {   system("cls");
        cout << "Main Menu:" << endl;
        cout << "1. New Game" << endl;
        cout << "2. Instructions" << endl;
        cout << "3. Exit" << endl;
        cout << "Press 1, 2 or 3 to select your chosen option...." << endl;
        char input = getch();
        switch (input)
        {
            case '1' : system("cls");
                       break;
            case '2' : helpscreen();
                       continue;
            case '3' : exit(0);
                       break;
            default : break;
        }
        maingame();
    }while(true);
    return 0;
}
