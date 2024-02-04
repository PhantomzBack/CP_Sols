#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, w;
    scanf("%lld %lld", &n, &w);
    vector<pair<ll, ll>> objs;
    ll max_v=0;
    for (int i = 0; i < n; i++)
    {
        ll a, b; // a is weight, and b is value
        scanf("%lld %lld", &a, &b);
        max_v+=b;
        objs.push_back({a, b});
    }
    
    vector<vector<ll>> scores(n+1, vector<ll>(max_v+1, std::numeric_limits<long long>::max()));
    for(ll i=0;i<=n;i++){
        scores[i][0]=0;
    }
    
    scores[0][objs[0].s]=objs[0].f;
    for (int i = 0; i < n-1; i++)
    {
        for(int j=0;j<=max_v;j++){
            if(scores[i][j]!= std::numeric_limits<long long>::max()){
                scores[i+1][j]=min(scores[i+1][j], scores[i][j]);
                scores[i+1][j+objs[i+1].s]=min(scores[i+1][j+objs[i+1].s], scores[i][j]+objs[i+1].f);
            }
        }
        
    }
    
    ll score=0;
    for(int j=0;j<=max_v;j++){
        if(scores[n-1][j]<=w && scores[n-1][j]!= std::numeric_limits<long long>::max()){
            score=j;
        }
    }
    printf("%lld", score);
}