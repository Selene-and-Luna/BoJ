#include <iostream>
#include <vector>
using namespace std;
int wcnt = 0, bcnt = 0;
vector<vector<bool> > color_paper;

void DC(int ys, int xs, int ye, int xe) { // y/x start, y/x end
    bool head = color_paper[ys][xs];
    // if(ys > ye || xs > xe) {
    //     cout << "ERR\n";
    //     return;
    // }
    // cout << head << '\n';
    // printf("%d %d %d %d\n", ys, xs, ye, xe);
    for(int i = ys; i <= ye; i++) {
        for(int j = xs; j <= xe; j++) {
            if(color_paper[i][j] != head) {
                DC(ys, xs, (ys + ye) / 2, (xs + xe) / 2);
                DC((ys + ye) / 2 + 1, xs, ye, (xs + xe) / 2);
                DC(ys, (xs + xe) / 2 + 1, (ys + ye) / 2, xe);
                DC((ys + ye) / 2 + 1, (xs + xe) / 2 + 1, ye, xe);
                return;
            }
        }
    }

    if(head)
        bcnt++;
    else
        wcnt++;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        vector<bool> tmp;
        for(int j = 0; j < n; j++) {
            bool t;
            cin >> t;
            tmp.push_back(t);
        }
        color_paper.push_back(tmp);
    }
    DC(0, 0, n - 1, n - 1);
    cout << wcnt << '\n' << bcnt;
}