#include<bits/stdc++.h>
#define ll long long
#define E 1e9+7

using namespace std;


class Graph{
public:
	ll V;
	vector<ll> adj[10000];
	Graph(ll a){
		this->V=a;
	}
	map<ll,ll> bfs(ll s);
	void add_edge(ll a,ll b);
	void dfs_utils(ll s,vector<bool> &vis,ll p,ll& t,map<ll,pair<ll,ll>>&time);
	map<ll,pair<ll,ll>> dfs(ll s);
	
};
void Graph::add_edge(ll a,ll b){
	adj[a].emplace_back(b);
}
void Graph::dfs_utils(ll v,vector<bool>& vis,ll p,ll &t,map<ll,pair<ll,ll>>& time){
	vis[v]=true;
	ll start=t+1;
	++t;
	for(auto x:adj[v]){
		if(!vis[x])
			dfs_utils(x,vis,v,t,time);
	}
	time[v]=make_pair(start,t);
}
map<ll,pair<ll,ll>> Graph::dfs(ll s){
	vector<bool> vis(V,false);
	ll t=0;
	map<ll,pair<ll,ll>> time;
	dfs_utils(s,vis,-1,t,time);
	return time;
}
map<ll,ll> Graph::bfs(ll s){
	vector<bool> vis(V,false);
	queue<ll> Q;
	map<ll,ll> dp;
	Q.push(s);
	vis[s]=true;
	dp[s]=0;
	while(!Q.empty()){
		ll v=Q.front();
		Q.pop();
		for(auto x:adj[v]){
			if(!vis[x]){
				Q.push(x);
				vis[x]=true;
				dp[x]=dp[v]+1;
			}
		}
	}
	return dp;
}

class Fen{
public:
	ll n;
	vector<ll> A;
	Fen(ll a){
		this->n=a;
		for(int i=0;i<n+1;i++)
			A.push_back(0);
	}
	void add_el(ll x,ll i);
	ll get_sum(ll a,ll b);
	
};
void Fen::add_el(ll x,ll i){
	ll k=i+1;
	while(k<=n){
		A[k]+=x;
		k+=(k&-k);
	}
}
ll Fen::get_sum(ll a,ll b){
		ll temp=a+1;
		ll S1=0;
		while(temp>0){
			S1+=A[temp];
			temp-=(temp&-temp);
		}
		ll S2=0;
		temp=b+1;
		while(temp>0){
			S2+=A[temp];
			temp-=(temp & -temp);
		}
		return S2-S1;
}
bool is_prime(ll n){
	if(n<2)
		return false;
	else if(n==2)
		return true;
	else if(n%2==0)
		return false;
	for(int i=3;i*i<=n;i+=2){
			if(n%i==0)
				return false;
	}
	return true;
}
bool checker(string s){
	ll n=s.length();
	if(n<=2)
		return true;
	
		ll a=(s[0]==s[n-2]);
		ll b=(s[1]==s[n-1]);
		if(a && b){
			for(int i=0;i<n-2;i++){
				if(s[i]!=s[i+2])
					return false;
			}
			return true;
		}
		
	return false;
}
ll rec(string s,ll low,ll high,ll v){
	if(low<=high){
		string temp=s.substr(low,high+1);
		if(checker(s))
			return v=max(v,high-low+1);
			
		return max(rec(s,low,high-1,v),rec(s,low+1,high,v));
		
	}
	return -1;
}
ll fact(ll n){
	ll res=1;
	const ll inf=1e9+7;
	for(ll i=1;i<=n;i++){
		res=((res%inf)*(i%inf))%inf;
	}
	return res;
}
bool can_win(vector<pair<ll,ll>> A,ll m){
		ll key=A[m].first;
		for(int i=0;i<A.size();i++){
			if(i==m)
				continue;
			else if(key<A[i].first)
				return false;
			key+=A[i].first;
			
		}
		return true;
}
ll binE(ll a,ll b){
	ll res=1;
	while(b>=1){
		if(b&1)
			res=res*a;
		a*=a;
		b>>=1;
	}
	return res;
}

vector<ll> facs(ll n){
		vector<ll> ans;
		for(int i=2;i*i<=n;i++){
				bool f=false;
				while(n%i==0){
					f=true;
					n/=i;
					ans.push_back(n);
				}
				
		}
		if(n>1)
			ans.push_back(n);
		return ans;
}
bool is_sorted(vector<ll> A,int start,int end){
		for(int i=start;i<end;i++){
			if(A[i]>A[i+1])
				return false;
		}
		return true;
}
bool possible(int n,int a,int b,int B[][1000]){
		for(int i=0;i<b;i++)
			if(B[a][i])
				return false;
		for(int i=a,j=b;j>=0 && i>=0;j--,i--)
				if(B[i][j])
					return false;
		for(int i=a,j=b;j>=0 && i<n;j--,i++)
			if(B[i][j])
				return false;
		return true;
		
	
}
bool backtrack(int n,int m,int b[][1000]){
		if(m>=n)
			return true;
		for(int i=0;i<n;i++){
				if(b[i][m]==0){
					if(possible(n,i,m,b)){
						b[i][m]=1;
						if(backtrack(n,m+1,b))
							return true;
						b[i][m]=0;
							
					}
						
				}
		}
		return false;
	
}

void test_case(){
	ll n;
	cin>>n;
	int b[n][1000];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			b[i][j]=0;
	if(!backtrack(n,0,b)){
		cout<<"NOTPOSSIBLE"<<"\n";
		return;
	}
	else{
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
					cout<<b[i][j]<<" ";
			}
			puts("");
		}
		
	}
	
	
}

int main(){
	int t;
	cin>>t;
	while(t--)
	test_case();
	
}
// 0 --> 2 ---> 2
// 1 --> 2 --> 1
// 0->1 --> 1
// 2->1 --> 2
// 
