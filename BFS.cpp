#include<bits/stdc++.h>
using namespace std;


#define inf 1000000
// stops after finding destination
void bfs(vector<int> v[], int src,int dest, vector<long long> &dist, int *visited){

    queue<int> que;
    que.push(src);

    visited[src]=1;
    dist[src]=0;

    while (!que.empty()){
        int out=que.front(); que.pop();
        for (auto i : v[out]){
            // if i node is white 
            if (visited[i]==0){
                // coloring i into gray 
                visited[i]=1;
                que.push(i);
                dist[i]=dist[out]+1;
                if (i== dest) return;
            }
        }
        // coloring out black 
        visited[out]=2;
    }
}

// visits all nodes
void bfs(vector<int> v[], int src, vector <long long > &dist, int *visited){

    queue<int> que;
    que.push(src);

    visited[src]=1;
    dist[src]=0;

    while (!que.empty()){
        int out=que.front(); que.pop();
        for (auto i : v[out]){
            // if i node is white 
            if (visited[i]==0){
                // coloring i into gray 
                visited[i]=1;
                que.push(i);
                dist[i]=dist[out]+1;
                
            }
        }
        // coloring out black 
        visited[out]=2;
    }

}
int main(){
    int v,e;
    cin >> v >> e;

    vector<int> adj[v+1];

    for(int i=0;i<e;i++){
        int x,y; cin >> x>> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int source=1;// cin >> source;
    //int destination ; cin >> destination ;


    vector<long long>  distance(v+1);
    int visited[v+1]={0};

    

    bfs(adj,source,distance, visited);

    for (int i=1 ;i < v+1 ; i++)cout << distance[i] << " ";
    cout << endl;
    //for (int i=1 ;i < v+1 ; i++)cout << visited[i] << " ";
   

    int oneend=1;
    int max=distance[1];

    for (int i=2;i<v+1;i++){
        if (distance[i]>max){
            max=distance[i];
            oneend=i;
        }
    }
    //cout << oneend;

    for (int i=1;i<v+1;i++) visited[i]=0;

    bfs(adj,oneend,distance,visited);

    max=distance[oneend];

    for (int i=1;i<v+1;i++){
        if (distance[i]>max){
            max=distance[i];
            //oneend=i;
        }
    }
    cout << max ;
    

    




    


    return 0;
}