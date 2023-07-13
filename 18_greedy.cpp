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

// General structure
// getOptimal(vector,int){
//     1)initialization of result
//     2)sorting/arrangment
//     3)while(i){
//         if(feasible) result+i;
//     }
//     4)return res;
// }

// -----------------------------------------------------------------
int MinCoin(vector<int> v,int amt){
    int res=0;
    sort(all(v),desc);
    forI(i,0,v.sz){
        if(amt){
            res=res+(amt/v[i]);
            amt=amt%v[i];
        }
        else break;
    }
    return res;
}
// -----------------------------------------------------------------
bool mycmp(pair<int,int> x,pair<int,int> y){
    return (x.ss<y.ss);
}

vector<pair<int,int>> ActivitySelect(vector<pair<int,int>> v){
    vector<pair<int,int>> op;
    sort(all(v),mycmp);
    op.pb(v[0]);
    forI(i,1,v.sz){
        if(v[i].ff>=op.back().ss){
            op.pb(v[i]);
        }
    }
    return op;
}
// -----------------------------------------------------------------
bool mycmp2(pair<double,int> x,pair<double,int> y){
    return (x.ff>y.ff);
}

int FractionalKnapsack(vector<pair<int,int>> ip,int cap){
    vector<pair<double,int>> tmp;
    forI(i,0,ip.sz){
        tmp.pb({(double)(ip[i].ss)/(ip[i].ff),i});
    }
    sort(all(tmp),mycmp2);
    int res=0;
    forI(i,0,tmp.sz){
        if(ip[tmp[i].ss].ff<=cap){
            res+=ip[tmp[i].ss].ss;
            cap-=ip[tmp[i].ss].ff;
        }
        else{
            res+=cap*tmp[i].ff;
            cap=0;
        }
        if(cap==0) return res;
    }
}
// -----------------------------------------------------------------
bool mycmp3(pair<int,int> x,pair<int,int> y){
    return (x.ss>y.ss);
}

int JobScheduling(vector<pair<int,int>> ip){
    sort(all(ip),mycmp3);
    int mAx=Ninf;
    for(auto x:ip){
        mAx=max(mAx,x.ff);
    }
    int slot[mAx],prof=0;
    fil1D(slot,mAx,0);
    forI(i,0,ip.sz){
        int k=1;
        while(ip[i].ff-k>-1){
            if(slot[ip[i].ff-k]==0){
                prof+=ip[i].ss;
                slot[ip[i].ff-k]=ip[i].ss;
                break;
            }
            k++;
        }
    }
    return prof;
}
// -----------------------------------------------------------------
struct node{
    char ch;
    int freq;
    node* left;
    node* right;
    node(char x,int y){
        ch=x;
        freq=y;
        left=NULL;
        right=NULL;
    }
};

void MINHEAPYFY(vector<node*> &arr,int i,int size){
    int lt=2*i+1,rt=2*i+2;
    int small=i;
    if(lt<size && arr[lt]->freq<arr[small]->freq) small=lt;
    if(rt<size && arr[rt]->freq<arr[small]->freq) small=rt;
    if(small!=i){
        swap(arr[small],arr[i]);
        MINHEAPYFY(arr,small,size);
    }
}

void BuildHeap(vector<node*> &v,int size){
    ford(i,(size-2)/2,0){
        MINHEAPYFY(v,i,size);
    }
}

node *BuildHuffmanTree(vector<pair<char,int>> ip){
    vector<node*> v;
    forI(i,0,ip.sz){
        node *tmp=new node(ip[i].ff,ip[i].ss);
        v.pb(tmp);
    }
    int s=v.sz;
    BuildHeap(v,s);
    while(s>1){
        node *n1=v[0];
        swap(v[0],v[s-1]);
        s--;
        MINHEAPYFY(v,0,s);
        node *n2=v[0];
        swap(v[0],v[s-1]);
        s--;
        MINHEAPYFY(v,0,s);
        node *tmp=new node('$',n1->freq+n2->freq);
        tmp->left=n1;
        tmp->right=n2;
        v[s]=tmp;
        s++;
        BuildHeap(v,s);
    }
    return v[0];
}

void Encode(node *root,string s){
    if(root==NULL) return;
    if(root->ch!='$'){
        cout<<root->ch<<"->"<<s<<endl;
        return;
    }
    else{
        Encode(root->left,s+'0');
        Encode(root->right,s+'1');
    }
}
// -----------------------------------------------------------------
int main(){
    vector<int> ip1={5,10,2,1};
    cout<<MinCoin(ip1,57)<<endl;

    vector<pair<int,int>> ip2={{3,8},{2,4},{1,3},{10,11}};
    ip2=ActivitySelect(ip2);
    for(auto x:ip2){
        cout<<x.ff<<"-"<<x.ss<<endl;
    }

    vector<pair<int,int>> ip3={{30,120},{20,100},{10,60}};
    cout<<FractionalKnapsack(ip3,50)<<endl;

    vector<pair<int,int>> ip4={{4,70},{1,80},{1,30},{1,100}};
    cout<<JobScheduling(ip4)<<endl;
    
    vector<pair<char,int>> ip5={{'a',10},{'d',50},{'b',20},{'e',40},{'f',80}};
    node *root=BuildHuffmanTree(ip5);
    Encode(root,"");
    return 0;
}