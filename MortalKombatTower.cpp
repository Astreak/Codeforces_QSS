#include<bits/stdc++.h>
#define ll long long 
#define E (ll)(1e9+7)
using namespace std;
 
bool chooseOptimal(ll& a,ll& b){
	if(a%b==0 || b%a==0)
		return true;
	else return false;
}
ll minDis(ll a,ll b){
	if(a>b){
		ll cnt1=0;
		ll cnt2=0;
		ll temp=a;
		while(temp>=1){
			if(b%temp==0)
				break;
			++cnt1;
			--temp;
		}
		temp=a;
		while(temp<=b){
			if(b%temp==0)
				break;
			++cnt2;
			++temp;
		}
		return min(cnt1,cnt2);
	}
	else{
		ll cnt1=0;
		ll cnt2=0;
		ll temp=a;
		while(temp>=b){
			if(temp%b==0)
				break;
			++cnt1;
			--temp;
		}
		cnt2=((a+b-1)/b)*b-a;
		return min(cnt1,cnt2);
		
	}
}
 
void test_case(){
	ll n;
	cin>>n;
	vector<ll> A(n);
	ll o=0;
	for(int i=0;i<n;i++){cin>>A[i]; if(A[i])++o;}
	if(n==1){
		if(A[0]==1)
			cout<<1<<"\n";
		else
			cout<<0<<"\n";
		return ;
	}
	
	ll glo=A[0]==1?1:0;
	ll dp[n][2];
	ll ans=0;
	for(int i=1;i<n;++i){
		ll k;
		ll cnt=A[i]==1;
		if(i-2<=0)
			k=0;
		else
			k=max(dp[i-2][0],dp[i-2][1]);
		ll p;
		ll q;
		if(i-1<=0){
			p=0;
			q=0;
		}
		else{
			p=dp[i-1][0];
			q=dp[i-1][1];
		}
			
		dp[i][0]=max(q,k+cnt);
		dp[i][1]=max(q,p+cnt);
		
	}
	ans=max(dp[n-1][0],dp[n-1][1]);
	ans=o-ans;
	cout<<ans<<"\n";
	
	
}
int main(){
	int t;
	cin>>t;
	while(t--)
	test_case();	
}
