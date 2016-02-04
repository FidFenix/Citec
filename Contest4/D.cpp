#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define MOD 1000000
int memo[N];
double lg[N];
double sen[N];
double sq[N];
int f(int n){
    if(n == 0)return 1;
    if(memo[n] != -1) return memo[n];
    return memo[n] = (f(floor(n - sq[n]))%MOD+ f(floor(lg[n]))%MOD+  f(floor(n*sen[n]*sen[n]))%MOD)%MOD;
}
int main(){
    int n;
    for(int i = 1; i < 1000001; i++){
        lg[i] = log((double)i);
        sen[i] = sin((double)i);
        sq[i] = sqrt((double)i);
    }
    memset(memo, -1, sizeof memo);
    while(scanf("%d",&n),(n != -1)){
        printf("%d\n", f(n));
    }
}
