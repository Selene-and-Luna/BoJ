#include <iostream>
using namespace std;
long long l,u;
long long sum(long long n){
  if(n<=0)  return 0;
  long long arr[10]={0,},r=0,i=1,q,c;
  while(n>0){
    q=n/(i*10);
    c=n%(i*10);
    for(int k=0; k<10; k++)  arr[k]+=q*i;
    for(int k=1; k<=c/i; k++)  arr[k]+=i;
    arr[(c/i+1)%10]+=c%i;
    n-=9*i;
    i*=10;
  }
  for(int k=0; k<10; k++) r+=k*arr[k];
  return r;
}
int main() {
  cin >> l >> u;
  cout << sum(u)-sum(l-1);
}