#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int INF = 1000000000;
const int MAXN = 1000;
const int MAXM = 100000;

int n, m;
int first[MAXN], d[MAXN];
int u[MAXM], v[MAXM], w[MAXM], next[MAXM];

typedef pair<int,int> pii;

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) first[i] = -1;
  for(int e = 0; e < m; e++) {
    scanf("%d%d%d", &u[e], &v[e], &w[e]);
    next[e] = first[u[e]];
    first[u[e]] = e;
  }

  priority_queue<pii, vector<pii>, greater<pii> > q;
  //bool done[MAXN];
  for(int i = 0; i < n; i++) d[i] = (i==0 ? 0 : INF);
  //memset(done, 0, sizeof(done));
  q.push(make_pair(d[0], 0));
  while(!q.empty()) {
    pii u = q.top(); q.pop();
    int x = u.second;
    if(x==3) printf("3 occurs, u.first=%d, d[3]=%d\n", u.first, d[3]); 
    if(u.first != d[x]) {printf("node #%d: first=%d, d[x]=%d, continue\n", x,u.first,d[x]); continue;}
    //done[x] = true;
    if(x==3) printf("3 using, d[3] = %d\n", d[3]); 
    for(int e = first[x]; e != -1; e = next[e]) if(d[v[e]] > d[x]+w[e]) {

      d[v[e]] = d[x] + w[e];
      q.push(make_pair(d[v[e]], v[e]));
      printf("%d kuozhanle %d, d=%d\n",x, v[e], d[v[e]]);
    }
  }

  for(int i = 0; i < n; i++)
    printf("d[%d] = %d\n", i, d[i]);
  while(1); 
  return 0;
}
