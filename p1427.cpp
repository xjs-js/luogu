#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> array;

    while(true) {
        int num;
        cin >> num;
        if (num == 0)
            break;

        array.push_back(num);
    }

    for (auto it = array.end()-1; it >= array.begin(); --it) {
        if (it == array.end()-1)
            cout << *it;
        else {
            cout << " " << *it;
        }
    }
    return 0;
}
