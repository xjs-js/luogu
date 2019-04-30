//  https://www.luogu.org/problemnew/show/P1089
//  p1089.cpp
//  luogu
//
//  Created by js on 4/30/19.
//  Copyright © 2019 js. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    // 读取12个输入
    int own = 0, mom = 0;
    for (int i = 1; i <= 12; ++i) {
        int expense;
        cin >> expense;
        
        own = own + 300 - expense;
        if (own < 0) {
            cout << "-" << i << endl;
            return 0;
        } else {
            if (own >= 100) {
                mom += (own / 100) * 100;
                own -= (own / 100) * 100;
            }
        }
    }
    
    double final_money = own + mom * 1.2;
    cout << final_money << endl;
    return 0;
}
