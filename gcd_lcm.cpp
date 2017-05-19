#include<iostream>
#include<cmath>
using namespace std;
// 10 ^ 9 + 7
long long int mod = 1000000007;
long long int LLinf = (1LL << 61);

long long int gcd(long long int a, long long int b){
  if( a == 0 || b == 0 ) return 0;
  long long int c;
  while( a != 0 ){
    c = a; a = b%a; b = c;
  }
  return b;
}
long long int lcm(long long int a, long long int b){
  if( a == 0 || b == 0 ) return 0;
  return ( a / gcd(a, b) ) * b;
}

int main(){

  cout << gcd(3,9) << endl;
  cout << lcm(3,9) << endl;

  return 0;
}
