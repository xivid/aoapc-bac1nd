#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
//(11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
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
  while(*c){
    if(*c=='L') {
      if(p->left==NULL) p->left=newnode();
      p=p->left;
    }
    else if(*c=='R') {
      if(p->right==NULL) p->right=newnode();
      p=p->right;
    }
    else break;
    c++;
  }
  if(p->hv==false) p->data=k;
  else failed=true;
  p->hv=true;  //DON'T FORGET TO SET HV TO TRUE!!!
}
void remove_tree(node* root){
    if(root!=NULL){
        remove_tree(root->left);
        remove_tree(root->right);
        free(root);
    }
}    
        
int init(){
  //return 0: no end-of-input
  //return 1: input ended successfully
  char s[300];
  remove_tree(root);
  root=newnode();
  while(scanf("%s",s) == 1) {
    if(strcmp(s,"()")==0) return 1;
    int d;
    sscanf(&s[1],"%d",&d);
    addnode(d,strchr(s,',')+1);
  }
  return 0;
}
int bfs(){
  node* queue[300];
  int front,rear,out[300],t=0;
  queue[front=rear=1]=root;
  while(front<=rear){
    node* p=queue[front];
    if(p->hv==false) return 0;
    out[++t]=p->data;
    if(p->left!=NULL) queue[++rear]=p->left;
    if(p->right!=NULL) queue[++rear]=p->right;
    front++;
  }
  for(int i=1;i<=t;i++) cout << out[i] <<" " ; cout << endl;
  return 1;
}
int main(){
  while(init()==1){
  if(!bfs()) failed=true;
  if(failed) cout << "-1" << endl;
  }  
  return 0;
}
