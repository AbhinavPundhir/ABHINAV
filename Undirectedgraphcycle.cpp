#include<bits/stdc++.h>
using namespace std;


bool checkCycle(vector<int>adj[], int src, int parent, vector<bool>&visited){
visited[src]=true;
vector<int>:: iterator itr;

for(itr = adj[src].begin(); itr!= adj[src].end(); itr++){
    if(!visited[*itr]){
bool ans = checkCycle(adj, *itr, src, visited);
if(ans==true){
    return true;
}
    }
 else if(*itr!= parent){
     return true;
 }

}
return false;
}

int main(){
 int v, e;
 cin>>v>>e;

 vector<int> adj[v];

 for(int i=0; i<e; i++){
     int v1, v2;
     cin>>v1>>v2;
     adj[v1].push_back(v2);
     adj[v2].push_back(v1);
 }  

 vector<bool>visited(v, false); 
 bool isCycle = false;

 for(int i=0; i<v; i++){
     if(!visited[i]){
         if(checkCycle(adj,i,-1,visited)){
             isCycle = true;
             break;
         }
     }
 }
 if(isCycle == true){
     cout<<"Yes"<<endl;
 }

 else cout<<"No"<<endl;
}