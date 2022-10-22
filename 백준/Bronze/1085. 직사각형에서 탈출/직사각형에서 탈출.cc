#include <iostream>
using namespace std;
int main() {
  int x,y,w,h;
  cin >> x >> y >> w >> h;
  int t=min(w-x,h-y), q=min(x,y);
  cout << min(t,q);
}