#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  if(n%100==n){
    cout << n;
  }
  else{
    int count=99;
    for(int i=100; i<=n; i++){
      int u=i,arr[3],d1,d2;
      for(int j=2; j>=0; j--){
        arr[j]=u%10;
        u/=10;
      }
      d1=arr[2]-arr[1];  d2=arr[1]-arr[0];
      if(d1==d2)  count++;
    }
    if(n==1000)  count--;
    cout << count;
  }
}