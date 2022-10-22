#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n=0;
  for(int i=0; i<8; i++){
    for(int k=0; k<8; k++){
      char c;
      cin >> c;
      if(i%2==0 && k%2==0 && c=='F')  n++;
      else if(i%2==1 && k%2==1 && c=='F')  n++;
    }
  }
  cout << n;
}