#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char alpha_sets[26];
    memset(alpha_sets, 0, sizeof(alpha_sets));

    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string sentence;
    int max_num = 0;
    for (int i = 0; i < 4; ++i) {
        getline(cin ,sentence);
        for (int j = 0; j < sentence.length(); ++j) {
            char c = sentence[j];
            if (isalpha(c)) {
                ++alpha_sets[c-65];
                if (alpha_sets[c-65] > max_num)
                    max_num = alpha_sets[c-65];
            }
        }

    }

    for (int i = max_num; i >= 1; --i) {
        for (int j = 0; j < 26; ++j) {
            if (j != 0) {
                cout << " ";
            }
            if (alpha_sets[j] < i) {
                cout << " ";
            }  else {
                cout << "*";
            }
        }
        cout << endl;
    }

    cout << "A";
    for (int i = 1; i < alpha.length(); ++i) {
        cout << " " << alpha[i];
    }
    cout << endl;

    return 0;    
}
