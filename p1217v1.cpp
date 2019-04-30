//  https://www.luogu.org/problemnew/show/P1217
//  p1217.cpp
//  luogu
//
//  Created by js on 4/30/19.
//  Copyright © 2019 js. All rights reserved.
//

#include <iostream>
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

//  判断是否是回文
bool isPalindrome (string s)
{
    string::iterator front = s.begin();
    string::iterator back  = s.end()-1;
    
    bool is_palindrome = true;
    while (front < back) {
        if (*front != *back) {
            is_palindrome = false;
            break;
        }
        ++front;
        --back;
    }
    return is_palindrome;
}

// 构造回文
void constructPalindrome (int a, int n)
{
    int num_of_digits = 0;
    int n_copy = n;
    if (n == 0)
        num_of_digits = 1;
    else {
        while (n_copy != 0) {
            ++num_of_digits;
            n_copy /= 10;
        }
    }
    
    //  一共要构造1位、2位、3位、...、n位的回文串
    for (int i = 1; i <= num_of_digits; ++i) {
        if (i == 1) {
            for (int d1 = 1; d1 <= 9; d1+=2) {
                if (d1 < a)
                    continue;
                else if (d1 > n)
                    break;
                else {
                    if (isPrime(d1))
                        cout << d1 << endl;
                }
            }
        }
        if (i == 2) {
            for (int d1 = 1; d1 <= 9; d1 += 2) {
                int palindrome = d1*10 + d1;
                if (palindrome < a)
                    continue;
                else if (palindrome > n)
                    break;
                else {
                    if (isPrime(palindrome))
                        cout << palindrome << endl;
                }
                
            }
        }
        if (i == 3) {
            for (int d1 = 1; d1 <= 9; d1 += 2) {
                for (int d2 = 0; d2 <= 9; ++d2) {
                    int palindrome = d1 * 100 + d2 * 10 + d1;
                    if (palindrome < a)
                        continue;
                    else if (palindrome > n)
                        break;
                    else {
                        if (isPrime(palindrome))
                            cout << palindrome << endl;
                    }
                }
            }
        }
        if (i == 4) {
            for (int d1 = 1; d1 <= 9; d1 += 2) {
                for (int d2 = 0; d2 <= 9; ++ d2) {
                    int palindrome = d1*1000 + d2 * 100 + d2 * 10 + d1;
                    if (palindrome <a)
                        continue;
                    else if (palindrome > n)
                        break;
                    else {
                        if (isPrime(palindrome))
                            cout << palindrome << endl;
                    }
                }
            }
        }
        if (i == 5) {
            for (int d1 = 1; d1 <= 9; d1+=2) {
                for (int d2 = 0; d2 <= 9; d2++) {
                    for (int d3 = 0; d3 <= 9; d3++) {
                        int palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
                        if (palindrome < a)
                            continue;
                        else if (palindrome > n)
                            break;
                        else {
                            if (isPrime(palindrome))
                                cout << palindrome << endl;
                        }
                    }
                }
            }
        }
        
        if (i == 6) {
            for (int d1 = 1; d1 <= 9; d1+=2) {
                for (int d2 = 0; d2 <= 9; d2++) {
                    for (int d3 = 0; d3 <= 9; d3++) {
                        int palindrome = 100000*d1 + 10000*d2 +1000*d3 + 100*d3 + 10*d2 + d1;
                        if (palindrome < a)
                            continue;
                        else if (palindrome > n)
                            break;
                        else {
                            if (isPrime(palindrome))
                                cout << palindrome << endl;
                        }
                    }
                }
            }
        }
        
        if (i == 7) {
            for (int d1 = 1; d1 <= 9; d1+=2) {
                for (int d2 = 0; d2 <= 9; d2++) {
                    for (int d3 = 0; d3 <= 9; d3++) {
                        for (int d4 = 0; d4 <= 9; ++d4) {
                            int palindrome = 1000000*d1 + 100000*d2 + 10000*d3 +1000*d4 +100*d3 + 10*d2 + d1;
                            if (palindrome < a)
                                continue;
                            else if (palindrome > n)
                                break;
                            else {
                                if (isPrime(palindrome))
                                    cout << palindrome << endl;
                            }
                        }
                    }
                }
            }
        }
        if (i == 8) {
            for (int d1 = 1; d1 <= 9; d1+=2) {
                for (int d2 = 0; d2 <= 9; d2++) {
                    for (int d3 = 0; d3 <= 9; d3++) {
                        for (int d4 = 0; d4 <= 9; ++d4) {
                            int palindrome = 10000000*d1 + 1000000*d2 + 100000*d3 +10000*d4 + 1000*d4 +100*d3 + 10*d2 + d1;
                            if (palindrome < a)
                                continue;
                            else if (palindrome > n)
                                break;
                            else {
                                if (isPrime(palindrome))
                                    cout << palindrome << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, const char *argv[])
{
    int a, b;
    cin >> a >> b;

    constructPalindrome(a, b);
    
    
    
    
    return 0;
}
