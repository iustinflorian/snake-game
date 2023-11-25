#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int x, y, fruitX, fruitY, score;
bool gameOver;
int tailX[100], tailY[100];
int nTail;
enum eDir { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDir dir;

void setup(){
    gameOver = false;
    dir = STOP;
    score = 0;
}

void frame(int a, int b){
    system("cls");
    cout << "Score: " << score;
    cout << endl;

    for (int i = 0; i <= a + 1; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < b; i++){
        for (int j = 0; j < a; j++){
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "0";
            else if (i == fruitY && j == fruitX)
                cout << "X";
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
            if (j == a-1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i <= a + 1; i++)
        cout << "#";
    cout<<endl;
}

void inputControls(){
    if (_kbhit()){
        switch (_getch()){
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void inputLogic(int a, int b){
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    if (x >= a) x = 0; else if (x < 0) x = a - 1;
    if (y >= b) y = 0; else if (y < 0) y = b - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    if (x == fruitX && y == fruitY) {
        score++; // crestem scorul
        fruitX = rand() % a;
        fruitY = rand() % b;
        //pozitionam fructul random
        nTail++;
    }
}
int main(){
    int width, height;
    cout << "Alegeti nivelul de dificultate: 1(usor) 2(mediu) 3(greu)" << endl;
    switch(_getch()){
        case '1':
            width = 30; height = 20;
            break;
        case '2':
            width = 15; height = 10;
            break;
        case '3':
            width = 10; height = 8;
            break;
        default:
            cout << "Valoare invalida, se reda nivelul usor. ";
            width = 30; height = 20;
            break;
    }
    cout << "Asteptati..";
    Sleep(2000);
    setup();
    x = width/2; y = height/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    while (!gameOver)
    {
        frame(width,height);
        inputControls();
        inputLogic(width,height);
        Sleep(75);
    }
}