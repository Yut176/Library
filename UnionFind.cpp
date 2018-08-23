#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<list>
#include<set>
using namespace std;
template <class T>
void inputV(vector<T> &x, int n){
  for(int i=0; i<n; i++) cin >> x[i];
}

class UnionFind {
public:
  vector<int> parent;
  vector<int> sizes;
  UnionFind(int n) : parent(n), sizes(n, 1) {
    for(int i=0; i<n; i++) parent[i] = i;
  }
  int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(sizes[x] < sizes[y]) swap(x, y);
    parent[y] = x;
    sizes[x] += sizes[y];
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return sizes[find(x)]; }
};

int main() {
  // ARC032 B
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  for(int i=0; i<m; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    uf.unite(a, b);
  }
  map<int, int> mp;
  for(int i=0; i<n; i++){
    mp[uf.find(i)]++;
  }
  cout << mp.size()-1 << endl;

  return 0;
}
