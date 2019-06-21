#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char s[100];
    int T=0,len;
    scanf("%s",s);
    len=strlen(s);
    for(T=1;T<=len;T++) if(len%T==0) {
     int ok=1;   
     for(int i=T;i<len;i++) //0~len-1
      if(s[i]!=s[i%T]) {ok=0; break;}
     if(ok) {printf("%d\n",T); break;}
    }    
    system("pause");
    return 0;
}    
