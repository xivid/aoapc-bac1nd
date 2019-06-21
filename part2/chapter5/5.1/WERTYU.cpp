#include<iostream>
//#include<cstdio>
using namespace std;
char *s="`1234567890-=QWERTYUIOP[]ASDFGHJKL;'\\ZXCVBNM,./";
int main(){
    char c;
    int i;
    /*
    while((c=getchar())!=EOF){
      for(i=0;s[i]&&s[i]!=c;i++);
      if(s[i]) putchar(s[i-1]);
      else putchar(c);
    } 
    */
    while((c=cin.get())!=EOF) {
       for(i=1;s[i]&&s[i]!=c;i++);    
       if(s[i]) cout << (s[i-1]);
       else cout << c;
   }    
    return 0;
}    
