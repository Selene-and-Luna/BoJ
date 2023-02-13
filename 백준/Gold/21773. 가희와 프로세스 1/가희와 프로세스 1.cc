#include <iostream>
#include <queue>

struct compare {
    bool operator()(std::pair<int, std::pair<int, int> > a, \
                std::pair<int, std::pair<int ,int> > b) {
        if(a.first == b.first)
            return a.second.first > b.second.first;
        
        return a.first < b.first;
    }
};

int main() {
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int t, n;
    std::cin >> t >> n;
    std::priority_queue<std::pair<int, std::pair<int, int> >, \
    std::vector<std::pair<int, std::pair<int, int> > >, compare> process; // {priority, {id, time} }
    while(n--) {
        int a, b, c; // id, time, priority
        std::cin >> a >> b >> c;
        process.push({c, {a, b}});
    }
    
    while(t--) {
        if(process.empty())
            break;
        std::pair<int, std::pair<int, int> > p = process.top();
        process.pop();
        std::cout << p.second.first << '\n';
        p.second.second--;
        p.first--;
        if(p.second.second)
            process.push(p);
    }

    return 0;
}