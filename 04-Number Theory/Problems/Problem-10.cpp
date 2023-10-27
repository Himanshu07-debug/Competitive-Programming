#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
	int N;
	cin>>N;
	vector<int> A(N);
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	vector<int> L(N);
	vector<int> R(N);
	for(int i=0;i<N;i++){
		if(i==0)L[i]=A[i];
		else{
			L[i]=max(L[i-1],A[i]);
		}
	}
	for(int i=N-1;i>=0;i--){
		if(i==N-1)R[i]=A[i];
		else{
			R[i]=max(R[i+1],A[i]);
		}
	}
	ll sm=0;
	for(int i=0;i<N;i++){
		sm+=min(L[i],R[i]);
	}
	cout<<sm<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	solve();
	return 0;
}