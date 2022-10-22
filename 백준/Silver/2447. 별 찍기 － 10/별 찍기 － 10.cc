#include <iostream>
#include <cmath>
using namespace std;
void star(int y, int x, int n){
  if((y/n)%3==1 && (x/n)%3==1)  cout << ' ';
  else{
    if(n/3==0)  cout << '*';
    else  star(y,x,n/3);
  }
}
int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      star(i,j,n);
    }
    cout << '\n';
  }
}