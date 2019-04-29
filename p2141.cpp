#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> data;
    int N;
    cin >> N;
    while(N--) {
        int num;
        cin >> num;
        data.insert(num);
    }

    int count = 0;
    for (auto it = data.begin(); it != data.end(); ++it) {
        for (auto it2 = data.begin(); it2 != it; ++it2) {
            if (data.find(*it - *it2) != data.end() && (*it - *it2) != *it2) {
                ++count;
                break;
            }
        }
    }

    cout << count << endl;
    return 0;    

}
