#include<bits/stdc++.h>
#include<stdio.h>
#define ll unsigned long long unsigned long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

vector<vector<unsigned long long>> adj_list;
vector<unsigned long long> ways;
unsigned long long dfs(unsigned long long q, unsigned long long parent){
    
    if(ways[q]!=-1){
        return (ways[q]%(1000000007));
    }
    else{
        ways[q]=0;
        int count=0;
        if(adj_list[q].size()==0){
            return 0;
            
        }
        for(auto it:adj_list[q]){
            if((it)!=parent){
                ways[q]+=dfs(it, q);
                count++;
            }
        }
        return (ways[q]%(1000000007));
    }
}
int main(){
    std::ifstream in("game_routes_input.cpp");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf());
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    unsigned long long n,m;
    
    cin >> n >> m;
    adj_list=vector<vector<unsigned long long>>(n+1, vector<unsigned long long>());
    ways=vector<unsigned long long>(n+1, -1);
    ways[1]=1;
    for(unsigned long long i=0;i!=m;i++){
        unsigned long long a, b;
        cin >> a >> b;
        adj_list[b].push_back(a);
    }
    
    cout << dfs(n, -1);
    

    

}