#include <iostream>
#include <deque>
using namespace std;
int main() {
  deque<int> d;
  int n,m,r=0;
  cin >> n >> m;
  for(int i=1; i<=n; i++){
    d.push_back(i);
  }
  while(m--){
    int t,idx;
    cin >> t;
    for(int i=0; i<d.size(); i++){
      if(d[i]==t){
        idx=i;
        break;
      }
    }
    if(idx>=d.size()-idx){
      while(1){
        if(t==d.front()){
          d.pop_front();
//          cout << r << '\n';
          break;
        }
        else{
          d.push_front(d.back());
          d.pop_back();
          r++;
        }
      }
    }
    else{
      while(1){
        if(t==d.front()){
          d.pop_front();
//          cout << r << '\n';
          break;
        }
        else{
          d.push_back(d.front());
          d.pop_front();
          r++;
        }
      }
    }
  }
  cout << r;
}