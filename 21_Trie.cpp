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

// Trie datastructure is used to maintain dictionary like order as it has insert, search, delete function of O(1) time complexity
// It also provide advantages like prefix search and lexicographic printing of string  
// it is good to use trie over hashing while handling strings
// -------------------------------------------------------------------------------
struct trienode{
    trienode *child[26];
    bool isend;
    trienode(){
        isend=false;
        forI(i,0,26){
            child[i]=NULL;
        }
    }
};

trienode *Insert(trienode *root,string s){
    trienode *last=NULL;
    last=root;
    forI(j,0,s.len){
        trienode *tmp=new trienode;
        if(last->child[s[j]-'a']==NULL){
            last->child[s[j]-'a']=tmp;
            last=tmp;
        }
        else last=last->child[s[j]-'a'];
    }
    last->isend=true;
    return root;
}

bool Search(trienode *root,string s){
    forI(j,0,s.len){
        if(root->child[s[j]-'a']==NULL) return false;
        else root=root->child[s[j]-'a'];
    }
    return (root->isend);
}

bool IsEmpty(trienode *root){
    forI(i,0,26){
        if(root->child[i]!=NULL) return false;
    }
    return true;
}

trienode *Delete(trienode *root,string s,int i){
    if(root==NULL) return NULL;
    if(i==s.len){
        root->isend=false;
        if(IsEmpty(root)){
            delete[] root;
            root=NULL; 
        }
        return root;
    }
    root->child[s[i]-'a']=Delete(root->child[s[i]-'a'],s,i+1);
    if(IsEmpty(root) && root->isend==false){
        delete[] root;
        root=NULL; 
    }
    return root;
}
// -------------------------------------------------------------------------------
// calculate distinct row in matrix
struct bintrienode{
    bintrienode *child[2];
    bool isend;
    bintrienode(){
        isend=false;
        child[0]=NULL;
        child[1]=NULL;
    }
};

bool Insert2(bintrienode *root,vector<int> v){
    bintrienode *last=NULL;
    last=root;
    forI(j,0,v.sz){
        bintrienode *tmp=new bintrienode;
        if(last->child[v[j]]==NULL){
            last->child[v[j]]=tmp;
            last=tmp;
        }
        else last=last->child[v[j]];
    }
    if(last->isend) return false;
    last->isend=true;
    return true;
}
// -------------------------------------------------------------------------------
// Given an integer array A and val x, you have to pick one element from array A such that its xor is maximum with x
struct triNode{
    triNode* arr[2];
    triNode(){
        arr[0]=NULL;
        arr[1]=NULL;
    }
};

int getMaxXor(triNode* root,int x){
    int ans=0;
    for(int i=31;i>=0;i--){
        int bit=(x>>i)&1;
        if(root->arr[!bit]!=NULL){
            ans=ans|(1<<i);
            root=root->arr[!bit];
        }
        else root=root->arr[bit];
    }
    return ans;
}

int findMaximumXOR(vector<int>& num) {
    int n=num.size();
    triNode* root=new triNode;
    for(int i=0;i<n;i++){
        triNode* n1=root;
        for(int j=31;j>=0;j--){
            if(n1->arr[(num[i]>>j)&1]==NULL){
                n1->arr[(num[i]>>j)&1]=new triNode;
            }
            n1=n1->arr[(num[i]>>j)&1];
        }
    }
    int mAx=0;
    for(int i=0;i<n;i++){
        mAx=max(mAx,getMaxXor(root,num[i]));
    }
    return mAx;
}
// -------------------------------------------------------------------------------
int main(){
    vector<string> ip={"bad","bat","geek","geeks","cat","cut","zoo"};
    trienode *root=new trienode;
    // trienode *last=NULL;
    forI(i,0,ip.sz){
        root=Insert(root,ip[i]);
    }
    cout<<Search(root,"geek")<<endl;
    root=Delete(root,"geek",0);
    cout<<Search(root,"geek")<<endl;
    cout<<endl;
// -------------------------------------------------------------------------------
    vector<vector<int>> ip2={{1,0,0},{1,1,1},{1,0,0},{0,1,0}};
    int res=0;
    bintrienode *rot=new bintrienode;
    forI(i,0,ip2.sz){
        if(Insert2(rot,ip2[i])) res++;
    }
    cout<<res<<endl;
    return 0;
}