#include<cstdio>
#include<cstring>
int board[1025][1025], k, bx, by;
//b*,s*: real   *: delta
void print(){
  for(int i=1; i<=(1<<k); i++){
    for(int j=1; j<=(1<<k); j++)
      printf("%d ", board[i][j]);
    printf("\n");
  }
}
void fill(int sx, int sy, int x, int y){
  // 0 1
  // 1 1
  if(x==1 && y==1) board[sx][sy+1]=board[sx+1][sy]=board[sx+1][sy+1]=1;
  // 2 0
  // 2 2
  else if(x==1 && y==2) board[sx][sy] = board[sx+1][sy] = board[sx+1][sy+1] = 2;
  // 3 3
  // 0 3
  else if(x==2 && y==1) board[sx][sy] = board[sx][sy+1] = board[sx+1][sy+1] = 3;
  // 4 4
  // 4 0
  else board[sx][sy] = board[sx+1][sy] = board[sx][sy+1] = 4;
}
void cover(int k, int sx, int sy, int x, int y){
  if(1==k) {fill(sx, sy, x, y); return;}  //x:shangxia y:zuoyou
    if(x<=(1<<(k-1))){
      if(y<=(1<<(k-1))) {  // zai zuo shang
        cover(k-1, sx, sy, x, y);
        fill(sx+(1<<(k-1))-1, sy+(1<<(k-1))-1, 1, 1);
        cover(k-1, sx, sy+(1<<(k-1)), 1<<(k-1), 1); //you shang
        cover(k-1, sx+(1<<(k-1)), sy, 1, 1<<(k-1)); //zuo xia
        cover(k-1, sx+(1<<(k-1)), sy+(1<<(k-1)), 1, 1);  //you xia
      }
      else if(y>(1<<(k-1))) {  //zai you shang
        cover(k-1, sx, sy+(1<<(k-1)), x, y-(1<<(k-1)));
        fill(sx+(1<<(k-1))-1, sy+(1<<(k-1))-1, 1, 2);
        cover(k-1, sx, sy, 1<<(k-1), 1<<(k-1)); // zuo shang
        cover(k-1, sx+(1<<(k-1)), sy, 1, 1<<(k-1));
        cover(k-1, sx+(1<<(k-1)), sy+(1<<(k-1)), 1, 1);  //you xia
      }
    }
    else {
      if(y<=(1<<(k-1))) {  // zai zuo xia
        cover(k-1, sx+(1<<(k-1)), sy, x-(1<<(k-1)), y);
        fill(sx+(1<<(k-1))-1, sy+(1<<(k-1))-1, 2, 1);
        cover(k-1, sx, sy+(1<<(k-1)), 1<<(k-1), 1); //you shang
        cover(k-1, sx, sy, 1<<(k-1), 1<<(k-1)); //zuo shang
        cover(k-1, sx+(1<<(k-1)), sy+(1<<(k-1)), 1, 1);  //you xia
      }
      else if(y>(1<<(k-1))) {  //zai you xia
        cover(k-1, sx+(1<<(k-1)), sy+(1<<(k-1)), x-(1<<(k-1)), y-(1<<(k-1)));
        fill(sx+(1<<(k-1))-1, sy+(1<<(k-1))-1, 2, 2);
        cover(k-1, sx, sy, 1<<(k-1), 1<<(k-1)); // zuo shang
        cover(k-1, sx, sy+(1<<(k-1)), 1<<(k-1), 1);  //you shang
        cover(k-1, sx+(1<<(k-1)), sy, 1, 1<<(k-1));  //zuo xia
      }
    }
}
int main(){
  memset(board, 0, sizeof(board));
  scanf("%d%d%d", &k, &bx, &by);
  cover(k, 1, 1, bx, by);
  print();
  return 0;
}
