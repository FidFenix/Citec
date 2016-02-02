#include<bits/stdc++.h>
using namespace std;
#define N 505
#define f first
#define s second
typedef pair<int,int> PII;
int V, E;
vector<int> adj[N];
bool mark[N];
bool TREE = 1;
void dfs(int u, int p){
    for(auto X: adj[u]){
        if(X == p)continue;
        if(!mark[X]){
            mark[X] = 1;
            dfs(X,u);
        }else TREE = 0;
    }
}
int CC(){
    int trees = 0;
    for(int i = 1; i <= V; i++){
        if(!mark[i]){
            mark[i] = 1;
            TREE = 1;
            dfs(i,i);
            if(TREE)trees++;
        }
    }
    return trees;
}
int main(){
    int  a, b, q, t = 1;
    while(scanf("%d %d",&V,&E),(V+E)){
        memset(adj, 0, sizeof adj);
        memset(mark, 0, sizeof mark);
        while(E--){
            scanf("%d %d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        q = CC();
        if(q == 1)printf("Case %d: There is one tree.\n",t++);
        else if(q > 1)printf("Case %d: A forest of %d trees.\n",t++,q);
        else printf("Case %d: No trees.\n",t++);
    }
}
