#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pll;

class Point {
private:
    long long x, y; // coord
    long long r1, r2; // dist x / y

public:
    Point(int x, int y, int r1, int r2);
    bool operator<(Point p);
    pll getCoord() const;
    void setR(int r1, int r2);
};

Point::Point(int x, int y, int r1, int r2) {
    this->x = x;
    this->y = y;
    this->r1 = r1;
    this->r2 = r2;
}

bool Point::operator<(Point p) {
    if(r1 * p.r2 == r2 * p.r1) {
        if(y == p.y)
            return x < p.x;
        return y < p.y;
    }

    return r2 * p.r1 < r1 * p.r2;
}

pll Point::getCoord() const {
    return {x, y};
}

void Point::setR(int x, int y) {
    this->r1 = this->x - x;
    this->r2 = this->y - y;
}

long long ccw(Point &a, Point &b, Point &c) {
    pll ac = a.getCoord(), bc = b.getCoord(), cc = c.getCoord();
    return (bc.first - ac.first) * (cc.second -ac.second) - (bc.second - ac.second) * (cc.first - ac.first);
}

int main() {
    int n;
    cin >> n;
    vector<Point> v;
    for(int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        v.push_back(*(new Point(x, y, 1, 0)));
    }

    sort(v.begin(), v.end());

    pll p = v[0].getCoord();
    for(int i = 1; i < n; i++) 
        v[i].setR(p.first, p.second);

    sort(v.begin() + 1, v.end());

    stack<int> s;
    s.push(0), s.push(1);
    int con = 2;
    while(con < n) {
        while(s.size() > 1) {
            pll tmp;
            tmp.first = s.top();
            s.pop();
            tmp.second = s.top();

            if(ccw(v[tmp.second], v[tmp.first], v[con]) > 0) {
                s.push(tmp.first);
                break;
            }
        }
        s.push(con++);
    }

    cout << s.size();
}