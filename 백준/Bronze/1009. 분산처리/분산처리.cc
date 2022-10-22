#include <iostream>
#include <cmath>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    unsigned long long a,b;
    cin >> a >> b;
    int u=a;
    for(int j=2; j<=b; j++){
      u=(u*a)%10;
    }
    if(u%10==0)  cout << 10 << '\n';
    else  cout << u%10 << '\n';
  }
}