#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> strings;
    string a, b, c="";
    cin >> a;
    cin >> b;
    int s=a.length();
    int t=b.length();
    int max_length=0;
    pair<int, int> max_length_pair={-1, -1};
    //cout << a[s-1] << " " << s << endl;
    if(s<t){
        c=a;
        a=b;
        b=c;
    }
    vector<vector<pair<int, pair<int, int>>>> lens(max(s, t), vector<pair<int, pair<int, int>>>(min(s, t), {0, {-1, -1}}));
    for(int i=0;i!=max(t, s);i++){
        for(int j=0;j!=min(t, s);j++){
            if(a[i]==b[j]){
                if(i==0 || j==0){
                    lens[i][j]={1, {i, j}};
                    if(max_length==0){
                        max_length=1;
                        max_length_pair={i, j};
                    }
                }
                else{
                    
                        lens[i][j]={1+lens[i-1][j-1].first, {i, j}};
                    
                        /*if(1+lens[i-1][j-1].first>max_length){
                            max_length=1+lens[i-1][j-1].first;
                            max_length_pair={i, j};
                        }*/
                    
                    /*else{
                        lens[i][j]={1+lens[i-1][j-1].first, {i, j}};
                    }*/
                }
            }
            else{
                if(i==0 && j!=0){
                    lens[i][j]=lens[i][j-1];
                }
                if(i!=0 && j==0){
                    lens[i][j]=lens[i-1][j];
                }
                if(i!=0 && j!=0){
                    lens[i][j]=max(lens[i-1][j], max(lens[i-1][j-1], lens[i][j-1]));
                }
            }
        }
    }
    string final_str;
    /*for(auto i:lens){
        for(auto j:i){
            printf("{%d %d %d}, ", j.first, j.second.first, j.second.second);
        }
        printf("\n");
    }
    printf("\ndone w that\n");*/
    
    //j=17, i=48
    //printf("\nMax length: %d\n", max_length);
    //printf("\na[48], b[17] %c %c %d\n", a[48], b[17], lens[48][17]);
    //printf("\na[46], b[19] %c %c %d\n", a[46], b[19], lens[46][19]);
    max_length_pair=lens[max(s,t)-1][min(s,t)-1].second;
    //max_length_pair={48, 17};
    //max_length_pair={9, 3};
    //auto j=lens[9][3];
    //printf("{%d %d %d}, ", j.first, j.second.first, j.second.second);
    while(1){
        if(max_length_pair.first!=-1){
            /*if(a[max_length_pair.first]=='w'){
                printf("%c%d%d", (a[max_length_pair.first]), max_length_pair.first, max_length_pair.second);
            }
            else{
                printf("%c")
            }*/
            final_str.push_back(a[max_length_pair.first]);
        }
        //printf("{%d %d} -> %c\n", max_length_pair.first, max_length_pair.second, a[max_length_pair.first]);
        if(max_length_pair.first!=0 && max_length_pair.second!=0 && max_length_pair.first!=-1){
            max_length_pair=lens[max_length_pair.first-1][max_length_pair.second-1].second;
            
        }
        else{
            break;
        }
    }
    //printf("%d", lens[max(s,t)-1][min(s,t)-1]);
    reverse(final_str.begin(), final_str.end());
    cout << final_str;

}