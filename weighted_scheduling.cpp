#include <bits/stdc++.h>
using namespace std;


struct job{
    int start, end, profit;
};

bool sortbyend(const job &a, const job &b){
    return a.end < b.end;
}

int main(){
    job j[6];

    for (int i =0;i<6 ;i++){
        cin >> j[i].start >> j[i].end >> j[i].profit;
    }

    sort(j,j+6,sortbyend);

    int T[6];
    for (int i=0;i<6;i++){
        T[i]=j[i].profit;
    }

    for (int i=1;i<6;i++){
        for (int k=0;k<i;k++){
            if (j[k].end <= j[i].start){
                T[i]=max(T[i],T[k]+j[i].profit);
            }
        }
    }

    for (int i=0;i<6;i++) cout << T[i] <<  " ";



    return 0;
}