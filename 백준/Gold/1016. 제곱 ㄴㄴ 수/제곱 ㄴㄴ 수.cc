#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long min, max, s = 0;
    cin >> min >> max;
    vector<bool> sqaured(max - min + 1, false);
    long long i = 2;
    while (i * i <= max) {
        long long num = min / (i * i);
        if (min % (i * i) != 0)    num++;
        while (num * (i * i) <= max) {
            if (sqaured[num * (i * i) - min] == false) {
                sqaured[num * (i * i) - min] = true;
                s++;
            }
            num++;
        }
        i++;
    }
    cout << max - min + 1 - s;
}