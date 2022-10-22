#include <iostream>
using namespace std;
int main() {
  int arr[26]={}, t;
  string s;
  cin >> s;
  for(int i=0; i<s.size(); i++){
    for(int k=97; k<123; k++){
      if((char)k==s[i])
        arr[k-97]++;
    }
    for(int k=65; k<97; k++){
      if((char)k==s[i])
        arr[k-65]++;
    }
  }
  int m=arr[0];
  char l='A';
  for(int i=1; i<26; i++){
    if(m<arr[i]){
      m=arr[i];
      l=(char)(i+65);
    }
    else if(m==arr[i])
      t=arr[i];
  }
  if(m==t)
    cout << '?';
  else
    cout << l;
}