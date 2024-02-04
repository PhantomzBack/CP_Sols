#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;
vector<vector<pair<int, ll>>> adj_list;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj_list=vector<vector<pair<int, ll>>>(n);
    vector<vector<pair<int, ll>>> rev_adj_list(n);
    set<pair<ll, int>> order;
    vector<ll> scores=vector<ll>(n, std::numeric_limits<long long int>::max());
    vector<ll> scores_reverse=vector<ll>(n, std::numeric_limits<long long int>::max());
    order.insert({0, 0});
    
    scores[0]=0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        adj_list[a].push_back({b, c});
        rev_adj_list[b].push_back({a, c});
    }
    while(!order.empty()){
        auto top=*order.begin();
        for(auto it:adj_list[top.second]){
            if(top.first+it.second<scores[it.first]){
                if(scores[it.first]!=std::numeric_limits<long long int>::max()){
                    order.erase({scores[it.first], it.first});
                }
                scores[it.first]=top.first+it.second;
                order.insert({top.first+it.second, it.first});
            }

        }
        order.erase(top);
    }
    scores_reverse[n-1]=0;
    order.insert({0,n-1});
    while(!order.empty()){
        auto top=*order.begin();
        for(auto it:rev_adj_list[top.second]){
            if(top.first+it.second<scores_reverse[it.first]){
                if(scores_reverse[it.first]!=std::numeric_limits<long long int>::max()){
                    order.erase({scores_reverse[it.first], it.first});
                }
                scores_reverse[it.first]=top.first+it.second;
                order.insert({top.first+it.second, it.first});
            }

        }
        order.erase(top);
    }
    
    ll min_score=std::numeric_limits<long long int>::max();
    for(int i=0;i!=n;i++){
        for(auto edge:adj_list[i]){
            if(scores[i]!=std::numeric_limits<long long int>::max() && scores_reverse[edge.first]!=std::numeric_limits<long long int>::max()){
                min_score=min(min_score, scores[i]+scores_reverse[edge.first]+edge.second/2);
            }
        }
    }
    cout << min_score;

    
    
}

/*vector<int> dp, visited;
vector<pair<int, int>> dp_;
vector<vector<pair<int, int>>> adj_list;

void dfs(int n, int parent){
    if(visited[n]!=1){
        for(auto it:adj_list[n]){
            if(it.first!=parent){
                if((dp_[n].first+it.second)<dp_[it.first].first){
                    dp_[it.first]=dp_[n].first+it.second
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    dp=vector<int>(n, INFINITY);
    dp_=vector<pair<int, int>>(n, {INFINITY, -1});
    adj_list=vector<vector<pair<int, int>>>(n);
    visited=vector<int>(n, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a;--b;
        adj_list[a].push_back({b, c});
    }
    dp[0]=0;
    dp_[0]={0, -2};

    
    
}*/