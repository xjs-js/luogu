#include <iostream>
#include <string>

using namespace std;

// 根据规则将字符串转化为数字
long long int str_to_num(string str)
{
    long long int result = 1;
    for (char c : str) {
        result *= (c-'A'+1);
    }
    return (result) % 47;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    if (str_to_num(str1) == str_to_num(str2)) {
        cout << "GO" << endl;
    } else {
        cout << "STAY" << endl;
    }
    return 0;    
}
