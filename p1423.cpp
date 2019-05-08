//
//  p1423.cpp
//  luogu
//
//  Created by js on 2019/5/8.
//  Copyright © 2019 js. All rights reserved.
//

#include <iostream>

using namespace std;

int main (int argc, const char* argv[])
{
    double target = 0;   //  目标距离
    cin >> target;
    
    double current = 2;                 //  当前步长
    double sum_distance = 2;            //  总距离
    int steps = 1;                      //  当前步数
    
    while (sum_distance < target) {
        //  当前步长更改为上次步长的98%
        current = current * 0.98;
        //  步数加1
        steps   = steps + 1;
        //  增加总距离
        sum_distance = sum_distance + current;
    }
    
    cout << steps << endl;
}
