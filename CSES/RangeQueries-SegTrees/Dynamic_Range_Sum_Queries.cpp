
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
        return 0;
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
    vector<ll> seg_tree(4*n+1, 0);
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


#ifdef lol
#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

void update(int n, vector<ll> &arr, vector<ll> &arr_orig, vector<pair<ll, ll>> &ps, set<int> &updated){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    vector<ll> arr(n);
    vector<ll> arr_orig(n);
    vector<pair<ll, ll>> ps(n, {0, -1}); //original, latest
    set<int> orders;
    set<int> updated;
    int last_unmodified=n-1;
    for(int i=0;i!=n;i++){
        cin >> arr[i];
        arr_orig[i]=arr[i];
        if(i!=0){
            ps[i]={ps[i-1].first+arr[i], ps[i-1].first+arr[i]};
        }
        else{
            ps[i]={arr[i], arr[i]};
        }
    }
    orders.insert(0);
    for(int j=0;j!=q;j++){
        int c, a, b;
        cin >> c >> a >> b;
        --a;
        if(c==1){
            updated.insert(a);
            last_unmodified=min(a, last_unmodified);
            arr[a]=b;
        }
        if(c==2){
            --b;
            ll val_a, val_b;
            
            cout << val_b-val_a << "\n";
            
        }

    }
}
#endif