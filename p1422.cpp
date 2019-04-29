#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int power = 0;
    cin >> power;
    double money = 0;

    if      (power <= 150)				   money = power * 0.4463;
    else if (power >= 151 && power <= 400) money = 150 * 0.4463 + (power-150)*0.4663;
    else    							   money = 150 * 0.4463 + 250 * 0.4663 + (power-400) * 0.5663;

    cout << fixed << setprecision(1) << money << endl;
    return 0;
}
