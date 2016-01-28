#include<bits/stdc++.h>
using namespace std;
#define N 105
bool mark[N];
vector<int> G[N];
int C, F;
void dfs(int u, int p){
    for(auto x: G[u]){
        if(x == p) continue;
        if(!mark[x]){
            mark[x] = 1;
            dfs(x,u);
        }else C++;
    }
}
int main(){
    int n,m,a,b, Cic = 0, CC = 0;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!mark[i]){
            C = 0;
            mark[i] = 1;
            dfs(i,i);
            Cic += C>>1;
            CC++;
        }
    }
    printf(CC == 1 && Cic == 1?"FHTAGN!\n":"NO\n");
}
