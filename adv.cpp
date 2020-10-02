#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    
    while(t--){
        int n;
        cin>>n;
        string p;
        cin>>p;
                int breven=0;
        int raodd=0;
        if(n==1){
            if((p[0]-'0')%2==0){
                cout<<"2\n";
                continue;
            }
            else{
                cout<<"1\n";
                continue;
            }
        }
        else{
            if(n%2==0){
            for(int i=1;i<n;i+=2){
                if((p[i]-'0')%2==0){
                    breven++;
                }
                
            }
            if(breven>0){
                    cout<<"2\n";
                    continue;
                }
                else{
                    cout<<"1\n";
                    continue;
                }
        }
        else{
            for(int i=0;i<n;i+=2){
                if((p[i]-'0')%2!=0){
                    raodd++;
                }
            }
            if(raodd>0){
                cout<<"1\n";
                continue;
            }
            else{
                cout<<"2\n";
                continue;
            }
        }
        }
        
    }
    
    return 0;
}
