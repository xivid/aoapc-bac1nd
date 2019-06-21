#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;
struct Tnode{
  char c;
  int p;
  Tnode* lc;
  Tnode* rc;
  Tnode() {c='\0'; p=0; lc=rc=NULL;}
};
Tnode *node[100], *queue[100];
int n, front1, front2, rear1, rear2;
bool cmp(Tnode* a, Tnode* b){
  return (a->p) < (b->p);
}
int code[100]={0};
void dfs(Tnode* u, int cur){
  if(u->lc==NULL && u->rc==NULL) {
    printf("%c(%d): ", u->c ,u->p);
    for(int i=0; i<cur; i++) printf("%d", code[i]);
    printf("\n");
  }
  else{
    code[cur] = 1;
    dfs(u->lc, cur+1);
    code[cur] = 0;
    dfs(u->rc, cur+1);
  }
}
int main(){
  char ch;
  int p;
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    do{ch=getchar();} while(!isalpha(ch));
    scanf("%d", &p);
    node[i] = new Tnode;
    node[i]->c = ch;
    node[i]->p = p;
  }
  sort(node+1, node+n+1, cmp);
  front1= 1; rear1= n+1;
  front2= 1; rear2= 1;
  Tnode *p1, *p2, *np;
  for(int i=1; i<n; i++){
    if(front2+1>rear2 || (front1+1<=rear1 && node[front1]->p < queue[front2]->p)) p1 = node[front1++];
    else p1 = queue[front2++];
    if(front2+1>rear2 || (front1+1<=rear1 && node[front1]->p < queue[front2]->p)) p2 = node[front1++];
    else p2 = queue[front2++];
    np = new Tnode;
    np->p = p1->p + p2->p;
    np->lc = p1;
    np->rc = p2;
    queue[rear2++] = np;
  }
  rear2--;
  dfs(queue[rear2], 0);
  return 0;
}

/*
Try this:
6
O 321
N 222
T 888
A 286
S 333
E 990
*/
