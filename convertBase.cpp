#include<iostream>
using namespace std;
// n 進数を 10 進数にする
int convert(string s, int n){
  int ret = 0;
  for(char c : s){
    int tmp = 0;
    if( 'A' <= c && c <= 'Z' ) tmp = c - 'A' + 10;
    else if( '0' <= c && c <= '9' ) tmp = c - '0';
    ret = ret * n + tmp;
  }
  return ret;
}

// 10進数 n を m進数にする
string convert(int a, int m){
  string moji = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string ret = "";
  while( a != 0 ){
    int tmp = a % n;
    ret += moji[tmp];
    a /= n;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

int main(void) {
  cout << convert("0014", 16) << endl;
  cout << convert(65535, 16) << endl;

  return 0;
}
