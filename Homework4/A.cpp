#include<bits/stdc++.h>
using namespace std;
#define N 22
int a[N], b[N];
int n, num;
int memo[N][N];
int f(int pos1, int pos2){
    if(pos1 >= n || pos2 >= n)return 0;
    if(memo[pos1][pos2] != -1)return memo[pos1][pos2];
    if(a[pos1] == b[pos2])return memo[pos1][pos2] = 1 + f(pos1 + 1, pos2 + 1);
    return memo[pos1][pos2] = max( f(pos1 + 1, pos2), f(pos1, pos2 + 1));
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string l;
    cin>>n;
    int arr1[n],arr2[n];
    for(int i = 0; i < n; i++)cin>>arr1[i];
    for(int i = 0; i < n; i++) a[arr1[i] - 1] = i;
    getline(cin, l);
    while(1){
        if(!getline(cin,l))break;
        memset(memo,-1,sizeof memo);
        for(int i = 0; i < l.size(); i++)
            if(l[i] == ' ')
                l[i] = '\n';
        istringstream S;
        S.str(l);
        int id = 0;
        for(string i;  getline(S,i);)
            arr2[id++] = stoi(i);
        for(int i = 0; i < n; i++) b[arr2[i] - 1] = i;
        cout<<f(0,0)<<endl;
    }
}
