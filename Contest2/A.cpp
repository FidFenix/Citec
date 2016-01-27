#include<bits/stdc++.h>
using namespace std;
#define MP(i,j) make_pair(i,j)
#define pb(i) push_back(i);
#define f first
#define s second
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string l;
    cin>>l;
    int count = 0, maxi = -1e7;
    int  n = l.size();
    stack<char> p;
    bool F = 0;
    for(int i = 0; i < n; i++){
        char L = l[i];
        if(!p.empty()){
            char R = p.top();
            if( R == '(' &&  ')' == L){
                count += 2;
                p.pop();
            }else{
                p.push(L);
            }
        }else{
            p.push(L);
        }
    }
    cout<<max(count,maxi)<<endl;
}
