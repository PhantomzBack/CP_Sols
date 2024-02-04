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
    int n;
    cin >> n;
    cout.precision(std::numeric_limits<long double>::digits10);
    vector<long double> pi(n, 0);
    vector<vector<long double>> prob_table(n, vector<long double>(n+1,0));
    for (int i = 0; i < n; i++)
    {
        cin >> pi[i];
        if(i==0){
            prob_table[0][0]=1-pi[0];
            prob_table[0][1]=pi[0];
        }
        else{
            prob_table[i][0]=prob_table[i-1][0]*(1-pi[i]);
            for(int j=1;j!=i+2;j++){
                prob_table[i][j]=prob_table[i-1][j-1]*pi[i]+prob_table[i-1][j]*(1-pi[i]);
            }
        }
    }
    long double prob_sum=0;
    for(int m=(n/2)+1;m<=n;m++){
        prob_sum+=prob_table[n-1][m];
    }
    cout << prob_sum;
    
    
}