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
	ll n,q,k;
	cin>>n>>q>>k;
	vector<ll> A(n);
	
	for(auto& x:A){
		cin>>x;
		
	}
	ll dp[n];
	for(int i=0;i<n;i++){
			if(i==0)
				dp[i]=A[i+1]-2;
			else if(i==n-1)
				dp[i]=dp[i-1]+(k-A[i-1]-1);
			else
				dp[i]=dp[i-1]+A[i+1]-A[i-1]-2;
	}
	
	vector<ll> ans;
	while(q--){
		ll a,b;
		cin>>a>>b;
		ll fi=0;
		if(a==b){
			ans.push_back(k-1);
			continue;
		}
		--a;--b;
		ll cn=0;
		ll store=A[a+1]-2;
		if(a!=0)
			cn+=store-dp[a];
		store=k-A[b-1]-1;
		cn+=store-(dp[b]-dp[b-1]);
		fi=dp[b]+cn;
		ans.push_back(fi);
		
	}
	for(auto x:ans)
		cout<<x<<"\n";
	
	
	
	
}
int main(){
	
	test_case();	
}

