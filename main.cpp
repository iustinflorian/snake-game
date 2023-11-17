#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// code that doesn't use object oriented programming (no classes)

const int width = 20, height = 20;
int x, y, fruitX, fruitY, score;
bool gameOver;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width/2; y = height/2; // to center the snake
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw()
{
   system("cls");
   for (int i = 0; i <= width; i++)
       cout << "#";
   cout << endl;

   for (int i = 0; i < height; i++)
   {
       for (int j = 0; j < width; j++)
       {
           if (j == 0)
               cout << "#";
           if (i == y && j == x)
               cout << "0";
               cout << " ";
           if (j == width-1)
               cout << "#";
       }
       cout << endl;
   }

   for (int i = 0; i <= width; i++)
       cout << "#";
   cout<<endl;
}
void Input()
{

}
void Logic()
{

}
int main()
{
    srand(time(0));
    Setup();
    while (!gameOver)
    {
        Draw(); Input(); Logic();

    }
}
