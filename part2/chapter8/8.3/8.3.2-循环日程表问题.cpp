#include<cstdio>
#include<cstdlib>
#define maxn 1025
int table[maxn][maxn];
void make(int k, int sx, int sy){
  int size = 1<<(k-1);
  if(k==1) {
    table[sx][sy] = 1;
    table[sx+size][sy] = table[sx][sy] + size;
    table[sx+size][sy+size] = table[sx][sy];
    table[sx][sy+size] = table[sx+size][sy];
  }
  else {
    make(k-1, sx, sy);
    for(int i=0; i<size; i++)
      for(int j=0; j<size; j++){
        table[sx+i+size][sy+j+size] = table[sx+i][sy+j];
        table[sx+i+size][sy+j] = table[sx+i][sy+j] + size;
        table[sx+i][sy+j+size] = table[sx+i+size][sy+j];
      }
  }
}
int main(){
  int k;
  scanf("%d", &k);
  make(k, 1, 1);
  for(int i=1; i<=(1<<k); i++){
    for(int j=2; j<=(1<<k); j++)
      printf("%d ", table[i][j]);
    printf("\n");
  }
  return 0;
}
