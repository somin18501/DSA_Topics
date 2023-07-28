// every problem have both iterative and recursive solution
// Tail recursion is the one in which the last line is return statement without any operation except function call
// Tail recursion is faster than any other recursion(implementation) for same problem as it is optimized by compiler and so takes 
// auxillary space of O(1) where as other takes O(height of recursion tree)

// return <cond> && function call; // here AND act as shot circuit

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

void print_Nto1(int n){
    if(n==0) return;
    cout<<n<<endl;
    print_Nto1(n-1);
}

void print_1toN(int n){
    if(n==0) return;
    print_1toN(n-1);
    cout<<n<<endl;
}

int k;
void pri_1toNTR(int n,int z){
    if(n==0) return;
    cout<<z<<endl;
    pri_1toNTR(n-1,z+1);
}

ll fac1(int n){
    if(n<2) return 1;
    return n*fac1(n-1);
}

ll fac2(int n,int z){
    if(n<2) return z;
    return fac2(n-1,z*n);
}

ll sumofN(int n){ // for tail recursive sumofN(int n,int z) and z=0 while calling
    if(n==0) return 0;
    return n+sumofN(n-1);  // return sumofN(n-1,n+z)
}

bool Palindromechk(string s,int l,int u){
    if(l>=u) return true;
    if(s[l]==s[u]) return Palindromechk(s,l+1,u-1);
    else return false;
}

int sumOfDigit_base_10(int n){ // in base_2 it gives sum of bits of n
    if(n==0) return 0;
    return n%10+sumOfDigit_base_10(n/10);
}

int mIn(int x,int y,int z){
    int arr[]={x,y,z};
    return *min_element(arr,arr+3);
}

int mAx(int x,int y,int z){
    int arr[]={x,y,z};
    return *max_element(arr,arr+3);
}

int Rope_cutting_pro(int len,int a,int b,int c){
    if(len<0) return -1;
    if(len==0) return 0;
    int ret=(mAx(Rope_cutting_pro(len-a,a,b,c),Rope_cutting_pro(len-b,a,b,c),Rope_cutting_pro(len-c,a,b,c)));
    if(ret>=0) return ret+1;
    return -1;
}

void Generate_Subsets(string ip,string s,int i){
    if(i==s.length()) cout<<ip<<endl;
    if(i<s.length()){
        Generate_Subsets(ip,s,i+1);
        Generate_Subsets(ip+s[i],s,i+1);
    }
}

// iterative way to get all unique subset sums
set<ll> getUniqueSubsetSums(vector<ll> ip){
    set<ll> sp;
    vector<ll> tp;
    tp.push_back(0);
    forI(i,0,ip.sz){
        ll k=tp.size();
        forI(j,0,k){
            if(!sp.count(tp[j]+ip[i])){
                sp.insert(tp[j]+ip[i]);
                tp.push_back(tp[j]+ip[i]);
            }
        }
    }
    return sp;
}

int subset_sum_pro(vector<int> v,int i,int sum){
    if(i==v.size())
        if(sum==0) return 1;
        else return 0;
    if(i<v.size()){
        return subset_sum_pro(v,i+1,sum) + subset_sum_pro(v,i+1,sum-v[i]);
    }
}

// ------------------------------------------------------------------------------------------------------------------------

// void getcombi(vector<int> ip,int k,vector<int> tp,vector<vector<int>> &op,int l){ // for generating all combinations of size k
//     if(k==0){                                                                     // No permutations
//         op.push_back(tp);
//         return;
//     }
//     for(int i=l;i<ip.size();i++){
//             tp.push_back(ip[i]);
//             getcombi(ip,k-1,tp,op,i+1);
//             tp.pop_back();
//     }
//     return;
// }

// entries of A are distict
void getcombi(vector<int> arr,int sum,vector<int> tp,set<vector<int>> &op,int l){ // when each entry can be used infinitely
    if(sum==0){                                                     // here we generate combinations of all size that sums to B
        op.insert(tp);                                              // set is used to maintain unique combination property
        return;
    }
    for(int i=l;i<arr.size();i++){
        if(arr[i]<=sum){
            tp.push_back(arr[i]);
            getcombi(arr,sum-arr[i],tp,op,i);
            tp.pop_back();
        }
        else return;
    }
}

// entries of A are not distict
void getcombi(vector<int> arr,int sum,vector<int> tp,set<vector<int>> &op,int l){ // when each entry can be used atmost once
    if(sum==0){                                                     // here we generate combinations of all size that sums to B
        op.insert(tp);                                              // set is used to maintain unique combination property
        return;
    }
    for(int i=l;i<arr.size();i++){
        if(arr[i]<=sum){
            tp.push_back(arr[i]);
            getcombi(arr,sum-arr[i],tp,op,i+1);
            tp.pop_back();
        }
        else return;
    }
}

vector<vector<int> > CombinationSum(vector<int> &A, int B) {
    set<vector<int>> op;
    sort(A.begin(),A.end()); // important to implement it
    getcombi(A,B,{},op,0);
    vector<vector<int>> out(op.begin(),op.end());
    return out;
}
// ------------------------------------------------------------------------------------------------------------------------
int jhosepus_pro(int n,int k){ // imp only for 0 indexing of people
    if(n==1) return 0;
    return (jhosepus_pro(n-1,k)+k)%n;
}
// modification for 1 indexing of people
// int safePos(int n, int k) {
//     if(n==1) return 1;
//     int z=safePos(n-1,k);
//     return ((z+k)%n==0)?n:(z+k)%n;
// }

void swap(char &a,char &b){
    char t=a;
    a=b;
    b=t; 
}
void generate_permute(string s,int i){
    if(i==s.length()-1) cout<<s<<endl;
    for(int j=i;j<s.length();j++){
        swap(s[i],s[j]);
        generate_permute(s,i+1);
        swap(s[i],s[j]);
    }
}

long long fact(int n){
    if(n==0 || n==1) return 1;
    long long pro=1;
    for(int i=2;i<=n;i++){
        pro*=i;
    }
    return pro;
}
string getkthPermutation(int n, int k) { // only for n in [1,9]
    vector<char> v;
    for(int i=0;i<n;i++){
        v.push_back((i+1)+'0');
    }
    string op="";
    k=k-1;
    while(n){
        long long z=fact(n-1);
        op+=(v[k/z]);
        v.erase(v.begin()+k/z);
        k=k%z;
        n--;
    }
    return op;
}

// void nextPermutation(vector<int>& nums) {
//     int i1=-1;
//     for(int i=nums.size()-2;i>=0;i--){
//         if(nums[i]<nums[i+1]){
//             i1=i;
//             break;
//         }
//     }
//     if(i1==-1) reverse(nums.begin(),nums.end());
//     else{
//         int i2;
//         for(int i=nums.size()-1;i>=0;i--){
//             if(nums[i]>nums[i1]){
//                 i2=i;
//                 break;
//             }
//         }
//         swap(nums[i1],nums[i2]);
//         int l=i1+1,h=nums.size()-1;
//         while(l<h){
//             swap(nums[l],nums[h]);
//             l++;
//             h--;
//         }   
//     }
// }

// imp
void tower_hanoi(int n,char A,char B,char C){ // here A is source, B is auxillary, C is sink // total moves for any n :2^n - 1
    if(n==1){
        cout<<"Move 1 from "<<A<<" to "<<C<<endl;
        return;
    }
    tower_hanoi(n-1,A,C,B);
    cout<<"Move "<<n<<" from "<<A<<" to "<<C<<endl;
    tower_hanoi(n-1,B,A,C);
}

// vector<TreeNode*> getWays(int n){
//     if(n==0) return {NULL};
//     vector<TreeNode*> tp;
//     for(int i=0;i<n;i++){
//         vector<TreeNode*> l=getWays(i);
//         vector<TreeNode*> r=getWays(n-i-1);
//         for(int x=0;x<l.size();x++){
//             for(int y=0;y<r.size();y++){
//                 TreeNode* node=new TreeNode;
//                 node->left=l[x];
//                 node->right=r[y];
//                 tp.push_back(node);
//             }
//         }
//     }
//     return tp;
// }
// vector<TreeNode*> generateTrees(int n) {
//     return getWays(n);
// }

// vector<string> getBrackets(vector<vector<string>> &dp,int n){
//     if(dp[n].size()==0){
//         if(n==0) return dp[n]={""};
//         if(n==1) return dp[n]={"()"};
//         for(int i=0;i<n;i++){
//             vector<string> tmp=getBrackets(dp,i);
//             vector<string> tmp2=getBrackets(dp,n-i-1);
//             for(int r=0;r<tmp.size();r++){
//                 for(int c=0;c<tmp2.size();c++){
//                     string tp="(";
//                     tp+=tmp[r];
//                     tp+=")";
//                     tp+=tmp2[c];
//                     dp[n].push_back(tp);
//                 }
//             }
//         }
//     }
//     return dp[n];
// }
// vector<string> generateParenthesis(int n) {
//     vector<vector<string>> dp(n+1);
//     return getBrackets(dp,n);
// }

// Get distinct full Binary trees i.e. each node has either 0 or 2 child
// vector<TreeNode*> getWays(vector<vector<TreeNode*>> &dp,int n){
//     if(dp[n].size()==0){
//         if(n==1){
//             TreeNode* node=new TreeNode;
//             return dp[n]={node};
//         }
//         int k=n-1;
//         for(int i=1;i<k;i+=2){
//             vector<TreeNode*> l=getWays(dp,i);
//             vector<TreeNode*> r=getWays(dp,k-i);
//             for(int x=0;x<l.size();x++){
//                 for(int y=0;y<r.size();y++){
//                     TreeNode* node=new TreeNode;
//                     node->left=l[x];
//                     node->right=r[y];
//                     dp[n].push_back(node);
//                 }
//             }
//         }
//     }
//     return dp[n];
// }
// vector<TreeNode*> allPossibleFBT(int n) {
//     if((n&1)==0) return {};
//     vector<vector<TreeNode*>> dp(n+1);
//     return getWays(dp,n);
// }

int main(){
    // int n;
    // cin>>n;

    // print_Nto1(n);
    // cout<<endl;
    // print_1toN(n);
    // cout<<endl;
    // k=1;
    // pri_1toNTR(n,k);

    // k=1;
    // cout<<fac1(n)<<endl;
    // cout<<fac2(n,k);

    // cout<<sumofN(n)<<endl;

    // cout<<sumOfDigit_base_10(n)<<endl;
// -------------------------------------------------------------------------
    // string s;
    // cin>>s;
    // if(Palindromechk(s,0,s.length()-1)) cout<<"YES\n";
    // else cout<<"NO\n";
// -------------------------------------------------------------------------
    // int len,a,b,c;
    // cin>>len>>a>>b>>c;
    // cout<<Rope_cutting_pro(len,a,b,c)<<endl;
// -------------------------------------------------------------------------
    // string s;
    // cin>>s;
    // Generate_Subsets("",s,0);
// -------------------------------------------------------------------------
    // vector<int> v={10,20,15};
    // int sum;
    // cin>>sum;
    // cout<<subset_sum_pro(v,0,sum)<<endl;
// -------------------------------------------------------------------------
    // int n,k;
    // cin>>n>>k;
    // cout<<jhosepus_pro(n,k)<<endl;
// -------------------------------------------------------------------------
    // string s;
    // cin>>s;
    // generate_permute(s,0);
// -------------------------------------------------------------------------
    // int n;
    // cin>>n;
    // tower_hanoi(n,'A','B','C');
// -------------------------------------------------------------------------
    unordered_set<string> op;
    getparenthesis(4,"()",1,op);
    return 0;
}