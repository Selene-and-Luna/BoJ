#include <iostream>
#include <deque>
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        string order;
        bool error = 0;
        deque<int> d;
        cin >> order >> n;
        // scanf("\n");
        // if(n == 0)
        //     scanf("[]");
        // else if(n == 1) {
        //     int u;
        //     scanf("[%d]",&u);
        //     d.pb(u);
        // }
        // else {
        //     for(int i = 1; i <= n; i++){
        //         int u;
        //         if(i == 1)  
        //             scanf("[%d,",&u);
        //         else if(i == n)  
        //             scanf("%d]",&u);
        //         else  
        //             scanf("%d,",&u);
        //         d.pb(u);
        //     }
        // }
        string num;
        cin >> num;
        for(int i = 0; i < num.size(); i++) {
            if(num[i] >= '0' && num[i] <= '9') {
                string tmp = "";
                while(num[i] >= '0' && num[i] <= '9')
                    tmp += num[i++];
                i--;
                d.push_back(stoi(tmp));
            }
        }
        bool reverse = 0;
        int frontidx = 0, backidx = d.size() - 1;
        for(char ord : order){
            if(ord == 'R'){
                if(frontidx == backidx)
                    continue;
                if(reverse)
                    reverse = 0;
                else
                    reverse = 1;
            }
            else if(ord == 'D'){
                if(frontidx > backidx){
                    error=true;
                    break;
                }
                if(!reverse)
                    frontidx++;
                else
                    backidx--;
            }
        }
        if(error == true)  
            cout << "error";
        else if(frontidx > backidx)  
            cout << "[]";
        else {
            cout << '[';
            if(frontidx == backidx) 
                cout << d[frontidx] << "]";
            else if(!reverse) {
                for(int i = frontidx; i < backidx; i++)
                    cout << d[i] << ",";
                cout << d[backidx] << "]";
            }
            else {
                for(int i = backidx; i > frontidx; i--)
                    cout << d[i] << ",";
                cout << d[frontidx] << "]";
            }
        }
        if(t > 0)
            cout << '\n';
    }
}