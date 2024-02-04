#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;
set<int> st;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    for(int i=0;i!=n;i++){
        int m;
        cin >> m;
        st.insert(m);
    }
    vector<int> vst;
    for(auto m:st){
        vst.push_back(m);
    }
    int dp[k+1];
    for(int i=k;i!=k-vst[0];i--){
        dp[i]=-1;
    }
    for(int i=k-vst[0];i>=0;i--){
        int sol=-1;
        for(int j=0;j!=n;j++){
            if(i+vst[j]<=k){
                sol=max(sol, -dp[i+vst[j]]);
            }
        }
        dp[i]=sol;
    }
    if(dp[0]+1){
        cout << "First";
    }
    else{
        cout << "Second";
    }

}