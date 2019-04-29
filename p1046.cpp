#include <iostream>

using namespace std;

int main()
{
    int *heights = new int[10];
    for (int i = 0; i < 10; ++i)
        cin >> heights[i];

    int arm = 0;
    cin >> arm;

    int count = 0;
    for (int i = 0; i < 10; ++i)
        if (heights[i] <= arm + 30)
            ++count;

    cout << count << endl;
    return 0;    
}
