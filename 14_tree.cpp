#include<bits/stdc++.h>

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

void Inorder(node *root){
    if(root==NULL) return;
    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
}

void InorderI(node *root){
    node *n1;
    stack<node*> stk;
    n1=root;
    while(n1){
        stk.push(n1);
        n1=n1->left;
    }
    cout<<stk.top()->val<<" ";
    while(!stk.empty()){
        node *tp=stk.top();
        if(tp->right==NULL){
            stk.pop();
        }
        else{
            n1=tp->right;
            cout<<stk.top()->val<<" ";
            stk.pop();
            while(n1){
                stk.push(n1);
                n1=n1->left;
            }
            cout<<stk.top()->val<<" ";
        }
    }
}

void Preorder(node *root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    Inorder(root->left);
    Inorder(root->right);
}

void preorderI(node *root){
    stack<node *> stk;
    while(root){
        cout<<root->val<<" ";
        if(root->right) stk.push(root->right);
        root=root->left;
    }
    while(!stk.empty()){
        node *tp=stk.top();
        stk.pop();
        while(tp){
            cout<<tp->val<<" ";
            if(tp->right) stk.push(tp->right);
            tp=tp->left;
        }
    }
}

void Postorder(node *root){
    if(root==NULL) return;
    Inorder(root->left);
    Inorder(root->right);
    cout<<root->val<<" ";
}

int TreeHeight(node *root){
    if(root==NULL) return 0;
    else{
        return max(TreeHeight(root->left),TreeHeight(root->right))+1;
    }
}

void printnodeatdistK(node *root,int k){
    if(root==NULL) return;
    if(k==0) cout<<root->val<<" ";
    else{
        printnodeatdistK(root->left,k-1);
        printnodeatdistK(root->right,k-1);
    }
}

void levelorder(node *root){
    if(root==NULL) return; 
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *tmp=q.front();
        q.pop();
        cout<<tmp->val<<" ";
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
    }
}

void levelorderwithnewline1(node *root){
    if(root==NULL) return; 
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(q.sz>1){
        node *tmp=q.front();
        q.pop();
        if(tmp==NULL){
            cout<<'\n';
            q.push(NULL);
            continue;
        }
        cout<<tmp->val<<" ";
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
    }
}

void levelorderwithnewline2(node *root){
    if(root==NULL) return; 
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        forI(i,0,n){
            node *tmp=q.front();
            q.pop();
            cout<<tmp->val<<" ";
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
        cout<<'\n';
    }
}

// vector<int> findSpiralTraversal(Node *root){ // for opposite of this order just swap push_front in both queue block
//     deque<Node*> q1;
//     deque<Node*> q2;
//     vector<int> ans;
//     q1.push_front(root);
//     int i=0;
//     while(!q1.empty() || !q2.empty()){
//         if(i%2==0){
//             while(!q1.empty()){
//                 Node* tp=q1.front();
//                 q1.pop_front();
//                 ans.push_back(tp->data);
//                 if(tp->right) q2.push_front(tp->right);
//                 if(tp->left) q2.push_front(tp->left);
//             }
//         }
//         else{
//             while(!q2.empty()){
//                 Node* tp=q2.front();
//                 q2.pop_front();
//                 ans.push_back(tp->data);
//                 if(tp->left) q1.push_front(tp->left);
//                 if(tp->right) q1.push_front(tp->right);
//             }
//         }
//         i++;
//     }
//     return ans;
// }

int sizeoftree(node *root){
    if(root==NULL) return 0;
    return (1+sizeoftree(root->left)+sizeoftree(root->right)); 
}

int maxintree(node *root){
    if(root==NULL) return Ninf;
    return max(root->val,max(maxintree(root->left),maxintree(root->right)));
}

void printleftview(node *root){ // the Recursive solution is also availabel for this problem 
    if(root==NULL) return; 
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        forI(i,0,n){
            node *tmp=q.front();
            q.pop();
            if(i==0) cout<<tmp->val<<" ";
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
    }
}
// ---------------------------------------------------------------------------------------------
bool childsumprop1(node *root){
    if(root==NULL) return true; 
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        forI(i,0,n){
            node *tmp=q.front();
            q.pop();
            int l=0,r=0;
            if(tmp->left){
                l=tmp->left->val;
                q.push(tmp->left);
            }
            if(tmp->right){
                r=tmp->right->val;
                q.push(tmp->right);
            }
            if((l!=0 || r!=0) && (l+r)!=tmp->val) return false; 
        }
    }
    return true;
}

bool childsumprop2(node *root){
    if(root==NULL) return true;
    if(root->left==NULL && root->right==NULL) return true;
    if(root->left==NULL && root->right!=NULL){
        if(root->right->val==root->val) return childsumprop1(root->right);
        else return false;
    }
    if(root->left!=NULL && root->right==NULL){
        if(root->left->val==root->val) return childsumprop1(root->left);
        else return false;
    }
    if(root->left!=NULL && root->right!=NULL){
        if(root->left->val+root->right->val==root->val){
            int a=childsumprop1(root->left);
            int b=childsumprop1(root->right);
            if(a && b) return true;
            else return false;
        }
        else return false;
    }
}

// program that converts any binary tree to one that follows the children sum property. 
// here node value can only be incremented in order to satisfy the property

// void changeTree(BinaryTreeNode < int > * root) {
//     if(root==NULL) return;
//     int p=-1,q=-1;
//     if(root->left==NULL || root->data>root->left->data){
//         p=(root->left==NULL)?0:root->left->data;
//     }
//     if(root->right==NULL || root->data>root->right->data){
//         q=(root->right==NULL)?0:root->right->data;
//     }
//     if(p!=-1 && q!=-1 && p+q<root->data){
//         if(root->left) root->left->data=root->data;
//         if(root->right) root->right->data=root->data;
//     }
//     changeTree(root->left);
//     changeTree(root->right);
//     int x=(root->left==NULL)?0:root->left->data;
//     int y=(root->right==NULL)?0:root->right->data;
//     root->data=((x+y)>root->data)?x+y:root->data;
// }  

// ------------------------------------------------------------------------------------
bool checkbalancing1(node *root){
    if(root==NULL) return true;
    int l=TreeHeight(root->left);
    int r=TreeHeight(root->right);
    if(abs(l-r)<=1){
        return (checkbalancing1(root->left) && checkbalancing1(root->right));
    }
    else return false;
}

bool checkbalancing2(node *root){ // some what complex but optimized
    if(root==NULL) return true;
    int l=checkbalancing2(root->left);
    if(l==-1) return -1;
    int r=checkbalancing2(root->right);
    if(r==-1) return -1;
    if(abs(l-r)>1){
        return -1;
    }
    else return max(l,r)+1;
}
// done using postorder traversal

// int getheight(TreeNode* root,int &fg){
//     if(fg==0){
//         if(root==NULL) return 0;
//         int l=getheight(root->left,fg);
//         int r=getheight(root->right,fg);
//         if(abs(l-r)>1) fg=1;
//         return 1+max(l,r);
//     }
//     else return 0;
// }

// -------------------------------------------------------------------------------------
int maxwidth(node *root){
    if(root==NULL) return 0; 
    queue<node*> q;
    q.push(root);
    int mAx=0;
    while(!q.empty()){
        int n=q.size();
        mAx=max(mAx,n);
        forI(i,0,n){
            node *tmp=q.front();
            q.pop();
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
    }
    return mAx;
}
// -------------------------------------------------------------------------------------
node *pre=NULL;
node *BTtoDLL(node *root){
    if(root==NULL) return root;
    node *head=BTtoDLL(root->left);
    if(pre==NULL) head=root;
    else{
        root->left=pre;
        pre->right=root;
    }
    pre=root;
    BTtoDLL(root->right);
    return head;
}
// to convert preoder of tree to single linklist using reverse postorder

// TreeNode* prev;
// void flattree(TreeNode* root){
//         if(root==NULL) return;
//         flattree(root->right);
//         flattree(root->left);
//         root->right=prev;
//         root->left=NULL;
//         prev=root;
//     }

// -------------------------------------------------------------------------------------
int preind=0;
node *TreefromInandPre(vector<int> &in,vector<int> &pre,int is,int ie){
    if(is>ie) return NULL;
    node *root=new node(pre[preind++]);
    int inind;
    for(int i=is;i<=ie;i++){
        if(in[i]==root->val){
            inind=i;
            break;
        }
    }
    root->left=TreefromInandPre(in,pre,is,inind-1);
    root->right=TreefromInandPre(in,pre,inind+1,ie);
    return root;
}

void spiralordertraversal(node *root){
    if(root==NULL) return; 
    stack<node *> s1,s2;
    s1.push(root); 
    while(!s1.empty() || !s2.empty()){
        int n=s1.empty()?s2.sz:s1.sz;
        while(!s1.empty()){
            node *tmp=s1.top();
            s1.pop();
            cout<<tmp->val<<" ";
            if(tmp->left) s2.push(tmp->left);
            if(tmp->right) s2.push(tmp->right);
        }
        cout<<'\n';
        while(!s2.empty()){
            node *tmp=s2.top();
            s2.pop();
            cout<<tmp->val<<" ";
            if(tmp->right) s1.push(tmp->right);
            if(tmp->left) s1.push(tmp->left);
        }
        cout<<'\n';
    }
}
// option 2
// vector<int> findSpiral(Node *root)
// {
//     vector<int> v;
//     if(root==NULL) return v;
//     deque<Node*> dq1;
//     deque<Node*> dq2;
//     dq1.push_back(root);
//     int i=0;
//     while(!dq2.empty() || !dq1.empty()){
//         if(i%2==0){
//             int k=dq1.size();
//             for(int i=0;i<k;i++){
//                 Node* tp=dq1.front();
//                 dq1.pop_front();
//                 v.push_back(tp->data);
//                 if(tp->right) dq2.push_front(tp->right);
//                 if(tp->left) dq2.push_front(tp->left);
//             }
//         }
//         else{
//             int k=dq2.size();
//             for(int i=0;i<k;i++){
//                 Node* tp=dq2.front();
//                 dq2.pop_front();
//                 v.push_back(tp->data);
//                 if(tp->left) dq1.push_front(tp->left);
//                 if(tp->right) dq1.push_front(tp->right);
//             }
//         }
//         i++;
//     }
//     return v;
// }

int diameter1(node *root){
    if(root==NULL) return 0;
    int h=1+TreeHeight(root->left)+TreeHeight(root->right);
    int l=diameter1(root->left);
    int r=diameter1(root->left);
    return max(h,max(l,r));
}

int res=0;
int diameter2(node *root){ // idea behind using it is postorder traversal
    if(root==NULL) return 0;
    int lh=diameter2(root->left);  // left
    int rh=diameter2(root->right); // right
    res=max(res,lh+rh+1);           
    return 1+max(lh,rh);           // root
}

bool find_path(node *root,vector<node*> &v,int n){
    if(root==NULL) return false;
    v.pb(root);
    if(root->val==n) return true;
    if(find_path(root->left,v,n) || find_path(root->right,v,n)) return true;
    v.pop_back();
    return false;
}

node *LAC1(node *root,int n1,int n2){
    vector<node*> v1,v2;
    int j=0;
    if(find_path(root,v1,n1) && find_path(root,v2,n2)){
        for(int i=0;i<v1.sz && i<v2.sz;i++){
            if(v1[i]==v2[i]) j=i;
        }
        return v1[j];
    }
    return NULL;
}

node *LAC2(node *root,int n1,int n2){ // complex to understand 
    if(root==NULL) return NULL;
    if(root->val==n1 || root->val==n2) return root;
    node *lca1=LAC2(root->left,n1,n2);
    node *lca2=LAC2(root->right,n1,n2);
    if(lca1!=NULL && lca2!=NULL) return root;
    if(lca1!=NULL) return lca1;
    else return lca2;
}

int ret=0;
int burnleaf(node *root,int leaf,int &dist){ //left to undrestand
    if(root==NULL) return 0;
    if(root->val==leaf){
        dist=1;
        return 1;
    }
    int rdist=-1,ldist=-1;
    int lh=burnleaf(root->left,leaf,ldist);
    int rh=burnleaf(root->right,leaf,rdist);
    if(ldist!=-1){
        dist=ldist+1;
        ret=max(ret,dist+rh);
    }
    else if(rdist!=-1){
        dist=rdist+1;
        ret=max(ret,dist+lh);
    }
    return 1+max(rh,lh);
}

int sizeofCompleteBT(node* root){
    if(root==NULL) return 0;
    node *n1,*n2;
    int c1=1,c2=1;
    n1=root;
    n2==root;
    while(n1){
        c1++;
        n1=n1->left;
    } 
    while(n1){
        c2++;
        n2=n2->right;
    } 
    if(c1==c2) return (pow(2,c1)-1);
    return (sizeofCompleteBT(root->left)+sizeofCompleteBT(root->right)+1);
}

void serialize(node *root,vector<int> &v){
    if(root==NULL){
        v.pb(-1);
        return;
    }
    v.pb(root->val);
    serialize(root->left,v);
    serialize(root->right,v);
}

int ind=0;
node *deserialize(vector<int> &v){
    if(ind==v.sz) return NULL;
    int val=v[ind];
    ind++;
    if(val==-1) return NULL;
    node *rot=new node(val);
    rot->left=deserialize(v);
    rot->right=deserialize(v);
    return rot;
}
// to check symmetricity of tree/trees

// bool IsMirror(TreeNode* n1,TreeNode* n2){
//     if(n1==NULL && n2==NULL) return true;
//     else if(n1 && n2 && n1->val==n2->val){
//         return (IsMirror(n1->left,n2->right) && IsMirror(n1->right,n2->left));
//     }
//     else return false;
// }
// int isSymmetric(TreeNode* A) {
//     return IsMirror(A,A);
// }

// to check Identicality of two trees

// bool IsSame(TreeNode* n1,TreeNode* n2){
//     if(n1==NULL && n2==NULL) return true;
//     else if(n1 && n2 && n1->val==n2->val){
//         return (IsSame(n1->left,n2->left) && IsSame(n1->right,n2->right));
//     }
//     else return false;
// }
// int isSameTree(TreeNode* A, TreeNode* B) {
//     return IsSame(A,B);
// }


// ----------------------------------------------------------------------------------------------------------------------------
// to check any path with given sum

// void pathsum(TreeNode *A,int B,int sum,int &f){
//     if(A==NULL){
//         if(sum==B) f=1;
//     } 
//     else{
//         sum+=A->val;
//         if(f==0 && A->left!=NULL){
//             pathsum(A->left,B,sum,f);
//         }
//         if(f==0 && A->right!=NULL){
//             pathsum(A->right,B,sum,f);
//         } 
//         if(f==0 && A->left==NULL && A->right==NULL){
//             if(sum==B){
//                 f=1;
//             }
//             else return;
//         }
//         else return;
//     }
//     if(f==1) return;
// } 
// int hasPathSum(TreeNode* A, int B) {
//     int f=0;
//     pathsum(A,B,0,f);
//     return f;
// }

// to find the maximum sum path in a binary tree. A path in a binary tree is a sequence of nodes where every adjacent pair of nodes are connected by an edge. A node can only appear in the sequence at most once. A path need not pass from the root. We need to find the path with the maximum sum in the binary tree.

// int maxpathsum(TreeNode* root,int &mAx){
//         if(root==NULL) return 0;                   // return -1; when there are no negative nodes
//         int l=max(0,maxpathsum(root->left,mAx));   // here also no need of max if no negative nodes
//         int r=max(0,maxpathsum(root->right,mAx));
//         mAx=max(mAx,l+r+root->val);
//         return max(l+root->val,r+root->val);       // max(root->val,(int)max(l+root->val,r+root->val)) // if we return -1
//     }

// ----------------------------------------------------------------------------------------------------------------------------
// fastest way to count nuber of node in complete(left weighted) binary tree
// int countNodes(TreeNode* root) {
//     if(root==NULL) return 0;
    // trick to check wether tree is full binary tree or not
//     TreeNode* lft=root->left;
//     TreeNode* rgt=root->right;
//     int l=1,r=1;
//     while(lft){
//         lft=lft->left;
//         l++;
//     }
//     while(rgt){
//         rgt=rgt->right;
//         r++;
//     }
//     if(l==r) return pow(2,l)-1;
    // then as per formula node = 2^l - 1 here l is inderectly height of tree
//     return 1+countNodes(root->left)+countNodes(root->right);
// }
// ----------------------------------------------------------------------------------------------------------------------------

int main(){
    // node *root=NULL;
    node *root=new node(30);
    root->left=new node(10);
    root->right=new node(20);
    // root->right->left=new node(90);
    Inorder(root);
    cout<<endl;
    Preorder(root);
    cout<<endl;
    Postorder(root);
    cout<<endl;
    cout<<TreeHeight(root)<<endl;
    printnodeatdistK(root,1);
    cout<<endl;
    levelorder(root);
    cout<<endl;
    levelorderwithnewline1(root);
    cout<<endl;
    levelorderwithnewline2(root);
    cout<<sizeoftree(root)<<endl;
    cout<<maxintree(root)<<endl;
    printleftview(root);
    cout<<endl;
    cout<<childsumprop1(root)<<endl;
    cout<<childsumprop2(root)<<endl;
    cout<<checkbalancing1(root)<<endl;
    cout<<checkbalancing2(root)<<endl;
    cout<<maxwidth(root)<<endl;
    cout<<diameter1(root)<<endl;
    cout<<diameter2(root)<<"-"<<res<<endl;

    node *head=BTtoDLL(root);
    cout<<head->val<<endl;

    vector<int> in={20,10,40,30,50};
    vector<int> pre={10,20,30,40,50};
    root=TreefromInandPre(in,pre,0,pre.sz-1);
    Inorder(root);
    cout<<endl;
    Preorder(root);
    cout<<endl;

    node *rot=new node(10);
    rot->left=new node(20);
    rot->right=new node(30);
    rot->right->left=new node(40);
    rot->right->right=new node(50);
    rot->right->right->left=new node(70);
    rot->right->right->right=new node(80);
    rot->right->left->left=new node(60);
    spiralordertraversal(rot);

    node *tp=LAC1(rot,40,10);
    cout<<tp->val<<endl;
    tp=LAC2(rot,40,10);
    cout<<tp->val<<endl;

    node *rt=new node(10);
    rt->left=new node(20);
    rt->right=new node(30);
    rt->left->left=new node(40);
    rt->left->right=new node(50);
    rt->right->left=new node(60);
    rt->right->right=new node(70);
    int dist=-1;
    cout<<burnleaf(rt,50,dist)<<"-"<<ret<<endl;

    cout<<sizeofCompleteBT(rt)<<endl;
    
    vector<int> v;
    serialize(rt,v);
    rt=deserialize(v);
    Inorder(rt);
    cout<<endl;
    InorderI(rt);
    cout<<endl;
    preorderI(rt);
    return 0;
}