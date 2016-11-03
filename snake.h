#ifndef snake_h
#define snake_h

//
//  snake.h
//  Snake
//
//  Created by Martin Kong on 10/27/16.
//  Copyright © 2016 Martin Kong. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

enum dir {UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3};
enum color { OFF = 0, SNAKE = 1, APPLE = 2, WALL = 3};

class Snake;
class Apple;

class Map{
public:
    Map();
    int getXSize();
    int getYSize();
    int change(int x, int y, int change);
    //void createPoint(int i);
    void printMap();
    int move();
    Snake* getSnake();
    Apple* getApple();
    bool eatApple();        // if snake eats apple, move apple with apple->change()
private:
    int xSize = 16;
    int ySize = 32;
    int arr[16][32];
    Snake* snake;
    Apple* apple;
};

struct Coord{
    Coord(int xPos, int yPos);
    int x;
    int y;
};

class Snake{
public:
    Snake(Map* m, int x, int y);
    int move();
    int getLength();
    int getX();
    int getY();
    void getBigger(int i);
private:
    int grow;
    int direction;
    int xPos;
    int yPos;
    Map* m;
    queue<Coord*> body;         // holds the entire snake, when moving: push newest coord, pop oldest
};

class Apple{
public:
    Apple(Map* m, int x, int y);
    int getX();
    int getY();
    void change();
private:
    int xPos;
    int yPos;
    Map* m;
};



//void Map::createPoint(int i){
//    int x = rand() % xSize;
//    int y = rand() % ySize;
//    while(arr[x][y]!=0){
//        x = rand() % xSize;
//        y = rand() % ySize;
//    }
//    arr[x][y] = i;
//    cout << x << " " << y << endl;
//}

#endif /* snake_h */
