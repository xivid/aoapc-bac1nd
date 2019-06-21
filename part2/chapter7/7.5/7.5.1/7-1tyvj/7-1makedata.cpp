#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
char str[5][5]={"ADD\0", "SUB\0", "MUL", "DIV", "DUP"};
long long n, a[6], length, s[6][100], top, comm = 0, c[100], now;
bool equal(){
    int ok=1;
    if(s[1][top]!=s[2][top]) return false;
    for(int i=1; i<n; i++) if(s[i][top]!=s[i+1][top]) return false;
    return true;
}    
int main(){
  srand(time(NULL));
  n = rand() % 5 + 1;
  cout << n << endl;
  top=1;
  for(int i=1; i<=n; i++) {a[i] = rand() % 1000; s[i][top] = a[i];} 
  //do{
      length = rand() % 20;
      now=1;
      while(length--){
        if(top == 1) comm=4;
        else {
            int ok=1;
            for(int i=1; i<=n; i++) if(s[i][top] == 0)  {ok=0; break;}
            if(ok) comm = rand() % 5;
            else do{comm = rand()%5;}while(comm == 3);
        }    
            c[now++] = comm;
            switch(comm){
              case 0:for(int i=1; i<=n; i++) s[i][top-1]=s[i][top-1]+s[i][top]; top--; break;
              case 1:for(int i=1; i<=n; i++) s[i][top-1]=s[i][top-1]-s[i][top]; top--; break;
              case 2:for(int i=1; i<=n; i++) s[i][top-1]=s[i][top-1]*s[i][top]; top--; break;
              case 3:for(int i=1; i<=n; i++) s[i][top-1]=s[i][top-1]/s[i][top]; top--; break;
              case 4:for(int i=1; i<=n; i++) s[i][top+1]=s[i][top]; top++; break;
            }    
      }

      //if(n==1) break;
  //}while(!equal());    

  for(int i=1; i<=n; i++) cout << a[i] << " " << s[i][top] << endl;
  cout << "Ans:\n";
  for(int i=1; i<now; i++) cout<< str[c[i]] <<" ";
  cout << endl;
  return 0;
}
