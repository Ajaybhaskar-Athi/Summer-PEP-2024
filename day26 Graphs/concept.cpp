#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> adjacencyList(){
    int n,e;
    cout<<"Enter No of Nodes ?"<<endl;
    cin>>n;
    cout<<"Enter Edges a and b That Are Connected: "<<endl;
    vector<vector<int>>g(n+1);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    return g;
}
void print(vector<vector<int>>g){

}






void dfs(int src,vector<int>&vis,vector<vector<int>>&g){
    vis[src]=1;
    cout<<src<<" ";
    for(int i=0;i<g[src].size();i++){
        if(!vis[g[src][i]]) dfs(g[src][i],vis,g);
    }
    return;


}


void bfs(vector<vector<int>>&g,int src){
    queue<int>q;
    vector<int>vis(g.size(),0);
    vis[src]=1;
    q.push(src);
    while(!q.empty()){
        int f=q.front();
        q.pop();
        cout<<f<<endl;
        for(int i=0;i<g[f].size();i++){
          if(!vis[g[f][i]]){
              q.push(g[f][i]);
            vis[g[f][i]]=1;

          }
        }
    }
}
int main(){
    vector<vector<int>>g=adjacencyList();
    print(g);
}