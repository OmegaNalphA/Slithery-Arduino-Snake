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
#include "snake.h"

using namespace std;

void run(Map* m){
    while(true){
        m->printMap();
        cout << endl;
        if(m->move()){
            break;
        }
    }
}

int main(int argc, const char * argv[]) {
    Map* m = new Map();
    run(m);
    cout << "Final Score: " << m->getSnake()->getLength() << endl;
    return 0;
}