// Find X such that A ^ X * B ^ X is maximum ... 0 <= X , A, B < 2^N
// N, A , B are given

// 1 <= N <= 30


// LOGIC --> 

// From A & B, we can guess X for maximum Product ..
// A ka first bit 1 then b ke saare 1



#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t, n, a, b, i, j, x, first;
    ll ca[30], cb[30];
    
    cin>>t;
    
    while(t--)
    {
        cin>>n>>a>>b;
        first=0;
        
        for(int i=0;i<n;i++){
            ca[i] = (a & (1LL << i)) > 0 ? 1 : 0;
            cb[i] = (b & (1LL << i)) > 0 ? 1 : 0;
        }

        x=0;
        
        for(i=n-1; i>=0; i--)
        {
            if(ca[i]==0 && cb[i]==0)
            {
                x=x+(1<<i);
            }else if(ca[i]==1 && cb[i]==0){
                if(first==0)
                {
                    first++;
                }else{
                    x=x+(1<<i);
                }
            }else if(ca[i]==0 && cb[i]==1){
                if(first==0){
                    first++;
                    x=x+(1<<i);
                }
            }
            
        }
        
        cout<<x<<"\n";
    }
    
}