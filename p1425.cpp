#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    int e, f;
    cin >> a >> b >> c >> d;

    int delta = c*60 + d - a*60 - b;
    e = delta / 60;
    f = delta % 60;
    cout << e << " " << f << endl;
    return 0;    
}
