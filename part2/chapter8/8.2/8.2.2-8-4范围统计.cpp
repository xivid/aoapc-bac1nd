#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 10000;
int v[maxn];
int main(){
  int n, m, a, b;
  scanf("%d", &n);
  for(int i=1; i<=n ;i++) scanf("%d", v+i);
  sort(v+1, v+n+1);
  while(m--){
    scanf("%d%d", &a, &b);
    cout << upper_bound(v+1, v+n+1, b)-lower_bound(v+1, v+n+1, a) << endl;
  }
  return 0;
}
