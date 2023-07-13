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

struct node{
    int val;
    node *left;
    node *right;
    node(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};

bool searchR(node *root,int n){
    if(root==NULL) return false;
    else if(root->val==n) return true;
    else if(n<root->val){
        return searchR(root->left,n);
    } 
    else{
        return searchR(root->right,n);
    }
    return false;
}

bool searchI(node *root,int n){
    while(root){
        if(root->val==n) return true;
        else if(n<root->val){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return false;
}

bool insertR(node *root,int n){
    if(root==NULL){
        root=new node(n);
        return true;
    }
    else if(root->val==n) return true;
    else if(n<root->val){
        if(root->left==NULL){
            root->left=new node(n);
            return true;
        }
        else{
            return insertR(root->left,n);
        }
    } 
    else{
        if(root->right==NULL){
            root->right=new node(n);
            return true;
        }
        else{
            return insertR(root->right,n);
        }
    }
    return false;
}

node *insertI(node *root,int n){
    node *n1;
    n1=root;
    while(n1){
        if(n1->val==n) return root;
        else if(n<n1->val){
            if(n1->left==NULL){
                n1->left=new node(n);
                return root;
            }
            else{
                n1=n1->left;
            }
        }
        else{
            if(n1->right==NULL){
                n1->right=new node(n);
                return root;
            }
            else{
                n1=n1->right;
            }
        }
    }
    return root;
}

void Inorder(node *root){
    if(root==NULL) return;
    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
}

node *Delete(node * root,int n){
    if(root==NULL) return root;
    else if(n<root->val){
        root->left=Delete(root->left,n);
    }
    else if(n>root->val){
        root->right=Delete(root->right,n);
    }
    else{
        if(root->left==NULL || root->right==NULL){
            if(root->left==root->right){
                delete[] root;
                return NULL;
            }
            else{
                if(root->left==NULL){
                    node *tp=root->right;
                    delete[] root;
                    return tp;
                }
                else{
                    node *tp=root->left;
                    delete[] root;
                    return tp;
                }
            }
        }
        else{
            node *n1;
            n1=root->right;
            while(n1->left){
                n1=n1->left;
            }
            root->val=n1->val;
            root->right=Delete(root->right,n1->val);
        }
        return root;
    }
}

node *findfloor(node *root,int n){
    node *n1=NULL;
    while(root){
        if(n<root->val){
            root=root->left;
        }
        else if(n>root->val){
            n1=root;
            root=root->right;
        }
        else{
            return root;
        }
    }
    return n1;
}

node *findceil(node *root,int n){
    node *n1=NULL;
    while(root){
        if(n<root->val){
            n1=root;
            root=root->left;
        }
        else if(n>root->val){
            root=root->right;
        }
        else{
            return root;
        }
    }
    return n1;
}

void CeilOnLeftOfArray(vector<int> &v){
    set<int> s;
    s.insert(v[0]);
    cout<<-1<<" ";
    forI(i,1,v.sz){
        s.insert(v[i]);
        int x;
        auto it=upper_bound(all(s),v[i]);
        x=(it==s.end())?-1:*it;
        cout<<x<<" ";   
    }
}

int c=0;
void kthsmallest(node *root,int x){
    if(root==NULL) return;
    kthsmallest(root->left,x);
    c++;
    if(c==x){
        cout<<root->val<<endl;
        return;
    }
    kthsmallest(root->right,x);
}
// there is another method also in which we manipulate struct node by adding lcount variable to store count of no. of node in left sub tree
// compare (lcount+1) with k
// if same, return root
// if greater, recur for left subtree with same k
// if smaller, recur for right subtree  with k as (k-lcount-1)

bool checkBST1(node *root,int a,int b){
    if(root==NULL) return true;
    if(root->val>a && root->val<b){
        return (checkBST1(root->left,a,root->val) && checkBST1(root->right,root->val,b));
    }
    else return false;
}

int pre=Ninf;
bool checkBST2(node *root){
    if(root==NULL) return true;
    if(checkBST2(root->left) && pre<root->val){
        pre=root->val;
        return checkBST2(root->right);
    }
    else return false;
}

void BSTtoArray(node *root,vector<node*> &v){
    if(root==NULL) return;
    BSTtoArray(root->left,v);
    v.pb(root);
    BSTtoArray(root->right,v);
}

int pr=Ninf;
node *first=NULL,*second=NULL;
void BSTSwapTwoNode(node *root){
    vector<node*> v;
    BSTtoArray(root,v);
    forI(i,0,v.sz){
        if(pr>v[i]->val){
            if(first==NULL){
                first=v[i-1];
            }
            second=v[i];
        }
        pr=v[i]->val;
    }
    swap(first->val,second->val);
}

// method-1: Inorder traversal and then two pointer
// method-2: Inorder traversal and hashing
unordered_set<int> s;
bool PairWithGivenSum(node *root,int sum){
    if(root==NULL){
        return false;
    }
    if(PairWithGivenSum(root->left,sum) || (!s.empty() && s.count(root->val)==1)){
        return true;
    }
    else{
        s.insert(sum-(root->val));
        return PairWithGivenSum(root->right,sum);
    }
}

void VerticalSum(node *root,int x,map<int,int> &m){
    if(root==NULL) return;
    VerticalSum(root->left,x-1,m);
    m[x]+=root->val;
    VerticalSum(root->right,x+1,m);
}

void VerticalTraversal(node *root,map<int,vector<int>> &m){
    queue<pair<node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        pair<node*,int> p;
        p=q.front();
        q.pop();
        if(p.first->left) q.push({p.first->left,p.second-1});
        if(p.first->right) q.push({p.first->right,p.second+1});
        m[p.second].pb(p.first->val);
    }
}
// to bulid balanced BST from sorted array

// node* BuildTree(vector<int> A,int l,int r){
//     node *root=NULL;
//     if(l<=r){
//         int mid=(l+r)/2;
//         root=new node(A[mid]);
//         root->left=BuildTree(A,l,mid-1);
//         root->right=BuildTree(A,mid+1,r);
//     }
//     return root;
// }

class BSTIteratorForward {
    stack<node*> stk;
public:
    BSTIteratorForward(node* root) {
        getStackFilled(root);
    }
    
    void next() {
        if(!stk.empty()){
            node* tp=stk.top();
            stk.pop();
            getStackFilled(tp->right);
        }
    }

    int getTop(){
        return stk.top()->val;
    }

    bool hasNext() {
        return !stk.empty();
    }

    void getStackFilled(node* root){
        if(root==NULL) return;
        stk.push(root);
        getStackFilled(root->left);
    }
};

class BSTIteratorBackward {
    stack<node*> stk;
public:
    BSTIteratorBackward(node* root) {
        getStackFilled(root);
    }
    
    int prev() {
        if(!stk.empty()){
            node* tp=stk.top();
            stk.pop();
            getStackFilled(tp->left);
        }
    }

    int getTop(){
        return stk.top()->val;
    }

    bool hasPrev() {
        return !stk.empty();
    }

    void getStackFilled(node* root){
        if(root==NULL) return;
        stk.push(root);
        getStackFilled(root->right);
    }
};

vector<int> getLargestBST(node* root){
    if(root==NULL) return {0,INT_MIN,INT_MAX};
    vector<int> lv=getLargestBST(root->left);
    vector<int> rv=getLargestBST(root->right);
    if(root->val>lv[1] && root->val<rv[2]){
        return {lv[0]+rv[0]+1,max(root->val,rv[1]),min(root->val,lv[2])};
    }
    else{
        return {max(lv[0],rv[0]),INT_MAX,INT_MIN};   
    }
}

int main(){
    node *root;
    root=new node(50);
    root->left=new node(30);
    root->right=new node(70);
    root->left->left=new node(20);
    root->left->right=new node(40);
    root->right->left=new node(60);
    root->right->right=new node(78);
    root->right->left->left=new node(55);
    root->right->left->right=new node(65);
    cout<<searchR(root,15)<<endl;
    cout<<searchI(root,15)<<endl;
    Inorder(root);
    cout<<endl;
    cout<<insertR(root,13)<<endl;
    Inorder(root);
    cout<<endl;
    Inorder(insertI(root,8));
    cout<<endl;
    Inorder(Delete(root,8));
    cout<<endl;
    Inorder(Delete(root,13));
    cout<<endl;
    cout<<(findfloor(root,35)->val)<<endl;
    cout<<findceil(root,15)->val<<endl;

    vector<int> v={2,8,30,15,25,12};
    CeilOnLeftOfArray(v);
    cout<<endl;
    kthsmallest(root,2);

    cout<<checkBST1(root,Ninf,Pinf)<<endl;
    cout<<checkBST2(root)<<endl;

    // Inorder(root);
    // cout<<endl;
    // BSTSwapTwoNode(root);
    // Inorder(root);
    // cout<<endl;

    cout<<PairWithGivenSum(root,85)<<endl;

    map<int,int> m;
    VerticalSum(root,0,m);
    for(auto x:m) cout<<x.ff<<" "<<x.ss<<endl;

    map<int,vector<int>> mi;
    VerticalTraversal(root,mi);

    for(auto x:mi){
        cout<<x.first<<":";
        for(auto z:x.second){
            // for top view of binary tree just print first index value of each vector
            // for bottom view of binary tree just print last index value of each vector
            cout<<z<<" ";
        }
        cout<<endl;
    }
    
    // given a sorted vector
    // node *root=BuildTree(A,0,A.size()-1);
    return 0;
}