// You are given an Array of N integers. You can perform the following operation any  no. of times --> 
// Select two integers l and r (1 <= l < r <= N)
// Chnage a[i] to min(a[l],a[r]) for l < i < r

// Output the Maximum sum of the array after performing the above operation any no. of times(possibly zero)

// 5 1 7  ---> 17  

// Constraint --> 1 <= N  <= 10^5

// LOGIC --> 

// Apne ko maximimum krna hai sum i.e, hume l and r ki aaisi range consider krni hongi jisme inside values < min(l,r) ho.. Then only it will
// contribute in the increase of the Sum

// For each element, we have to find the Suitable l and r from the left and right respectively

// Kya koi past Question Yaad Aaya, Trapping rainwater Problem..... Left max and Right max ka track rkhlo each element ke liye, so that hum
// update kar sake




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