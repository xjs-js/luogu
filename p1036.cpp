//  https://www.luogu.org/problemnew/show/P1036
//  p1036.cpp
//  luogu
//
//  Created by js on 4/29/19.
//  Copyright © 2019 js. All rights reserved.
//
//  TAGS：Complete Search - subset

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//  判断n是否为素数
bool isPrime(int n)
{
    if (n == 1)         //  如果是1，直接返回false
        return false;
    if (n == 2)         //  如果是2，直接返回true
        return true;
    
    bool is_prime = true; //  FLAG
    for (int i = 2; i <= int(sqrt(n))+1; ++i) {  //  用sqrt(n)， 而不是n/2
        if (n % i == 0) {   //  找到了一个因数
            is_prime = false;
            break;
        }
    }
    
    return is_prime;
}

//  一个数字n转化为二进制后，包含多少个1
//  7，转换为二进制后为 111， 包含3个1，返回3
//  8，转换为二进制后为 1000， 包含1个1，返回1
int countBits (int n)
{
    int count = 0;  // 计数器
    
    while(n) {
        if (n & 1)     // 最右边一位是否为1
            ++count;
        n = n >> 1;    // 向右移一位，直到为0
    }
    
    return count;   //  返回最终的计数器
}

//  生成所有位数为3的子集
//  迭代法，生成子集，
int search (const vector<int> &nums, int n, int k)
{
    int result = 0;
    for (int b = 0; b < (1<<n); ++b) {      //  外层循环，2^n
        if (countBits(b) != k)              //  题目要求k个数加起来
            continue;
        
        int sum = 0;                        //  三个数的和
        for (int i = 0; i < n; ++i) {
            if (b & (1<<i)) {
                sum += nums[i];
            }
        }
        if (isPrime(sum)) {                 //  如果为素数，计数器加1
            ++result;
        }
    }
    return result;
}

int main(int argc, const char *argv[])
{
    int n, k;
    cin >> n >> k;
    
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    
    cout << search(nums, n, k) << endl;
    
    return 0;
}
