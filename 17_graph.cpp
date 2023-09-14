#include <bits/stdc++.h>

using namespace std;

// typedef $long name$ $short name$;
#define ll long long
#define forI(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define endl '\n'
#define dbug1(a) cout<<a<<endl
#define dbug2(a,b) cout<<a<<"-"<<b<<endl
#define dbug3(a,b,c) cout<<a<<"-"<<b<<"-"<<c<<endl
#define dbug4(a,b,c,d) cout<<a<<"-"<<b<<"-"<<c<<"-"<<d<<endl
#define fil1D(a,n,d) fill(a,a+n,d)
#define fil2D(a,n,d) fill(a[0], a[0] + n*n, d)
#define eve_chk(a) (a%2==0)
#define ff first
#define ss second  
#define desc greater<int>()
#define sz size()
#define all(v) v.begin(),v.end()
#define us unsigned
#define MAX 1e9+7
#define ARMX 1e8+1
#define pb push_back 
#define swapI(x,y) {x=x+y;y=x-y;x=x-y;}
#define maxA *max_element 
#define minA *min_element
#define Pinf INT_MAX
#define Ninf INT_MIN
#define rdm(l,h) rand()%(h-l+1)+l 
#define len length()
// srand(time(NULL));

// Node* DFS(Node* node,unordered_map<int,Node*> &mp){
//     if(mp.find(node->val)==mp.end()){
//         Node *tmp=new Node(node->val);
//         mp[node->val]=tmp;
//         for(int i=0;i<node->neighbors.size();i++){
//             tmp->neighbors.push_back(DFS(node->neighbors[i],mp));
//         }
//         return tmp;
//     }
//     return mp[node->val];
// }    
// Node* cloneGraph(Node* node) {
//     if(node==NULL) return NULL;
//     unordered_map<int,Node*> mp;    
//     return DFS(node,mp);
// }

// bool checkBipartBFS(vector<int> *lst,vector<int> &visit,vector<int> &col,int src){
//     queue<int> q;
//     visit[src]=1;
//     q.push(src);
//     col[src]=0;
//     while(!q.empty()){
//         int u=q.front();
//         q.pop();
//         for(auto v:lst[u]){
//             if(visit[v]==0){
//                 visit[v]=1;
//                 col[v]=col[u]^1;
//                 q.push(v);
//             }
//             else{
//                 if(col[v]==col[u]){
//                     return false;
//                 }
//             }
//         }
//     }
//     return true;
// }
// bool isBipartite(int V, vector<int>adj[]){
//     vector<int> visit(V,0);
//     vector<int> col(V,-1);
//     for(int i=0;i<V;i++){
//         if(visit[i]==0 && !checkBipartBFS(adj,visit,col,i)){
//             return false;
//         }
//     }
//     return true;
// }

void addedge(vector<int> *lst,int u,int v){
    lst[u].pb(v);
    lst[v].pb(u);
}

void addDirectedge(vector<int> *lst,int u,int v){
    lst[u].pb(v);
}

void addDirectWeightedge(vector<pair<int,int>> *lst,int u,int v,int w){
    lst[u].pb({v,w});
}

void printgraph(vector<int> *lst,int ver){
    forI(i,0,ver){
        forI(j,0,lst[i].sz){
            cout<<lst[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printWeightgraph(vector<pair<int,int>> *lst,int ver){
    forI(i,0,ver){
        forI(j,0,lst[i].sz){
            cout<<lst[i][j].ff<<":"<<lst[i][j].ss<<" ";
        }
        cout<<endl;
    }
}

void TransposeGraph(vector<int> *lst,vector<int> *op,int ver){
    forI(u,0,ver){
        for(auto v:lst[u]){
            addDirectedge(op,v,u);
        }
    }
}
// ------------------------------------------------------------------
void DFSrecur(vector<int> *lst,int src,bool *visited){
    visited[src]=true;
    cout<<src<<" ";
    for(auto v:lst[src]){
        if(visited[v]==false){
            DFSrecur(lst,v,visited);
        }
    }
}

void DFSdiscont(vector<int> *lst,int ver){
    bool visited[ver];
    fil1D(visited,ver,false);
    forI(i,0,ver){
        if(visited[i]==false){
            DFSrecur(lst,i,visited);
        }
    }
}
// ------------------------------------------------------------------
void BFS(vector<int> *lst,int src,bool *visited){
    queue<int> q;
    visited[src]=true;
    q.push(src);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(auto v:lst[u]){
            if(visited[v]==false){
                visited[v]=true;
                q.push(v);
            }
        }
    }
}

void BFSdiscont(vector<int> *lst,int ver){
    bool visited[ver];
    fil1D(visited,ver,false);
    forI(i,0,ver){
        if(visited[i]==false){
            BFS(lst,i,visited);
        }
    }
}
// ------------------------------------------------------------------
int NoofIslandInGraph(vector<int> *lst,int ver){ // same changes can be done in DFS for same question
    int c=0;
    bool visited[ver];
    fil1D(visited,ver,false);
    forI(i,0,ver){
        if(visited[i]==false){
            BFS(lst,i,visited);
            c++;
        }
    }
    return c;
}

vector<int> ShortPathUnweight(vector<int> *lst,int ver,int src){
    bool visited[ver];
    fil1D(visited,ver,false);
    vector<int> dist(ver,Pinf);
    dist[src]=0;
    queue<int> q;
    visited[src]=true;
    q.push(src);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:lst[u]){
            if(visited[v]==false){
                visited[v]=true;
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist;
}
// ------------------------------------------------------------------
bool LoopDetectDFSrecur(vector<int> *lst,int src,bool *visited,int parent){
    visited[src]=true;
    for(auto v:lst[src]){
        if(visited[v]==false){
            if(LoopDetectDFSrecur(lst,v,visited,src)){
                return true;
            }
        }
        else if(visited[v]==true && v!=parent){
            return true;
        }
    }
    return false;
}

bool DetectLoopUndirected(vector<int> *lst,int ver){
    bool visited[ver];
    fil1D(visited,ver,false);
    forI(i,0,ver){
        if(visited[i]==false){
            return LoopDetectDFSrecur(lst,i,visited,-1);
        }
    }
    return false;
}
// ------------------------------------------------------------------
bool LoopDetectDFSrecur2(vector<int> *lst,int src,bool *visited,bool *recur){
    visited[src]=true;
    recur[src]=true;
    for(auto v:lst[src]){
        if(visited[v]==false && LoopDetectDFSrecur2(lst,v,visited,recur)){
            return true;
        }
        else if(recur[v]==true){
            return true;
        }
    }
    recur[src]=false;
    return false;
}

bool DetectLoopDirected(vector<int> *lst,int ver){
    bool visited[ver];
    fil1D(visited,ver,false);
    bool recur[ver];
    fil1D(recur,ver,false);
    forI(i,0,ver){
        if(visited[i]==false){
            if(LoopDetectDFSrecur2(lst,i,visited,recur)) return true;
        }
    }
    return false;
}
// ------------------------------------------------------------------
void TopologicalBFS(vector<int> *lst,int src,bool *visited,int *indeg){
    queue<int> q;
    visited[src]=true;
    q.push(src);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(auto v:lst[u]){
            indeg[v]--;
            if(indeg[v]==0 && visited[v]==false){
                visited[v]=true;
                q.push(v);
            }
        }
    }
}

void TopologicalSortKahnAlgo(vector<int> *lst,int ver){ // It is only for acyclic graphs
    bool visited[ver];
    fil1D(visited,ver,false);
    int indeg[ver];
    fil1D(indeg,ver,0);
    forI(i,0,ver){
        for(auto v:lst[i]){
            indeg[v]++;
        }
    }
    forI(i,0,ver){
        if(indeg[i]==0 && visited[i]==false){
            TopologicalBFS(lst,i,visited,indeg);
        }
    }
}
// ------------------------------------------------------------------
stack<int> stk;
void DFSrecur2(vector<int> *lst,int src,bool *visited){
    visited[src]=true;
    for(auto v:lst[src]){
        if(visited[v]==false){
            DFSrecur2(lst,v,visited);
        }
    }
    stk.push(src);
}

void TopologicalDFS(vector<int> *lst,int ver){ // this sort also give vertices in decreasing order of their finish time
    bool visited[ver];
    fil1D(visited,ver,false);
    forI(i,0,ver){
        if(visited[i]==false){
            DFSrecur2(lst,i,visited);
        }
    }
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
}
// ------------------------------------------------------------------
bool TopologicalLoopDetect(vector<int> *lst,int src,bool *visited,int *indeg,int ver){
    queue<int> q;
    visited[src]=true;
    q.push(src);
    int count=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:lst[u]){
            indeg[v]--;
            if(indeg[v]==0 && visited[v]==false){
                visited[v]=true;
                q.push(v);
            }
        }
        count++;
    }
    return (count!=ver);
}

bool LoopDetectUseKahnAlgo(vector<int> *lst,int ver){ // It is only for acyclic graphs
    bool visited[ver];
    fil1D(visited,ver,false);
    int indeg[ver];
    fil1D(indeg,ver,0);
    forI(i,0,ver){
        for(auto v:lst[i]){
            indeg[v]++;
        }
    }
    forI(i,0,ver){
        if(indeg[i]==0 && visited[i]==false){
            return TopologicalLoopDetect(lst,i,visited,indeg,ver);
        }
    }
}
// ------------------------------------------------------------------
void DFSrecur3(vector<pair<int,int>> *lst,int src,bool *visited,vector<int> &topo){
    visited[src]=true;
    for(auto v:lst[src]){
        if(visited[v.ff]==false){
            DFSrecur3(lst,v.ff,visited,topo);
        }
    }
    topo.pb(src);
}

vector<int> topoDFS(vector<pair<int,int>> *lst,int ver){
    bool visited[ver];
    fil1D(visited,ver,false);
    vector<int> topo;
    forI(i,0,ver){
        if(visited[i]==false){
            DFSrecur3(lst,i,visited,topo);
        }
    }
    reverse(all(topo));
    return topo;
}

vector<int> ShortPathDAG(vector<pair<int,int>> *lst,int ver,int src){ // DAG: Directed Acyclic graph
    vector<int> dist(ver,100000);
    dist[src]=0;
    vector<int> topo=topoDFS(lst,ver);
    forI(u,0,topo.sz){
        for(auto v:lst[u]){
            dist[v.ff]=min(dist[v.ff],dist[u]+v.ss);
        }
    }
    return dist;
}
// ------------------------------------------------------------------
int primMST(vector<int> *lst,int ver){ // can be optimised using adjacency list and min heap
    int key[ver],res=0;
    fil1D(key,ver,100000);
    key[0]=0;
    bool mset[ver];
    fil1D(mset,ver,false);
    forI(count,0,ver){
        // ---Extracting Minimum---
        int u=-1;
        forI(i,0,ver){
            if(!mset[i] && (u==-1 || key[i]<key[u])) u=i;
        }
        // ---Including it in set---
        mset[u]=true;
        res+=key[u];
        // ---updaing key vector---
        forI(v,0,ver){
            if(lst[u][v]!=0 && !mset[v]){
                key[v]=min(key[v],lst[u][v]);
            }
        }
    }
    return res;
}
// ------------------------------------------------------------------

// works for both directed & undirected grphs with or without cycles
// does not work for negative weighted edge
// result get affected when all the edge weights are increased by addition due to number of edges are different in different path
// result does not get affected when all the edge weights are increased by multiplication
vector<int> DijkstraAlgo(vector<int> *lst,int ver,int src){
    vector<int> dist(ver,100000);
    dist[src]=0;
    bool final[ver];
    fil1D(final,ver,false);
    forI(count,0,ver){
        // ---Extracting Minimum---
        int u=-1;
        forI(i,0,ver){
            if(!final[i] && (u==-1 || dist[i]<dist[u])) u=i;
        }
        // ---Including it in set---
        final[u]=true;
        // ---updaing(relaxing) distance vector---
        forI(v,0,ver){
            if(lst[u][v]!=0 && !final[v]){
                dist[v]=min(dist[v],dist[u]+lst[u][v]);
            }
        }
    }
    forI(u,0,ver){
        forI(v,0,ver){
            if(lst[u][v]!=0 && dist[v]>dist[u]+lst[u][v]){
                cout<<"Negative weight cycle detected\n";
            }
        }
    }
    return dist;
}
// when no weighted edges use BFS, when +ve weighted edges use Dijkstra, and when -ve weighted directed edges or -ve weighted directed edge cycles use Bellman Ford
// optimal 
// it is single source shortest path algo
vector <int> dijkstra(int n, vector<vector<int>> adj[], int S){
    unordered_map<int,int> lst[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            lst[i][adj[i][j][0]]=adj[i][j][1];
        }
    }
    vector<int> cost(n,INT_MAX);
    cost[S]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0,S});
    // BFS using priority queue
    while(!pq.empty()){
        int dk=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(dk!=cost[u]) continue;
        for(auto v:lst[u]){
            if(cost[v.first]>cost[u]+v.second){
                cost[v.first]=cost[u]+v.second;
                pq.push({cost[v.first],v.first});
            }
        }
    }
    return cost;
}
// Bellman Ford algo (applicable only on directed graphs)
// to use in undirected graph just replicate undirected edge in two directed edge
// it is single source shortest path algo
vector<ll> BellmanFord(vector<vector<pair<ll,ll>>> &lst,ll src){
    ll n=lst.sz;
    vector<ll> dist(n,LLONG_MAX);
    dist[0]=0;
    forI(j,1,n){
        forI(i,0,n){
            for(auto z:lst[i]){
                if(dist[i]!=LLONG_MAX && dist[z.ff]>dist[i]+z.ss){
                    dist[z.ff]=dist[i]+z.ss;
                }
            }
        }
    }
    forI(i,0,n){
        for(auto z:lst[i]){
            if(dist[i]!=LLONG_MAX && dist[z.ff]>dist[i]+z.ss){
                dist[z.ff]=LLONG_MIN; // to detect -ve weighted cycle
            }
        }
    }
    return dist;
}
// ------------------------------------------------------------------
// it is Floyd Warshall algorithm for shortest path for edge-weighted directed Graph
// matrix mat is the adjacency matrix denoting edge from i to j and -1 denote no edge from i to j
// it is multi source shortest path algo
void shortest_distance(vector<vector<int>>&mat){
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat.size();j++){
            if(mat[i][j]==-1) mat[i][j]=INT_MAX;
        }
    }
    for(int k=0;k<mat.size();k++){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                if(mat[i][k]!=INT_MAX && mat[k][j]!=INT_MAX){
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
    }
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat.size();j++){
            if(mat[i][j]==INT_MAX) mat[i][j]=-1;
        }
    }
}
// ------------------------------------------------------------------
void DFSrecur4(vector<int> *lst,int src,bool *visited,vector<int> &topo){
    visited[src]=true;
    for(auto v:lst[src]){
        if(visited[v]==false){
            DFSrecur4(lst,v,visited,topo);
        }
    }
    topo.pb(src);
}

vector<int> topoDFS2(vector<int> *lst,int ver){
    bool visited[ver];
    fil1D(visited,ver,false);
    vector<int> topo;
    forI(i,0,ver){
        if(visited[i]==false){
            DFSrecur4(lst,i,visited,topo);
        }
    }
    reverse(all(topo));
    return topo;
}

void DFSdiscont2(vector<int> *lst,int ver){
    bool visited[ver];
    fil1D(visited,ver,false);
    forI(i,0,ver){
        if(visited[i]==false){
            DFSrecur(lst,i,visited);
            cout<<endl;
        }
    }
}
// Kosaraju Algo used to find Strongly connected components in directed graph
// strongly connected components are one in which for all pairs of vertices: every vertices in pair are reachable to each other 
// steps of algo:
// 1) do topo sort of vertices
// 2) reverse the entire graph
// 3) do dfs based on the order of toposort
void kosaraju(vector<int> *lst,int ver){ // used to get strongly connected components in directed graph
    vector<int> topo;
    topo=topoDFS2(lst,ver);
    vector<int> op[ver];
    TransposeGraph(lst,op,ver);
    // DFSdiscont2(op,ver);
    bool visited[ver];
    fil1D(visited,topo.size(),false);
    for(int i=0;i<topo.size();i++){
        if(visited[topo[i]]==false){
            DFSrecur(op,topo[i],visited);
            cout<<endl;
        }
    }
}
// ------------------------------------------------------------------
int c=0;
void DFSrecur5(vector<int> *lst,int src,bool *visited,unordered_set<int> &op,vector<int> &disc,vector<int> &low,int parent){
    visited[src]=true;
    // cout<<src<<" ";
    c++;
    disc[src]=c;
    low[src]=disc[src];
    int k=0;
    for(auto v:lst[src]){
        if(visited[v]==false){
            k++;
            DFSrecur5(lst,v,visited,op,disc,low,src);
            if(low[v]!=disc[v]){
                low[src]=low[v];
            }
            if(parent!=-1 && low[v]>=disc[src]){
                op.insert(src);
            }
        }
        else if(visited[v]==true && v!=parent && low[v]==disc[v]){ 
            low[src]=disc[v];
            // cout<<src<<"->"<<v<<"-"<<low[src]<<":"<<disc[v]<<"hello";
        }
    }
    if(parent==-1 && k>1) op.insert(src); 
}
// A vertex in an undirected connected graph is called articulation point if on removing it makes graph disconnected

// must visit this question for articulation point
// https://practice.geeksforgeeks.org/problems/articulation-point-1/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=articulation-point

// In DFS tree a vertex u is articulation point if one of the following two conditions is true
// 1) u is the root of DFS tree and it has at least two children
// 2) u is not the root of DFS tree and it has a child v such that no vertex in the subtree rooted with v has a back edge to one of
//    the ancestors (in DFS tree) of u.
unordered_set<int> ArticulationPoint(vector<int> *lst,int ver,int src){
    bool visited[ver];
    fil1D(visited,ver,false);
    vector<int> disc(ver),low(ver);
    unordered_set<int> op;
    if(visited[src]==false){
        DFSrecur5(lst,src,visited,op,disc,low,-1);
    }
    // cout<<endl;
    // for(auto x:disc){cout<<x<<" ";}
    // cout<<endl;
    // for(auto x:low){cout<<x<<" ";}
    // cout<<endl;
    return op;
}

// An edge in an undirected connected graph is a bridge if and only if removing it disconnects the graph
int c2=0;
void DFSrecur6(vector<int> *lst,int src,bool *visited,unordered_map<int,int> &op,vector<int> &disc,vector<int> &low,int parent){
    visited[src]=true;
    // cout<<src<<" ";
    c2++;
    disc[src]=c2;
    low[src]=disc[src];
    for(auto v:lst[src]){
        if(visited[v]==false){
            DFSrecur6(lst,v,visited,op,disc,low,src);
            if(low[v]!=disc[v]){
                low[src]=low[v];
            }
            if(parent!=-1 && low[v]>disc[src]){
                op.insert({src,v});
            }
        }
        else if(visited[v]==true && v!=parent && low[v]==disc[v]){ 
            low[src]=disc[v];
            // cout<<src<<"->"<<v<<"-"<<low[src]<<":"<<disc[v]<<"hello";
        }
    }
}
// must visit this problem
// https://leetcode.com/problems/critical-connections-in-a-network/description/
unordered_map<int,int> BridgeEdge(vector<int> *lst,int ver,int src){
    bool visited[ver];
    fil1D(visited,ver,false);
    vector<int> disc(ver),low(ver);
    unordered_map<int,int> op;
    if(visited[src]==false){
        DFSrecur6(lst,src,visited,op,disc,low,-1);
    }
    // cout<<endl;
    // for(auto x:disc){cout<<x<<" ";}
    // cout<<endl;
    // for(auto x:low){cout<<x<<" ";}
    // cout<<endl;
    return op;
}
// ------------------------------------------------------------------
int c3=0;
stack<int> st;
void DFSrecur7(vector<int> *lst,int src,bool *visited,vector<int> &disc,vector<int> &low,int parent){ // for graph containing cross-edge
    visited[src]=true;
    st.push(src);
    // cout<<src<<" ";
    c3++;
    disc[src]=c3;
    low[src]=disc[src];
    for(auto v:lst[src]){
        vector<int>::iterator it;
        it=find(all(lst[parent]),v);
        if(visited[v]==false){
            DFSrecur7(lst,v,visited,disc,low,src);
            if(low[v]!=disc[v]){
                low[src]=low[v];
            }
        }
        else if(visited[v]==true && v!=parent && low[v]==disc[v] && it==lst[parent].end()){ 
            low[src]=disc[v];
        }
    }
}

void DFSrecur8(vector<int> *lst,int src,bool *visited,vector<int> &disc,vector<int> &low,int parent){ // for graph without cross-edge
    visited[src]=true;
    st.push(src);
    // cout<<src<<" ";
    c3++;
    disc[src]=c3;
    low[src]=disc[src];
    for(auto v:lst[src]){
        // vector<int>::iterator it;
        // it=find(all(lst[parent]),v);
        if(visited[v]==false){
            DFSrecur8(lst,v,visited,disc,low,src);
            if(low[v]!=disc[v]){
                low[src]=low[v];
            }
        }
        else if(visited[v]==true && v!=parent && low[v]==disc[v]){/*&& it==lst[parent].end()*/ 
            low[src]=disc[v];
        }
    }
}
// Use DFSrecur7 as general function 
void TarjanAlgo(vector<int> *lst,int ver){
    bool visited[ver];
    fil1D(visited,ver,false);
    vector<int> disc(ver),low(ver);
    forI(i,0,ver){
        if(visited[i]==false){
            DFSrecur7(lst,i,visited,disc,low,-1); // for graph with cross edge
            // DFSrecur8(lst,i,visited,disc,low,-1);    // for graph without cross edge
        }
    }
    // cout<<endl;
    // for(auto x:disc){cout<<x<<" ";}
    // cout<<endl;
    // for(auto x:low){cout<<x<<" ";}
    // cout<<endl;
    while(!st.empty()){
        if(low[st.top()]==disc[st.top()]){
            cout<<st.top()<<endl;
            st.pop();
        }
        else{
            while(low[st.top()]!=disc[st.top()]){
                cout<<st.top()<<" ";
                st.pop();
            }
            cout<<st.top()<<endl;
            st.pop();
        }
    }
}
// ------------------------------------------------------------------
struct edge{
    int u,v,w;
    edge(int x,int y,int z){
        u=x;
        v=y;
        w=z;
    }
};

bool mycmpforobj(edge obj1,edge obj2){
    return obj1.w<obj2.w;
}

int KruskalAlgo(vector<pair<int,int>> *lst,int ver){
    vector<struct edge> ip;
    forI(u,0,ver){
        for(auto v:lst[u]){
            ip.pb({u,v.ff,v.ss});
        }
    }
    sort(all(ip),mycmpforobj);
    unordered_set<int> s;
    int mst=0,res=0;
    for(int i=0;i<ip.sz && mst<ver-1;i++){
        if(s.empty()){
            s.insert(ip[i].u);
            s.insert(ip[i].v);
            res+=ip[i].w;
            mst++;
            cout<<ip[i].u<<"->"<<ip[i].v<<":"<<ip[i].w<<endl;
        }
        else{
            if(s.find(ip[i].u)==s.end() || s.find(ip[i].v)==s.end()){
                s.insert(ip[i].u);
                s.insert(ip[i].v);
                res+=ip[i].w;
                mst++;
                cout<<ip[i].u<<"->"<<ip[i].v<<":"<<ip[i].w<<endl;
            }
        }
    }
    return res;
}
// ------------------------------------------------------------------
// count island in matrix where 1 in cell represent land and 0 represent water
void DFSinMatrixRecur(vector<vector<int>> mat,vector<vector<bool>> &visited,int r,int c){
    // since each cell has 8 adjacent/neighbour cells
    int adjrow[8]={-1,-1,-1,0,0,1,1,1};
    int adjcol[8]={-1,0,1,-1,1,-1,0,1};
    visited[r][c]=true;
    for(int i=0;i<8;i++){
        if((r+adjrow[i]>=0 && r+adjrow[i]<mat.size()) && (c+adjcol[i]>=0 && c+adjcol[i]<mat[0].size()) && visited[r+adjrow[i]][c+adjcol[i]]==false){
            DFSinMatrixRecur(mat,visited,r+adjrow[i],c+adjcol[i]);
        }
    }
}

int CountIslandInMatrix(vector<vector<int>> mat,int row,int col){
    vector<vector<bool>> visited(col);
    int count=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j] && visited[i][j]==false){
                DFSinMatrixRecur(mat,visited,i,j);
                count++;
            }
        }
    }
    return count;
}
// ------------------------------------------------------------------
// minimum time required to rot all oranges: where 0 in matrix represent empty cell, 1 represent fresh and 2 represent rotten oranges 
int BFS(vector<vector<int>> grid,vector<vector<int>> &visit){
    queue<pair<int,int>> q;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==2 && visit[i][j]==0){
                q.push({i,j});
                visit[i][j]=1;
            }
        }
    }
    int x[4]={-1,0,+1,0};
    int y[4]={0,+1,0,-1};
    int t=0;
    while(!q.empty()){
        int k=q.size();
        int fg=0;
        for(int i=0;i<k;i++){
            pair<int,int> p=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                if((p.first+x[i]>=0 && p.first+x[i]<grid.size()) && (p.second+y[i]>=0 && p.second+y[i]<grid[0].size())){
                    if(grid[p.first+x[i]][p.second+y[i]]==1 && visit[p.first+x[i]][p.second+y[i]]==0){
                        fg=1;
                        visit[p.first+x[i]][p.second+y[i]]=1;
                        q.push({p.first+x[i],p.second+y[i]});
                    }
                }   
            }
        }
        if(fg==1) t++;
    }
    return t;
}
// ------------------------------------------------------------------
// minimum rools required to reach end of board : using BFS
int snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    unordered_map<int,int> lad;
    unordered_map<int,int> snk;
    for(int i=0;i<A.size();i++){
        lad[A[i][0]]=A[i][1];
    }
    for(int i=0;i<B.size();i++){
        snk[B[i][0]]=B[i][1];
    }
    vector<int> visit(101,0);
    queue<int> q;
    q.push(1);
    visit[1]=1;
    int stp=0;
    while(!q.empty()){
        int k=q.size();
        for(int j=0;j<k;j++){
            int src=q.front();
            q.pop();
            if(src==100) return stp;
            for(int i=1;i<=6;i++){
                if(src+i<=100 && visit[src+i]==0){
                    if(snk.find(src+i)==snk.end()){
                        if(lad.find(src+i)!=lad.end()){
                            visit[src+i]=1;
                            visit[lad[src+i]]=1;
                            q.push(lad[src+i]);
                        }
                        else{
                            visit[src+i]=1;
                            q.push(src+i);
                        }
                    }
                    else{
                        visit[src+i]=1;
                        visit[snk[src+i]]=1;
                        q.push(snk[src+i]);
                    }
                }
            }
        }
        stp++;
    }
    return -1;
}
// ------------------------------------------------------------------
// Hamiltonoian path
void DFS(vector<int> *lst,vector<int> &visit,int src,int &res){
    if(res==0){
        visit[src]=1;
        int fg=0;
        for(auto v:lst[src]){
            if(visit[v]==0){
                fg=1;
                DFS(lst,visit,v,res);
            }
        }
        if(fg==0){
            int k=0;
            for(auto z:visit){
                if(z==0){
                    k=1;
                    break;
                }
            }
            if(k==0) res=1;
        }
        visit[src]=0;
    }
    return;
}

bool check(int N,int M,vector<vector<int>> Edges)
{
    vector<int> lst[N];
    vector<int> visit(N,0);
    for(int i=0;i<M;i++){
        lst[Edges[i][0]-1].push_back(Edges[i][1]-1);
        lst[Edges[i][1]-1].push_back(Edges[i][0]-1);
    }
    int res=0;
    for(int i=0;i<N;i++){
        DFS(lst,visit,i,res);
        if(res==1) break;
    }
    return res;
}
// must visit below question
// https://thejoboverflow.com/problem/342/

// Code for getting Eulerian path in directed graph
// https://leetcode.com/problems/reconstruct-itinerary/description/
vector<string> findItinerary(vector<vector<string>>& tick) {
    map<string,vector<string>> mp;
    map<string,int> cnt;
    for(int i=0;i<tick.size();i++){
        mp[tick[i][0]].push_back(tick[i][1]);
        cnt[tick[i][0]]++;
    }
    for(auto z:mp){
        sort(mp[z.first].begin(),mp[z.first].end(),greater<string>());
    }
    stack<string> cp;
    vector<string> cir;
    string curr="JFK";
    cp.push(curr);
    while(!cp.empty()){
        if(cnt[curr]>0){
            string tp=mp[curr].back();
            cp.push(curr);
            mp[curr].pop_back();
            cnt[curr]--;
            curr=tp;
        }
        else{
            cir.push_back(curr);
            curr=cp.top();
            cp.pop();
        }
    }
    reverse(cir.begin(),cir.end());
    return cir;
}

int main(){
    int ver=5;
    vector<int> adjlist[ver];
    addedge(adjlist,0,1);
    addedge(adjlist,0,2);
    addedge(adjlist,1,3);
    addedge(adjlist,1,4);
    addedge(adjlist,2,3);
    addedge(adjlist,3,4);
    
    printgraph(adjlist,ver);
    
    bool visited[ver];
    fil1D(visited,ver,false);
    BFS(adjlist,0,visited);
    cout<<endl;
    DFSdiscont(adjlist,ver);
    cout<<endl;
// ------------------------------------------------------------------
    int ver2=7;
    vector<int> adjlist2[ver2];
    addedge(adjlist2,0,1);
    addedge(adjlist2,0,2);
    addedge(adjlist2,1,3);
    addedge(adjlist2,2,3);
    addedge(adjlist2,4,5);
    addedge(adjlist2,4,6);
    addedge(adjlist2,5,6);

    printgraph(adjlist2,ver2);

    BFSdiscont(adjlist2,ver2);
    cout<<endl;
    DFSdiscont(adjlist2,ver2);
    cout<<endl;
// ------------------------------------------------------------------
    cout<<NoofIslandInGraph(adjlist2,ver2)<<endl;
    
    int ver3=4;
    vector<int> map1[ver3];
    addedge(map1,0,1);
    addedge(map1,0,2);
    addedge(map1,1,2);
    addedge(map1,1,3);
    addedge(map1,2,3);

    vector<int> op;
    op=ShortPathUnweight(map1,ver3,0);
    forI(i,0,ver3){
        cout<<op[i]<<" ";
    }
    cout<<endl;
// ------------------------------------------------------------------
    int ver4=6;
    vector<int> map2[ver4];
    addedge(map2,0,1);
    addedge(map2,1,2);
    addedge(map2,1,3);
    addedge(map2,2,3);
    addedge(map2,2,4);
    addedge(map2,4,5);

    cout<<DetectLoopUndirected(map2,ver4)<<endl;
// ------------------------------------------------------------------
    int ver5=6;
    vector<int> map3[ver5];
    addDirectedge(map3,0,1);
    addDirectedge(map3,2,1);
    addDirectedge(map3,2,3);
    addDirectedge(map3,3,4);
    addDirectedge(map3,4,5);
    addDirectedge(map3,5,3);
    printgraph(map3,ver5);
    cout<<DetectLoopDirected(map3,ver5)<<endl;
// ------------------------------------------------------------------
    int ver6=6;
    vector<int> map4[ver6];
    addDirectedge(map4,0,1);
    addDirectedge(map4,0,2);
    addDirectedge(map4,1,3);
    addDirectedge(map4,2,3);
    addDirectedge(map4,3,4);
    addDirectedge(map4,3,5);
    printgraph(map4,ver6);
    TopologicalSortKahnAlgo(map4,ver6);
    cout<<endl;
// ------------------------------------------------------------------
    int ver7=5;
    vector<int> map5[ver7];
    addDirectedge(map5,0,1);
    addDirectedge(map5,1,2);
    addDirectedge(map5,2,3);
    addDirectedge(map5,3,1);
    addDirectedge(map5,4,1);
    printgraph(map5,ver7);
    cout<<LoopDetectUseKahnAlgo(map5,ver7)<<endl;
// ------------------------------------------------------------------
    int ver8=5;
    vector<int> map6[ver8];
    addDirectedge(map6,0,1);
    addDirectedge(map6,1,3);
    addDirectedge(map6,2,3);
    addDirectedge(map6,2,4);
    addDirectedge(map6,3,4);
    printgraph(map6,ver8);
    TopologicalDFS(map6,ver8);
    cout<<endl;
// ------------------------------------------------------------------
    int ver9=6;
    vector<pair<int,int>> map7[ver9];
    addDirectWeightedge(map7,0,1,2);
    addDirectWeightedge(map7,0,4,1);
    addDirectWeightedge(map7,1,2,3);
    addDirectWeightedge(map7,4,2,2);
    addDirectWeightedge(map7,4,5,4);
    addDirectWeightedge(map7,2,3,6);
    addDirectWeightedge(map7,5,3,1);

    printWeightgraph(map7,ver9);
    
    op=ShortPathDAG(map7,ver9,0);
    forI(i,0,op.sz){
        cout<<op[i]<<" ";
    }
    cout<<endl;
// ------------------------------------------------------------------
    int ver10=4;
    vector<int> map8[ver10]={{0,5,10,0},{5,0,8,15},{10,8,0,20},{0,15,20,0}};
    cout<<primMST(map8,ver10)<<endl;
// ------------------------------------------------------------------
    int ver11=4;
    vector<int> map9[ver11]={{0,4,8,0},{0,0,-8,0},{0,0,0,2},{0,3,0,0}};
    op=DijkstraAlgo(map9,ver11,0);
    for(auto z:op){
        cout<<z<<" ";
    }
    cout<<endl;
// ------------------------------------------------------------------
    int ver12=4;
    vector<int> map10[ver12];
    addDirectedge(map10,0,1);
    addDirectedge(map10,1,2);
    addDirectedge(map10,1,3);
    addDirectedge(map10,3,0);
    printgraph(map10,ver12);
    kosaraju(map10,ver12);
// ------------------------------------------------------------------
    int ver13=7;
    vector<int> map11[ver13];
    addedge(map11,0,1);
    addedge(map11,0,3);
    addedge(map11,1,2);
    addedge(map11,1,4);
    addedge(map11,2,3);
    addedge(map11,4,5);
    addedge(map11,4,6);
    addedge(map11,5,6);
    printgraph(map11,ver13);
    cout<<endl;
    unordered_set<int> Op=ArticulationPoint(map11,ver13,0);
    for(auto z:Op){
        cout<<z<<" ";
    }
    cout<<endl;
// ------------------------------------------------------------------
    int ver14=6;
    vector<int> map12[ver14];
    addedge(map12,0,1);
    addedge(map12,0,2);
    addedge(map12,1,2);
    addedge(map12,2,3);
    addedge(map12,3,4);
    addedge(map12,3,5);
    addedge(map12,4,5);
    printgraph(map12,ver14);
    cout<<endl;
    unordered_map<int,int> OP=BridgeEdge(map12,ver14,0);
    for(auto z:OP){
        cout<<z.ff<<" "<<z.ss<<endl;
    }
// ------------------------------------------------------------------
    int ver15=5;
    vector<int> map13[ver15];
    addDirectedge(map13,0,1);
    addDirectedge(map13,1,2);
    addDirectedge(map13,2,0);
    addDirectedge(map13,1,3);
    addDirectedge(map13,3,4);
    cout<<endl;
    printgraph(map13,ver15);
    cout<<endl;
    TarjanAlgo(map13,ver15);
// ------------------------------------------------------------------
    int ver16=5;
    vector<pair<int,int>> map14[ver16];
    addDirectWeightedge(map14,0,1,6);
    addDirectWeightedge(map14,0,2,5);
    addDirectWeightedge(map14,1,2,3);
    addDirectWeightedge(map14,1,3,8);
    addDirectWeightedge(map14,2,3,7);
    addDirectWeightedge(map14,2,4,12);
    addDirectWeightedge(map14,3,4,10);

    printWeightgraph(map14,ver16);
    cout<<KruskalAlgo(map14,ver16)<<endl;
// ------------------------------------------------------------------
    vector<vector<int>> mat={{1,1,0,0,0},{0,1,0,0,1},{1,0,0,1,1},{0,0,0,0,0},{1,0,1,0,1}};
    cout<<CountIslandInMatrix(mat,5,5)<<endl;
    return 0;
}