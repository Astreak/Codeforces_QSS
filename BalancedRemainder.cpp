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
		A.assign(2*n,1e8);
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
	ll minQ(ll l,ll r,ll x,ll lx,ll rx){
		if(l>=rx || r<=lx) return 1e8;
 		if(lx>=l  && rx<=r) return A[x];
 		ll m=(lx+rx)/2;
 		ll s1=minQ(l,r,2*x+1,lx,m);
 		ll s2=minQ(l,r,2*x+2,m,rx);
 		return min(s1,s2);
 		
	}
	ll minQ(ll l,ll r){
		return minQ(l,r,0,0,n);
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
		A.assign(2*n,-1*1e8);
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
	ll maxQ(ll l,ll r,ll x,ll lx,ll rx){
		if(l>=rx || r<=lx) return -1*1e8;
 		if(lx>=l  && rx<=r) return A[x];
 		ll m=(lx+rx)/2;
 		ll s1=maxQ(l,r,2*x+1,lx,m);
 		ll s2=maxQ(l,r,2*x+2,m,rx);
 		return max(s1,s2);
 		
	}
	ll maxQ(ll l,ll r){
		return maxQ(l,r,0,0,n);
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
	assert(n%3==0);
	ll k=n/3;
	vector<ll> A(n);
	map<ll,ll> M;
	for(int i=0;i<n;i++){ cin>>A[i];M[A[i]%3]++}
	ll m=0;
	ll v=-1;
	ll cnt=0;
	for(auto x:M){
		if(m<x.second){
			m=x.second;
			v=x.first;
		}
	}
	if(M[v]==k){
		if(M[(v+1)%3]>=k){
			cnt+=abs(M[(v+2)%3]-k);
		}
		else{
			cnt+=2*abs(M[(v+1)%3]-k);
		}
	}
	else{
		M[(v+1)%3]+=abs(M[v]-k);
		if(M[(v+1)%3]>=k){
			cnt+=abs(M[(v+2)%3]-k);
		}
		else{
			cnt+=2*abs(M[(v+1)%3]-k);
		}
		
	}
	cout<<cnt<<"\n";
		
	
	
}
int main(){
	int t;
	cin>>t;
	while(t--)
	test_case();	
}
	
