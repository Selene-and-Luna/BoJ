#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int x1,y1,r1,x2,y2,r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    float dist=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    if(dist==0){
      if(r1==r2)  cout << -1 << '\n';
      else  cout << 0 << '\n';
    }  
    else if((r1+r2)>dist && dist>abs(r2-r1))   cout << 2 << '\n';
    else if((r1+r2)==dist || abs(r2-r1)==dist)  cout << 1 << '\n';
    else  cout << 0 << '\n';
  }
}