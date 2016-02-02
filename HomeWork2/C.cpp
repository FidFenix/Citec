#include<bits/stdc++.h>
using namespace std;
#define N 30005
int V;
vector<int> adj[N];
bool mark[N];
void dfs(int u, int p){
    for(auto X: adj[u]){
        if(X == p)continue;
        if(!mark[X]){
            mark[X] = 1;
            dfs(X,u);
            V++;
        }
    }
}
int main(){
    int q, n, m, dig, d, ant, FLAG;
    while(scanf("%d %d",&n,&m),(n+m)){
        memset(mark, 0, sizeof mark);
        memset(adj, 0, sizeof adj);
        while(m--){
            scanf("%d",&dig);
            FLAG = 0;
            while(dig--){
                scanf("%d",&d);
                if(!FLAG)FLAG = 1, ant = d;
                else{
                    adj[ant].push_back(d);
                    adj[d].push_back(ant);
                }
            }
        }
        mark[0] = 1;
        V = 1;
        dfs(0,0);
        printf("%d\n",V);
    }
}
