#include<cstdio>
#include<cstdlib>
#include<cstring>
long long a[510], n, m;
int sep[510], cases;
bool p(long long x){
  long long sum=0;
  int k=m-1, i;
  for(i=n-1; k && i>=0; i--){
    if(a[i]>x) return false;
    if(sum+a[i]<=x) sum+=a[i];
    else {sum=a[i]; k--;}
  }
  if(i>=0) {
    for(int j=0;j<=i;j++) {sum+=a[j]; if(sum>x) return false;}
  }
  return true;
}
void divide(long long x){
  long long sum, done=m-1, i, j=n;
  for(i=done; i>0; i--){
    sum=0;
    while(j>=i && (sum=sum+a[j])<=x) j--;
    sep[i] = j;
  }
  j=1;
  for(i=0; i<n-1; i++) {
    printf("%lld ",a[i]);
    if(i==sep[j]) {printf("/ "); j++;}
  }
  printf("%lld",a[n-1]);
}
int main(){
  long long x, l, r, k;
  scanf("%d",&cases);
  while(cases--){
    memset(a,0,sizeof(a));
    memset(sep,-1,sizeof(sep));
    scanf("%d%d",&n,&m);
    l=0; r=0;
    for(int i=0; i<n; i++) {scanf("%lld",a+i); r+=a[i]; }
    while(l<r){
      k = l+(r-l)/2;
      if(p(k)) r=k;
      else l=k+1;
    }
    divide(l);
    putchar('\n');
  }
  return 0;
}
