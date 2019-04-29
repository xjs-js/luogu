#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 输入
    int L, M;
    cin >> L >> M;

    // 定义，打表， true表示这棵树是存在的
    vector<bool> trees(L+1, true);


    // 输入
    int left, right;
    while(M--) {  // 循环
        cin >> left >> right;
        for (int i = left; i <= right; ++i)
            trees[i] = false;
    }

    // 结果
    int count = 0;
    for (int i = 0; i <= L ; ++i)
        if (trees[i])
            ++ count;

    cout << count << endl;

    return 0;
}
