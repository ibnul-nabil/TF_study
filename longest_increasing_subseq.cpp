#include <bits/stdc++.h>
using namespace std;

#define forn(n) for (int i=0;i<n;i++)

int main(){

    int n; cin >> n;
    vector<int> v(n);

    forn(n) cin >> v[i];

    vector<int> len(n,1);

    forn(n){
        for(int j=0;j<i;j++){
            if (v[j]<v[i]) len[i]=max(len[i],len[j]+1);
        }
    }
    for (auto i : len )  cout  << i << " ";


    
    return 0;
}