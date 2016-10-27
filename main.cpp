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

class Snake{
    int length;
    int direction;
    int x;
    int y;
};

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
        if(x<8 && x>=0 && y<8 && y>=0){
            arr[x][y] = change;
            return 0;
        }
        return 1;
    }
    void createApple(){
        int x_apple = rand() % 8;
        int y_apple = rand() % 8;
        while(arr[x_apple][y_apple]!=0){
            x_apple = rand() % 8;
            y_apple = rand() % 8;
        }
        arr[x_apple][y_apple] = 2;
        cout << x_apple << " " << y_apple << endl;
    }
private:
    int arr[8][8];
    // 0 = empty, 1 = wall, 2 = apple
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
