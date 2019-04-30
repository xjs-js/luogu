//  https://www.luogu.org/problemnew/show/P1149
//  p1149.cpp
//  luogu
//
//  Created by js on 4/30/19.
//  Copyright © 2019 js. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//  0有6根火柴，1有两根火柴，3有5根火柴...
int matches_at[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

//  将一个整数转换为多少根火柴，如12有7根火柴
int numToMatches (int num)
{
    if (num == 0)
        return matches_at[0];
    
    int result = 0;
    while (num) {
        int digit = num % 10;
        result += matches_at[digit];
        num = num / 10;
    }
    return result;
}

//  判断a+b=c的火柴个数是否等于n
bool matchesEqual (int a, int b, int n)
{
    int c = a + b;
    int result = numToMatches(a) + numToMatches(b) + numToMatches(c) + 4;
    
    return (result == n);
}



int main(int argc, const char *argv[])
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i <= 1000; ++i) {           //  随便试出来的
        for (int j = 0; j <= 1000; ++j) {       //  随便试出来的
            if (matchesEqual(i, j, n)) {        //  满足条件
                ++count;                        //  计数器加1
            }
        }
    }
    
    cout << count << endl;
    return 0;
}
