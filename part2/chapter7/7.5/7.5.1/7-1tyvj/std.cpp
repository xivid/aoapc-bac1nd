#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
char s[][4]={"ADD", "SUB", "MUL", "DIV", "DUP"};
#define INF 50000000
#define maxnode 1000
int n, a[15], b[15], found, head, tail;
struct node{
  int s[15][100];
  int t[15];
  int c[100], cn;
  node() {
    memset(s, 0, sizeof(s));
    memset(t, 0, sizeof(t));
    memset(c, 0, sizeof(c));
    cn = 0;
  }
  void check(){
    found = 1;
    for(int i=1; i<=n; i++) if(s[i][t[i]]!=b[i]) {found=0; break;}
  }
  bool notzero(){
    for(int i=1; i<=n; i++){
        if(t[i]<=1) return true;
        else if(s[i][t[i]]==0 && s[i][t[i]-1]==0) return false;
        }
    return true;
  }
  bool onlyone(){
    for(int i=1; i<=n; i++) if(t[i]==1) return true;
    return false;
  }
  bool add(){
    if(onlyone()) return false;
    for(int i=1; i<=n; i++) if(abs(s[i][t[i]] + s[i][t[i]-1]) > INF)return false;
    for(int i=1; i<=n; i++) {s[i][t[i]-1] = s[i][t[i]] + s[i][t[i]-1]; t[i]--;}
    return true;
  }
  bool sub(){
    if(onlyone()) return false;
    for(int i=1; i<=n; i++) if(abs(s[i][t[i]-1] - s[i][t[i]]) > INF) return false;
    for(int i=1; i<=n; i++) {s[i][t[i]-1] = s[i][t[i]-1] - s[i][t[i]]; t[i]--;}
    return true;
  }
  bool mul(){
    if(onlyone()) return false;
    for(int i=1; i<=n; i++) if(abs(s[i][t[i]-1] * s[i][t[i]]) > INF) {
      return false;
    }
    for(int i=1; i<=n; i++) {s[i][t[i]-1] = s[i][t[i]-1] * s[i][t[i]]; t[i]--;}
    return true;
  }
  bool div(){
    if(onlyone()) return false;
    int fh;
    for(int i=1; i<=n; i++) {
      if(s[i][t[i]]==0) {
        return false;
      }
      if(abs(s[i][t[i]-1]) / abs(s[i][t[i]]) > INF){
        return false;
      }
    }
    for(int i=1; i<=n; i++) {
      if(s[i][t[i]-1]/s[i][t[i]]>=0) fh=1;
      else fh=-1;
      s[i][t[i]-1] = abs(s[i][t[i]-1]) / abs(s[i][t[i]]);
      s[i][t[i]-1]*=fh;
      t[i]--;
      }
    return true;
  }
  bool dup(){
    for(int i=1; i<=n; i++) {
      s[i][t[i]+1]=s[i][t[i]];
      t[i]++;
      }
    return true;
  }
  bool doit(int c){
    switch(c){
      case 0: return add(); break;
      case 1: return sub(); break;
      case 2: return mul(); break;
      case 3: return div(); break;
      case 4: return dup(); break;
    }
  }
} q[maxnode];
int main(){
  scanf("%d", &n);
  head=0; tail=1;
  for(int i=1; i<=n; i++) {scanf("%d%d", &a[i], &b[i]); q[0].s[i][q[0].t[i]=1] = a[i];}
  found = 0;
  node t;
  while(!found && head<tail){
    t = q[head];
    int flag = 0;
    for(int i=0; i<5; i++){
      t.cn++;
      t.c[t.cn] = i;
      if(t.doit(i)) {
        t.check();
        if(t.notzero()) q[tail++] = t;
        if(found) break;
      }
      t=q[head];
    }
    head++;
    if(!found && tail>maxnode-10) break;
  }
  tail--;
  if(found) for(int i=1; i<=q[tail].cn; i++) printf("%s ", s[q[tail].c[i]]);
  else printf("Not Found.");
  putchar('\n');  
  while(1); 
  return 0;
}
