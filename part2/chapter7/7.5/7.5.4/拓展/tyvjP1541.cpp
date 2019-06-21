#include<cstdio>
#include<cstdlib>
#include<cstring>
#define maxn 1000000
typedef int state[9];
state q[maxn], goal={1,2,3,8,0,4,7,6,5};
int dist[maxn], head, tail;
const int dx[]={-1,1,0,0};
const int dy[]={0,0, 1, -1};
int fact[9], vis[362880];
void init_lookup_table(){
    fact[0]=1;
    for(int i=1; i<9; i++) fact[i] = i*fact[i-1];
}
int try_to_insert(int s){
    int cnt, node=0;
    for(int i=0; i<9; i++){
        cnt = 0;
        for(int j=i+1; j<9; j++) if(q[s][i]>q[s][j]) ++cnt;
        node+=fact[8-i]*cnt;
    }
    if(vis[node]) return 0;
    return vis[node] = 1;
}    
int bfs(){
    init_lookup_table();  
    head = 1; tail = 2;
    while(head < tail){
        state& u = q[head];
        if(memcmp(goal, u, sizeof(u)) == 0) return head;
        int i, x, y;
        for(i=0; i<9&&u[i]!=0; i++);
        x=i/3; y=i%3;
        for(i=0; i<4; i++){
            int newx = x+dx[i], newy = y+dy[i];
            if(newx>=0 && newx <3 && newy>=0 && newy <3) {
                state& v = q[tail];
                memcpy(&v, &u, sizeof(u));
                v[x*3+y] = v[newx*3+newy];
                v[newx*3+newy] = 0;
                dist[tail] = dist[head] + 1;
                if(try_to_insert(tail)) tail++;
            }
        }
        head++;        
    }      
    return 0;
}     
int main(){
    char c;
    for(int i=0; i<9; i++) {scanf("%c", &c); q[1][i] = c - '0';}
    int ans = bfs();
    if(ans>0) printf("%d\n", dist[ans]);
    else printf("0\n");
    return 0;
}    
