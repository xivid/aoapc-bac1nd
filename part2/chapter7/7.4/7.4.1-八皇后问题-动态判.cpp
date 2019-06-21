#include<cstdio>
#include<cstdlib>
#include<cstring>
const int n = 8;
int a[n], ans = 0;
void search(int cur){
   if(cur == n){
    //for(int i=0; i<n; i++) printf("%d",a[i]);
    //printf("\n");
    ans++;
    return;
   }
   else for(int i=0; i<n; i++){
     int ok=1;
     a[cur] = i;
     for(int j=0; j<cur; j++) if(a[j] == i || j+a[j] == cur+a[cur] || a[j]-j == a[cur]-cur)
      {
        ok = 0;
        break;
      }
     if(ok) {

       search(cur+1);
     }
   }
}
int main(){
   memset(a, 0, sizeof(a));
   search(0);
   printf("%d\n",ans);
   return 0;
}
