#include<bits/stdc++.h>
#define ll long long 
#define E (ll)(1e9+7)
using namespace std;
struct SumsgTree{
	ll n;
	vector<ll> A;
	void init(ll a){
		n=1;
		while(n<a) n*=2;
		A.assign(2*n,0ll);
	}
	void update(ll l,ll v,ll x,ll lx,ll rx){
			if(lx==rx-1){
				A[x]=v;
				return;
			}
			ll m=(lx+rx)/2;
			if(l<m){
				update(l,v,2*x+1,lx,m);
			}else{
				update(l,v,2*x+2,m,rx);
			}
			A[x]=A[2*x+1]+A[2*x+2];
				
	}
	ll sum(ll l,ll r,ll x,ll lx,ll rx){
		if(l>=rx || r<=lx) return 0;
 		if(lx>=l  && rx<=r) return A[x];
 		ll m=(lx+rx)/2;
 		ll s1=sum(l,r,2*x+1,lx,m);
 		ll s2=sum(l,r,2*x+2,m,rx);
 		return s1+s2;
 		
	}
	ll sum(ll l,ll r){
		return sum(l,r,0,0,n);
	}
	void update(ll i,ll v){
		update(i,v,0,0,n);
	}
	void print(){
		for(auto x:A)
			cout<<x<<" ";
		puts("");
		
	}
	
	
};
struct MinsgTree{
	ll n;
	vector<ll> A;
	void init(ll a){
		n=1;
		while(n<a) n*=2;
		A.assign(2*n,0ll);
	}
	void update(ll l,ll v,ll x,ll lx,ll rx){
			if(lx==rx-1){
				A[x]=v;
				return;
			}
			ll m=(lx+rx)/2;
			if(l<m){
				update(l,v,2*x+1,lx,m);
			}else{
				update(l,v,2*x+2,m,rx);
			}
			A[x]=min(A[2*x+1],A[2*x+2]);
				
	}
	void update(ll i,ll v){
		update(i,v,0,0,n);
	}
	void print(){
		for(auto x:A)
			cout<<x<<" ";
		puts("");
		
	}
	
	
};
struct MaxsgTree{
	ll n;
	vector<ll> A;
	void init(ll a){
		n=1;
		while(n<a) n*=2;
		A.assign(2*n,0ll);
	}
	void update(ll l,ll v,ll x,ll lx,ll rx){
			if(lx==rx-1){
				A[x]=v;
				return;
			}
			ll m=(lx+rx)/2;
			if(l<m){
				update(l,v,2*x+1,lx,m);
			}else{
				update(l,v,2*x+2,m,rx);
			}
			A[x]=max(A[2*x+1],A[2*x+2]);
				
	}
	
	void update(ll i,ll v){
		update(i,v,0,0,n);
	}
	void print(){
		for(auto x:A)
			cout<<x<<" ";
		puts("");
		
	}
	
	
};

void test_case(){
	ll n;
	cin>>n;
	SumsgTree st;
	st.init(n);
	for(int i=0;i<n;i++){
		ll a;
		cin>>a;
		st.update(i,a);
	}
	cout<<st.sum(1ll,3ll)<<"\n";
	
	
}
int main(){
	int t;
	cin>>t;
	while(t--)
	test_case();	
}
	
