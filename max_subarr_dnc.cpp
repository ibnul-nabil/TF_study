#include <bits/stdc++.h>
using namespace std;


#define forn(n) for (int i=0;i<n;i++)
#define ll long long 
ll crossing_sum(vector <ll > &v, int start , int mid , int end ){
    ll left=v[mid];
    ll right=v[mid+1];

    ll lsum=0;
    ll rsum=0;

    for(int i=mid;i>=start;i--){
        lsum+=v[i];
        left=max(left, lsum);
    }

    for(int i=mid+1;i<=end;i++){
        rsum+=v[i];
        right=max(right, rsum);
    }
    
    return max(max(left, right),left+right);

}
ll max_subarr_sum(vector<ll> &v, int start, int end){

    if (start==end) return v[start];

    int mid =(start+end)/2;

    ll left_sum= max_subarr_sum(v,start, mid);
    ll right_sum= max_subarr_sum(v, mid+1,end);
    ll cross=crossing_sum(v,start, mid , end);
    

    return max(max(left_sum, right_sum),cross);
}
int main(){

    int n; cin >> n;
    vector<ll> v(n);

    forn(n) cin >> v[i];
    int s=0;  int e=n-1;
    ll r=max_subarr_sum(v,s,e);
    cout << r <<  endl;
    return 0;
}