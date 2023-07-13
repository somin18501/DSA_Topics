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

// In naive method for getsum and update operation can be done in O(n) and O(1) time if there are more update operation compared to getsum
// In naive method for getsum(using prefix sum technique) and update operation can be done in O(1) and O(n) time 
// if there are more getsum operation compared to update  

// But if there are equal number of getsum and update operation on given data then we need some efficient datastructure to handle it 
// with better time complexity than O(n) so we use Segment and binary Indexed tree to do so

// ----------------------------------------------------------------------------------------------------------
// Segment Tree is used when there are many queries on given input array like getsum in given range & Update at given index.
// it does getsum O(logn) time upperbound by 4logn
// and update in O(logn) time upperbound by logn

// For input array of size n 
// size of segment tree is:
// 1)2n-1 if n is power of 2
// 2)2x-1 where x is smallest power of 2 greater than n i.e. x=2^ceil(log2(n)), here it is  upperbound by 2x-1<4n
// this difference is due to addition of dummy node to maintain complete binary tree like heap

int constST(vector<int> ip,vector<int> &op,int s,int e,int i){
    if(s==e){
        op[i]=ip[s];
        return ip[s];
    }
    int mid=(s+e)/2;
    op[i]=constST(ip,op,s,mid,2*i+1)+constST(ip,op,mid+1,e,2*i+2);
    return op[i];
}

int getSumForRange(vector<int> &op,int qs,int qe,int s,int e,int i){
    if(qe<s || qs>e) return 0;
    if(qs<=s && qe>=e) return op[i];
    int mid=(s+e)/2;
    return getSumForRange(op,qs,qe,s,mid,2*i+1)+getSumForRange(op,qs,qe,mid+1,e,2*i+2);
}

void UpdateST(vector<int> &op,int s,int e,int i,int q,int diff){
    if(q<s || q>e) return;
    op[i]+=diff;
    if(e>s){
        int mid=(s+e)/2;
        UpdateST(op,s,mid,2*i+1,q,diff);
        UpdateST(op,mid+1,e,2*i+2,q,diff);
    }
}
// ----------------------------------------------------------------------------------------------------------
// Both getsum and update operation in Binary Indexed Tree is upperbound by O(logn)

int CalSum(vector<int> ip,int i,int j){
    int sum=0;
    forI(k,i,j+1) sum+=ip[k];
    return sum;
}

void constBIT(vector<int> ip,vector<int> &op){
    forI(k,1,op.sz){
        if(op[k]==0){
            int i=k,j=1;
            while(i<op.sz && op[i]==0){
                op[i]=CalSum(ip,k-1,i-1);
                i+=j;
                j+=j;
            }
        }
    }
}

int getSumBTtree(vector<int> BITree,int i){ // give sum of elements from index 0-i 
    i++;
    int sum=0;
    while(i!=0){
        sum+=BITree[i];
        i=i&(i-1); // we can also use: i=i-i&(-i) i.e. removing last set bit of i, here (-i) means (~i+1) or 2s complement
    }
    return sum;
}

void UpdateBT(vector<int> &ip,vector<int> &op,int i,int u){ // update value of index i to u and all those range in BItree which contain i
    int diff=u-ip[i];
    ip[i]=u;
    i++;
    while(i<op.sz){
        op[i]+=diff;
        i=i+i&(-i); // because next index to be updated is obtained by adding 1 to last set bit
    }
}
// ----------------------------------------------------------------------------------------------------------
int main(){
    vector<int> ip={10,20,30,40};
    vector<int> op(4*ip.sz,0); // we use segment tree array of size 4n as number of node in it is upperbound by it
    cout<<constST(ip,op,0,ip.sz-1,0)<<endl;
    for(auto z:op) cout<<z<<" ";
    cout<<endl;
    cout<<getSumForRange(op,0,2,0,ip.sz-1,0)<<endl;
    UpdateST(op,0,ip.sz-1,0,1,25-ip[1]);
    ip[1]=25;
    cout<<getSumForRange(op,0,2,0,ip.sz-1,0)<<endl;
    cout<<endl;
// ----------------------------------------------------------------------------------------------------------
    vector<int> ip1={10,20,30,40};
    vector<int> op2(ip1.sz+1,0);
    constBIT(ip1,op2);
    for(auto z:op2) cout<<z<<" ";
    cout<<endl;
    cout<<getSumBTtree(op2,2)<<endl;
    UpdateBT(ip1,op2,1,25);
    cout<<getSumBTtree(op2,2)<<endl;
    return 0;
}