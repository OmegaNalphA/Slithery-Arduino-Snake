//
//  snake.cpp
//  Snake
//
//  Created by Martin Kong and Anshul Aggarwal on 11/3/16.
//  Copyright © 2016 Martin Kong and Anshul Aggarwal. All rights reserved.
//

#include "snakey8.h"

Map::Map(){
    for(int i=0; i<xSize; i++){
        for(int j=0; j<ySize; j++){
            arr[i][j] = OFF;
        }
    }
    apple = new Apple(this, 0, 2);
    snake = new Snake(this, 0, 0);
    //srand(time(NULL));
    //apple = new Apple(this, random(8), rand(7));
    randomSeed(analogRead(0));
}
int Map::getXSize(){
    return this->xSize;
}
int Map::getYSize(){
    return this->ySize;
}
int Map::change(int x, int y, int change){
    arr[x][y] = change;
    return 1;
}
void Map::printMap(){
    for(int i=0; i<8; i++){
        digitalWrite(col[i], LOW);
        digitalWrite(row[i], HIGH);
    }
    digitalWrite(col[count%8], HIGH);
    for(int i=0; i<8; i++){
        if(arr[count%8][i]>=1){
            digitalWrite(row[i], LOW);
        }
    }
    count++;
    count = count % 8;
    delay(1);
}
int Map::move(){
    return snake->move();
}
Snake* Map::getSnake(){
    return this->snake;
}
Apple* Map::getApple(){
    return this->apple;
}
bool Map::eatApple(){
    if(snake->getX()==apple->getX() && snake->getY()==apple->getY()){
        return true;
    }
    return false;
}
int Map::colorAt(int x, int y){
    return arr[x][y];
}

Coord::Coord(int xPos, int yPos){
    x = xPos;
    y = yPos;
}

Snake::Snake(Map *map, int x, int y) {
    grow = 0;
    direction = RIGHT;
    m = map;
    xPos = x;
    yPos = y;
    m->change(xPos, yPos, SNAKE);
    //m->change(xPos+3, yPos+4, APPLE);
    Coord* c = new Coord(xPos, yPos);
    body.push(c);
}
int Snake::move(){
    switch (direction) {
        case RIGHT:
            if(yPos==m->getYSize()-1 || m->colorAt(xPos, yPos+1)==1){
                return 1;
            }
            if(grow>0){
                grow--;
            }else{
                Coord* d = body.front();
                body.pop();
                m->change(d->x, d->y, 0);
            }
            yPos += 1;
            break;
        case LEFT:
            if(yPos==0 || m->colorAt(xPos, yPos-1)==1){
                return 1;
            }
            if(grow>0){
                grow--;
            }else{
                Coord* d = body.front();
                body.pop();
                m->change(d->x, d->y, 0);
                //m->change(xPos, yPos, 0);
            }
            yPos -= 1;
            break;
        case UP:
            if(xPos==0 || m->colorAt(xPos-1, yPos)==1){
                return 1;
            }
            if(grow>0){
                grow--;
            }else{
                Coord* d = body.front();
                body.pop();
                m->change(d->x, d->y, 0);
                //m->change(xPos, yPos, 0);
            }
            xPos -= 1;
            break;
        case DOWN:
            if(xPos==m->getXSize()-1 || m->colorAt(xPos+1, yPos)==1){
                return 1;
            }
            if(grow>0){
                grow--;
            }else{
                Coord* d = body.front();
                body.pop();
                m->change(d->x, d->y, 0);
                //m->change(xPos, yPos, 0);
            }
            xPos += 1;
            break;
        default:
            break;
    }
    Coord* c = new Coord(xPos, yPos);
    body.push(c);
    m->change(c->x, c->y, 1);
    if(m->eatApple()){
        m->getApple()->change();
        getBigger(1);
    }
    return 0;
}
int Snake::getLength(){
    return (int)body.count();
}
int Snake::getX(){
    return xPos;
}
int Snake::getY(){
    return yPos;
}
void Snake::getBigger(int i){
    grow = i;
}
void Snake::changeDir(int d){
    direction = (direction+d)%4;
    //direction = 2;
}
int Snake::getDirection(){
    return direction;
}

Apple::Apple(Map* map, int x, int y) {
    m = map;
    xPos = x;
    yPos = y;
    m->change(xPos, yPos, APPLE);
}
void Apple::change(){
    xPos += 4;
    xPos = random(8);
    yPos = random(8);
    while(m->arr[xPos][yPos]==1){
        xPos = random(8);
        yPos = random(8);
    }
    m->change(xPos, yPos, APPLE);
}
int Apple::getX(){
    return xPos;
}
int Apple::getY(){
    return yPos;
}
