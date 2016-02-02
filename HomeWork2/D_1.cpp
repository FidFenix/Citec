#include <cstdio>
using namespace std;
#define N 10005
int id[N];
int sz[N];
int contar[N];
int find(int p){
    if(p != id[p]){
        int q = find(id[p]);
        contar[p] += contar[id[p]];
        id[p] = q;
    }
    return id[p];
}
void unir(int p, int q){
    int i = find(p);
    int j = find(q);
    if(i == j)return;
    id[p] = q;
    sz[q] += sz[p];
    ++contar[p];
}
int main(){
    int t, n, q, a, b;
    char s[2];
    scanf("%d",&t);
    for(int c = 1; c <= t; c++){
        scanf("%d %d",&n,&q);
        printf("Case %d:\n",c);
        for(int i = 1;i <= N;++i){
            id[i] = i;
            sz[i] = 1;
            contar[i] = 0;
        }
        while(q--){
            scanf("%s",s);
            if(s[0] == 'T'){
                scanf("%d %d",&a,&b);
                unir(a, b);
            }else{
                scanf("%d",&a);
                int R = find(a);
                printf("%d %d %d\n",R, sz[R], contar[a]);
            }
        }
    }
}
