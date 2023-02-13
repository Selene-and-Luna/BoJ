#include <iostream>
#include <map>
// #include <windows.h>
using namespace std;
map<long long, long long> m; // idx, value

// mod 1,000,000,007 / 1 <= n <= 1,000,000,000,000,000,000

long long fib(long long n) {
    // cout << n << " Call\n";
    // Sleep(500);
    if(n == 1 || n == 2)
        return 1;
    else if(!n)
        return 0;
    
    if(m.find(n) != m.end())
        return (*m.find(n)).second;
    
    long long tmp;
    if(n % 2)
        tmp = (fib(n / 2 + 1) * fib(n / 2 + 1) + fib(n / 2) * fib(n / 2)) % 1000000007;
    else
        tmp = (fib(n / 2 + 1) * fib(n / 2) + fib(n / 2) * fib(n / 2 - 1)) % 1000000007;
    m.insert({n, tmp});
    return tmp;
}

int main() {
    long long n;
    cin >> n;
    cout << fib(n);
}