#include<bits/stdc++.h>
using namespace std;
#define N 104
int n1, n2;
int a[N];
int b[N];
int memo[N][N];
int f(int p1, int p2){
    if(p1 >= n1|| p2 >= n2) return 0;
    if(memo[p1][p2] != -1) return memo[p1][p2];
    if(a[p1] == b[p2]) return memo[p1][p2] = 1 + f(p1 + 1, p2 + 1);
    return memo[p1][p2] = max(f(p1, p2+1), f(p1+1, p2 ));
}
int main(){
    int k = 1;
    while(scanf("%d %d",&n1,&n2),(n1 + n2)){
        memset(memo, -1, sizeof memo);
        for(int i = 0; i < n1; i++)scanf("%d",a + i);
        for(int i = 0; i < n2; i++)scanf("%d",b + i);
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",k++, f(0,0));
    }
}
