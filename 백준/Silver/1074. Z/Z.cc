#include <iostream>
using namespace std;
int N,r,c;
int Z(int y,int x,int n){
  if(n==0)  return 0;
  else  return 2*(y%2)+(x%2)+4*Z(y/2,x/2,n-1);
}
int main() {
  cin >> N >> r >> c;
  cout << Z(r,c,N);
}