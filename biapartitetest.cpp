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
vector<int>arr[200005];
bool vis[200005]={false};
int col[200005];
bool dfs(int i,int co){
    vis[i]=true;
    col[i]=co;
    for(auto child:arr[i]){
     //   cout<<i<<" "<<child<<" ";
        if(!vis[child]){
            if(dfs(child,co^1)==false)
                return false;
        }
        else if(vis[child]==true){
        //    cout<<i<<" "<<child<<" "<<col[i]<<" "<<col[child]<<endl;
            if(col[i]==col[child]) {
                return false;
               
            }
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{1},k{1};
    cin>>t;
    while(t--){
        int u,v;
        cin>>u>>v;
        while(v--){
            int a,b;
            cin>>a>>b;
            arr[a].eb(b);
            arr[b].eb(a);
        }
        int co=0,ans{0};
        bool yes=false,h=true;
        for(int i=1;i<=u;i++){
            if(!vis[i]){
                yes=dfs(i,co),ans++;
                if(yes==false) h=false; 
            }
        }
        yes=h;
        if(yes) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    //    cout<<ans<<endl;
//    for(int i=1;i<=u;i++)
//        cout<<col[i]<<" ";
//    cout<<endl;
//        if(yes) cout<<"Scenario #"<<k<<":"<<endl<<"No suspicious bugs found!"<<endl;
//        else cout<<"Scenario #"<<k<<":"<<endl<<"Suspicious bugs found!"<<endl;
        for(int i=0;i<200005;i++){
            col[i]=0;
            vis[i]=false;
            arr[i].clear();
        }
        k++;
    }
 return 0;
}
