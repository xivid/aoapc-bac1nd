#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<set>
using namespace std;
#define maxn 1000003
typedef int state[9];
state q[maxn], goal;
int dist[maxn], head, tail;
const int dx[]={-1,1,0,0};
const int dy[]={0,0, 1, -1};
struct cmp{
    bool operator () (int a, int b) const{
        return memcmp(q[a], q[b], sizeof(q[b])) < 0;
    }
};
set<int, cmp> vis;
void init_lookup_table(){vis.clear();}
int try_to_insert(int s){
    if(vis.count(s)) return 0;
    vis.insert(s);
    return 1;
}    
int bfs(){
    init_lookup_table();  
    head = 1; tail = 2;
    while(head < tail){
        state& u = q[head];
        if(memcmp(goal, u, sizeof(u)) == 0) return head;
        int i, x, y;
        for(i=0; i<9&&u[i]!=0; i++);
        if(u[i]==0) {x=i/3; y=i%3;}
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
    for(int i=0; i<9; i++) scanf("%d", &q[1][i]);
    for(int i=0; i<9; i++) scanf("%d", &goal[i]);
    int ans = bfs();
    if(ans>0) printf("%d\n", dist[ans]);
    else printf("-1\n");
    system("pause");
    return 0;
}    
/*
2 6 4 1 3 7 0 5 8
8 1 5 7 3 6 4 0 2

Output:
31 
*/
