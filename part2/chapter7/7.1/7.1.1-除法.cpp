#include<cstdio>
#include<cstring>
#include<cassert>
inline bool check(int x, int y){
  char s[15];
  sprintf(s,"%05d%05d",x,y);
  for(char i='0'; i<='9'; i++) if(!strchr(s,i)) return false;
  return true;
}
int main(){
  int abcde,fghij,n;
  scanf("%d",&n);
  assert(n >= 2 && n <= 79);
  for (fghij = 1234; fghij <= 98765; fghij++){
    abcde = n * fghij;
    if(abcde < 100000 && check(abcde,fghij)) printf("%05d/%05d=%d\n",abcde,fghij,n);
  }
  return 0;
}
