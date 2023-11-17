#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int x, y, fruitX, fruitY, score;
bool gameOver;
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
           else
               cout << " ";
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
    switch (dir){
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
    if (x > a || x < 0 || y > b || y < 0)
        gameOver = true;
    if (x == fruitX && y == fruitY) {
        score++;
        fruitX = rand() % a;
        fruitY = rand() % b;
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
        frame(width ,height); inputControls(); inputLogic(width,height);
        Sleep(100);
    }
}
