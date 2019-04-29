//  https://www.luogu.org/problemnew/show/P1553
//  P1553.cpp
//  luogu
//
//  Created by js on 4/29/19.
//  Copyright © 2019 js. All rights reserved.
//

#include <iostream>

using namespace std;

//  整数翻转
string int_flip (const string &str)
{
    string result = "";         //  最终结果
    
    //  从后向前遍历，给result
    for (int index = str.size()-1; index >= 0; --index) {
        result += str[index];
    }
    
    //  去除前面的0
    int i = 0;
    while (i != str.size()-1  &&  result[i] == '0')
        ++i;
    
    result = result.substr(i);
    
    return result;
}


// 小数翻转
string decimal_change (const string &first, const string &second)
{
    string first_result  = int_flip(first);         //  翻转小数点前面部分
    string second_result = int_flip(second);        //  翻转小数点后面部分
    
    //  小数末尾不为0
    if (second_result.size() > 1) {     //  如果second_result == "0", 则不需要处理
        int i = second_result.size() - 1;
        while (i != 0 && second_result[i] == '0') {
            --i;
        }
        second_result = second_result.substr(0, i+1);
    }
    
    string final_result  = first_result + "." + second_result;
    
    return final_result;
}

//  分数翻转
string fraction_change (const string &first, const string &second)
{
    string first_result  = int_flip(first);     //  分子翻转
    string second_result = int_flip(second);    //  分母翻转
    
    string final_result = first_result + "/" + second_result;   //  最终结果
    
    return final_result;
}

int main(int argc, const char *argv[])
{
    string str_num;
    cin >> str_num;     //  输入
    
    size_t point_pos   = str_num.find(".");     //  查找小数点位置
    size_t slash_pos   = str_num.find("/");     //  查找除号位置
    size_t percent_pos = str_num.find("%");     //  查找百分号位置
    
    if (point_pos != string::npos) {            //  输入的是一个小数
        //  调用decimal_change函数
        string first  = str_num.substr(0, point_pos);   //  小数点前面
        string second = str_num.substr(point_pos+1);    //  小数点后面
        cout << decimal_change(first, second) << endl;
        
    } else if (slash_pos != string::npos) {     //  输入的是一个分数
        //  调用fraction_change函数
        string first  = str_num.substr(0, slash_pos);   //  分子
        string second = str_num.substr(slash_pos+1);    //  分母
        cout << fraction_change(first, second) << endl;
        
    } else if (percent_pos != string::npos) {   //  输入的是一个百分数
        
        string int_num = str_num.substr(0, str_num.size()-1);
        cout << int_flip(int_num) << "%" << endl;
        
    } else { // 整数
        cout << int_flip(str_num) << endl;
    }
    
    return 0;
}
