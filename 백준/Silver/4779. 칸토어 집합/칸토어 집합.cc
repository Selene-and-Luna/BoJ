#include <iostream>
#include <cmath>
using namespace std;
string s = "";

void cut(int count, int front, int back) {
    if (count == 0) return;
    int mid = front + pow(3, count) / 3;
    int end = front + pow(3, count) / 3 * 2;
    for(int i = mid; i < end; i++)  s[i] = ' ';
    cut(count - 1, front, mid - 1);
    cut(count - 1, end, back);
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        s = "";
        for (int i = 0; i < pow(3, n); i++) s += "-";
        cut(n, 0, s.size() - 1);
        cout << s << '\n';
        scanf("");
    }
}