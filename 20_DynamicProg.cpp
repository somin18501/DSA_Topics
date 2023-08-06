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

// it is an optimization over plain recurrsion
// The idea is to reuse the solution of subproblems when there are overlapping subproblems
// It is implemented in two ways
// 1) Memoization(top down) i.e. first call is made for root and then goes till leaf
// 2) Tabulation(Bottom Up) i.e. first value of leaf is calculated/assigned and then values are calculated till root

// substring: is always contiguous
// subsequence: is not always contiguous but in order in which letters appear in main string

// Steps to solve dp problems:
// 1)make recursive function with help of recursion tree(try to see overlapping subproblems in tree) such that changing parameter reduce 
//   from root to leaf
// 2)use leaf node to decide base case
// 3)make array of dimension based on number of parameters that are changing with each calls
//   i.e. if only one parameter changes then use 1D array, if two then 2D array
// 4)if you fill array using recursive function then it is called memoization technique(using -1 for initializing all array values,
//   and then filling other values recursively if initial value is -1 else using that value as solution of subproblem for other values) 
// 5)if you fill base case as default values and other values of array iteratively using previously filled values corresponding
//   to recursive calls. this techique is called tabulation method it is iterative method
// 6)at the end we get solution mostly as last value of array or max/min value of array

// Note: use memoization mostly when you can not decide basecase directly i.e. it need some pre computed value 
// -------------------------------------------------------------------------------------------------------
// Fibonacci:
int FibR(int n){
    if(n<2) return n; // f0=0,f1=1,f2=1,f3=2,f4=3,...
    return FibR(n-1)+FibR(n-2);
}

int FibM(int n,vector<int> &memo){
    if(memo[n]==-1){
        int res;
        if(n<2){
            res=n;
        }
        else{
            res=FibM(n-1,memo)+FibM(n-2,memo);
        }
        memo[n]=res;
    }
    return memo[n];
}

int FibT(int n){
    int tab[n+1];
    tab[0]=0;
    tab[1]=1;
    forI(i,2,n+1){
        tab[i]=tab[i-1]+tab[i-2];
    }
    return tab[n];
}
// -------------------------------------------------------------------------------------------------------
// Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once.
// Find out the total number of ways in which friends can remain single or can be paired up.
int getcount(int n){
    if(n==1 || n==2) return n;
    return getcount(n-1)+(n-1)*getcount(n-2);
}
int countFriendsPairings(int n) 
{   if(n<3) return n;
    int x=2,y=1;
    for(int i=3;i<=n;i++){
        int t=x;
        x=x+(i-1)*y;
        y=t;
    }
    return x;
}
// -------------------------------------------------------------------------------------------------------
// Longest Common Subsequence(LCS):
int LCSR(string s1,string s2,int l1,int l2){
    if(l1==0 || l2==0) return 0;
    if(s1[l1-1]==s2[l2-1]){
        return 1+LCSR(s1,s2,l1-1,l2-1);
    }
    else{
        return max(LCSR(s1,s2,l1,l2-1),LCSR(s1,s2,l1-1,l2));
    }
}

const int l1=4,l2=3;
int memo2[l1+1][l2+1];
// fill(memo2[0], memo2[0] + (l1+1)*(l2+1), -1);
int LCSM(string s1,string s2,int l1,int l2){
    if(memo2[l1][l2]==-1){
        int res;
        if(l1==0 || l2==0){
            res=0;
        }
        else{
            if(s1[l1-1]==s2[l2-1]){
                res=1+LCSM(s1,s2,l1-1,l2-1);
            }
            else{
                res=max(LCSM(s1,s2,l1,l2-1),LCSM(s1,s2,l1-1,l2));
            }
        }
        memo2[l1][l2]=res;
    }
    return memo2[l1][l2];
}

int LCST(string s1,string s2,int l1,int l2){
    int tab[l1+1][l2+1];
    forI(i,0,l1+1) tab[i][0]=0;
    forI(i,0,l2+1) tab[0][i]=0;
    forI(r,1,l1+1){
        forI(c,1,l2+1){
            if(s1[r-1]==s2[c-1]){
                tab[r][c]=1+tab[r-1][c-1];
            }
            else{
                tab[r][c]=max(tab[r-1][c],tab[r][c-1]); // for longest common substring here tab[r][c]=0; as substrings are contigous
            }
            // mAx=max(mAx,tab[r][c]); // for longest common substring
        }
    }
    // forI(i,0,l1+1){
    //     forI(j,0,l2+1){
    //         cout<<tab[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return tab[l1][l2]; // return mAx; // for longest common substring
}
// use this function to reconstruct lcs after doing memoization
void reconstruct(string &s,string &t,vector<vector<int>> &dp,string &tp,int x,int y){
    if(x==0 || y==0) return;
    else{
        if(s[x-1]==t[y-1]){
            tp=s[x-1]+tp;
            reconstruct(s,t,dp,tp,x-1,y-1);
        }
        else{
            if(dp[x][y-1]>=dp[x-1][y]){
                reconstruct(s,t,dp,tp,x,y-1);
            }
            else{
                reconstruct(s,t,dp,tp,x-1,y);
            }
        }
    }
}
// use this function to reconstruct lcs after doing memoization with return string
string lcs(string &s,string &t,int l1,int l2,vector<vector<string>> &dp){
    if(dp[l1][l2]=="0"){
        if(l1==0 || l2==0) dp[l1][l2]="";
        else{
            if(s[l1-1]==t[l2-1]){
                dp[l1][l2]=(lcs(s,t,l1-1,l2-1,dp)+s[l1-1]);
            }
            else{
                string s1=lcs(s,t,l1-1,l2,dp);
                string s2=lcs(s,t,l1,l2-1,dp);
                if(s1.len>s2.len){
                    dp[l1][l2]=s1;
                }
                else{
                    dp[l1][l2]=s2;
                }
            }
        }
    }
    return dp[l1][l2];
}
// use this function to form Shortest Common SuperSequence for two given string
string shortestCommonSupersequence(string s, string t) {
    int l1=s.len,l2=t.len;
    vector<vector<string>> dp(l1+1,vector<string>(l2+1,"0"));
    string tp=lcs(s,t,l1,l2,dp);
    int i=0,j=0;
    string ans="";
    for(int k=0;k<tp.length();k++){
        while(s[i]!=tp[k]){
            ans+=s[i];
            i++;
        }
        while(t[j]!=tp[k]){
            ans+=t[j];
            j++;
        }
        ans+=tp[k];
        i++;
        j++;
    }
    ans+=(s.substr(i)+t.substr(j));
    return ans;
}
// shortest superstring ------------------------------------------------------------------
string solve(vector<vector<string>> &dp,vector<vector<int>> &overlap,int &n,vector<string> &ip,int i,int mask){
    if(dp[i][mask]=="-1"){
        if(mask==pow(2,n)-1) return "";
        int mIn=INT_MAX;
        for(int j=0;j<n;j++){
            if((mask&(1<<j))==0){
                int tp=(mask|(1<<j));
                string tmp=solve(dp,overlap,n,ip,j,tp);
                if(overlap[j][j]-overlap[i][j]+tmp.length()<mIn){
                    mIn=overlap[j][j]-overlap[i][j]+tmp.length();
                    dp[i][mask]=ip[j].substr(overlap[i][j])+tmp;
                }
            }
        }
    }
    return dp[i][mask];
}

string getShortestSuperString(vector<string> &ip){
    int n=ip.size();
    vector<vector<int>> overlap(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) overlap[i][j]=ip[i].length();
            else{
                for(int k=ip[j].length()-1;k>=1;k--){
                    if(ip[i].length()>k && ip[i].substr(ip[i].length()-k,k)==ip[j].substr(0,k)){
                        overlap[i][j]=k;
                        break;
                    }
                }
            }
        }
    }
    int mask=0,mIn=INT_MAX;
    vector<vector<string>> dp(n,vector<string>(pow(2,n),"-1"));
    string ans="";
    for(int i=0;i<n;i++){
        string tmp=solve(dp,overlap,n,ip,i,mask);
        if(overlap[i][i]+tmp.length()<mIn){
            mIn=overlap[i][i]+tmp.length();
            ans=ip[i]+tmp;
        }
    }
    return ans;
}
// ------------------------------------------------------------------------------------
// Variation in LCS:
// 1)Minimum insertion and deletion to convert s1 to s2:insert(s2-lcs)+delete(s1-lcs)
// 2)Shortest Common Supersequence: i.e. find shortest third string which has s1 and s2 as their LCS: add remaining letter of both s1 & s2
//  in order in lcs
// 3)longest palindromic subsequence in s1: find lcs between s1 and reverse of s1
// 4)longest repeating subsequence in s1: find lcs of s1 with s1 but check that index of matching character are different
// 5)Optimized tabulation table: i.e. we use only two succesive row at a time to find lcs(reduce memory reqirement)
// 6)Printing all lcs: use tabulation table to traverse character by character and print them
// 7)minimum insertion to make a string s1 a palindrome is: s1.length()-(length of longest palindromic subsequence)  
// -------------------------------------------------------------------------------------------------------
// distict subsequences: i.e. given two strings s1 and s2 find number of all subsequences s2 in s1 
int getdistseq(string A,string B,int j,int k){
    if(j==0) return 1;
    if(k<j) return 0;
    int res=0;
    if(A[k-1]==B[j-1]){
        res+=getdistseq(A,B,j-1,k-1);
        res+=getdistseq(A,B,j,k-1);
    }
    else{
        res+=getdistseq(A,B,j,k-1);
    }
    return res;
}

int getdistseqT(string A, string B) {
    if(A.length()<B.length()) return 0;
    int tab[A.length()+1][B.length()+1];
    for(int i=0;i<=A.length();i++){
        tab[i][0]=1;
    }
    for(int i=1;i<=B.length();i++){
        for(int j=0;j<i;j++){
            tab[j][i]=0;
        }
    }
    for(int r=1;r<=A.length();r++){
        for(int c=1;c<=r && c<=B.length();c++){
            tab[r][c]=0;
            if(A[r-1]==B[c-1]){
                tab[r][c]+=tab[r-1][c-1];
                tab[r][c]+=tab[r-1][c];
            }
            else{
                tab[r][c]+=tab[r-1][c];
            }
        }
    }
    return tab[A.length()][B.length()];
}
// -------------------------------------------------------------------------------------------------------
// Coin Change(all possible combination of sum in given denomination of coin)
int getcoinR(int sum,int *coin,int n){
    if(sum==0) return 1;
    if(n==0) return 0;
    int res;
    res=getcoinR(sum,coin,n-1);
    if(coin[n-1]<=sum){
        res+=getcoinR(sum-coin[n-1],coin,n);
    }
    return res;
}
// above algo: when one item is allowed to use more than once
// if includable: then 1) include and do not reduce
//                     2) do not include and reduce
// else do not include and reduce 
int getcoinT(int sum,int *coin,int n){
    int tab[sum+1][n+1];
    forI(i,0,n+1){
        tab[0][i]=1;
    }
    forI(i,1,sum+1){
        tab[i][0]=0;
    }
    forI(i,1,sum+1){
        forI(j,1,n+1){
            int res;
            res=tab[i][j-1];
            if(coin[j-1]<=i){
                res+=tab[i-coin[j-1]][j];
            }
            tab[i][j]=res;
        }
    }
    return tab[sum][n];
}

int getcoinTO(vector<int> &A, int B) { // spaced optimized
    vector<int> v1(B+1,0);
    for(int c=1;c<=A.size();c++){
        vector<int> v2(B+1,0);
        v2[0]=1;
        for(int r=1;r<=B;r++){
            v2[r]=0;
            if(A[c-1]<=r){
                v2[r]+=(v2[r-A[c-1]])%1000007;
            }
            v2[r]+=v1[r]%1000007;
        }
        v1=v2;
    }
    return v1[B]%1000007;
}
// -------------------------------------------------------------------------------------------------------
// Edit distance(converting s1->s2) by doing three operations i.e. insert,delete and replace 
int EditDistR(string s1,string s2,int l1,int l2){
    if(l1==0) return l2;
    if(l2==0) return l1;
    if(s1[l1-1]==s2[l2-1]){
        return EditDistR(s1,s2,l1-1,l2-1);
    }
    else{
        return 1+min(EditDistR(s1,s2,l1,l2-1),min(EditDistR(s1,s2,l1-1,l2),EditDistR(s1,s2,l1-1,l2-1)));
    }
}

int EditDistT(string s1,string s2,int l1,int l2){
    int tab[l1+1][l2+1];
    forI(i,0,l2+1){
        tab[0][i]=i;
    }
    forI(j,0,l1+1){
        tab[j][0]=j;
    }
    forI(r,1,l1+1){
        forI(c,1,l2+1){
            if(s1[r-1]==s2[c-1]){
                tab[r][c]=tab[r-1][c-1];
            }
            else{
                tab[r][c]=1+min(tab[r-1][c],min(tab[r][c-1],tab[r-1][c-1]));
            }
        }   
    }
    return tab[l1][l2];
}
// -------------------------------------------------------------------------------------------------------
// Longest Increasing Subsequence(lis):
int LisT(vector<int> ip){
    int tab[ip.sz];
    tab[0]=1;
    forI(i,1,ip.sz){
        tab[i]=1;
        forI(j,0,i){
            if(ip[j]<ip[i]){
                tab[i]=max(tab[i],tab[j]+1);
            }
        }
    }
    return maxA(tab,tab+ip.sz);
}

int getceil(vector<int> v,int n){
    int l=0,r=v.sz-1;
    int latest=v.sz-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(n==v[mid]){
            return mid;
        }
        else if(n<v[mid]){
            latest=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return latest;
}

int LisBin(vector<int> ip){
    vector<int> tail;
    tail.pb(ip[0]);
    forI(i,1,ip.sz){
        if(ip[i]>tail.back()){
            tail.pb(ip[i]);
        }
        else{
            tail[getceil(tail,ip[i])]=ip[i];
        }
    }
    return tail.sz;
}
// Variation in LIS:
// 1)Minimum deletion to make an array sorted
// 2)Maximum sum increasing subsequenece
int MaxSumIS(vector<int> v){
    int msis[v.sz];
    msis[0]=v[0];
    forI(i,1,v.sz){
        msis[i]=v[i];
        forI(j,0,i){
            if(v[j]<v[i]){
                msis[i]=max(msis[i],msis[j]+v[i]);
            }
        }
    }
    return maxA(msis,msis+v.sz);
}
// 3)Longest bitonic sequece: i.e. which increase first and then decrease
int Lbs(vector<int> ip){
    int lis[ip.sz],lds[ip.sz];
    lis[0]=1;
    lds[ip.sz-1]=1;
    forI(i,1,ip.sz){
        lis[i]=1;
        forI(j,0,i){
            if(ip[j]<ip[i]){
                lis[i]=max(lis[i],lis[j]+1);
            }
        }
    }
    ford(i,ip.sz-2,0){
        lds[i]=1;
        ford(j,ip.sz-1,i+1){
            if(ip[j]<ip[i]){
                lds[i]=max(lds[i],lds[j]+1);
            }
        }
    }
    int mAx=Ninf;
    forI(i,0,ip.sz){
        mAx=max(mAx,lis[i]+lds[i]-1);
    }
    return mAx;
}
// 4)Building maximum bridges: without intersecting two bridges
bool mycmp(pair<int,int> p1,pair<int,int> p2){
    if(p1.ff==p2.ff) return (p1.ss<p2.ss);
    return p1.ff<p2.ff;
}

int BuildMaxBridge(vector<pair<int,int>> v){
    sort(all(v),mycmp);
    int tab[v.sz];
    tab[0]=1;
    forI(i,1,v.sz){
        tab[i]=1;
        forI(j,0,i){
            if(v[j].ss<v[i].ss){
                tab[i]=max(tab[i],tab[j]+1);
            }
        }
    }
    return maxA(tab,tab+v.sz);
}
// 5)Longest chain of pairs: same as activity selection of greedy
int lcp(vector<pair<int,int>> v){
    sort(all(v),mycmp);
    int tab[v.sz];
    tab[0]=1;
    forI(i,1,v.sz){
        tab[i]=1;
        forI(j,0,i){
            if(v[j].ss<v[i].ff){
                tab[i]=max(tab[i],tab[j]+1);
            }
        }
    }
    return maxA(tab,tab+v.sz);
}
// -------------------------------------------------------------------------------------------------------
// longest increasing AP
int solve(const vector<int> &A) {
    if(A.size()<2) return A.size();
    int tab[A.size()][A.size()];
    fill(tab[0], tab[0] + A.size() * A.size(), 0);
    multimap<int, int> m;
    int mAx=2;
    for(int i=2;i<A.size();i++){
        m.insert({A[i],i});
    }
    for(int i=1;i<A.size();i++){
        for(int j=0;j<i;j++){
            int diff=A[i]-A[j],fg=0,mIn=INT_MAX;
            for (auto itr = m.find(A[i]+diff); itr != m.end(); itr++){
                fg=1;
                if(itr->first==A[i]+diff){
                    mIn=min(mIn,itr->second);
                }
                else break;
            }
            if(fg==0){
                tab[j][i]=max(tab[j][i],2);
            }
            else{
                tab[j][i]=max(tab[j][i],2);
                tab[i][mIn]=tab[j][i]+1;
            }
            mAx=max(mAx,tab[j][i]);
        }
        if(i+1<A.size()){
            auto itr2 = m.find(A[i+1]);
            m.erase(itr2);
        }
    }
    return mAx;
}
// -------------------------------------------------------------------------------------------------------
// Maximum cut:
int MaxCutR(int length,int a,int b,int c){
    if(length<0) return -1;
    if(length==0) return 0;
    int res=max(MaxCutR(length-a,a,b,c),max(MaxCutR(length-b,a,b,c),MaxCutR(length-c,a,b,c)));
    if(res==-1) return res;
    else return res+1;
}

int MaxCutT(int length,int a,int b,int c){
    int tab[length+1];
    tab[0]=0;
    forI(i,1,length+1){
        tab[i]=-1;
        if(i-a>=0) tab[i]=max(tab[i],tab[i-a]);
        if(i-b>=0) tab[i]=max(tab[i],tab[i-b]);
        if(i-c>=0) tab[i]=max(tab[i],tab[i-c]);
        if(tab[i]!=-1) tab[i]++;
    }
    return tab[length];
}
// -------------------------------------------------------------------------------------------------------
// Minimum coin(minimum coin required of given denomination to pay amount of given sum)
int MinCoinR(int sum,vector<int> deno){
    if(sum==0) return 0;
    int res=Pinf;
    forI(i,0,deno.sz){
        if(deno[i]<=sum){
            int tmp=MinCoinR(sum-deno[i],deno);
            if(tmp!=Pinf) res=min(res,tmp+1);
        }
    }
    return res;
}

int MinCoinT(int sum,vector<int> deno){
    int tab[sum+1];
    tab[0]=0;
    forI(i,1,sum+1){
        tab[i]=Pinf;
        forI(j,0,deno.sz){
            if(deno[j]<=i){
                if(tab[i-deno[j]]!=Pinf){
                    tab[i]=min(tab[i],tab[i-deno[j]]+1);
                }
            }
        }
    }
    return tab[sum];
}
// -------------------------------------------------------------------------------------------------------
// Minimum jump to reach end
int getminjumpRmy(vector<int> v,int i){
    int step=v[i];
    if(i==v.sz-1) return 0;
    int res=Pinf;
    forI(j,1,step+1){
        if(v[i+j]<=v.sz-1){
            res=min(res,getminjumpRmy(v,i+j));
        }
    }
    if(res!=Pinf) return (res+1);
    return res;
}

int getminjumpR(vector<int> v,int n){
    if(n==1) return 0;
    int res=Pinf;
    forI(i,0,n-1){
        if(i+v[i]>=n-1){
            int tmp=getminjumpR(v,i+1);
            if(tmp!=Pinf){
                res=min(res,tmp+1);
            }
        }
    }
    return res;
}

int getminjumpT(vector<int> v,int n){
    int tab[n];
    tab[0]=0;
    forI(i,1,n){
        tab[i]=Pinf;
        forI(j,0,i){
            if(j+v[j]>=i){
                int tmp=tab[j];
                if(tmp!=Pinf){
                    tab[i]=min(tab[i],tab[j]+1);
                }
            }
        }
    }
    return tab[n-1];
}
// -------------------------------------------------------------------------------------------------------
// 0/1 knapsack Problem:
int knapsackR(vector<int> val,vector<int> w,int cap,int n){
    if(cap==0 || n==0){
        return 0;
    }
    if(w[n-1]>cap){
        return knapsackR(val,w,cap,n-1);
    }
    else{
        return max(knapsackR(val,w,cap,n-1),val[n-1]+knapsackR(val,w,cap-w[n-1],n-1));
    }
}
// above algo: when one item is allowed atmost once
// if includable: then 1) include and reduce
//                     2) do not include and reduce
// else do not include and reduce 
int knapsackT(vector<int> val,vector<int> w,int cap,int n){
    int tab[cap+1][n+1];
    forI(i,0,cap+1){
        tab[i][0]=0;
    }
    forI(i,0,n+1){
        tab[0][i]=0;
    }
    forI(r,1,cap+1){
        forI(c,1,n+1){
            if(w[c-1]>r){
                tab[r][c]=tab[r][c-1];
            }
            else{
                tab[r][c]=max(tab[r][c-1],val[c-1]+tab[r-w[c-1]][c-1]);
            }
        }
    }
    return tab[cap][n];
}
// -------------------------------------------------------------------------------------------------------
// below function can be used to calculate disjoint set or sack each of weight atmost k
int getMin(vector<int> &std,int k,vector<int> &sets,int n){
    if(n==0){
        return sets.size();
    }
    int mIn=INT_MAX;
    for(int i=0;i<sets.size();i++){
        if(sets[i]+std[n-1]<=k){
            sets[i]+=std[n-1];
            mIn=min(mIn,getMin(std,k,sets,n-1));
            sets[i]-=std[n-1];
        }
    }
    sets.push_back(std[n-1]);
    mIn=min(mIn,getMin(std,k,sets,n-1));
    sets.pop_back();
    return mIn;
}
// -------------------------------------------------------------------------------------------------------
// Optimal Game Startegy:
int sol1(int *arr,int i,int j,int sum){
    if(j==i+1) return max(arr[i],arr[j]);
    return max(sum-sol1(arr,i+1,j,sum-arr[i]),sum-sol1(arr,i,j-1,sum-arr[j]));
}
int mainsol1(int *arr,int n){
    int sum=0;
    forI(i,0,n) sum+=arr[i];
    return sol1(arr,0,n-1,sum);
}
// Golden Rule for Such question: maximize our score in our turn and minimize our score in opponent's turn
// solution 2 is clear but solution 1 is still a doubt
int sol2(int *arr,int i,int j){
    if(i+1==j) return max(arr[i],arr[j]);
    return max(arr[i]+min(sol2(arr,i+2,j),sol2(arr,i+1,j-1)),arr[j]+min(sol2(arr,i,j-2),sol2(arr,i+1,j-1)));
}

int sol2T(int *arr,int n){
    int tab[n][n];
    fil2D(tab,n,0);
    for(int i=1;i<n;i+=2){
        int c=i,r=0;
        while(c<n){
            if(r+1==c){
                tab[r][c]=max(arr[r],arr[c]);
            }
            else{
                tab[r][c]=max(arr[r]+min(tab[r+2][c],tab[r+1][c-1]),arr[c]+min(tab[r][c-2],tab[r+1][c-1]));
            }
            r++;
            c++;
        }
    }
    // forI(i,0,n){
    //     forI(j,0,n){
    //         cout<<tab[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return tab[0][n-1];
}
// -------------------------------------------------------------------------------------------------------
// Egg Droping Puzzle: finding threashold floor(minimum trials required to find from which floor egg breaks if it is dropped)
int MinEggDropTrial(int f,int e){
    if(f==0) return 0; // if we are on ground then we would not be able to do trial
    if(f==1) return 1; // if we have one floor then we will be able to do only one trial
    if(e==1) return f; // if only one egg is there then we need to try all f floors in worst case
    int res=Pinf;
    forI(i,1,f+1){
        res=min(res,max(MinEggDropTrial(i-1,e-1),MinEggDropTrial(f-i,e))+1);
    }
    return res;
}

int MinEggDropTrialT(int f,int e){
    int tab[f+1][e];
    forI(i,0,e){
        tab[0][i]=0;
        tab[1][i]=1;
    }
    forI(i,0,f+1){
        tab[i][0]=i;
    }
    forI(r,2,f+1){
        forI(c,1,e){
            tab[r][c]=Pinf;
            forI(i,1,r+1){
                tab[r][c]=min(tab[r][c],max(tab[i-1][c-1],tab[r-i][c])+1);
            }
        }
    }
    return tab[f][e-1];
}
//for more further time optimized code use Binary search technique with memoization 
int MinEggDropTrialM(vector<vector<int>> &memo,int f,int e){
    if(memo[f][e-1]==-1){
        int res=INT_MAX;
        if(f==0 || f==1) memo[f][e-1]=f;
        if(e==1) memo[f][e-1]=f;
        if(memo[f][e-1]==-1){
            int low=1,high=f;
            while(low<=high){
                int mid=(low+high)/2;
                int left=MinEggDropTrialM(memo,mid-1,e-1);
                int right=MinEggDropTrialM(memo,f-mid,e);
                res=min(res,max(left,right)+1);
                if(right>left) low=mid+1;
                else high=mid-1;
            }
            memo[f][e-1]=res;
        }
    }
    return memo[f][e-1];
}
// -------------------------------------------------------------------------------------------------------
int CountUniqueBST(int n){
    if(n==0 || n==1) return 1;
    int res=0;
    forI(i,1,n+1){
        res+=CountUniqueBST(i-1)*CountUniqueBST(n-i);
    }
    return res;
}

int CountUniqueBSTT(int n){ // It is also called Catalan Number res(n)=1/(n+1)*2nCn
    int tab[n+1];
    tab[0]=1;
    tab[1]=1;
    forI(i,2,n+1){
        tab[i]=0;
        forI(j,1,i+1){
            tab[i]+=tab[j-1]*tab[i-j];
        }
    }
    return tab[n];
}
// -------------------------------------------------------------------------------------------------------
// Maximum sum with no consecutive
int getMaxSum(int *arr,int n){
    if(n==1) return arr[0];
    if(n==2) return max(arr[0],arr[1]);
    return max(getMaxSum(arr,n-1),arr[n-1]+getMaxSum(arr,n-2));
}

int getMaxSumT(int *arr,int n){
    int tab[n];
    tab[0]=arr[0]; // it result of array with size 1 
    tab[1]=max(arr[0],arr[1]); // it result of array with size 2
    forI(i,2,n){ // it find for array of size 3 to n
        tab[i]=max(tab[i-1],arr[i]+tab[i-2]);
    }
    return tab[n-1];
}

int getMaxSumI(int *arr,int n){
    int a=arr[0];
    int b=max(arr[0],arr[1]);
    if(n==1) return a;
    if(n==2) return b;
    int i=n-2;
    while(i){
        int c=b;
        b=max(b,arr[n-i]+a);
        a=c;
        i--;
    }
    return b;
}
// -------------------------------------------------------------------------------------------------------
// find number of subset with given sum
int getNoOfSubset(int *arr,int n,int sum){
    if(n==0) return (sum==0)?1:0;
    int res=0;
    res+=getNoOfSubset(arr,n-1,sum);
    res+=getNoOfSubset(arr,n-1,sum-arr[n-1]);
    return res;
}

int getNoOfSubsetT(int *arr,int n,int sum){
    int tab[n+1][sum+1];
    forI(i,1,sum+1) tab[0][i]=0;
    forI(i,0,n+1) tab[i][0]=1;
    forI(r,1,n+1){
        forI(c,1,sum+1){
            if(c>=arr[r-1]){
                tab[r][c]=tab[r-1][c]+tab[r-1][c-arr[r-1]];
            }
            else{
                tab[r][c]=tab[r-1][c];
            }
        }
    }
    return tab[n][sum];
}
// -------------------------------------------------------------------------------------------------------
// Patterns of partisan DP:
// MCM
// Burst ballon
// Palindrome Partition
// entropy of combining
// Crayon colour 
// -------------------------------------------------------------------------------------------------------
// finding minimum number for multiplication required in matrix chain multiplication
int mChainR(int *arr,int i,int j){
    if(i+1==j) return 0;
    int res=Pinf;
    forI(k,i+1,j){
        res=min(res,mChainR(arr,i,k)+mChainR(arr,k,j)+(arr[i]*arr[k]*arr[j]));
    }
    return res;
}

int mChainT(int *arr,int n){
    int tab[n][n];
    forI(i,0,n-1){
        tab[i][i+1]=0;
    }
    for(int i=2;i<n;i++){
        int c=i,r=0;
        while(c<n){
            tab[r][c]=Pinf;
            forI(k,r+1,c){
                tab[r][c]=min(tab[r][c],tab[r][k]+tab[k][c]+(arr[r]*arr[k]*arr[c]));
            }
            r++;
            c++;
        }
    }
    return tab[0][n-1];
}
// -------------------------------------------------------------------------------------------------------
// There is a strange printer with the following two special properties:
// The printer can only print a sequence of the same character each time.
// At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
// Given a string s, return the minimum number of turns the printer needed to print it.
int getMin(vector<vector<int>> &dp,string s,int i,int e){
    if(i>e) return 0;
    if(dp[i][e]==-1){
        int j;
        for(j=i+1;j<=e;j++){
            if(s[j]!=s[i]) break; 
        }
        dp[i][e]=1+getMin(dp,s,j,e);
        for(int k=j;k<=e;k++){
            if(s[k]==s[i]){
                dp[i][e]=min(dp[i][e],getMin(dp,s,j,k-1)+getMin(dp,s,k,e));
            }
        }
    }
    return dp[i][e];
}
// -------------------------------------------------------------------------------------------------------
// Palindrome Partisan i.e. find minimum number of partisans required to make all partitions as palindrome
bool isPalindrome(string s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int PalindromePart(string s,int i,int j){
    if(isPalindrome(s,i,j)){
        return 0;
    }
    int res=Pinf;
    forI(k,i,j){
        res=min(res,PalindromePart(s,i,k)+PalindromePart(s,k+1,j)+1);
    }
    return res;
}

int PalindromePartT(string s,int n){
    int tab[n][n];
    bool ispal[n][n];
    forI(i,0,n){
        tab[i][i]=0;
        ispal[i][i]=true;
    }
    for(int i=1;i<n;i++){
        int c=i,r=0;
        while(c<n){
            // if(isPalindrome(s,r,c)){ // to optimize further by reducing is palindrome calls
            //     tab[r][c]=0;
            // }
            if(s[r]==s[c] && (ispal[r+1][c-1] || i==1)){ // it is imp concept of palindromic substrings
                tab[r][c]=0;
                ispal[r][c]=true;
            }
            else{
                tab[r][c]=Pinf;
                ispal[r][c]=false;
                forI(k,r,c){
                    tab[r][c]=min(tab[r][c],tab[r][k]+tab[k+1][c]+1);
                }
            }
            r++;
            c++;
        }
    }
    return tab[0][n-1];
}
// -------------------------------------------------------------------------------------------------------
int getMaxScore(vector<vector<int>> &mem,vector<int>& nums,int l,int r){
    if(mem[l][r]==-1){
        if(l>r) return 0;
        mem[l][r]=0;
        for(int i=l;i<=r;i++){
            mem[l][r]=max(mem[l][r],nums[l-1]*nums[i]*nums[r+1]+getMaxScore(mem,nums,l,i-1)+getMaxScore(mem,nums,i+1,r));
        }
    }
    return mem[l][r];
}
int maxCoins(vector<int>& nums) {
    vector<int> tmp;
    tmp.push_back(1);
    for(int i=0;i<nums.size();i++) tmp.push_back(nums[i]);
    tmp.push_back(1);
    vector<vector<int>> mem(tmp.size(),vector<int>(tmp.size(),-1));
    return getMaxScore(mem,tmp,1,nums.size());
}
// -------------------------------------------------------------------------------------------------------
// entropy of combining
// ll getMinEntropy(vector<vector<ll>> &dp,vector<ll> &ip,int l,int r){
//     if(l>r) return INT_MAX;
//     if(l==r) return 0;
//     if(dp[l][r]==-1){
//         dp[l][r]=LLONG_MAX;
//         ll tp=ip[r]-ip[l-1];
//         fori(i,l,r){
//             dp[l][r]=min(dp[l][r],tp+getMinEntropy(dp,ip,l,i)+getMinEntropy(dp,ip,i+1,r));
//         }
//     }
//     return dp[l][r];
// }
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin>>n;
//     vector<ll> ip(n+1);
//     ip[0]=0;
//     fori(i,0,n){
//         cin>>ip[i+1];
//         ip[i+1]+=ip[i];
//     }
//     vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
//     cout<<getMinEntropy(dp,ip,1,n)<<endl;
//     return 0;
// }
// -------------------------------------------------------------------------------------------------------
// find all combinations of substrings that forms palindrome
bool ispalin(string s,int l,int r){
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
    
void getpartisans(string s,int l,vector<string> v,vector<vector<string>> &op){
    if(l==s.length()){
        op.push_back(v);
        return;
    }
    for(int i=l;i<s.length();i++){
        if(ispalin(s,l,i)){
            v.push_back(s.substr(l,i-l+1));
            getpartisans(s,i+1,v,op);
            v.pop_back();
        }
    }
}
    
vector<vector<string>> partition(string s) {
    vector<vector<string>> op;
    getpartisans(s,0,{},op);
    return op;
}
// -------------------------------------------------------------------------------------------------------
// most Imp interview question: Allocate minimum pages(distribute evenly such that max of all such distribution is minimum) to k students  
int sumpage(int *arr,int i,int j){
    int sum=0;
    forI(l,i,j+1){
        sum+=arr[l];
    }
    return sum;
}

int MinPage(int *arr,int n,int k){
    if(n==1) return arr[0];
    if(k==1) return sumpage(arr,0,n-1);
    int res=Pinf;
    forI(i,1,n){
        res=min(res,max(MinPage(arr,i,k-1),sumpage(arr,i,n-1)));
    }
    return res;
}

int MinPageT(int *arr,int n,int k){
    int tab[k][n]; // here n=0 means there is only one book of arr[0] pages and k=0 means 1 student
    int sum[n]; // to optimize by using prefix sum technique for calculating sum
    forI(i,0,k){
        tab[i][0]=arr[0];
        sum[0]=arr[0];
    }  
    forI(i,1,n){
        tab[0][i]=tab[0][i-1]+arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    forI(r,1,k){
        forI(c,1,n){
            tab[r][c]=Pinf;
            forI(i,0,c){
                tab[r][c]=min(tab[r][c],max(tab[r-1][i],sum[c]-sum[i]));
            }
        }
    }
    return tab[k-1][n-1];
}
// -------------------------------------------------------------------------------------------------------
// GIven three prime numbers A, B and C and an integer D. You need to find the first(smallest) D integers which only have A, B, C or a combination of them as their prime factors.
vector<int> solve(int A, int B, int C, int D) {
    vector<int> tab(D+1);
    tab[0]=1;
    int i=0,j=0,k=0;
    for(int l=1;l<=D;l++){
        tab[l]=min(A*tab[i],min(B*tab[j],C*tab[k]));
        if(tab[l]==A*tab[i]) i++;
        if(tab[l]==B*tab[j]) j++;
        if(tab[l]==C*tab[k]) k++;
    }
    tab.erase(tab.begin());
    return tab;
}
// -------------------------------------------------------------------------------------------------------
// For: Questions like finding max sum path in such matrix, think how can I reach particular index satifying the problem statement  
// Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move
// 1) to the cell diagonally up towards the right 
// 2) to the right
// 3) to the cell diagonally down towards the right
// Find out maximum amount of gold which he can collect.
// Hint: For each index calculate what is the max value with which we can enter it from the 0th column. The highest value at the last column is the answer.
int maxGold(int n, int m, vector<vector<int>> M){
   for(int c=1;c<M[0].size();c++){
       for(int r=0;r<M.size();r++){
           int k=0;
           if(r-1!=-1) k=max(k,M[r-1][c-1]);
           k=max(k,M[r][c-1]);
           if(r+1!=M.size()) k=max(k,M[r+1][c-1]);
           M[r][c]+=k;
       }
   }
   int mAx=0;
   for(int i=0;i<M.size();i++){
       mAx=max(mAx,M[i][M[0].size()-1]);
   }
   return mAx;
}
// -------------------------------------------------------------------------------------------------------
// Maximum product subarray: uses idea of kandane by finding maximum and minimum product for each index
int maxProduct(vector<int>& nums) {
    int pro1=nums[0],pro2=nums[0];
    int res=nums[0];
    for(int i=1;i<nums.size();i++){
        int temp=pro1;
        pro1=max(nums[i],max(nums[i]*pro1,nums[i]*pro2));
        pro2=min(nums[i],min(nums[i]*temp,nums[i]*pro2));
        res=max(res,pro1);
    }
    return res;
}
// -------------------------------------------------------------------------------------------------------
// Nice and must look application of memoization (Minimum sum partition)
// Given an array arr of size n containing non-negative integers, 
// the task is to divide it into two sets S1 and S2 such that 
// the absolute difference between their sums is minimum and find the minimum difference
int getmin(int *arr,long long tsum,int n,long long sum,vector<vector<int>> &memo){
    if(memo[n][sum]==-1){
        if(n==0){
            memo[n][sum]=abs((tsum-sum)-sum);
        }
        else{
            memo[n][sum]=min(getmin(arr,tsum,n-1,sum-arr[n-1],memo),getmin(arr,tsum,n-1,sum,memo));
        }
    }
    return memo[n][sum];
}
  
int minDifference(int arr[], int n)  { 
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    vector<vector<int>> memo(n+1);
    for(int i=0;i<=n;i++){
        vector<int> tp(sum+1,-1);
        memo[i]=tp;
    }
    
    return getmin(arr,sum,n,sum,memo);
} 
// -------------------------------------------------------------------------------------------------------
// You are given N balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array arr. 
// You are asked to brust all the balloons. If you brust the ith  balloon,, you will get arr[ i - 1 ] * arr[ i ] * arr[ i + 1] coins. 
// If i - 1, or i + 1 goes out of bounds of the array, consider it as if there is a balloon with a 1 painted on it.
// Return the maximum coins you can collect by brusting the balloons wisely.

// int getvalue(vector<int> bal,int k){
    //     if(k!=-1) bal.erase(bal.begin()+k);
    //     if(bal.size()==1) return bal[0];
    //     int mAx=0;
    //     for(int i=0;i<bal.size();i++){
    //         if(i==0){
    //             mAx=max(mAx,bal[i]*bal[i+1]+getvalue(bal,i));
    //         }
    //         else if(i==bal.size()-1){
    //             mAx=max(mAx,bal[i]*bal[i-1]+getvalue(bal,i));
    //         }
    //         else{
    //             mAx=max(mAx,bal[i-1]*bal[i]*bal[i+1]+getvalue(bal,i));
    //         }
    //     }
    //     return mAx;
    // }

    int getvalueM(vector<int> &bal,vector<vector<int>> &memo,int i,int j){
        if(i<=j){
            if(memo[i][j]==-1){
                int l=(i-1>=0)?bal[i-1]:1;
                int r=(j+1<bal.size())?bal[j+1]:1;
                for(int k=i;k<=j;k++){
                    int left=getvalueM(bal,memo,i,k-1);
                    int right=getvalueM(bal,memo,k+1,j);
                    
                    int ans=left+right+(l*bal[k]*r);
                    memo[i][j]=max(memo[i][j],ans);
                }
            }
            return memo[i][j];
        }
        return 0;
    }


    int maxCoins(int N, vector<int> &arr) {
        // return getvalue(arr,-1);
        
        vector<vector<int>> memo(N,vector<int>(N,-1));
        return getvalueM(arr,memo,0,N-1);
    }
// -------------------------------------------------------------------------------------------------------
int main(){
    int n=5;
    cout<<FibR(n)<<endl;
    vector<int> memo(n+1,-1);
    cout<<FibM(n,memo)<<endl;
    // for(auto z:memo) cout<<z<<" ";
    // cout<<endl;
    cout<<FibT(n)<<endl;
    cout<<endl;
// -------------------------------------------------------------------------------------------------------
    cout<<LCSR("AXYZ","BAZ",4,3)<<endl;
    fill(memo2[0], memo2[0] + (l1+1)*(l2+1), -1);
    cout<<LCSM("AXYZ","BAZ",l1,l2)<<endl;
    // forI(i,0,l1+1){
    //     forI(j,0,l2+1){
    //         cout<<memo2[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<LCST("AXYZ","BAZ",l1,l2)<<endl;
    cout<<endl;
// -------------------------------------------------------------------------------------------------------
    int coin[4]={2,5,3,6};
    cout<<getcoinR(10,coin,4)<<endl;
    cout<<getcoinT(10,coin,4)<<endl;
    cout<<endl;
// -------------------------------------------------------------------------------------------------------
    cout<<EditDistR("SATURDAY","SUNDAY",8,6)<<endl;
    cout<<EditDistT("SATURDAY","SUNDAY",8,6)<<endl;
    cout<<endl;
// -------------------------------------------------------------------------------------------------------
    vector<int> ip={1,11,2,10,4,5,2,1};
    cout<<LisT(ip)<<endl;
    cout<<LisBin(ip)<<endl;
    cout<<MaxSumIS(ip)<<endl;
    cout<<Lbs(ip)<<endl;
    vector<pair<int,int>> v={{5,24},{30,60},{15,28},{27,40},{50,90}};
    cout<<BuildMaxBridge(v)<<endl;
    cout<<lcp(v)<<endl;
    cout<<endl;
// -------------------------------------------------------------------------------------------------------
    cout<<MaxCutR(5,1,2,3)<<endl;
    cout<<MaxCutT(5,1,2,3)<<endl;
    cout<<endl;
// -------------------------------------------------------------------------------------------------------
    vector<int> deno={3,4,1};
    cout<<MinCoinR(5,deno)<<endl;
    cout<<MinCoinT(5,deno)<<endl;
    cout<<endl;
// -------------------------------------------------------------------------------------------------------
    vector<int> v1={4,1,5,3,1,3,2,1,8};
    cout<<getminjumpRmy(v1,0)<<endl;
    cout<<getminjumpR(v1,v1.sz)<<endl;
    cout<<getminjumpT(v1,v1.sz)<<endl;
    cout<<endl;
// -------------------------------------------------------------------------------------------------------
    vector<int> val={10,40,30,50},w={5,4,6,3};
    cout<<knapsackR(val,w,10,w.sz)<<endl;
    cout<<knapsackT(val,w,10,w.sz)<<endl;
    cout<<endl;
// -------------------------------------------------------------------------------------------------------
    int v2[6]={20,5,4,6,8,3};
    cout<<mainsol1(v2,6)<<endl;
    cout<<sol2(v2,0,5)<<endl;
    cout<<sol2T(v2,6)<<endl;
    cout<<endl;
// -------------------------------------------------------------------------------------------------------
    cout<<MinEggDropTrial(5,1)<<endl;
    cout<<MinEggDropTrialT(5,1)<<endl;
    vector<vector<int>> memo3;
    vector<int> tp(1,-1);
    for(int i=0;i<=5;i++){
        memo3.push_back(tp);
    }
    cout<<MinEggDropTrialM(memo3,5,1)<<endl;
// -------------------------------------------------------------------------------------------------------
    cout<<CountUniqueBST(5)<<endl;
    cout<<CountUniqueBSTT(5)<<endl;
    cout<<endl;
// -------------------------------------------------------------------------------------------------------
    int v3[4]={10,5,15,20};
    cout<<getMaxSum(v3,4)<<endl;
    cout<<getMaxSumT(v3,4)<<endl;
    cout<<getMaxSumI(v3,4)<<endl;
    cout<<endl;
// -------------------------------------------------------------------------------------------------------
    int v4[3]={10,15,30};
    cout<<getNoOfSubset(v4,3,25)<<endl;
    cout<<getNoOfSubsetT(v4,3,25)<<endl;
    cout<<endl;
// -------------------------------------------------------------------------------------------------------
    int v5[4]={2,1,3,4};
    cout<<mChainR(v5,0,3)<<endl;
    cout<<mChainT(v5,4)<<endl;
    cout<<endl;
// -------------------------------------------------------------------------------------------------------
    string s="geek";
    cout<<PalindromePart(s,0,s.len-1)<<endl;
    cout<<PalindromePartT(s,s.len)<<endl;
    cout<<endl;
// -------------------------------------------------------------------------------------------------------
    int v6[8]={10,5,30,1,2,5,10,10};
    cout<<MinPageT(v6,8,3)<<endl;
    cout<<MinPage(v6,8,3)<<endl;
    return 0;
}