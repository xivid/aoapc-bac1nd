#include<iostream>
#include<cstdio>
#include<cstdlib>
using std::cin;
using std::cout;
using std::endl;
const int maxn=500000 + 50; 
int left[maxn],right[maxn],n,t; 
void link(int a,int b){
    right[a]=b;
    left[b]=a;
}    
int main(){
     cin >> n;
     for(int i=1;i<=n;i++) { left[i]=i-1; right[i]=i+1;}
     right[n]=0;
     cin >> t;
     for(int i=1;i<=t;i++){
         int X,Y;
         char c;
         c=getchar();
         while(c!='A'&&c!='B') c=getchar();
         cin >> X >> Y;
         link(left[X],right[X]);
         if(c=='B'){
             //X .. Y-> .. Y X right[Y]
             link(X,right[Y]);
             link(Y,X);             
         }
         else {//A
             //X .. Y -> .. X Y
             link(left[Y],X);
             link(X,Y);
         }
     }
     int head;
     for(head=1;head<=n&&left[head]!=0;head++);
     cout << head<<" ";
     while(right[head]!=0){
         head=right[head];
         cout << head<<" ";
     }    
     cout << endl;
     return 0;
}     
