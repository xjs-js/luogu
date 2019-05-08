//
//  p1035.cpp
//  luogu
//
//  Created by js on 2019/5/8.
//  Copyright © 2019 js. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char* argv[])
{
    int K = 0;  //  输入
    cin >> K;   //  输入
    
    // Sn = 1 + 1/2 + 1/3 + ...
    double sum = 0;
    int i = 0;
    while (!(sum > K)) {
        ++i;
        sum += 1.0 / i;
    }
    
    //  输出最后的i
    cout << i << endl;
    
    return 0;
}
