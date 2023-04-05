#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int table[1002][1002];

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++) {
            if(s1[i - 1] == s2[j - 1])
                table[i][j] = table[i - 1][j - 1]+1;
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }

    string s = "";
    int sz1 = s1.size(), sz2 = s2.size();
    while(sz1 && sz2) {
        if(table[sz1 - 1][sz2] == table[sz1][sz2])
            sz1--;
        else if(table[sz1][sz2 - 1] == table[sz1][sz2])
            sz2--;
        else {
            s += s1[sz1 - 1];
            sz1--;
            sz2--;
        }
    }

    reverse(s.begin(), s.end());
    if(s.size())
        cout << table[s1.size()][s2.size()] << '\n' << s;
    else
        cout << 0;
}