#include <iostream>
using namespace std;
int main(){
  int n,k,t,i=1;
  cin >> n;
  if(n>9){
    k=n/10+n%10;
    t=n%10*10+k%10;
    while(t!=n){
      if(t>9){
        k=t/10+t%10;
        t=t%10*10+k%10;
      }
      else
        t=t*11;
      i++;
    }
    cout << i;
  }
  else{
    t=n*11;
    while(t!=n){
      if(t>9){
        k=t/10+t%10;
        t=t%10*10+k%10;
      }
      else
        t=t*11;
      i++;
    }
    cout << i;
  }
}