#include<bits/stdc++.h>
using namespace std;
#define N 505
int id[N];
bool mark[N];
int find(int p){
        while(p != id[p]){
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
}
int unir(int p, int q){
    int i = find(p);
    int j = find(q);
    int mayor = max(i, j);
    int menor = min(i, j);
    id[menor] = mayor;
    if(mark[mayor] && mark[menor]) return -1;
    if(mark[mayor] || mark[menor]) mark[mayor] = 1;
    return 0;
}
int kill_tree(int p, int q){
    int i = find(p);
    if(!mark[i]){
        mark[i] = 1;
        return 1;
    }
    return 0;
}
bool connected(int p, int q){
    return find(p) == find(q);
}
int main(){
    int V, E, a, b, tree = 0, killtree, q, t = 1,CC;
    while(scanf("%d %d",&V,&E),(V+E)){
        memset(mark, 0, sizeof mark);
        for(int i = 0; i <= V; i++) id[i] = i;
        tree = V;
        killtree = 0;
        while(E--){
            scanf("%d %d",&a,&b);
            if(!connected(a,b)){
                tree--;
                killtree += unir(a,b);
            }else killtree += kill_tree(a,b);
        }
        q = tree - killtree;
        if(q == 1)printf("Case %d: There is one tree.\n",t++);
        else if(q > 1)printf("Case %d: A forest of %d trees.\n",t++,q);
        else printf("Case %d: No trees.\n",t++);
    }
}
