#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
char s[][4]={"ADD", "DIV", "DUP", "MUL", "SUB"};
#define INF 30000
#define maxnode 2000
int n, a[15], b[15], found, head, tail;
struct node{
  int s[15][100];
  int t[15];
  int c[15], cn;
  node() {
    memset(s, 0, sizeof(s));
    memset(t, 0, sizeof(t));
    memset(c, 0, sizeof(c));
    cn = 0;
  }
  void clear(){
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
      case 4: return sub(); break;
      case 3: return mul(); break;
      case 1: return div(); break;
      case 2: return dup(); break;
    }
  }
} q[maxnode];
int main(){
    //freopen("uva.in", "r", stdin); 
        //freopen("uva.txt", "w", stdout);
    int cases = 0;
    while(scanf("%d", &n) == 1 && n){
      printf("Program %d\n", ++cases);
      memset(a, 0, sizeof(a));
      memset(b, 0, sizeof(b));
      head=0; tail=1;
      q[head].clear(); q[tail].clear();
      for(int i=1; i<=n; i++) {scanf("%d", &a[i]); q[0].s[i][q[0].t[i]=1] = a[i];}
      for(int i=1; i<=n; i++) scanf("%d", &b[i]);
      found = 0;
      node t;
      while(!found && head!=tail){
        t = q[head];
        int flag = 0;
        for(int i=0; i<5; i++){
          t.cn++;
          if(t.cn > 10)  break;
          t.c[t.cn] = i;
          if(t.doit(i)) {
            t.check();
            if(t.notzero()) {q[tail] = t; tail = (tail+1)%maxnode;} //q[tail++] = t;
            if(found) break;
          }
          t=q[head];
        }
        //head++;
        head = (head+1) % maxnode;
        //if(!found && ) break;
      }
      tail--;
      
      if(found) {
          if(q[tail].cn<1 || (q[tail].cn == 1 && !strcmp(s[q[tail].c[1]], "DUP"))) printf("Empty sequence\n");
          else {
              for(int i=1; i<=q[tail].cn; i++) printf("%s ", s[q[tail].c[i]]);
              putchar('\n');
          }    
      }    
      else printf("Impossible\n");
      putchar('\n');  
  }   
  return 0;
}
