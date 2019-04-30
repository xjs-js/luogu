//  https://www.luogu.org/problemnew/show/P1217
//  p1217.cpp
//  luogu
//
//  Created by js on 4/30/19.
//  Copyright © 2019 js. All rights reserved.
//

#include <iostream>
#include <cmath>        // sqrt
#include <algorithm>    // reverse
#include <cstdlib>      // atoi
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


//  计算一个数占几位，如num=111，返回3
int numOfDigits(int num)
{
    if (num == 0)   return 1;
    
    int count = 0;
    while (num != 0) {
        ++count;
        num /= 10;
    }
    return count;
}



// 构造n_digits位的回文
void constructPalindrome (int n_digits, int a, int b)
{
    //  特殊情况，只有1位，遍历一遍2～9
    if (n_digits == 1) {
        for (int i = 2; i <= 9; ++i) {
            if (i < a) continue;        //  小于下界，不符合
            else if (i > b) break;      //  大于上届，不符合
            else {                      //  在[a,b]之间
                if (isPrime(i))         //  是素数，输出
                    cout << i << endl;
            }
        }
    }
    else {
        int start = 1 * pow(10, n_digits/2-1);
        for (int j = start; j < 1*pow(10, n_digits/2); ++j) {   // 假设j = 12
            string first = to_string(j);                        // first = "12"
            string first_reversed = first;
            // first_reversed = "21"
            reverse(first_reversed.begin(), first_reversed.end());
            
            string final_string;
            if (n_digits % 2 == 0) {
                final_string = first + first_reversed;  // final_string = "1221"
                int num = atoi(final_string.c_str());   // num = 1221
                // 重复之前的逻辑
                if (num < a) continue;
                else if (num > b) break;
                else {
                    if (isPrime(num))
                        cout << num << endl;
                }
            } else {
                
                for (int i = 0; i <= 9; ++i) {         // 在中间插入
                    final_string = first + to_string(i) + first_reversed;
                    int num = atoi(final_string.c_str());
                    // 重复之前的逻辑
                    if (num < a) continue;
                    else if (num > b) break;
                    else {
                        if (isPrime(num))
                            cout << num << endl;
                    }
                }
            }
        }
    }
}


// 根据a和b的位数构造回文
void constructPalindrome (int a, int b)
{
    int num_of_digits_a = numOfDigits(a);
    int num_of_digits_b = numOfDigits(b);
    
    //  调用重载函数
    for (int i = num_of_digits_a; i <= num_of_digits_b; ++i)
        constructPalindrome(i, a, b);
}

int main(int argc, const char *argv[])
{
    int a, b;           //  定义输入变量
    cin >> a >> b;      //  从cin输入
    
    constructPalindrome(a, b);  //  调用函数
    return 0;
}
