#include <iostream>
#include <vector>

int main() {
    int r, c;
    std::vector<std::string> v;
    std::cin >> r >> c;
    int rg, cg, rp, cp;
    std::cin >> rg >> cg >> rp >> cp;
    for(int i = 0; i < r; i++) {
        std::string s;
        std::cin >> s;
        v.push_back(s);
    }

    int gsize = 0, psize = 0;
    for(std::string s : v) {
        for(char c : s) {
            if(c == 'G')
                gsize++;
            else if(c == 'P')
                psize++;
        }
    }

    if(rp * cp == psize)
        std::cout << 0;
    else
        std::cout << 1;
    return 0;
}