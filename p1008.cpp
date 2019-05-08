//
//  p1008.cpp
//  luogu
//
//  Created by js on 2019/5/8.
//  Copyright © 2019 js. All rights reserved.
//

//  最终答案
//  192 384 576
//  219 438 657
//  273 546 819
//  327 654 981
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//  判断a:b:c == 1:2:3
bool isRight (int a, int b, int c) {
    bool condition_1 = (b == 2*a);      // a:b = 1:2
    bool condition_2 = (c == 3*a);      // a:c = 1:3
    bool condition_3 = (2*c == 3*b);    // b:c = 2:3
    
    return condition_1 && condition_2 && condition_3;
}


int main(int argc, const char* argv[]) {
    //  新建一个大小为10的数组，初始化为0
    //  nums[i] = 1 -> 表示加入第一个数组中
    //  nums[i] = 2 -> 表示加入第二个数组中
    //  nums[i] = 3 -> 表示加入第三个数组中
    vector<int> permutation;
    for (int i = 1; i <= 9; ++i) {
        permutation.push_back(i);
    }
    
    //  1,2,3...9排列
    do {
        //  vector中前三个为组成的第一个三位数
        int num_1 = permutation[0] * 100 + permutation[1] * 10 + permutation[2];
        //  往后再推三个，成为第二个三位数
        int num_2 = permutation[3] * 100 + permutation[4] * 10 + permutation[5];
        //  往后再推三个，成为第三个三位数
        int num_3 = permutation[6] * 100 + permutation[7] * 10 + permutation[8];
        
        //  如果num_1, num_2, num_3满足1:2:3的关系，就输出到console
        if (isRight(num_1, num_2, num_3)) {
            cout << num_1 << " " << num_2 << " " << num_3 << endl;
        }
    } while (next_permutation(permutation.begin(), permutation.end()));
    
    return 0;
}
