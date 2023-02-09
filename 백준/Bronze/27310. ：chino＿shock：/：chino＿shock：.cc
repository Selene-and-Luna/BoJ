#include <iostream>

int main() {
    std::string s;
    std::cin >> s;
    int dif = s.size();
    for(char c : s) {
        if(c == ':')
            dif++;
        else if(c == '_')
            dif += 5;
    }
    std::cout << dif;
}