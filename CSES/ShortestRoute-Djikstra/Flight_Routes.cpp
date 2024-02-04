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
    int n, m, k;
    cin >> n >> m >> k;
    adj_list=vector<vector<pair<int, ll>>>(n);
    multiset<pair<ll, int>> order;
    vector<ll> scores=vector<ll>(n, std::numeric_limits<long long int>::max());
    order.insert({0, 0});
    vector<int> visited(n, k);
    vector<ll> routes;
    scores[0]=0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        adj_list[a].push_back({b, c});
    }
    while(visited[n-1]!=0){
        auto top=*order.begin();
        if(visited[top.second]!=0){
            visited[top.second]-=1;
            for(auto it:adj_list[top.second]){
                if(it.first==n-1){
                    routes.push_back(top.first+it.second);
                }
                order.insert({top.first+it.second, it.first});
                
                // if(top.first+it.second<scores[it.first]){
                //     if(scores[it.first]!=std::numeric_limits<long long int>::max()){
                //         order.erase({scores[it.first], it.first});
                //     }
                //     scores[it.first]=top.first+it.second;
                //     order.insert({top.first+it.second, it.first});
                // }

            }
        }
        order.erase(order.find(top));
        
    }
    sort(routes.begin(), routes.end());
    for(int i=0;i!=k;i++){
        cout << routes[i] << " ";
    }
    /*for(int i=0;i!=n;i++){
        cout << scores.push_back[i] << " ";
    }*/
    

    
    
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