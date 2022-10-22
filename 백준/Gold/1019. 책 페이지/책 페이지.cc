#include <iostream>
using namespace std;
long long n;
void sum(long long t){
  long long arr[10]={0,},i=1,q,c;
  while(t>0){
    q=t/(i*10);
    c=t%(i*10);
    for(int k=0; k<10; k++)  arr[k]+=q*i;
    for(int k=1; k<=c/i; k++)  arr[k]+=i;
    arr[(c/i+1)%10]+=c%i;
    t-=9*i;
    i*=10;
  }
  for(int k=0; k<10; k++) cout << arr[k] << ' ';
}
int main() {
  cin >> n;
  sum(n);
}