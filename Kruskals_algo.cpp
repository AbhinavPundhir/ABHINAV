#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int u;
    int v;
    int wt;
};

bool comp( Node a,  Node b){
    return a.wt<b.wt;
}

int findParent(int Node, vector<int>&parent){ // finds the the ultimate parrent of a given  node
    if(Node==parent[Node]){
     return Node;
    }

    else{
       return findParent(parent[Node], parent);
    }
}

void unionfind(int u, int v, vector<int>&parent, vector<int>&rank){
    int U = findParent(u, parent);
    int V = findParent(v, parent);

    if(rank[U]<rank[V]){
        parent[U]=V;
        return;
    }
    else if(rank[V]<rank[U]){
        parent[V]=U;
        return;
    }
    else{
        parent[U]=V;
        rank[V]+=1;
    }

}

int main(){
    int v,e;
    cin>>v>>e;
    vector<Node>edges;
    for(int i=0; i<e; i++){
        int u,v,wt;
        cin>>u>>v>>wt;

        Node X;
        X.u=u;
        X.v=v;
        X.wt=wt;
        edges.push_back(X);
    }

    sort(edges.begin(), edges.end(), comp);

    vector<int>parent(v);
    for(int i=0; i<v; i++){
        parent[i]=i;
    }
    vector<int>rank(v,0);
    vector<pair<int,pair<int,int>>>MST;
    int ans=0;

    for(int i=0; i<edges.size(); i++){
        int u=edges[i].u;
        int v=edges[i].v;
        int wt=edges[i].wt;

        if(findParent(u, parent)!= findParent(v, parent)){
            MST.push_back({wt,{u,v}});
            unionfind(u,v,parent,rank);
        }
    }
    
    for(int i=0; i<MST.size(); i++){
        ans+=MST[i].first;
        cout<<MST[i].first<<" "<<MST[i].second.first<<" "<<MST[i].second.second<<endl;
    }
    cout<<ans<<endl;
    return 0;

}


