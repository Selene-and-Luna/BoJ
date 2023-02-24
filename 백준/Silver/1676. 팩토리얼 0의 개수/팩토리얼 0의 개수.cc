#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long fac = 1;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        fac *= i;
        fac %= 1000000000000;
        while(fac % 10 == 0) {
            fac /= 10;
            cnt++;
        }
    }
    cout << cnt;
}