#include<iostream>
using namespace std;
/* 組み合わせ, 重複組み合わせの計算をする
 * init() -> 必ず実行 O(n)
 */
const int mod = 1e9+7;
const int maxsize = 500001;
long long int fac[maxsize], finv[maxsize], inv[maxsize];
void init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i=2; i<maxsize; i++){
    fac[i] = fac[i-1] * i % mod;
    inv[i] = mod - inv[mod%i] * (mod/i) % mod;
    finv[i] = finv[i-1] * inv[i] % mod;
  }
}

long long int nCk(int n, int k, int mod){
  if( n < k ) return 0;
  if(n<0 || k<0) return 0;
  return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}

long long int nHk(int n, int k, int mod){
  return nCk(n+k-1, n-1, mod);
}

int main() {
  int n, k; cin >> n >> k;

  init();
  cout << nCk(n, k, mod) << endl;

  return 0;
}
