#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;
#define ld long double

int n;
vector<vector<vector<ld>>> arr;
ld calculate_sol_n(vector<int> counts){
    //cout << "\nLol:" << arr[counts[0]][counts[1]][counts[2]] << "\n";
    /*cout << "Counts: ";
    for(auto it:counts){
        cout << it << " ";
    }
    cout << endl;*/
    if(arr[counts[0]][counts[1]][counts[2]]==-1){
        arr[counts[0]][counts[1]][counts[2]]=((ld)n);
        if(counts[0]){
            //cout << "1.Adding:" << counts[0]-1 << " " << counts[1] << " " << counts[2] << " as " << ((ld)counts[0])*calculate_sol_n({counts[0]-1, counts[1], counts[2]}) << "\n";
            arr[counts[0]][counts[1]][counts[2]]+=((ld)counts[0])*calculate_sol_n({counts[0]-1, counts[1], counts[2]});
        }
        if(counts[1]){
            //cout << "2.Adding:" << counts[0]+1 << " " << counts[1]-1 << " " << counts[2]<< " as " << ((ld)counts[1])*calculate_sol_n({counts[0]+1, counts[1]-1, counts[2]}) << "\n";
            arr[counts[0]][counts[1]][counts[2]]+=((ld)counts[1])*calculate_sol_n({counts[0]+1, counts[1]-1, counts[2]});
        }
        if(counts[2]){
            //cout << "3.Adding:" << counts[0] << " " << counts[1]+1 << " " << counts[2]-1<< " as " << ((ld)counts[2])*calculate_sol_n({counts[0], counts[1]+1, counts[2]-1}) << "\n";
            arr[counts[0]][counts[1]][counts[2]]+=((ld)counts[2])*calculate_sol_n({counts[0], counts[1]+1, counts[2]-1});
        }
        arr[counts[0]][counts[1]][counts[2]]/=((ld)(counts[0]+counts[1]+counts[2]));
        //cout << "IT's:" << arr[counts[0]][counts[1]][counts[2]] <<endl;
        //arr[counts[0]][counts[1]][counts[2]]=(((ld)counts[0])*calculate_sol_n({0, counts[1], counts[2]})+((ld)counts[2])*calculate_sol_n({counts[0], counts[1]+counts[2], 0})+((ld)counts[1])*calculate_sol_n({counts[0]+counts[1],0, counts[2]}))/((ld)n);
    }
    return arr[counts[0]][counts[1]][counts[2]];
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    arr=vector<vector<vector<ld>>>(n+1, vector<vector<ld>>(n+1, vector<ld>(n+1, ((ld)-1))));
    vector<int> counts(3,0);
    vector<ll> ai(n,0);
    cout.precision(17);
    arr[0][0][0]=0;
    for (int i = 0; i < n; i++)
    {
        cin >> ai[i];
        counts[ai[i]-1]+=1;
        arr[i+1][0][0]=arr[i][0][0]+((ld)n)/(i+1);
        //cout << "Arr " << i+1 << ":" << arr[i+1][0][0] << "\n";
    }
    
    cout << calculate_sol_n(counts);
    




    
}