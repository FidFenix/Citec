#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int n, m, k,num,q;
   while(1){
       cin>>n>>m;
       if(!(n+m)) break;
       int arr[m];
       for(int i = 0; i < m; i++)cin>>arr[i];
       set< queue<int>,  greater< queue<int> > > S;
       for(int i = 1; i < (1<<m); i++){
           int sum = 0;
           queue<int> res;
           for(int j = 0; j < m; j++){
               if(i & (1<<j)){
                   res.push(arr[j]);
                   sum += arr[j];
               }
           }
           if(sum == n) S.insert(res);
       }
       cout<<"Sums of "<<n<<":"<<endl;
       if(!S.size())cout<<"NONE"<<endl;
       else for(queue<int> X: S){
           while(!X.empty()){
               cout<<X.front();
               X.pop();
               if(X.size())cout<<"+";
           }
           cout<<endl;
       }
   }
}
