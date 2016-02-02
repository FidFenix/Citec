#include<bits/stdc++.h>
using namespace std;
#define N 10003
int id[N];
int count[N];
int balls[N];
int main(){
    int t, N, M, a, b;
    char l[2];
    scanf("%d",&t);
    for(int T = 1; T <= t; T++){
        scanf("%d %d",&N,&M);
        for(int i = 0; i <= N; i++){
            count[i] = 0;
            balls[i] = 1;
            id[i] = i;
        }
        printf("Case %d:\n",T);
        while(M--){
            scanf("%s",l);
            if(l[0] == 'T'){
                scanf("%d %d",&a,&b);
                int H = id[a];
                for(int i = 1; i <= N; i++){
                    if(id[i] == H){
                        id[i] = id[b];
                        count[i]++;
                        balls[i] = 0;
                        balls[b]++;
                    }
                }
            }else{
                scanf("%d",&a);
                printf("%d %d %d\n",id[a],balls[id[a]],count[a]);
            }
        }
    }
}
