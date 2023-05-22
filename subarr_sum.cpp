#include <bits/stdc++.h>
using namespace std;

#define forn(n) for (int i=0;i<n;i++)
int main(){

    int n; cin >> n;
    vector<int> v(n);

    forn(n) cin >> v[i];
    
    int best=v[0];
    /*
    forn(n){
        int sum=0;
        for (int j=i;j<n;j++)
        {
            sum+=v[j];
            best=max(sum,best);
        }
    }
    */

    //kadane's algo

    int sum=0;

    forn(n){
        sum=max(v[i],sum+v[i]);
        best=max(best,sum);
    }
    cout << best << endl;
    return 0;
}