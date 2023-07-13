#include <bits/stdc++.h>

using namespace std;

// typedef $long name$ $short name$;
#define us unsigned
#define ll long long
#define fori(i, a, b) for (ll i = a; i < b; i++)
#define ford(i, a, b) for (ll i = a; i >= b; i--)
#define endl '\n'
#define dbug1(a) cout << a << endl
#define dbug2(a, b) cout << a << "-" << b << endl
#define dbug3(a, b, c) cout << a << "-" << b << "-" << c << endl
#define dbug4(a, b, c, d) cout << a << "-" << b << "-" << c << "-" << d << endl
#define rdm(l, h) rand() % (h - l + 1) + l
#define fil1D(a, n, d) fill(a, a + n, d)
#define fil2D(a, n, d) fill(a[0], a[0] + n * n, d)
#define memo(a,b) memset(a,b,sizeof(a))
#define iseve(a) (a % 2 == 0)
#define ff first
#define ss second
#define desc greater<int>()
#define sz size()
#define all(v) v.begin(), v.end()
#define mod 1000000007
#define ARMX 1e8 + 1
#define pb push_back
#define swapI(x, y) \
    {               \
        x = x + y;  \
        y = x - y;  \
        x = x - y;  \
    }
#define maxA *max_element
#define minA *min_element
#define Pinf INT_MAX
#define Ninf INT_MIN
#define Plong LLONG_MAX
#define Nlong LLONG_MIN
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define len length()
#define strend string::npos
#define JustGreat(v, x) upper_bound(all(v), x)              // index of first number that is just greater than x
#define GreaterEqual(v, x) lower_bound(all(v), x)           // index of first number that is just greater or equal to x
#define NoEleLessX(v, x) upper_bound(all(v), x) - v.begin() // applicable only for sorted array
#define forr(it,ds) for(auto it = ds.rbegin(); it != ds.rend(); ++it)
#define forf(it,ds) for(auto it = ds.begin(); it != ds.end(); ++it)
// printf("%0.5lf",l);

// srand(time(NULL));
// O(1) < O(log n) < O(n) < O(n log n) < O(n^2) < O(2^n) < O(n!)

// struct TreeNode{
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x){
//         val=x;
//         left=NULL;
//         right=NULL;
//     }
// };

// struct ListNode{
//     int val;
//     ListNode *next;
//     ListNode(int x){
//         val=x;
//         next=NULL;
//     }
// };

// struct trienode{
//     trienode* child[26];
//     bool isend;
//     trienode(){
//         for(int i=0;i<26;i++) child[i]=NULL;
//         isend=false;
//     }
// };

// // use when priority queue needs to be an object
// struct obj{
//     ll dist;
//     ll cx;
//     ll cy;
// };
// bool operator<(const struct obj& obj1,const struct obj& obj2){ // will have min dist on the top
//     return obj1.dist>obj2.dist;
// }

// MAX_QUEUE // return max in queue in O(1);
// class max_queue{
//     queue<ll> q;
//     deque<ll> dq;
// public:
//     max_queue(){
//         q=queue<ll>();
//         dq=deque<ll>();
//     }
//     void push(ll x){
//         q.push(x);
//         if(dq.empty()) dq.push_back(x);
//         else{
//             while(!dq.empty() && dq.back()<x) dq.pop_back();
//             dq.push_back(x);
//         }
//     }
//     void pop(){
//         if(q.front()==dq.front()){
//             q.pop();
//             dq.pop_front();
//         }
//         else q.pop();
//     }
//     ll getMax(){
//         return dq.front();
//     }
//     bool empty(){
//         return q.empty();
//     }
// };

// MIN_QUEUE // return min in queue in O(1);
// class min_queue{
//     queue<ll> q;
//     deque<ll> dq;
// public:
//     min_queue(){
//         q=queue<ll>();
//         dq=deque<ll>();
//     }
//     void push(ll x){
//         q.push(x);
//         if(dq.empty()) dq.push_back(x);
//         else{
//             while(!dq.empty() && dq.back()>x) dq.pop_back();
//             dq.push_back(x);
//         }
//     }
//     void pop(){
//         if(q.front()==dq.front()){
//             q.pop();
//             dq.pop_front();
//         }
//         else q.pop();
//     }
//     ll getMin(){
//         return dq.front();
//     }
//     bool empty(){
//         return q.empty();
//     }
// };

// TC = O(4*alpha) // no idea
// class DisjointSet{
//     vector<ll> par;
//     vector<ll> rnk;
//     vector<ll> siz;
// public:
//     DisjointSet(ll node){
//         rnk=vector<ll>(node,0);
//         siz=vector<ll>(node,1);
//         par=vector<ll>(node);
//         for(ll i=0;i<node;i++) par[i]=i;
//     }
//     ll FindByPathComp(ll x){ 
//         if(par[x]!=x){
//             par[x]=FindByPathComp(par[x]);
//         }
//         return par[x];
//     } 
//     void UnionByRank(ll x,ll y){
//         ll xp=FindByPathComp(x);
//         ll yp=FindByPathComp(y);
//         if(xp==yp) return;
//         if(rnk[xp]>rnk[yp]) par[yp]=xp;
//         else if(rnk[yp]>rnk[xp]) par[xp]=yp;
//         else{
//             par[yp]=xp;
//             rnk[xp]++;
//         }
//     }
//     void UnionBySize(ll x,ll y){
//         ll xp=FindByPathComp(x);
//         ll yp=FindByPathComp(y);
//         if(xp==yp) return;
//         if(siz[xp]>=siz[yp]){
//             par[yp]=xp;
//             siz[xp]+=siz[yp];
//         }else{
//             par[xp]=yp;
//             siz[yp]+=siz[xp];
//         }
//     }
//     // Note: even after making disjoint set retrieve by using find operation as parent may not give right value always
//     int getNumSets(){
//         unordered_set<ll> sp;
//         for(ll i=0;i<par.size();i++) sp.insert(FindByPathComp(i));
//         return sp.size();
//     }
// };

// bool mycmp(pair<int,int> n1,pair<int,int> n2){
//     if(n1.ff==n2.ff) return n1.ss<n2.ss;
//     return n1.ff>n2.ff;
// }

// to overload operator '<' for using priority queue for different data type
// bool operator<(const struct tup& obj1,const struct tup& obj2){ // will have max height on the top
//     return obj1.sum<obj2.sum;
// }

// int gcd(int a,int b){
//     if(b==0) return a;
//     else return gcd(b,a%b);
// }

// bool check_prime3(int n){  
//     if(n==1) return false;
//     if(n==2 || n==3) return true;
//     if(n%2==0 || n%3==0) return false;
//     for(int i=5;i*i<=n;i+=6) 
//         if(n%i==0 || n%(i+2)==0) return false;
//     return true;
// }

// void all_factors2(int n){
//     int i;
//     for(i=1;i*i<=n;i++)
//         // if(n%i==0) cout<<i<<" "<<n/i<<" "; // do not give in sorted order
//         if(n%i==0) cout<<i<<" ";
//     for(i--;i>0;i--)
//         if(n%i==0) cout<<n/i<<" ";
//     cout<<endl;
// }

// long long binpow(long long a, long long b, long long m) {
//     a %= m;
//     long long res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = res * a % m;
//         a = a * a % m;
//         b >>= 1;
//     }
//     return res;
// }

// long long Inversemod(long long a,long long b,long long m){
//     return (a%m*binpow(b,m-2,m))%m;
// }

ll max(ll x,ll y){
    return (x>y)?x:y;
}

ll min(ll x,ll y){
    return (x<y)?x:y;
}

// for upper/lower bound on pair use 
// auto it = lower_bound(all(ip),make_pair((int_type)5,numeric_limits<int_type>::min()));    
// auto it = lower_bound(all(ip),make_pair(numeric_limits<int_type>::min(),(int_type)5));    
// -------------------------------------------------------------------------------------------------
// two types:
// 1) either asks for length of longest window
// 2) or asks for count no. of windows that satisfies certain condition
// 3) there can be some thing like finding max or min in window of size k
// -------------------------------------------------------------------------------------------------
// Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 
long long countSubStrK(string s, int k){
    vector<int> mp(26,0);
    int i=0;
    int dist=0;
    long long cnt=0;
    for(int j=0;j<s.length();j++){
        if(mp[s[j]-'a']==0) dist++;
        mp[s[j]-'a']++;
        while(dist>k){
            mp[s[i]-'a']--;
            if(mp[s[i]-'a']==0) dist--;
            i++;
        }
        cnt+=(j-i+1);
    }
    return cnt;
}

long long int substrCount (string s, int k) {
    return countSubStrK(s,k)-countSubStrK(s,k-1);
}
// -------------------------------------------------------------------------------------------------
// Given a binary array arr of size N and an integer target, return the number of non-empty subarrays with a sum equal to target.
// Note: this question can be done in O(N) TC ans SC using map but using sliding window it is done in O(N) TC and O(1) SC
int getCnt(vector<int>& arr, int tar){
    int i=0,sum=0,cnt=0;
    for(int j=0;j<arr.size();j++){
        sum+=arr[j];
        while(sum>tar){
            sum-=arr[i];
            i++;
        }
        cnt+=(j-i+1);
    }
    return cnt;
}

int numberOfSubarrays(vector<int>& arr, int n, int tar){
    return getCnt(arr,tar)-getCnt(arr,tar-1);
}
// -------------------------------------------------------------------------------------------------
// Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number k
int countSubArrayProductLessThanK(vector<int>& a, int n, long long k) {
    int i=0;
    int cnt=0;
    long long pro=1;
    for(int j=0;j<n;j++){
        pro*=a[j];
        while(i<=j && pro>=k){
            pro/=a[i];
            i++;
        }
        cnt+=(j-i+1);
    }
    return cnt;
}
// -------------------------------------------------------------------------------------------------
// https://practice.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1
int totalFruits(int n, vector<int> &fruit) {
    vector<int> mp(100001,0);
    int dist=0;
    int i=0;
    int mAx=0;
    for(int j=0;j<n;j++){
        if(mp[fruit[j]]==0) dist++;
        mp[fruit[j]]++;
        while(dist>2){
            mp[fruit[i]]--;
            if(mp[fruit[i]]==0) dist--;
            i++;
        }
        mAx=max(mAx,j-i+1);
    }
    return mAx;
}
// -------------------------------------------------------------------------------------------------
// You are given array nums of n length and an integer k .return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
int longestOnes(int n, vector<int>& nums, int k) {
    int i=0,j=0;
    int mAx=0;
    while(j<nums.size()){
        if(nums[j]==1){
            mAx=max(mAx,j-i+1);
            j++;
        }
        else{
            if(k>0){
                mAx=max(mAx,j-i+1);
                k--;
                j++;
            }
            else{
                if(nums[i]==1) i++;
                else{
                    k++;
                    i++;
                }
            }
        }
    }
    return mAx;
}
// -------------------------------------------------------------------------------------------------
// https://practice.geeksforgeeks.org/problems/maximum-point-you-can-obtain-from-cards/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-point-you-can-obtain-from-cards
long long maxScore(vector<int> &cp, int n, int k) {
    long long sum=0,mAx;
    int i;
    for(i=0;i<k;i++) sum+=cp[i];
    mAx=sum;
    int j=n-1;
    i--;
    while(i>=0){
        sum+=cp[j];
        sum-=cp[i];
        mAx=max(mAx,sum);
        i--;
        j--;
    }   
    return mAx;
}
// -------------------------------------------------------------------------------------------------
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}