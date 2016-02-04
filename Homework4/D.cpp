#include<iostream>
#include<string>
#include<stack>
using namespace std;
#define MP(h,k) make_pair(h,k)
#define f first
#define s second
typedef pair<int,int> PII;
int main(){
    string A,B;
    int n,m;
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    while(cin>>A>>B){
        n = A.size();
        m = B.size();
        int memo[n+1][m+1];
        PII res[n+1][m+1];
        for(int i = 0; i <= n; i++){
            memo[i][0] = 0;
            res[i][0] = MP(0,0);
        }
        for(int i = 0; i <= m; i++){
            memo[0][i] = 0;
            res[0][i] = MP(0,0);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(A[i-1] == B[j-1]){
                    memo[i][j] = memo[i-1][j-1] + 1;
                    res[i][j] = MP(-1,-1);
                }else if(memo[i-1][j] >= memo[i][j-1]){
                    memo[i][j] = memo[i-1][j];
                    res[i][j] = MP(-1,0);
                }else{
                    memo[i][j] = memo[i][j-1];
                    res[i][j] = MP(0,-1);
                }
            }
        }
        stack<char> pila;
        int i = n, j = m, tmp;
        while(res[i][j].f || res[i][j].s){
            if(res[i][j].f == res[i][j].s)pila.push(A[i-1]);
            else if(!res[i][j].f)pila.push(B[j-1]);
            else pila.push(A[i-1]);
            tmp = i;
            i += res[tmp][j].f;
            j += res[tmp][j].s;
        }
        while(j > 0){
            pila.push(B[j-1]);
            j--;
        }
        while(i > 0){
            pila.push(A[i-1]);
            i--;
        }
        while(!pila.empty()){
            cout<<pila.top();
            pila.pop();
        }
        cout<<endl;
    }
}
