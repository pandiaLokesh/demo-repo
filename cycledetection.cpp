#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define MA 10e+18
int va=10e8+7;
ll val[200007]={0};
using namespace std;
//Conditional Operator (condition?true part:false part) eg : cout<<(y<=3?"YES":"NO")<<endl;
//string s(3,'1');
// if number of elements in array >10^5 then declare global array.
ll getmul(ll n){ll int k{0};while(n>0){k+=n%10;n=n/10;}return k;}//Sum OF n DIGITS 
vector<int>arr[10001];
bool vis[10001]={false};
bool dfs(int i,int prev){
    vis[i]=true;
    for(int child:arr[i]){
        if(!vis[child]){
            if(!dfs(child,i)) return false;
        } 
        else{
            if(child!=prev) return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{1};
   // cin>>t;
    while(t--){
       int u,v;
       cin>>u>>v;
       while(v--){
           int a,b;
           cin>>a>>b;
           arr[a].eb(b);
           arr[b].eb(a);
       }
       bool ans=true;
       for(int i=1;i<=u;i++){
           bool fg;
           if(!vis[i]) {
               fg=dfs(i,0);
               if(!fg) ans=false;
           }
       }
       bool fg=ans;
       if(fg) cout<<"No Cycles"<<endl;
       else cout<<"Cycles"<<endl;
  //     cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    }
 return 0;
}
