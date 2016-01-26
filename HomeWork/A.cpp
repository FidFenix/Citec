#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, p, q;
    long long mini, maxi, H , den;
    string N = "";
    scanf("%d",&t);
    for(int k = 1; k <= t; k++){
        scanf("%d %d",&p,&q);
        den = 1LL<<q, mini = -1LL, maxi = -1LL;
        N = "";
        for(long long i = 0; i < (1LL<<p); i++){
            N = "";
            for(int j = 0; j < p; j++){
                N = (i&(1LL<<j))?"2"+N:"1"+N;
            }
            H = stol(N);
            if(!(H%den)){
                mini = H;
                break;
            }
        }
        if(mini > 0)
        for(long long i = (1LL<<p)-1LL ; i >= 0; i--){
            N = "";
            for(int j = 0; j < p; j++){
                N = (i&(1LL<<j))?"2"+N:"1"+N;
            }
            H = stol(N);
            if(!(H%den)){
                maxi = H;
                break;
            }
        }
        if(mini == -1LL)printf("Case %d: impossible\n",k);
        else if(mini == maxi)printf("Case %d: %lld\n",k, mini);
        else printf("Case %d: %lld %lld\n",k,mini,maxi);
    }
}
