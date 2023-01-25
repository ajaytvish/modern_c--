#include <iostream>
#include <conio.h>
using namespace std;
bool gameover;  //game start or end indicator
const int width = 60;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100]; //snake coordinates, max value 100
int Tail;
enum Directon {STOP = 0, LEFT,RIGHT, UP, DOWN};  //declaring the controls
Directon dir;
void Setup() {
gameover = false;
dir = STOP;
x = width / 10;    //initial location of snake head (x)
y = height / 3;    //initial location of snake head (y)
fruitX = rand() % width; //display fruit in a random place (x)
fruitY = rand() % height; score = 0; //display fruit in a random place (y)
}
void Draw() {
system("cls");  //clearing screen after each run to draw single play-board
for(int i = 0; i < width+2; i++) //so that upper bound does not start at top
cout << "-";  //upper bound creation

cout << endl ;
for (int i = 0; i < height ; i++) {
for (int j = 0; j < width; j++) {
if (j == 0)
cout << "|"; //left bound creation
if (i == y && j == x)
cout << "*"; // snake head
else if (i == fruitY && j == fruitX )
cout << "@"; // fruit
else {
bool print = false;
for (int k = 0; k< Tail ; k++) {
if (tailX [k] == j && tailY [k] == i) {      //production of first tail
cout << "-"; print = true;      //snake tail
}
}
if (!print) cout << " ";    //printing null so that space is utilized for board creation
}
if (j == width -1)
cout << "|";    //creation of right bound
}
cout << endl;
}
for (int i = 0; i< width+2; i++)   //creation of downward bound
cout << "-";
cout << endl;
cout << "Score:" << score << endl ;
}
void Input () //controls for each key press
{
if (_kbhit ()) {             //assigning keys for each direction
switch (_getch ()) {
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
dir = DOWN ;
break;
case 'x': //exit game midway
gameover = true;
break;
}
}
}
void algorithm()
{
int prevX = tailX [0];
int prevY = tailY [0];
int prev2X, prev2Y;
tailX[0] = x;
tailY[0] = y;
for(int i = 1;i < Tail ; i++) {  //starting of tail function, so game ends if player consumes tail if key presses towards the tail
prev2X = tailX[i];
prev2Y = tailY[i];
tailX[i] = prevX;
tailY[i] = prevY;
prevX = prev2X;   //swap to carry the tail consume after each point earned
prevY = prev2Y ;
}
switch (dir) {  //moving the snake coordinates to the directions necessary
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
}
if (x >= width) x =0;else if (x <0) x = width -1; //defining play-board area (x)
if (y >= height) y = 0; else if (y < 0) y = height - 1; //defining play-board area (y)
for (int i =0; i< Tail ;i++)
if (tailX[i] == x && tailY[i] == y) //if direction is towards tail, game ends
gameover = true;
if (x == fruitX && y == fruitY) { //score increase after eating fruit
score +=10;
fruitX = rand() % width; //random generation of fruit (x)
fruitY = rand() % height; //random generation of fruit(y)
Tail ++;  //tail growth after eating fruit
}
}
int main()
{
Setup(); //generation and placing of board, snake and first fruit
while (!gameover) {  //performing functions at condition !gameover
Draw ();
Input ();
algorithm ();
}
return 0;
}