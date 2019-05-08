//  https://www.luogu.org/problemnew/show/P2089
//  p2089.cpp
//  luogu
//
//  Created by js on 2019/5/8.
//  Copyright © 2019 js. All rights reserved.
//

#include <iostream>
using namespace std;


// 分别对应10个调味酱, pos[0]， 不用
int pos[11];

bool is_complete = false;
int counter = 0;

void search (int i, int remain) {
    //  搜索成功
    if (i == 11 && remain == 0) {
        if (is_complete) {
            for (int i = 1; i <= 10; ++i) {
                cout << pos[i] << " ";
            }
            cout << endl;
        } else {
            counter = counter + 1;
        }
        
    }
    
    //  搜索失败 -- 10瓶酱料都放完了，还是没有满足条件
    if (i == 11 && remain != 0) {
        return ;
    }
    
    //  剪枝---10瓶中有3瓶用过了，那么剩下的美味程度应该为[7, 21]
    if (i != 11) {
        int should_min_remain = (11 - i) * 1;
        int should_max_remain = (11 - i) * 3;
        if (remain < should_min_remain || remain > should_max_remain) {
            return ;
        }
    }
    
    if (i != 11) {
        pos[i] = 1;         //  放1g，搜索下一个
        search(i+1, remain-1);
        pos[i] = 2;         //  放2g, 搜索下一个
        search(i+1, remain-2);
        pos[i] = 3;         //  放3g, 搜索下一个
        search(i+1, remain-3);
    }
    
}


int main(int argc, const char* argv[])
{
    int target = 0;   //  需要达到的美味程度
    cin >> target;    //  输入
    
    memset(pos, 0, 11);
    
    //  10种酱料，每种1～3g，则所能达到的美味程度范围为[10, 30]
    if (target < 10 || target > 30) {
        cout << 0 << endl;
        return 0;
    }
    
    //  因为这里要先输出总共有有多少种答案，所以就。。。搜索了两遍
    //  这样写也能AC，感觉是运气好，可能剪枝得好
    search(1, target);
    is_complete = true;
    cout << counter << endl;
    search(1, target);
    
}
