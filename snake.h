//
//  snake.h
//  Snake
//
//  Created by Martin Kong on 10/27/16.
//  Copyright © 2016 Martin Kong. All rights reserved.
//

#ifndef snake_h
#define snake_h


//
//  main.cpp
//  Snake
//
//  Created by Martin Kong on 10/27/16.
//  Copyright © 2016 Martin Kong. All rights reserved.
//

#include <iostream>

using namespace std;

class Snake;
class Apple;

class Map{
public:
    Map();
    int change(int x, int y, int change);
    void createPoint(int i);
private:
    int arr[8][8];
    // 0 = empty, 1 = wall, 2 = apple
};

class Snake{
public:
private:
    int length;
    int direction;
    int x;
    int y;
    Map* m;
};



#endif /* snake_h */
