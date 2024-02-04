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
    int n, w;
    scanf("%d %d", &n, &w);
    vector<pair<ll, ll>> objs;
    for (int i = 0; i < n; i++)
    {
        ll a, b; // a is weight, and b is value
        scanf("%lld %lld", &a, &b);
        objs.push_back({a, b});
    }
    
    vector<vector<ll>> scores(n+1, vector<ll>(w+1, -1));
    scores[0][0]=0;
    if(objs[0].f<=w){
        scores[0][objs[0].f]=objs[0].s;
    }
    for (int i = 0; i < n-1; i++)
    {
        for(int j=0;j<=w;j++){
            if(scores[i][j]!=-1){
                scores[i+1][j]=max(scores[i+1][j], scores[i][j]);
                if(j+objs[i+1].f<=w){
                    scores[i+1][j+objs[i+1].f]=max(scores[i+1][j+objs[i+1].f], scores[i][j]+objs[i+1].s);
                }
            }
        }
        
    }
    for(auto j:scores[n]){
        
    }
    
    ll score=0;
    for(int j=0;j<=w;j++){
        score=max(score, scores[n-1][j]);
    }
    printf("%lld", score);
}