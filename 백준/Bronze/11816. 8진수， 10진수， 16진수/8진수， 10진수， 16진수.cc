#include <iostream>
#include <cmath>

int main() {
    std::string x;
    std::cin >> x;
    if(x.size() == 1)
        std::cout << x;
    else if(x[1] == 'x') {
        int result = 0;
        for(int i = 2; i < x.size(); i++) {
            if(x[i] >= '0' && x[i] <= '9')
                result += (x[i] - '0') * pow(16, (x.size() - i - 1));
            else
                result += (x[i] - 'a' + 10) * pow(16, (x.size() - i - 1));
        }
        std::cout << result;
    }
    else if(x[0] == '0') {
        int result = 0;
        for(int i = 1; i < x.size(); i++) {
            result += (x[i] - '0') * pow(8, (x.size() - i - 1));
        }
        std::cout << result;
    }
    else
        std::cout << x;
    return 0;
}