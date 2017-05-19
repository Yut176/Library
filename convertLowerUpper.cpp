#include<iostream>
using namespace std;
// 大文字と小文字の変換
char convertChar(char c){
  if( 'a' <= c && c <= 'z' ) return c - 'a' + 'A';
  else if( 'A' <= c && c <= 'Z' ) return c - 'A' + 'a';
  return c;
}
// string convertString(string s){
//   for(int i = 0; i < s.size(); i++) s[i] = convertChar(s[i]);
//   return s;
// }
int main(){

  string s = "AbCdE";
  for(int i=0; i<s.size(); i++) cout << convertChar(s[i]);
  cout << endl;
  // cout << convertString(s) << endl;

  return 0;
}
