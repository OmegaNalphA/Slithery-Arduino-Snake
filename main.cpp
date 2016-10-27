//
//  main.cpp
//  Snake
//
//  Created by Martin Kong and Anshul Aggarwal on 10/27/16.
//  Copyright © 2016 Martin Kong. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

enum dir {UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3};
enum color { OFF = 0, SNAKE = 1, APPLE = 2, WALL = 3};

class Map{
public:
    Map(){
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                arr[i][j] = OFF;
            }
        }
		snake = new Snake(this, 0, 0);
		apple = new Apple(this, 7, 7);
    }

	int getSize() {
		return this->size;
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

	void printMap() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << arr[i][j];
			}
			cout << endl;
		}
	}
private:
	int size = 8;
    int arr[8][8];
	Snake* snake;
	Apple* apple;
    // 0 = empty, 1 = wall, 2 = apple
};

class Snake{
public:

	Snake() {

	}
	
	Snake(Map *map, int x, int y) {
		length = 1;
		direction = RIGHT;
		m = map;
		xPos = x;
		yPos = y;
		m->change(xPos, yPos, SNAKE);
	}

    void createHead(){
        
    }
private:
    int length;
    int direction;
    int xPos;
    int yPos;
    Map* m;
};

class Apple {
public:
	Apple() {
	}
	Apple(Map* map, int x, int y) {
		m = map;
		xPos = x;
		yPos = y;
		m->change(xPos, yPos, APPLE);
	}
private:
	int xPos, yPos;
	Map* m;
};

void run(){
    Map* m = new Map();
    if(m->change(0, 0, 1)==0){
        cout << "works" << endl;
    }
    //srand(time(NULL));
    m->createApple();
}

int main(int argc, const char * argv[]) {
    // insert code here...
	Map* m = new Map();
	m->printMap();
    //run();
    return 0;
}
