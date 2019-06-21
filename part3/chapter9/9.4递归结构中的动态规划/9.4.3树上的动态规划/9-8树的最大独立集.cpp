//本题用到11章中无根树转有根树的相关知识 
#include<cstdio>
#include<cstdlib>
#include<vector>
#define maxn 1000
using namespace std;
vector<int> G[maxn], H[maxn]; //H[i]记录高度为i的点 
int n, p[maxn], height[maxn], maxh, f[maxn], sums[maxn], sumgs[maxn];
inline int max(int a, int b) {if(a>b) return a; return b;}
void make_tree(int u, int fa, int h){
    int d = G[u].size();
    for(int i = 0; i < d; ++i){
        const int& v = G[u][i];
        if(v != fa) {
            height[v] = h + 1;
            H[height[v]].push_back(v);
            if(height[v] > maxh) maxh = height[v];
            make_tree(v, p[v] = u, height[v]);
        }    
    }
}        
int main(){
    freopen("tree.in2", "r", stdin); 
    //build tree
    scanf("%d", &n);
    int u, v;
    for(int i = 0; i < n-1; ++i){
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int root = 0;
    p[root] = -1; height[root] = 1; H[1].push_back(root);
    make_tree(root, -1, 1);
    
    //dp
    memset(f, 0, sizeof(f));
    memset(sums, 0, sizeof(sums));
    memset(sumgs, 0, sizeof(sumgs));
    for(int h = maxh; h > 0; --h){
      int d = H[h].size();
      for(int i = 0; i < d; ++i){
        const int& v = H[h][i];
        f[v] = (h == maxh ? 1 : max(sums[v], sumgs[v] + 1));
        if(p[v]!=-1) sums[p[v]]+=f[v];
        if(p[p[v]]!=-1) sumgs[p[p[v]]]+=f[v];
      }    
    }    
    printf("%d\n", f[root]);
    return 0;
}    
