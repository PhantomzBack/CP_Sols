#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;
void build(int v, int tl, int tr, vector<ll> &arr, vector<ll> &seg_tree){
    if(tl==tr){
        seg_tree[v]=arr[tl-1];
        
    }
    else{
        int mid=(tl+tr)/2;
        build(2*v, tl, mid, arr, seg_tree);
        build(2*v+1, mid+1, tr, arr, seg_tree);
        seg_tree[v]=seg_tree[2*v]+seg_tree[2*v+1];
        
    }
}
void update(int v, int tl, int tr,int pos, int val, vector<ll> &arr, vector<ll> &seg_tree){
    if(tl==tr){
        seg_tree[v]=val;
        
    }
    else{
        int mid=(tl+tr)/2;
        if(pos<=mid){
            update(2*v, tl, mid, pos, val, arr, seg_tree);
            seg_tree[v]=seg_tree[2*v];
        }
        else{
            update(2*v+1, mid+1, tr, pos, val, arr, seg_tree);
            seg_tree[v]=seg_tree[2*v+1];
        }
        seg_tree[v]=seg_tree[2*v]+ seg_tree[2*v+1];
        
    }
}

ll query(int v, int tl, int tr, int l, int r, vector<ll> &arr, vector<ll> &seg_tree){
    if(l>r){
        return numeric_limits<long long>::max();
    }
    if(l==tl && r==tr){
        return seg_tree[v];
    }
    int mid=(tl+tr)/2;
    //cout << tl << " " << min(mid, r) << "\n";
    //cout << max(mid+1, l) << " " << tr << "\n";
    //return min(query(2*v, tl, min))
    return query(2*v, tl, mid, l, min(mid, r), arr, seg_tree)+ query(2*v+1, mid+1, tr, max(l, mid+1), r, arr, seg_tree);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    vector<ll> seg_tree(4*n+1, numeric_limits<long long int>::max());
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    build(1, 1, n, arr, seg_tree);
    
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> c >> a >> b;
        if(c==1){
            update(1, 1, n, a, b, arr, seg_tree);
            /*for(int i=0;i<4*n;i++){
                cout << seg_tree[i] << "\n";
            }*/
        }
        
        else{
            cout << query(1, 1, n, a, b, arr, seg_tree) << "\n";
        }
    }
    
    

    
}