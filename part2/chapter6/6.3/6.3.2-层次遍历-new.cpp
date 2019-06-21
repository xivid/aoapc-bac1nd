#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
//(3,L) (4,R) ()
//(11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
using namespace std;
struct node{
  bool hv; //have value
  int data;
  node *left,*right;
};
node* root;
bool failed=false;
node* newnode(){
  node* p;
  p=(node*)malloc(sizeof(node));
  if(p!=NULL){
  p->hv=false;
  p->left=p->right=NULL;}
  return p;
}
void addnode(int k,char* c){
  node* p=root;
  while(c){
    if(*c=='L') {
      if(p->left==NULL) p->left=newnode();
      p=p->left;
    }
    else if(*c=='R') {
      if(p->right==NULL) p->right=newnode();
      p=p->right;
    }
    else if(*c==')') break;
    else {failed=true; break;}
    c++;
  }
  if(p->hv==false) {p->data=k; p->hv=true;}
  else failed=true;
}
void delete_tree(node* u){
    if(u==NULL) return;
    delete_tree(u->left);
    delete_tree(u->right);
    free(u);
}    
int init(){
  //return 0: no end-of-input
  //return 1: input ended successfully
  char s[300];
  delete_tree(root);
  root=newnode();
  while(scanf("%s",s) == 1) {
    if(strcmp(s,"()")==0) return 1;      
    int d;
    sscanf(&s[1],"%d",&d);
    addnode(d,strchr(s,',')+1);
  }
  return 0;
}
bool bfs(int ans[],int& n){
    node* q[300];
    n=0;
    int front,rear;
    q[rear=front=1]=root;
    while(front<=rear){
        node* p=q[front++];
        if(!p->hv) return false;
        ans[++n]=p->data;
        if(p->left!=NULL) q[++rear]=p->left;
        if(p->right!=NULL) q[++rear]=p->right;
    }
    return true;    
}    
int main(){
  while(init() != 0){
    int ans[300],n;
    if(bfs(ans,n)) for(int i=1;i<=n;i++) cout << ans[i] << " ";
    else failed=true;
    if(failed) cout << "-1";
    cout << endl;
  }    
  return 0;
}
