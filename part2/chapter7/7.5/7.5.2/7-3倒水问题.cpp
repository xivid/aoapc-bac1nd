#include<cstdio>
#include<cstdlib>
#include<cstring>
#define maxn 1000 + 5
#define min(a, b) (a)<(b)?(a):(b)
int cup[3], x;
struct node{
    int v[3], fa, last_op, dist;
    node() {v[0]=v[1]=v[2]=fa=last_op=dist=0;}
} q[maxn];    
int vis[maxn][maxn], front, rear; //总体积一定，由两体积即可确定整个状态 
void print_path(int idx){
    if(q[idx].fa != idx){
        print_path(q[idx].fa);
        printf("Cup %d -> Cup %d\n", q[idx].last_op/10+1, q[idx].last_op%10+1);
    }
    printf("%d %d %d\n", q[idx].v[0], q[idx].v[1], q[idx].v[2]);
}            
int main(){
    scanf("%d%d%d%d", cup, cup+1, cup+2, &x);
    memset(vis, 0, sizeof(vis));
    q[front = 0].v[0]=cup[0]; 
    vis[0][0] = 1;
    rear = 1;
    while(front<rear){
        node& u=q[front];
        if(u.v[0]==x || u.v[1]==x || u.v[2]==x){
            printf("%d\n", u.dist);
            print_path(front);
            break;
        }
        for(int i=0; i<3; i++)
          for(int j=0; j<3; j++) if(i!=j){
              int amount = min(u.v[i], cup[j]-u.v[j]);
              node& v=q[rear];
              for(int k=0; k<3; k++) v.v[k] = u.v[k];
              v.v[i]-=amount;
              v.v[j]+=amount;
              if(!vis[v.v[1]][v.v[2]]){
                  vis[v.v[1]][v.v[2]] = 1;
                  v.fa = front;
                  v.dist = u.dist+1;
                  v.last_op = i*10 + j;
                  rear++;
              }    
          }   
        front++;
    }    
    system("pause");
    return 0;
}    
