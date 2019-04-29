#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

bool is_equal(string word1, string word2)
{
    for (char &c : word1)
        c = tolower(c);
    for (char &c : word2)
        c = tolower(c);

    return (word1 == word2);
}


int main()
{
    string word;		// 第一行单词
    string sentence;	// 句子
    // 输入

//    方法一
//    cin >> word;
//    getchar();			// 舍去第一行的换行符

    // 方法二
    getline(cin, word);
    getline(cin, sentence);

    // trick
    // 为什么要添加这个trick？
    // 为了保存句子中的最后一个单词
    sentence += " ";

    int count = 0, first_pos = 0; 	// 计数器，第一个位置

    string split_word = "";
    // 遍历整个句子，分割单词
    // 设置初试变量 split_word 为空，从前向后遍历句子，遇到正常字符添加到split_word中
    // 如果遇到空格，split_word 为一个完整的单词，将它和 word比教
    // 比较完之后，重新设置split_word为空
    for (int i = 0; i < sentence.length(); ++i) {
        if(sentence[i] == ' ') {
            if (split_word.length() != 0) {
                if (is_equal(word, split_word)) {
                    if (count == 0) first_pos = i - split_word.length();
                    ++count;
                }
            }
            split_word = "";
        }
        else {
            split_word += sentence[i];
        }
    }


    // 最后输出
    if (count == 0) {			// 如果count为0，说明第二种例子的情况
        cout << -1 << endl;
    } else {					// 否则，第一种样例，依次输出共找到多少次和第一次的位置
        cout << count << " " << first_pos << endl;
    }
    return 0;
}
