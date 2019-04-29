#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int max_length = 0;    //  初始化最长天数
    int count = 0;		   //  当前计数
    int N; 				   //  数据个数
    cin >> N;			   //  输入

    int current, last = -999; //  记住这次和上次
    //  循环输入
    while (N--) {
        cin >> current;

        //  如果气温变高了
        if (current >= last) {
            ++count;		   //  计数器加1
            last = current;    //  更新 last
        }
        else {				   //  否则，如果气温变低了
            if (count > max_length)  //  更新 max_length
                max_length = count;
            count = 1;				 //  重置 count
            last = current;			 //  更新 last
        }
    }

    //  特殊情况处理：天气都是递增的，如1,2,3,4,5
    if (count > max_length)
        max_length = count;
    cout << max_length << endl;

    return 0;    
}
