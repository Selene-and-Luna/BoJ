#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int u=0,t=0;
  while(t!=n){
    u++;
    int r=u;
    while(r!=0){
      if(r%1000==666){
        t++;
        break;
      }
      else  r/=10;
    }
  }
  cout << u;
}