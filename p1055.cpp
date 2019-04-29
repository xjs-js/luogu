#include <iostream>
#include <string>
using namespace std;

char calc_last_digit(string str)
{
    int result = 0;
    for (int i = 1; i <= str.length(); i++) {
        result += (str[i-1] - '0') * i;
    }
    if ( result % 11 == 10 )
        return 'X';
    else
        return (result % 11) + 48;
}

int main()
{
    string isbn;
    cin >> isbn;
    string str = isbn.substr(0, 1) + isbn.substr(2, 3) + isbn.substr(6, 5);
    char last_digit = isbn[isbn.length()-1];
    char right_digit = calc_last_digit(str);
    if (last_digit == right_digit) {
        cout << "Right" << endl;
    } else {
        cout << isbn.substr(0, isbn.length()-1) + right_digit << endl;
    }
    return 0;    
}
