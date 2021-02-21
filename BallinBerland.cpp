#include<bits/stdc++.h>
#define ll long long
#define E 1e8+7
using namespace std;
 
 
void test_case(){
	ll a,b,k;
	cin>>a>>b>>k;
	vector<ll> A(k);
	vector<ll> B(k);
	ll ans=(k*(k-1))/2;
	map<ll,ll> M1;
	map<ll,ll> M2;
	for(int i=0;i<k;i++){ cin>>A[i]; M1[A[i]]++;}
	for(int i=0;i<k;i++){ cin>>B[i]; M2[B[i]]++;}
	for(auto x:M1)
		ans-=(x.second*(x.second-1))/2;
	for(auto x:M2)
		ans-=(x.second*(x.second-1))/2;
	printf("%lld\n",ans);
	return;
	
	
		
}
int main(){
		int t;
		scanf("%d",&t);
		while(t--)
		test_case();
	
}
