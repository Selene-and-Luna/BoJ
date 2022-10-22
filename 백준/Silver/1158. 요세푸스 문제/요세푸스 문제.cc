#include <iostream>
#include <queue>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k;
  queue<int> q;
  cin >> n >> k;
  for(int i=1; i<=n; i++){
    q.push(i);
  }
  int t=0;
  cout << '<';
  while(!q.empty()){
    t++;
    if(t%k==0){
      if(q.front()==q.back())  cout << q.front() << '>';
      else  cout << q.front() << ',' << ' ';
      q.pop();
    }
    else{
      q.push(q.front());
      q.pop();
    }
  }
}