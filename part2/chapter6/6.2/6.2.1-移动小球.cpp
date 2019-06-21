#include<iostream>
#include<cstdlib>
using namespace std;
int A[500000 + 10];
int n,m;
int find(int key){
    for(int i=1;i<=n;i++) if(A[i]==key) return i;
}
void shift_circular_left(int l,int r){
    //p a b c q => a b c p q
    int key=A[l];
    for(int i=l;i<r;i++) A[i]=A[i+1];
    A[r]=key;
}    
void shift_circular_right(int l,int r){
    /*
   id . 1 2 3 4 .
 data . 4 3 2 1 .  ==> . 1 4 3 2 .
           */
   int key=A[r];
   for(int i=r;i>l;i--) A[i]=A[i-1];
   A[l]=key;
}    
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) A[i]=i;
    while(m--){
        char c[50];
        int x,y;
        scanf("%s%d%d",c,&x,&y);   
        int p=find(x),q=find(y);
        if(c[0]=='A'){
            //1 . . . 4 => . . . 1 4 q>p
            //4 . . . 1 => 1 4 . . . q<p
            if(q>p) shift_circular_left(p,q-1);
            else shift_circular_right(q,p);
        }    
        else if(c[0]=='B'){
            //3 . . . 5 => . . . 5 3 q>p
            //5 . . . 3 => 5 3 . . . q<p
            if(q>p) shift_circular_left(p,q);
            else shift_circular_right(q+1,p); 
        }         
    }    
    for(int i=1;i<=n;i++) printf("%d ",A[i]);
    printf("\n");
    return 0;
}    
