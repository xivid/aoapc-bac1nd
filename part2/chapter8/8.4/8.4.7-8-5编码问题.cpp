//Input a series of nodes with char c(data) and int p(frequency), build a huffman tree,
// and output the huffman code of each node.
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
} ;
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
    code[cur] = 1;  //left = 1
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
  for(int i=1; i<=n; i++) printf("Node[%d]: [%c], p=%d\n", i, node[i]->c, node[i]->p);
  front1= 1; rear1= n+1;
  front2= 1; rear2= 1;
  Tnode *p1, *p2, *np;
  for(int i=1; i<n; i++){
    printf("Select process #%d, front1=%d, front2=%d, rear1=%d, rear2=%d\n", i, front1, front2, rear1, rear2);
    int flag1=0;
    if(front2+1>rear2 || (front1+1<=rear1 && node[front1]->p < queue[front2]->p)) {p1 = node[front1++]; flag1=1;}
    else p1 = queue[front2++];
    printf("p1(%c:%d) selected from %s%d]\n", p1->c, p1->p, flag1?"node[":"queue[", flag1?front1-1:front2-1);
    int flag2=0;
    if(front2+1>rear2 || (front1+1<=rear1 && node[front1]->p < queue[front2]->p)) {p2 = node[front1++]; flag2=1;}
    else p2 = queue[front2++];
    printf("p2(%c:%d) selected from %s%d]\n", p2->c, p2->p, flag2?"node[":"queue[", flag2?front1-1:front2-1);
    np = new Tnode;
    printf("new node created\n");
    np->p = p1->p + p2->p;
    np->lc = p1;
    np->rc = p2;
    printf("new node %d ready\n", np->p);
    queue[rear2++] = np;
    printf("new node inserted at queue[%d]\n", rear2-1);
  }
  printf("end.\nfront1=%d, front2=%d, rear1=%d, rear2=%d\n\nAns:\n",front1, front2, rear1, rear2);
  rear2--;
  dfs(queue[rear2], 0);
  return 0;
}

/*
6
O 321
N 222
T 888
A 286
S 333
E 990
*/
