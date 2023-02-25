#include <bits/stdc++.h>
using namespace std;
int cnt;

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

bool miller_rabin(unsigned long long n, unsigned long long prime) {
    if(prime % n == 0) return 1;
    unsigned long long d = n - 1;
    while(1) {
        unsigned long long temp = power(prime, d, n);
        if(temp == n-1) return 1;
        if(d % 2 == 1) return (temp == 1 || temp == n-1);
        d /= 2;
    }
}

bool chkprime(unsigned long long n) {
    if(n == 2 || n == 3) return 1;
    if(n%2 == 0) return 0;
    unsigned long long witness[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for(unsigned k : witness)
        if(!miller_rabin(n, k)) {
            return 0;
            break;
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
    else if(chkprime(n))
        return n;
    __int128 a = rand() % (n - 2) + 2, c = rand() % 10 + 1, g = 1;
    __int128 b = a;
    while(g == 1) {
        a = (a * a % n + c) % n;
        b = (b * b % n + c) % n;
        b = (b * b % n + c) % n;
		if (a - b < 0)	 
            g = gcd(-1 * (a - b), n);
        else	
            g = gcd(a - b, n);
        
        if(g == n)
            return pollard_rho(n);
    }
    if(chkprime(g))
        return g;
    else
        return pollard_rho(g);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    set<unsigned long long> s;
    unsigned long long n;
    cin >> n;
    unsigned long long phi = n;
    if(n == 1) {
        cout << 1;
        return 0;
    }
    if(chkprime(n)) {
        cout << n - 1;
        return 0;
    }

    while(n > 1) {
        unsigned long long prime = pollard_rho(n);
        s.insert(prime);
            
        n /= prime;
    }
    
    for(unsigned long long k : s) {
        phi /= k;
        phi *= k - 1;
    }

    cout << phi << '\n';
}