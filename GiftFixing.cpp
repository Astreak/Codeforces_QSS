#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define ll long long
#define E 1e9+7
using namespace std;
 
 
void test_case(){
    ll n;
    cin>>n;
    vector<ll> A(n);
    vector<ll> B(n);
    ll m1=LLONG_MAX;
    ll m2=LLONG_MAX;
    for(int i=0;i<n;i++){ cin>>A[i],m1=min(m1,A[i]);} 
    for(int i=0;i<n;++i){ cin>>B[i],m2=min(m2,B[i]);}
    ll cnt=0;
    for(int i=0;i<n;i++){
        ll da=A[i]-m1;
        ll db=B[i]-m2;
        ll k=min(da,db);
        cnt+=k;
        da-=k;
        db-=k;
        cnt+=max(da,db);
      
    }
    cout<<cnt<<"\n";
   
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--)
      test_case();
    
  
}
 
