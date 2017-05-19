#include<iostream>
using namespace std;
// 10 ^ 9 + 7
long long int mod = 1000000007;
long long int LLinf = (1LL << 61);

// 累乗 a^b mod p を返す
long long int powmod(long long int a, long long int b, long long int p){
  if( b == 0 ) return 1;
  if( b%2 == 0 ){
    long long int d = powmod(a, b/2, p);
    return ((d%p) * (d%p)) % p;
  }
  return ( (a%p) * (powmod(a, b-1, p)%p) ) % p;
}
int main(){
  cout << powmod(2, 1000000, mod) << endl;

  return 0;
}
