#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;
vector<pair<vector<int>, int>> adj;
vector<int> pres;

int calculate_max_depth(int v){
    //printf("here with %d\n", v);
    if(adj[v-1].second!=-1){
        return adj[v-1].second;
    }
    else{
        int depth=0;
        for(auto child:adj[v-1].first){
            //printf("here with %d\n", child);
            depth=max(depth, calculate_max_depth(child));
        }
        adj[v-1].second=depth+1;
        return depth+1;
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj=vector<pair<vector<int>, int>> (n, {vector<int>(0), -1});
    pres=vector<int>(n, 0);
    //cout << "here";
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x-1].first.push_back(y);
        pres[y-1]=1;
    }
    //int parent=-1;
    int max_depth=-1;
    for(int i=1;i<=n;i++){
        //printf("%d-%d ", pres[i-1], i);
        if(pres[i-1]==0){
            max_depth=max(max_depth, calculate_max_depth(i));
        }
    }
    // for (int i = 0; i < adj.size(); i++)
    // {
    //     printf("%d->%d ", i+1, adj[i].second);
    // }
    
    // printf("\n");
    cout << max_depth-1;
}