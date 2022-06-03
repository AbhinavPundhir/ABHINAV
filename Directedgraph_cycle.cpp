#include<bits/stdc++.h>
using namespace std;


bool checkCycle(vector<int>adj[], int src, vector<bool>&visited, vector<bool>&recvisited){
visited[src]=true;
recvisited[src]=true;
vector<int>:: iterator itr;

for(itr = adj[src].begin(); itr!= adj[src].end(); itr++){
    if(!visited[*itr]){
bool ans = checkCycle(adj, *itr, visited, recvisited);
if(ans==true){
    return true;
}
    }
 else if(recvisited[*itr] == true ){
     return true;
 }
}
recvisited[src]=false;
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
     
 }  

 vector<bool>visited(v, false); 
 vector<bool>recvisited(v,false);
 bool isCycle = false;

 for(int i=0; i<v; i++){
     if(!visited[i]){
         if(checkCycle(adj,i,visited,recvisited)){
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