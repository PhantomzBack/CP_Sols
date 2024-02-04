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
    int h, w;
    cin >> h >> w;
    ll arr[h][w], mod=1000000007;
    for(int i=0;i!=h;i++){
        char x;
        string m;
        cin >> m;
        for(int j=0;j!=w;j++){
            x=m[j];
            //cout << x;
            if(x=='.'){
                arr[i][j]=0;
                if(i==0 && j==0){
                    arr[i][j]=1;
                }
                else if(i==0){
                    if(arr[i][j-1]!=-1){
                        arr[i][j]=(arr[i][j]+arr[i][j-1])%mod;
                    }
                    else{
                        arr[i][j]=-1;
                    }
                }
                else if(j==0){
                    if(arr[i-1][j]!=-1){
                        arr[i][j]=(arr[i][j]+arr[i-1][j])%mod;
                    }
                }
                else{
                    if(arr[i][j-1]!=-1){
                        arr[i][j]=(arr[i][j]+arr[i][j-1])%mod;
                    }
                    if(arr[i-1][j]!=-1){
                        arr[i][j]=(arr[i][j]+arr[i-1][j])%mod;
                    }
                    if(arr[i-1][j]==-1 && arr[i][j-1]==-1){
                        arr[i][j]=-1;
                    }

                }
            }
            else{
                arr[i][j]=-1;
            }
        }
    }
    /*for(int i=0;i!=h;i++){
        for(int j=0;j!=h;j++){
            printf("%lld ", arr[i][j]);
        }
        printf("\n");
    }*/
    if(arr[h-1][w-1]==-1){
        arr[h-1][w-1]=0;
    }
    cout << arr[h-1][w-1];
}