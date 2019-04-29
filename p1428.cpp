#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num;			// 	鱼的数量
    int score;			//  鱼的可爱程度
    vector<int> array;  //  列表
    cin >> num;
    while (num--) {
        cin >> score;
        array.push_back(score);
    }

    for (int i = 0; i < array.size(); ++i) {
        int count = 0;  //  统计变量
        //  向前寻找
        for (int j = 0; j <= i; ++j)
            if (array[j] < array[i])
                ++count;
        // 格式化输出
        if (i == 0) cout << count;
        else 		cout << " " << count;
    }

    return 0;    
}
