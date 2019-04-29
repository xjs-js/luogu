#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;		//	第一行输入
    string str;	// 	第二行输入

    string low_alpha = "abcdefghijklmnopqrstuvwxyz";  //  小写的字符集
    string up_alpha  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  //  大写的字符集

    cin >> n;		//	第一行输入
    cin >> str;		//	第二行输入
    for (char &c : str) {
        if (isupper(c)) {  // 大写字母
            c = up_alpha[(c -'A' + n) % 26];
        } else {		   // 小写字母
            c = low_alpha[(c - 'a' + n) % 26];
        }
    }

    cout << str << endl;

    return 0;    
}
