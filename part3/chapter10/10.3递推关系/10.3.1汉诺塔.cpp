#include<cstdio>
int step = 0;
void hanoi(int n, int from, int to, int via){
  if(n == 1) {
    printf("S%d: plate 1 %c -> %c\n", ++step, from, to);
    return;
  }
  hanoi(n-1, from, via, to);
  printf("S%d: plate %d %c -> %c\n", ++step, n, from, to);
  hanoi(n-1, via, to, from);
}  
int main(){
  int n;
  scanf("%d", &n);
  hanoi(n, 'A', 'B', 'C');
  return 0;
} 

