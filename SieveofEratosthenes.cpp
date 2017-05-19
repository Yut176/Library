#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// Sieve of Eratosthenes
vector<bool> isPrime(long long int n){
  vector<bool> prime(n+1, true);
  prime[0] = false;
  prime[1] = false;
  for(long long int i=2; i<=sqrt(n); i++){
    if( !prime[i] ) continue;
    for(long long int j=i*2; j<=n; j+=i){
      prime[j] = false;
    }
  }
  return prime;
}

int main(){

  vector<bool> prime = isPrime(1000);
  cout << prime[2] << endl;
  cout << prime[4] << endl;

  return 0;
}
