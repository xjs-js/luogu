//  https://www.luogu.org/problemnew/show/P1909
//  p1909.cpp
//  luogu
//
//  Created by js on 4/30/19.
//  Copyright © 2019 js. All rights reserved.
//

#include <iostream>
#include <climits>
using namespace std;


int main(int argc, const char *argv[])
{
    int target = 0;    //  需要买的铅笔数
    int min_money = INT_MAX; //  最少需要多少钱
    
    cin >> target;
    int N = 3;
    while (N--) {
        int num, price, money;
        cin >> num >> price;
        
        if (target % num == 0) {    //  不需要多买
            money = target / num * price;
        } else {                    //  需要多买一盒
            money = (target / num + 1 ) * price;
        }
        
        if (money < min_money)
            min_money = money;
    }
    
    cout << min_money << endl;
    return 0;
}
