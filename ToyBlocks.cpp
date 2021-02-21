#include<bits/stdc++.h>
#define ll long long
#define E 1e8+7
using namespace std;
 
 
void test_case(){
	ll n;
	scanf("%lld",&n);
	vector<ll> A(n);
	ll S=0;
	for(int i=0;i<n;i++){ cin>>A[i]; S+=A[i];}
	sort(A.begin(),A.end());
	ll m=A[n-1];
	ll div=n-1;
	if(S%div==0 && S/div>=m){
		puts("0");
		return;
	}
	if(m*div>S){
		ll ans=m*div-S;
		printf("%lld\n",ans);
		return;
	}
	ll high=m;
	while(high*div<S) high*=2; //logn
	ll low=m;
	while(low<high-1){
		ll mid=(low+high)/2;
		if(mid*div<S)
			low=mid;
		else
			high=mid;
	}
	assert(high*div>=S);
	ll ans=high*div-S;
	printf("%lld\n",ans);
	
	
		
}
int main(){
		int t;
		scanf("%d",&t);
		while(t--)
		test_case();
	
}
