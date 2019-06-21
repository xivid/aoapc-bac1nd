#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio> 
using namespace std;
int N=500000,M=100000;
double random(){ return (double)rand()/RAND_MAX;}
int random(int m) { return (int)((m-1)*random()+0.5);}
int main(){
    srand(time(NULL));
    int n,m;
    do{
        n=random(N)+1;
        m=random(M)+1;
    }while(m>=n);    
    cout << n <<" " << m << endl;
    for(int i=1;i<=m;i++){
        cout<<(rand()%2?'A':'B')<<" ";
        int x,y;
        do{
            x=random(n)+1;
            y=random(n)+1;
        }while(x==y);
        cout << x <<" " << y << endl;    
    }    
    return 0;
}     
