#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//#define debug
#define pause
char s[][4]={"ADD", "SUB", "MUL", "DIV", "DUP"};
//             +      -       *     /     copy
#define INF 30000
#define maxnode 5000
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
  #ifdef debug
  #define pause
  void print(){
    printf("stack:\n");
    for(int i=1; i<=n; i++) printf("[%d]: top=%d, %d\n",i, t[i], s[i][t[i]]);
  }
  #endif
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
    for(int i=1; i<=n; i++) if(abs(s[i][t[i]] + s[i][t[i]-1]) > INF){
      #ifdef debug
      printf("#%d add error%d: %d + %d = %d\n",i ,(abs(s[i][t[i]] + s[i][t[i]-1]) > INF),
             s[i][t[i]], s[i][t[i]-1], abs(s[i][t[i]] + s[i][t[i]-1]));
      getchar();
      #endif
     return false;
    }
    #ifdef debug
    int i=1;
    printf("#%d (%d): %d + %d = %d\n",i ,(abs(s[i][t[i]] + s[i][t[i]-1]) > INF),
             s[i][t[i]], s[i][t[i]-1], abs(s[i][t[i]] + s[i][t[i]-1]));
    getchar();
    #endif
    for(int i=1; i<=n; i++) {s[i][t[i]-1] = s[i][t[i]] + s[i][t[i]-1]; t[i]--;}
    return true;
  }
  bool sub(){
    if(onlyone()) return false;
    for(int i=1; i<=n; i++) if(abs(s[i][t[i]-1] - s[i][t[i]]) > INF){
      #ifdef debug
      printf("#%d sub error: %d - %d = %d\n",i ,s[i][t[i]-1], s[i][t[i]], abs(s[i][t[i]-1] - s[i][t[i]]));
      #endif
       return false;
    }
    #ifdef debug
    int i=1;
    printf("#%d (%d): %d - %d = %d\n",i ,(abs(s[i][t[i]] - s[i][t[i]-1]) > INF),
             s[i][t[i]], s[i][t[i]-1], abs(s[i][t[i]] - s[i][t[i]-1]));
    getchar();
    #endif
    for(int i=1; i<=n; i++) {s[i][t[i]-1] = s[i][t[i]-1] - s[i][t[i]]; t[i]--;}
    return true;
  }
  bool mul(){
    if(onlyone()) return false;
    for(int i=1; i<=n; i++) if(abs(s[i][t[i]-1] * s[i][t[i]]) > INF) {
      #ifdef debug
      printf("#%d mul error: %d * %d = %d\n",i ,s[i][t[i]-1], s[i][t[i]], abs(s[i][t[i]-1] * s[i][t[i]]));
      #endif
      return false;
    }
    #ifdef debug
    int i=1;
    printf("#%d (%d): %d * %d = %d\n",i ,(abs(s[i][t[i]] * s[i][t[i]-1]) > INF),
             s[i][t[i]], s[i][t[i]-1], abs(s[i][t[i]] * s[i][t[i]-1]));
    getchar();
    #endif
    for(int i=1; i<=n; i++) {s[i][t[i]-1] = s[i][t[i]-1] * s[i][t[i]]; t[i]--;}
    return true;
  }
  bool div(){
    if(onlyone()) return false;
    int fh;
    for(int i=1; i<=n; i++) {
      if(s[i][t[i]]==0) {
        #ifdef debug
        printf("#%d div0 error: %d / %d\n",i ,s[i][t[i]-1], s[i][t[i]]);
        #endif
        return false;
      }
      if(abs(s[i][t[i]-1]) / abs(s[i][t[i]]) > INF){
        #ifdef debug
        printf("#%d div error: %d / %d = +-%d\n",i ,s[i][t[i]-1], s[i][t[i]], abs(s[i][t[i]-1] / s[i][t[i]]));
        #endif
        return false;
      }
    }
    for(int i=1; i<=n; i++) {
      if(s[i][t[i]-1]/s[i][t[i]]>=0) fh=1;
      else fh=-1;
      #ifdef debug
      printf("#%d (%d): %d / %d = +-%d\n",i ,(abs(s[i][t[i]-1] / s[i][t[i]]) > INF),
             s[i][t[i]-1], s[i][t[i]], abs(s[i][t[i]-1] / s[i][t[i]]));

      getchar();
      #endif
      s[i][t[i]-1] = abs(s[i][t[i]-1]) / abs(s[i][t[i]]);
      s[i][t[i]-1]*=fh;
      t[i]--;
      }
    return true;
  }
  bool dup(){
    for(int i=1; i<=n; i++) {
      s[i][t[i]+1]=s[i][t[i]];
      s[i][2]=s[i][t[i]];
      #ifdef debug
      printf("#%d(top%d): %d=%d copied.\n",i , t[i] ,s[i][t[i]], s[i][2]);
      getchar();
      #endif
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
      #ifdef debug
      printf("to try %dth command\n", t.cn);
      printf("t=q[%d],top=%d , should try %d\n",head,t.t[1], i);
      printf("[top]=%d, [[top]-1]=%d\n",t.s[1][t.t[1]], t.s[1][t.t[1]-1]);
      #endif
      t.c[t.cn] = i;
      if(t.doit(i)) {
        #ifdef debug
        printf("t=q[%d], tried %d\n",head, i);
        #endif
        t.check();
        if(t.notzero()) q[tail++] = t;
        #ifdef debug
        if(t.notzero()) printf("not zero,node t-> %d\n==========\n",tail-1);
        #endif
        if(found) break;
      }
      t=q[head];
    }
    head++;
    printf("µ±Ç°²ãÊý£º%d\n", q[tail-1].cn); 
    if(!found && q[tail-1].cn>10) break;
  }
  tail--;
  if(found) for(int i=1; i<=q[tail].cn; i++) printf("%s ", s[q[tail].c[i]]);
  else printf("Not found.");
  putchar('\n');
  #ifdef pause
  system("pause");
  #endif
  
  return 0;
}
