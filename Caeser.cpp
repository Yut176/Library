#include<iostream>
using namespace std;

// rot ずらす シーザー暗号
char Caeser(char c, int rot){
  while( rot < 0 ) rot += 26;
  rot %= 26;
  if( 'a' <= c && c <= 'z' ){
    if( c + rot > 'z' ) c = 'a' + (c + rot) % 'z' - 1;
    else c += rot;
  }else if( 'A' <= c && c <= 'Z' ){
    if( c + rot > 'Z' ) c = 'A' + (c + rot) % 'Z' - 1;
    else c += rot;
  }
  return c;
}
int main(){

  for(int i=0; i<30; i++){
    cout << Caeser('a', i);
  }
  cout << endl;

  return 0;
}
