#include <bits/stdc++.h>
using namespace std;

unsigned long long power(__int128 base, __int128 exp, __int128 n) {
    __int128 r = 1;
    base %= n;
    while (exp) {
        if(exp % 2 == 1) r = (r * base) % n;
        exp /= 2;
        base = (base * base) % n;
    }
    return (unsigned long long)r;
}

bool miller_rabin(unsigned long long n) {
    unsigned long long witness[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    if(n == 2)    return 1;
    else if(n % 2 == 0)    return 0;
    for(unsigned long long k : witness) {
        unsigned long long d = n - 1;
        if(k == n)
            continue;
        else if(k % n == 0)
            return 0;
        while(d > 0) {
            unsigned long long tmp = power(k, d, n);
            if(tmp == n - 1)  
                break;
            else if(d % 2 == 1) {
                if(tmp == 1 || tmp == n - 1)    
                    break;
                else    
                    return 0;
            }
            d /= 2;
        }
    }
    return 1;
}

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (a < b)  swap(a, b);
    while (b != 0) {
        unsigned long long tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

unsigned long long pollard_rho(__int128 n) {
    if(n % 2 == 0)
        return 2;
    else if(miller_rabin(n))
        return n;
    __int128 a = rand() % (n - 2) + 2, c = rand() % 10 + 1, g = 1;
    __int128 b = a;
    while(g == 1) {
        a = (a * a % n + c) % n;
        b = (b * b % n + c) % n;
        b = (b * b % n + c) % n;
		if (a - b < 0)	 g = gcd(-1 * (a - b), n);
        else	g = gcd(a - b, n);
        if(g == n)
            return pollard_rho(n);
    }
    if(miller_rabin(g))
        return g;
    else
        return pollard_rho(g);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    set<unsigned long long> s;
    multiset<unsigned long long> ms;
    unsigned long long n;
    cin >> n;
    while(n > 1) {
        unsigned long long prime = pollard_rho(n);
        s.insert(prime);
        ms.insert(prime);
        n /= prime;
    }
    unsigned long long t = 1;
    for(unsigned long long k : s)
        t *= ms.count(k) + 1;
    cout << t << '\n';
}