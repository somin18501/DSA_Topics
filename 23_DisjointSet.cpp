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

int Find(vector<int> v,int x){
    if(v[x]==x) return x;
    else return Find(v,v[x]);
}

int FindByPathComp(vector<int> &v,int x){ // it makes all the node as child of its representative that comes in path of x 
    if(v[x]==x) return x;
    v[x]=FindByPathComp(v,v[x]);
    return v[x];
}

void Union(vector<int> &v,int x,int y){ // here we simply make parent of y(i.e. yp) as child of parent of x(i.e. xp) 
    int xp=Find(v,x);
    int yp=Find(v,y);
    if(xp==yp) return;
    else v[yp]=xp;
}

void UnionByRank(vector<int> &v,vector<int> &r,int x,int y){
    int xp=Find(v,x);
    int yp=Find(v,y);
    // always connect smaller rank to larger i.e. make make larger rank one as parent of smaller one
    if(r[xp]>r[yp]) v[yp]=xp;
    else if(r[yp]>r[xp]) v[xp]=yp;
    else {
        // this case occurs when height i.e. rank of both parents is same so either one of their rank will need to be increased
        v[yp]=xp;
        r[xp]++;
    }
}
// ----------------------------------------------------------------------------------
// Kruskal Algo using disjoint set
void addDirectWeightedge(vector<pair<int,int>> *lst,int u,int v,int w){
    lst[u].pb({v,w});
}

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
    vector<int> parent;
    vector<int> rank(ver,0);
    forI(u,0,ver){
        for(auto v:lst[u]){
            ip.pb({u,v.ff,v.ss});
        }
    }
    sort(all(ip),mycmpforobj);
    forI(i,0,ver){
        parent.pb(i);
    }
    int mst=0,res=0;
    for(int i=0;i<ip.sz && mst<ver-1;i++){
        int xp=FindByPathComp(parent,ip[i].u);
        int yp=FindByPathComp(parent,ip[i].v);
        if(xp!=yp){
            UnionByRank(parent,rank,ip[i].u,ip[i].v);
            res+=ip[i].w;
            mst++;
            cout<<ip[i].u<<"->"<<ip[i].v<<":"<<ip[i].w<<endl;
        }
    }
    return res;
}
// ----------------------------------------------------------------------------------
int main(){
    int n=5;
    vector<int> par(n,0); // 0 0 0 0 0
    forI(i,0,n) par[i]=i; // 0 1 2 3 4
    Union(par,2,3);       // 0 1 2 2 4
    cout<<Find(par,3)<<endl;
    Union(par,1,2);       // 0 1 1 2 4
    cout<<Find(par,3)<<endl;
    Union(par,0,1);       // 0 0 1 2 4 
    cout<<Find(par,3)<<endl;
    forI(i,0,n) cout<<par[i]<<" "; 
    cout<<endl;
    cout<<FindByPathComp(par,3)<<endl; // 0 0 0 0 4
    forI(i,0,n) cout<<par[i]<<" "; 
    cout<<endl;
// ----------------------------------------------------------------------------------
    vector<int> par2(n,0);      // 0 0 0 0 0
    vector<int> rnk(n,0);                       // 0 0 0 0 0
    forI(i,0,n) par2[i]=i;      // 0 1 2 3 4
    UnionByRank(par2,rnk,2,3);  // 0 1 2 2 4    // 0 0 1 0 0
    cout<<Find(par2,3)<<endl;
    UnionByRank(par2,rnk,1,2);  // 0 2 2 2 4    // 0 0 1 0 0
    cout<<Find(par2,3)<<endl;
    UnionByRank(par2,rnk,0,1);  // 2 2 2 2 4    // 0 0 1 0 0
    cout<<Find(par2,3)<<endl;
    forI(i,0,n) cout<<par2[i]<<" "; 
    cout<<endl;
    forI(i,0,n) cout<<rnk[i]<<" "; 
    cout<<endl;
    cout<<endl;
// ----------------------------------------------------------------------------------
    int ver16=5;
    vector<pair<int,int>> map14[ver16];
    addDirectWeightedge(map14,0,1,6);
    addDirectWeightedge(map14,0,2,5);
    addDirectWeightedge(map14,1,2,3);
    addDirectWeightedge(map14,1,3,8);
    addDirectWeightedge(map14,2,3,7);
    addDirectWeightedge(map14,2,4,12);
    addDirectWeightedge(map14,3,4,10);
    cout<<KruskalAlgo(map14,ver16)<<endl;
    return 0;
}