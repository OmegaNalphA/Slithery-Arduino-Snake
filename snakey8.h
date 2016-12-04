#ifndef snake_h
#define snake_h

//
//  snake.h
//  Snake
//
//  Created by Martin Kong on 10/27/16.
//  Copyright © 2016 Martin Kong. All rights reserved.
//

#include <Arduino.h>
#include <QueueArray.h>

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
    void printMap();
    int move();
    Snake* getSnake();
    Apple* getApple();
    bool eatApple();        // if snake eats apple, move apple with apple->change()
    int colorAt(int x, int y);
    int arr[8][8];
private:
    int xSize = 8;
    int ySize = 8;
    Snake* snake;
    Apple* apple;
    int count = 0;
    const int row[8] = {16, 12, 18, 13, 5, 19, 7, 2};
    const int col[8] = {6, 11, 10, 3, 17, 4, 8, 9};
};

struct Coord{
    Coord(int xPos, int yPos);
    int x;
    int y;
};

class Snake{
public:
    Snake(Map* m, int x, int y);
    int move();             // move the snake in its current direction, check if valid
    int getLength();
    int getX();
    int getY();
    void getBigger(int i);
    void changeDir(int i);
    int getDirection();
private:
    int grow;
    int direction;
    int xPos;
    int yPos;
    Map* m;
    QueueArray<Coord*> body;         // holds the entire snake, when moving: push newest coord, pop oldest
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

#endif /* snake_h */
