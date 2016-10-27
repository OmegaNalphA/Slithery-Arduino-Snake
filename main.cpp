//
//  main.cpp
//  Snake
//
//  Created by Martin Kong on 10/27/16.
//  Copyright © 2016 Martin Kong. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

class Map{
public:
    Map(){
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                arr[i][j] = 0;
            }
        }
    }
    int change(int x, int y, int change){
        arr[x][y] = change;
        return 1;
    }
    void createPoint(int i){
        int x = rand() % 8;
        int y = rand() % 8;
        while(arr[x][y]!=0){
            x = rand() % 8;
            y = rand() % 8;
        }
        arr[x][y] = i;
        cout << x << " " << y << endl;
    }
private:
    int arr[8][8];
    // 0 = empty, 1 = wall, 2 = apple
};

class Snake{
public:
    void createHead(){
        
    }
private:
    int length;
    int direction;
    int x;
    int y;
    Map* m;
};

void run(){
    Map* m = new Map();
    if(m->change(0, 0, 1)==0){
        cout << "works" << endl;
    }
    srand(time(NULL));
    m->createApple();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    run();
    return 0;
}
