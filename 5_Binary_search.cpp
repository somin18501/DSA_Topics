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

int binary_searchI(vector<int> v,int x){
    int low=0,high=v.sz-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(x<v[mid]){
            high=mid-1;
        }
        else if(x>v[mid]){
            low=mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int binary_searchR(vector<int> v,int low,int high,int x){
    if(low<=high){
        int mid=(low+high)/2;
        if(x<v[mid]){
            return binary_searchR(v,low,mid-1,x);
        }
        else if(x>v[mid]){
            return binary_searchR(v,mid+1,high,x);
        }
        else{
            return mid;
        }
    }
    return -1;
}

int first_occuranceI(vector<int> v,int x){
    int low=0,high=v.sz-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(x<v[mid]){
            high=mid-1;
        }
        else if(x>v[mid]){
            low=mid+1;
        }
        else{
            if(mid==0 || v[mid-1]!=v[mid]){
                return mid;
            }
            high=mid-1;
        }
    }
    return -1;
}

int last_occuranceI(vector<int> v,int x){
    int low=0,high=v.sz-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(x<v[mid]){
            high=mid-1;
        }
        else if(x>v[mid]){
            low=mid+1;
        }
        else{
            if(mid==v.sz-1 || v[mid+1]!=v[mid]){
                return mid;
            }
            low=mid+1;
        }
    }
    return -1;
}

int count_all_occurance(vector<int> v,int x){
    int first=first_occuranceI(v,x);
    if(first==-1) return 0;
    return (last_occuranceI(v,x)-first+1);
}

int count_1s_inSortArr(vector<int> v){
    int first=first_occuranceI(v,1);
    if(first==-1) return 0;
    return (v.sz-1-first+1);
}

int Sqrt(int n){
    int low=0,high=n,ans;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid*mid<n){
            low=mid+1;
            ans=mid; // when mid*mid becomes floor of n 
        }
        else if(mid*mid>n){
            high=mid-1;
        }
        else{
            return mid;
        }
    }
    return ans;
}

int search_UnboundSortArr(vector<int> v,int x){ // infinity sized array i.e. x is present in left half of large sized array
    if(v[0]==x) return 0;
    int i;
    for(i=1;i<v.sz;i*=2){
        if(v[i]==x) return i;
        else if(v[i]>x) break;
    }
    if(i>=v.sz) return binary_searchR(v,i/2+1,v.sz-1,x);
    return binary_searchR(v,i/2+1,i-1,x);
}

int search_RotatedSortArr(vector<int> v,int x){ // sorted and rotated // imp
    int low=0,high=v.sz-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]==x) return mid;
        else if(v[low]<=v[mid]){  // imp step
            if(x>=v[low] && x<v[mid]) high=mid-1;
            else low=mid+1;
        }
        else{
            if(x<=v[high] && x>v[mid]) low=mid+1;
            else high=mid-1;
        }
    }
    return -1;
}

int find_peak(vector<int> v){ // element in array which is not smaller than its neighbour
    int low=0,high=v.sz-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid==0 && v[mid]>=v[mid+1]) return mid;
        if(mid==v.sz-1 && v[mid]>=v[mid-1]) return mid;
        if(v[mid]>=v[mid-1] && v[mid]>=v[mid+1]) return mid;
        else{
            if(mid>0 && v[mid]<=v[mid-1]) high=mid-1;
            else low=mid+1;
        }
    }
    return -1;
}

// int rotatedsearch(vector<int> A,int l,int h){ // peak in sorted and rotated array
//     if(l<=h){
//         int mid=(l+h)/2;
//         if(mid==0 && A[mid+1]<A[mid]){
//             return mid;
//         }
//         else if(mid==A.size()-1 && A[mid]>A[0]){
//             return mid;
//         }
//         else if(A[mid]>A[mid+1]){
//             return mid;
//         }
//         else{
//             int k1=rotatedsearch(A,l,mid-1);
//             int k2=rotatedsearch(A,mid+1,h);
//             if(k1==-1) return k2;
//             else return k1;
//         }
//     }
//     return -1;
// }

bool ispair_equalsum(vector<int> v,int sum,int s,int e){ // check if there exist a,b such that a+b=sum using two pointer
    while(s<e){
        if(v[s]+v[e]==sum) return true;
        else if(v[s]+v[e]>sum) e--;
        else s++;
    }
    return false;
}
// Above approach is also usefull for the maximum container with water
int diffPossible(vector<int> &A, int k) { // check if there exist a,b such that a-b=k using two pointer
    int i=0,j=1;
    while(i<A.size() && j<A.size()){
        if(A[j]-A[i]==k && j!=i){
            return 1;
        }
        else if(A[j]-A[i]>k){
            i++;
        }
        else{
            j++;
        }
    }
    return 0;
}
// Given an integer array nums and an integer k, return the number of good subarrays of nums.
// A subarray arr is good if it there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
// A subarray is a contiguous non-empty sequence of elements within an array.
// Note here sliding window is used for checking condition at each index r
long long countGood(vector<int>& nums, int k) {
    int l=0,r=0;
    unordered_map<int,int> mp;
    long long c=0,ans=0;
    while(r<nums.size()){
        c+=mp[nums[r]];
        mp[nums[r]]++;
        while(l<r && c>=k){
            ans+=nums.size()-r;
            mp[nums[l]]--;
            c-=mp[nums[l]];
            l++;
        }
        r++;
    }
    return ans;
}

// Max Consecutive Ones: Given a binary array nums and an integer k, 
// return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
int longestOnes(vector<int>& nums, int k) {
    int i=0,j=0;
    int c=0,mAx=0;
    while(j<nums.size()){
        if(c<k){
            if(nums[j]==0){
                c++;
            }
            j++;
        }
        else{
            if(nums[j]==1){
                j++;
            }
            else{
                mAx=max(mAx,j-i);
                if(nums[i]==0){
                    c--;
                }
                i++;
            }
        }
    }
    mAx=max(mAx,j-i);
    return mAx;
}

bool istriplet_equalsum(vector<int> v,int sum){ // check if there exist a,b,c such that a+b+c=sum using two pointer
    forI(i,0,v.sz-2){
        int tp=sum-v[i];
        if(ispair_equalsum(v,tp,i+1,v.sz-1)) return true;
    }
    return false;
}

double median_2SortArr(vector<int> v1,vector<int> v2){ // here v1.sz<=v2.sz // imp question
    int low=0,high=v1.sz,i1,i2;
    while(low<=high){
        i1=(low+high)/2;
        i2=(v1.sz+v2.sz+1)/2-i1;
        int min1=(i1==v1.sz)?Pinf:v1[i1];
        int max1=(i1==0)?Ninf:v1[i1-1];

        int min2=(i2==v2.sz)?Pinf:v2[i2];
        int max2=(i2==0)?Ninf:v2[i2-1];
        if(max1<=min2 && max2<=min1){
            if((v1.sz+v2.sz)%2==0){
                return ((double)max(max1,max2)+min(min1,min2))/2;
            }
            return (double)max(max1,max2);
        }
        else if(max1>min2) high=i1-1;
        else low=i1+1;
    }
}

int find_repeat_Arrind1(vector<int> v){ // valid for v.sz>=2(unsorted), only one ele repeat, 1<=ele<=max(v) all are present, so 1<=max(v)<=n-1 
    // it has three navie sol: 1) O(n^2) & O(1) aux, 2) O(nlogn+n) & O(1) aux, 3) O(n) & O(n) aux for boolean array
    // but efficient solution has O(n) and O(1) aux
    int slow=v[0],fast=v[0];
    do{
        slow=v[slow];
        fast=v[v[fast]];
    }while(slow!=fast);
    slow=v[0];
    while(slow!=fast){
        slow=v[slow];
        fast=v[fast];
    }
    return slow;
}

int find_repeat_Arrind0(vector<int> v){ // valid for v.sz>=2(unsorted), only one ele repeat, 0<=ele<=max(v) all are present, so 0<=max(v)<=n-2 
    // it has three navie sol: 1) O(n^2) & O(1) aux, 2) O(nlogn+n) & O(1) aux, 3) O(n) & O(n) aux for boolean array
    // but efficient solution has O(n) and O(1) aux
    int slow=v[0]+1,fast=v[0]+1;
    do{
        slow=v[slow]+1;
        fast=v[v[fast]+1]+1;
    }while(slow!=fast);
    slow=v[0]+1;
    while(slow!=fast){
        slow=v[slow]+1;
        fast=v[fast]+1;
    }
    return slow-1;
}
// --------------------------------------------------------------------------------------
// allocate minimumpages continously: here we find min of all max but assign continously  
int sum(vector<int> v,int s,int e){
    int c=0;
    forI(i,s,e+1) c+=v[i];
    return c;
}

int minpageR(vector<int> v,int siz,int k){ // very time consuming as it check all combinations i.e. siz-1 C k-1 
    if(k==1) return sum(v,0,siz-1);
    if(siz==1) return v[0];
    int res=Pinf;
    forI(i,0,siz){
        res=min(res,max(minpageR(v,i,k-1),sum(v,i,siz-1)));
    }
    return res;
}

bool isfeasible(vector<int> v,int k,int ans){
    int res=0;
    int sum=0;
    forI(i,0,v.sz){
        if(sum+v[i]<=ans) sum+=v[i];
        else{
            sum=v[i];
            res++;
        }
    }
    if(res+1<=k) return true;
    return false;
}

int minpageI(vector<int> v,int k){
    int high=sum(v,0,v.sz-1);
    int low=maxA(all(v));
    int ret=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(isfeasible(v,k,mid)){
            ret=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ret;
}
// --------------------------------------------------------------------------------------
// allocate position: here we find max of all minimum distances  
bool isfeasible(vector<int> pos,int C,int mid){
    int lst=0,res=1,i;
    for(i=lst+1;i<pos.size();i++){
        if(pos[i]-pos[lst]>=mid){
            lst=i;
            res++;
        }
    }
    if(res<C) return false;
    return true;
}

int AggressiveCows(vector<int> pos,int C){
    sort(pos.begin(),pos.end());
    int high=pos[pos.size()-1]-pos[0],low=high;
    for(int i=1;i<pos.size();i++){
        low=min(low,pos[i]-pos[i-1]);
    }
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(isfeasible(pos,C,mid)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
// --------------------------------------------------------------------------------------
// There are several consecutive houses along a street, each of which has some money inside. There is also a robber, 
// who wants to steal money from the homes, but he refuses to steal from adjacent homes.
// The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.
// You are given an integer array nums representing how much money is stashed in each house. 
// More formally, the ith house from the left has nums[i] dollars.
// You are also given an integer k, representing the minimum number of houses the robber will steal from.
// It is always possible to steal at least k houses.
// Return the minimum capability of the robber out of all the possible ways to steal at least k houses.
bool isfeasible(vector<int> nums,int mid,int k){
    int res=0;
    int i=0;
    while(i<nums.size()){
        if(nums[i]<=mid){
            i+=2;
            res++;
        }
        else{
            i++;
        }
    }
    if(res>=k) return true;
    return false;
}

int minCapability(vector<int>& nums, int k) {
    int r=*max_element(nums.begin(),nums.end());
    int l=*min_element(nums.begin(),nums.end());
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(isfeasible(nums,mid,k)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }   
    return ans;
}
// must vist this below question as it is another way to do binary search when k not given
// https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/

int main(){
    // vector<int> v={3,6,9}; // must always be sorted
    
    // int x;
    // cin>>x;
    // cout<<binary_searchI(v,x)<<endl;
    // cout<<binary_searchR(v,0,v.sz-1,x)<<endl;
    // cout<<search_UnboundSortArr(v,x)<<endl;
    
    // cout<<first_occuranceI(v,x)<<endl;
    // cout<<last_occuranceI(v,x)<<endl;

    // cout<<count_all_occurance(v,x)<<endl;
    // cout<<count_1s_inSortArr(v)<<endl;

    // int n;
    // cin>>n;
    // cout<<Sqrt(n)<<endl;

    // cout<<search_RotatedSortArr(v,x)<<endl;

    // cout<<find_peak(v)<<endl;

    // cout<<ispair_equalsum(v,x,0,v.sz-1)<<endl;

    // cout<<istriplet_equalsum(v,x)<<endl;

    // vector<int> w={2,6,9};
    // cout<<median_2SortArr(v,w)<<endl;

    // cout<<find_repeat_Arrind1(v)<<endl; // input array should not contain 0
    // cout<<find_repeat_Arrind0(v)<<endl; // input array should contain 0

    // cout<<minpageR(v,v.sz,x)<<endl;
    // cout<<minpageI(v,x)<<endl;

    // vector<int> pos={1,2,8,4,9};
    // int C=3;
    // cout<<AggressiveCows(pos,C)<<endl;
    return 0;
}

// nice logic for traversing diagonally in pair
// http://thejoboverflow.com/problem/354/
//     ll n,m;
//     cin>>n>>m;
//     string s;
//     cin>>s;
//     unordered_map<ll,set<pair<int,int>>> mp1,mp2;
//     ll a,b;
//     fori(i,0,n){
//       ll x,y;
//       cin>>x>>y;
//       if(i==0){
//         a=x;
//         b=y;
//       }
//       mp1[x-y].insert({x,y});
//       mp2[x+y].insert({x,y});
//     }
//     pair<int,int> cur={a,b};
//     fori(i,0,m){
//       if(s[i]=='A'){
//         auto it=mp1[cur.ff-cur.ss].lower_bound(cur);
//         it++;
//         if(it!=mp1[cur.ff-cur.ss].end()){
//           mp1[cur.ff-cur.ss].erase(cur);
//           mp2[cur.ff+cur.ss].erase(cur);
//           cur=*it;
//         }
//       }
//       else if(s[i]=='B'){
//         auto it=mp2[cur.ff+cur.ss].lower_bound(cur);
//         it++;
//         if(it!=mp2[cur.ff+cur.ss].end()){
//           mp1[cur.ff-cur.ss].erase(cur);
//           mp2[cur.ff+cur.ss].erase(cur);
//           cur=*it;
//         }
//       }
//       else if(s[i]=='C'){
//         auto it=mp2[cur.ff+cur.ss].lower_bound(cur);
//         if(it!=mp2[cur.ff+cur.ss].begin()){
//           it--;
//           mp1[cur.ff-cur.ss].erase(cur);
//           mp2[cur.ff+cur.ss].erase(cur);
//           cur=*it;
//         }
//       }
//       else{
//         auto it=mp1[cur.ff-cur.ss].lower_bound(cur);
//         if(it!=mp1[cur.ff-cur.ss].begin()){
//           it--;
//           mp1[cur.ff-cur.ss].erase(cur);
//           mp2[cur.ff+cur.ss].erase(cur);
//           cur=*it;
//         }
//       }
//     }
//     cout<<cur.ff<<" "<<cur.ss;