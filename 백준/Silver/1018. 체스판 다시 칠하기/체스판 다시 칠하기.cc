#include <iostream>
#define mins(y,x) y<x ? y:x
using namespace std;
int main() {
  int n,m,minimum=81;
  char board[51][51];
  cin >> n >> m;
  for(int i=0; i<n; i++){
    cin >> board[i];
  }
  for(int i=0; i<n-7; i++){
    for(int j=0; j<m-7; j++){
      int w=0,b=0;
      for(int a=i; a<i+8; a++){
        for(int c=j; c<j+8; c++){
          if((a+c)%2==0){
            if(board[a][c]=='B')  w++;
            else  b++;
          }
          else{
            if(board[a][c]=='B')  b++;
            else  w++;
          }
        }
      }
      minimum=mins(minimum,b);
      minimum=mins(minimum,w);
    }
  }
  cout << minimum;
}