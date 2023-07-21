#include <bits/stdc++.h>

using namespace std;

// typedef $long name$ $short name$;
#define ll long long
#define forI(i, a, b) for (int i = a; i < b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define endl '\n'
#define dbug1(a) cout << a << endl
#define dbug2(a, b) cout << a << "-" << b << endl
#define dbug3(a, b, c) cout << a << "-" << b << "-" << c << endl
#define dbug4(a, b, c, d) cout << a << "-" << b << "-" << c << "-" << d << endl
#define fil1D(a, n, d) fill(a, a + n, d)
#define fil2D(a, n, d) fill(a[0], a[0] + n * n, d)
#define eve_chk(a) (a % 2 == 0)
#define ff first
#define ss second
#define desc greater<int>()
#define sz size()
#define all(v) v.begin(), v.end()
#define us unsigned
#define MAX 1e9 + 7
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
#define rdm(l, h) rand() % (h - l + 1) + l
#define len length()
// srand(time(NULL));
// O(1) < O(log n) < O(n) < O(n log n) < O(n^2) < O(2^n) < O(n!)

// vector<data_type> cont;
// unordered_set<data_type> cont;
// set<data_type> cont;
// unordered_map<key,value> cont;
// map<key,value> cont;
// stack<data_type> cont;
// queue<data_type> cont;
// deque<data_type> cont;
// priority_queue<data_type> cont; // it is max heap // it can be used as min heap by multiplying it with -1
// priority_queue<data_type,vector<data_type>,greater<data_type>> cont; // it is min heap 
// list<data_type> cont;

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

// struct DListNode{
//     int val;
//     DListNode *prev;
//     DListNode *next;
//     DListNode(int x){
//         val=x;
//         prev=NULL;
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

// struct bintrienode{
//     trienode* child[2];
//     bool isend;
//     trienode(){
//         child[0]=NULL;
//         child[1]=NULL;
//         isend=false;
//     }  
// };

// number of digit of an integer n in base b is floor(logb(x) + 1), here b=10(decimal) or 2(binary)

// int facI(int n){
//     int pro=1;
//     forI(i,2,n+1) pro*=i;
//     return pro;
// }

// int gcdR2(int a,int b){
//     if(b==0) return a;
//     else return gcdR2(b,a%b);
// }

// int lcm2(int a,int b){ // as a*b=lcm*gcd
//     return (a*b)/gcdR2(a,b);
// }

// IMP: sieve of erathosthenes technique i.e. remove all element that are divisible by i and greater than square of 
// i(where i varies from 5 to i*i<=n with increment of 6) to check wether number is prime or not if not divisible by 2 or 3 
// bool check_prime3(int n){  
//     if(n==1) return false;
//     if(n==2 || n==3) return true;
//     if(n%2==0 || n%3==0) return false;
//     for(int i=5;i*i<=n;i+=6) 
//         if(n%i==0 || n%(i+2)==0) return false; // here (n%i==0 || n%(i+2)==0) is done as in gap of 6 there is prime number at i and i+2 
//     return true;
// }

// void prime_fac3(int n){
//     while(n%2==0){
//         n/=2;
//         cout<<2<<" ";
//     }
//     while(n%3==0){
//         n/=3;
//         cout<<3<<" ";
//     }
//     int i;
//     for(i=5;i*i<=n;i+=6) 
//         if(check_prime3(i)) 
//             while(n%i==0){
//                 n/=i;
//                 cout<<i<<" ";
//             }
//             while(n%(i+2)==0){
//                 n/=(i+2);
//                 cout<<i+2<<" ";
//             }
//     if(n>3) cout<<n;
//     cout<<endl;
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

// long long binpow(long long a, long long b, long long m) { // optimized code for calculating a^b
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

// int nCr(int n, int r){ // nCr = (n-1)Cr + (n-1)C(r-1);
//         if(n<r) return 0;
//         int tab[r][n];
//         for(int i=0;i<n;i++){
//             tab[0][i]=(i+1)%(int)(1e9+7);
//         }
//         for(int i=0;i<r;i++){
//             tab[i][i]=1;
//         }
//         for(int i=1;i<r;i++){
//             for(int c=i+1;c<n;c++){
//                 tab[i][c]=(tab[i][c-1]+tab[i-1][c-1])%(int)(1e9+7);   
//             }
//         }
//         return tab[r-1][n-1]%(int)(1e9+7);
//         // code here
//     }

// nPr = (n-1)Pr + r*(n-1)P(r-1)

// & - bitwise and
// | - bitwise or
// ^ - bitwise xor
// ~ - bitwise not
// a<<b left shift makes number a=a*2^b 
// a>>b right shift makes number a=a/2^b
// a+b=(a|b)+(a&b)
// To vanish rightmost set bit do n=n&(n-1) or do n=n-n&(-n) where -n is 2s complement i.e. (~n+1)
// for leftmost set bit position do log2(n)+1

// int tab[256]; // here 256 is used as it calculate 32 bit number in pair of 8 bits
// void count_SetBitLT(){
//     tab[0]=0;
//     for(int i=1;i<256;i++){
//         tab[i]=(i&1)+tab[i>>1]; // use concept of tabulation method of DP and calculate the set bits in i 
//     }                           // by checking for set bit at lsb of i and adding it to value at i/2
// }

// void print_pow_set(string s){ //IMP for genrating subsets
//     int n=s.length();
//     int powsz=pow(2,n);
//     forI(c,0,powsz){
//         forI(j,0,n){
//             if((c&(1<<j))!=0)
//                 cout<<s[j];
//         }
//         cout<<endl;
//     }
// }

// for XOR of first N numbers
// find N%4 
// if(N%4==0) XOR = N
// if(N%4==1) XOR = 1
// if(N%4==2) XOR = N+1
// if(N%4==3) XOR = 0

// void generate_permute(string s,int i){
//     if(i==s.length()-1) cout<<s<<endl;
//     for(int j=i;j<s.length();j++){
//         swap(s[i],s[j]);
//         generate_permute(s,i+1);
//         swap(s[i],s[j]);
//     }
// }

// void Generate_Subsets(string ip,string s,int i){
//     if(i==s.length()) cout<<ip<<endl;
//     if(i<s.length()){
//         Generate_Subsets(ip,s,i+1);
//         Generate_Subsets(ip+s[i],s,i+1);
//     }
// }

// int max_sum_subarr_kadane(vector<int> v){
//     int maxend[v.sz],mAx=v[0];
//     maxend[0]=v[0];
//     forI(i,1,v.sz){
//         maxend[i]=max(maxend[i-1]+v[i],v[i]);
//         mAx=max(mAx,maxend[i]);
//     }
//     return mAx;
// }

// int binary_searchI(vector<int> v,int x){
//     int low=0,high=v.sz-1;
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(x<v[mid]){
//             high=mid-1;
//         }
//         else if(x>v[mid]){
//             low=mid+1;
//         }
//         else{
//             return mid;
//         }
//     }
//     return -1;
// }

// int binary_search2Arr(int *nums1, int *nums2,int n,int m){
//     int low=0,high=n;                                        // depends on question
//     while(low<=high){
//         int i1=(low+high)/2;                                 // depends on question
//         int max1=(i1==0)?INT_MIN:nums1[i1-1];
//         int min1=(i1==n)?INT_MAX:nums1[i1];        
//         int i2=(n+m+1)/2-i1;                                 // depends on question
//         int max2=(i2==0)?INT_MIN:nums2[i2-1];
//         int min2=(i2==m)?INT_MAX:nums2[i2];       
//         if(max2<=min1 && max1<=min2){
//              // binary search for two sorted arrays          // depends on question
//         }
//         else{
//             if(max1>min2){
//                 high=i1-1;
//             }
//             else low=i1+1;
//         }
//     }
//     return -1;
// }

// bool isfeasible(vector<int> v,int k,int ans){
//     int res=0;
//     int sum=0;
//     forI(i,0,v.sz){
//         if(sum+v[i]<=ans) sum+=v[i];
//         else{
//             sum=v[i];
//             res++;
//         }
//     }
//     if(res+1<=k) return true;
//     return false;
// }
// int minpageI(vector<int> v,int k){
//     int high=sum(v,0,v.sz-1);
//     int low=maxA(all(v));
//     int ret=0;
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(isfeasible(v,k,mid)){
//             ret=mid;
//             high=mid-1;
//         }
//         else low=mid+1;
//     }
//     return ret;
// }

// stable sort: bubble,insertion,merge
// unstable sort: selection,quick,heap 
// inplace: quicksort, heap, bubble, insertion, selection

// int partisanLomuto(vector<int> &v,int l,int h){ // here by default pivot is last element
//     int i=l-1;
//     // int piv=rdm(l,h); // for randomized pivot
//     // swap(v[piv],v[h]);
//     forI(j,l,h){
//         if(v[j]<v[h]){
//             i++;
//             swap(v[i],v[j]);
//         }
//     }
//     swap(v[i+1],v[h]);
//     return (i+1);
// }

// int partisanHoare(vector<int> &v,int l,int h){ // here by default pivot is first element
//     // int pv=rdm(l,h); // for randomized pivot
//     // swap(v[pv],v[l]);
//     int piv=v[l];
//     int i=l-1,j=h+1;
//     while(1){
//         do{
//             i++;
//         } while (v[i]<piv);
//         do{
//             j--;
//         } while (v[j]>piv);
//         if(i>=j) return j;
//         swap(v[i],v[j]);
//     }
// }

// void print_occurances_more_nbyk2(vector<int> v,int k){
//     unordered_map<int,int> m;
//     forI(i,0,v.sz){
//         if(m.find(v[i])!=m.end()) m[v[i]]++;
//         else if(m.size()<(k-1)) m[v[i]]++;
//         else{
//             for(auto z:m){
//                 z.second-=1;
//                 if(z.second==0) m.erase(z.first);
//             }
//         }
//     }
//     for(auto z:m){
//         int c=0;
//         forI(i,0,v.sz){
//             if(v[i]==z.first) c++;
//         }
//         if(c>v.sz/k) cout<<z.first<<" ";
//     }
//     cout<<endl;
// }

// bool ispalin(string s,int l,int r){
//     while(l<r){
//         if(s[l]!=s[r]) return false;
//         l++;
//         r--;
//     }
//     return true;
// }

// void RabinKarp(string s1,string s2){ // In this algo we first check hash value of substring at any index with hash value of pattern 
//     int h=1,d=5,q=61;                // if it matches than only we compare further
//     forI(i,1,s2.len){                // if there are n different character in s1 and s2 then d=n
//         h=(h*d)%q;                   // if p="abc" then hash value is 1*d^2+2*d^1+3*d^0
//     }                                // here %q is done to prevent higher values
//     int p=0,t=0;
//     forI(i,0,s2.len){
//         p=(p*d+s2[i])%q; // p is hash value of pattern
//         t=(t*d+s1[i])%q; // hash value of current window or substring
//     }
//     forI(i,0,s1.len-s2.len+1){
//         if(t==p){
//             int f=0;
//             forI(j,0,s2.len){
//                 if(s1[i+j]!=s2[j]){
//                     f=1;
//                     break;
//                 }
//             }
//             if(f==0){
//                 cout<<i<<" ";
//             }
//         }
//         if(i<s1.len-s2.len){
//             t=(d*(t-h*s1[i])+s1[i+s2.len])%q; // t(i+1)=d*(t(i)-s1[i]*d^(m-1))+s1[i+m]
//             if(t<0) t+=q;                     // here instead of calculating d^(m-1) always we calculated it earlier as h
//         }
//     }
// }

// imp and basic algo
// vector<int> construct_lpsArr(string s){ // used to store longest proper prefix which is also a suffix
//     vector<int> v;                      // proper prefix of string are one which is not equal to string
//     v.push_back(0);                     // for string "aba" proper prefix are "","a","ab" and suffix are "","a","ba"
//     int l=0,i=1;                        // so here longest proper prefix which is also a suffix is "a" and has length 1
//     while(i<s.len){                     // for string "ababa" lps array will look like
//         if(s[i]==s[l]){                 //            [00123] 
//             l++;                        // 0 for only string "a",
//             v.push_back(l);             // 0 for only string "ab",
//             i++;                        // 1 for only string "aba" as it has "a" as both proper prefix and suffix,
//         }                               // 2 for only string "abab" as it has "ab" as both proper prefix and suffix,
//         else{                           // 3 for only string "ababa" as it has "aba" as both proper prefix and suffix,
//             if(l==0){
//                 v.push_back(0);         // there is O(n^2) Naive solution for it in which we compare
//                 i++;   // all prefix from length 1->(m-1) to its corresponding suffix from m->2 if it is same then lps is that length
//             }                           // but this is O(n) solution as it uses
//             else{                       // previously calculated index value for current index
//                 l=v[l-1];
//             }
//         }
//     }
//     return v;
// }

// void kmp(string s1,string s2){                  // s1="ababcababaad" and s2="ababa" 
//     vector<int> v=construct_lpsArr(s2);         // so lps=[00123]
//     int i=0,j=0;
//     while(i<s1.len){
//         if(s2[j]==s1[i]){                       // ababcababaad
//             i++;                                // ababa              here i=4  and j=4 mismatch so j=lps[4-1]=lps[3]=2
//             j++;                                // ababcababaad
//         }                                       //   ababa            here i=4  and j=2 mismatch so j=lps[2-1]=lps[1]=0
//         if(j==s2.len){                          // ababcababaad
//             cout<<i-j<<" ";                     //     ababa          here i=4  and j=0 mismatch and j=0 so i++ i.e. i=5 and j=0
//             j=v[j-1];                           // ababcababaad
//         }                                       //      ababa         here i=10 and j=5 so matched index=10-5=5 and j=lps[5-1]=lps[4]=3 
//         else if(i<s1.len && s2[j]!=s1[i]){      // ababcababaad 
//             if(j==0) i++;                       //        ababa       here i=10 and j=3 mismatch so j=lps[3-1]=lps[2]=1
//             else j=v[j-1];                      // ababcababaad 
//         }                                       //          ababa     here i=10 and j=1 mismatch so j=lps[1-1]=lps[0]=0
//     }                                           // ababcababaad 
// }                                               //           ababa    here i=11 and j=1 mismatch so j=lps[1-1]=lps[0]=0
//                                                 // ababcababaad 
//                                                 //            ababa   here i=11 and j=0 mismatch and j=0 so i++ i.e. i=12 and j=0

// void printlistI(ListNode *head){
//     ListNode *n1;
//     n1=head;
//     while(n1){
//         cout<<n1->val<<" ";
//         n1=n1->next;
//     }
//     cout<<endl;
// }

// void middleoflist(ListNode *head){
//     if(head!=NULL){
//         ListNode *slow,*fast;
//         slow=head;
//         fast=head;
//         while(fast!=NULL && fast->next!=NULL){
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         cout<<slow->val<<endl;
//     }
// }

// void Nthnodefromlast2(ListNode *head,int n){ // used when there is need to count number of nodes for any operation from end
//     if(n>0){
//         ListNode *first=head,*second=head;
//         while(first){
//             if(n>0){
//                 first=first->next;
//                 n--;
//             }
//             else{
//                 first=first->next;
//                 second=second->next;
//             }
//         }
//         if(n==0) cout<<second->val<<endl;
//     }
// }

// ListNode *ReverseI(ListNode *head){
//     if(head!=NULL){
//         ListNode *curr=head;
//         ListNode *prev=NULL;
//         while(curr){
//             node *tmp=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=tmp;
//         }
//         return prev;
//     }
// }

// bool loopdetect3(node *head){
//     if(head==NULL || head->next==NULL) return false;
//     node *slow,*fast;
//     slow=head->next;
//     fast=head->next->next;
//     while(fast!=NULL && fast->next!=NULL && slow!=fast){
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     if(slow==fast) return true;
//     return false;
// }

// bool loopdetectANDremove(node *head){
//     if(head==NULL || head->next==NULL) return false;
//     node *slow,*fast;
//     slow=head->next;
//     fast=head->next->next;
//     while(fast!=NULL && fast->next!=NULL && slow!=fast){
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     if(slow==fast){
//         slow=head;
//         while(slow->next!=fast->next){
//             slow=slow->next;
//             fast=fast->next;
//         }
//         fast->next=NULL;
//         return true;
//     }
//     return false;
// }

// void reverseQR(queue<int> &q){
//     if(q.empty()) return;
//     int x=q.front();
//     q.pop();
//     reverseQR(q);
//     q.push(x);
// }

// int FirstCircTour2(vector<int> pet,vector<int> dist){
//     int curr_pet=0,start=0;
//     int prev_pet=0;
//     forI(i,0,pet.sz){
//         curr_pet+=(pet[i]-dist[i]);
//         if(curr_pet<0){
//             start=i+1;
//             prev_pet+=curr_pet;
//             curr_pet=0;
//         }
//     }
//     return ((curr_pet+prev_pet)>=0)?start+1:-1;
// }

// In heap complete binary tree is used where all levels are fully filled except last 
// left child = 2*i+1
// right child = 2*i+2
// parent = floor((i-1)/2)
// to sort array in increaseing order use max heap
// to sort array in decreaseing order use min heap

// void MINHEAPYFY(vector<int> &arr,int i,int size){
//     int lt=2*i+1,rt=2*i+2;
//     int small=i;
//     if(lt<size && arr[lt]<arr[small]) small=lt;
//     if(rt<size && arr[rt]<arr[small]) small=rt;
//     if(small!=i){
//         swap(arr[small],arr[i]);
//         MINHEAPYFY(arr,small,size);
//     }
// }

// void BuildHeap(vector<int> &v,int size){
//     ford(i,(size-2)/2,0){
//         MINHEAPYFY(v,i,v.sz);
//     }
// }

// General structure
// getOptimal(vector,int){
//     1)initialization of result
//     2)sorting/arrangment
//     3)while(i){
//         if(feasible) result+i;
//     }
//     4)return res;
// }

// void DFSrecur(vector<int> *lst,int src,bool *visited){
//     visited[src]=true;
//     cout<<src<<" ";
//     for(auto v:lst[src]){
//         if(visited[v]==false){
//             DFSrecur(lst,v,visited);
//         }
//     }
// }
// void DFSdiscont(vector<int> *lst,int ver){
//     bool visited[ver];
//     fil1D(visited,ver,false);
//     forI(i,0,ver){
//         if(visited[i]==false){
//             DFSrecur(lst,i,visited);
//         }
//     }
// }

// void BFS(vector<int> *lst,int src,bool *visited){
//     queue<int> q;
//     visited[src]=true;
//     q.push(src);
//     while(!q.empty()){
//         int u=q.front();
//         q.pop();
//         cout<<u<<" ";
//         for(auto v:lst[u]){
//             if(visited[v]==false){
//                 visited[v]=true;
//                 q.push(v);
//             }
//         }
//     }
// }
// void BFSdiscont(vector<int> *lst,int ver){
//     bool visited[ver];
//     fil1D(visited,ver,false);
//     forI(i,0,ver){
//         if(visited[i]==false){
//             BFS(lst,i,visited);
//         }
//     }
// }

// void TopologicalBFS(vector<int> *lst,int src,bool *visited,int *indeg){
//     queue<int> q;
//     visited[src]=true;
//     q.push(src);
//     while(!q.empty()){
//         int u=q.front();
//         q.pop();
//         cout<<u<<" ";
//         for(auto v:lst[u]){
//             indeg[v]--;
//             if(indeg[v]==0 && visited[v]==false){
//                 visited[v]=true;
//                 q.push(v);
//             }
//         }
//     }
// }
// void TopologicalSortKahnAlgo(vector<int> *lst,int ver){ // It is only for acyclic graphs
//     bool visited[ver];
//     fil1D(visited,ver,false);
//     int indeg[ver];
//     fil1D(indeg,ver,0);
//     forI(i,0,ver){
//         for(auto v:lst[i]){
//             indeg[v]++;
//         }
//     }
//     forI(i,0,ver){
//         if(indeg[i]==0 && visited[i]==false){
//             TopologicalBFS(lst,i,visited,indeg);
//         }
//     }
// }

// stack<int> stk;
// void DFSrecur2(vector<int> *lst,int src,bool *visited){
//     visited[src]=true;
//     for(auto v:lst[src]){
//         if(visited[v]==false){
//             DFSrecur2(lst,v,visited);
//         }
//     }
//     stk.push(src);
// }
// void TopologicalDFS(vector<int> *lst,int ver){ // this sort also give vertices in decreasing order of their finish time
//     bool visited[ver];
//     fil1D(visited,ver,false);
//     forI(i,0,ver){
//         if(visited[i]==false){
//             DFSrecur2(lst,i,visited);
//         }
//     }
//     while(!stk.empty()){
//         cout<<stk.top()<<" ";
//         stk.pop();
//     }
// }

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

// int FibR(int n){
//     if(n<2) return n; // f0=0,f1=1,f2=1,f3=2,f4=3,...
//     return FibR(n-1)+FibR(n-2);
// }
// int FibM(int n,vector<int> &memo){
//     if(memo[n]==-1){
//         int res;
//         if(n<2){
//             res=n;
//         }
//         else{
//             res=FibM(n-1,memo)+FibM(n-2,memo);
//         }
//         memo[n]=res;
//     }
//     return memo[n];
// }
// int FibT(int n){
//     int tab[n+1];
//     tab[0]=0;
//     tab[1]=1;
//     forI(i,2,n+1){
//         tab[i]=tab[i-1]+tab[i-2];
//     }
//     return tab[n];
// }

// int LCSR(string s1,string s2,int l1,int l2){
//     if(l1==0 || l2==0) return 0;
//     if(s1[l1-1]==s2[l2-1]){
//         return 1+LCSR(s1,s2,l1-1,l2-1);
//     }
//     else{
//         return max(LCSR(s1,s2,l1,l2-1),LCSR(s1,s2,l1-1,l2));
//     }
// }
// int LCST(string s1,string s2,int l1,int l2){
//     int tab[l1+1][l2+1];
//     forI(i,0,l1+1) tab[i][0]=0;
//     forI(i,0,l2+1) tab[0][i]=0;
//     forI(r,1,l1+1){
//         forI(c,1,l2+1){
//             if(s1[r-1]==s2[c-1]){
//                 tab[r][c]=1+tab[r-1][c-1];
//             }
//             else{
//                 tab[r][c]=max(tab[r-1][c],tab[r][c-1]);
//             }
//         }
//     }
//     // forI(i,0,l1+1){
//     //     forI(j,0,l2+1){
//     //         cout<<tab[i][j]<<" ";
//     //     }
//     //     cout<<endl;
//     // }
//     return tab[l1][l2];
// }
// Variation in LCS:
// 1)Minimum insertion and deletion to convert s1 to s2:insert(s2-lcs)+delete(s1-lcs)
// 2)Shortest Common Supersequence: i.e. find shortest third string which has s1 and s2 as their LCS: add remaining letter of both s1 & s2
//  in order in lcs
// 3)longest palindromic subsequence in s1: find lcs between s1 and reverse of s1
// 4)longest repeating subsequence in s1: find lcs of s1 wwith s1 but check that index of matching character are different
// 5)Optimized tabulation table: i.e. we use only two succesive row at a time to find lcs(reduce memory reqirement)
// 6)Printing all lcs: use tabulation table to traverse character by character and print them

// int getcoinR(int sum,int *coin,int n){
//     if(sum==0) return 1;
//     if(n==0) return 0;
//     int res;
//     res=getcoinR(sum,coin,n-1);
//     if(coin[n-1]<=sum){
//         res+=getcoinR(sum-coin[n-1],coin,n);
//     }
//     return res;
// }
// int getcoinTO(vector<int> &A, int B) { // spaced optimized
//     vector<int> v1(B+1,0);
//     for(int c=1;c<=A.size();c++){
//         vector<int> v2(B+1,0);
//         v2[0]=1;
//         for(int r=1;r<=B;r++){
//             v2[r]=0;
//             if(A[c-1]<=r){
//                 v2[r]+=(v2[r-A[c-1]])%1000007;
//             }
//             v2[r]+=v1[r]%1000007;
//         }
//         v1=v2;
//     }
//     return v1[B]%1000007;
// }
// int knapsackR(vector<int> val,vector<int> w,int cap,int n){
//     if(cap==0 || n==0){
//         return 0;
//     }
//     if(w[n-1]>cap){
//         return knapsackR(val,w,cap,n-1);
//     }
//     else{
//         return max(knapsackR(val,w,cap,n-1),val[n-1]+knapsackR(val,w,cap-w[n-1],n-1));
//     }
// }

// int LisT(vector<int> ip){
//     int tab[ip.sz];
//     tab[0]=1;
//     forI(i,1,ip.sz){
//         tab[i]=1;
//         forI(j,0,i){
//             if(ip[j]<ip[i]){
//                 tab[i]=max(tab[i],tab[j]+1);
//             }
//         }
//     }
//     return maxA(tab,tab+ip.sz);
// }
// int getceil(vector<int> v,int n){
//     int l=0,r=v.sz-1;
//     int latest=v.sz-1;
//     while(l<=r){
//         int mid=(l+r)/2;
//         if(n==v[mid]){
//             return mid;
//         }
//         else if(n<v[mid]){
//             latest=mid;
//             r=mid-1;
//         }
//         else{
//             l=mid+1;
//         }
//     }
//     return latest;
// }
// int LisBin(vector<int> ip){
//     vector<int> tail;
//     tail.pb(ip[0]);
//     forI(i,1,ip.sz){
//         if(ip[i]>tail.back()){
//             tail.pb(ip[i]);
//         }
//         else{
//             tail[getceil(tail,ip[i])]=ip[i];
//         }
//     }
//     return tail.sz;
// }
// Variation in LIS:
// 1)Minimum deletion to make an array sorted
// 2)Maximum sum increasing subsequenece
// 3)Longest bitonic sequece: i.e. which increase first and then decrease
// 4)Building maximum bridges: without intersecting two bridges
// 5)Longest chain of pairs: same as activity selection of greedy

// int MaxCutR(int length,int a,int b,int c){
//     if(length<0) return -1;
//     if(length==0) return 0;
//     int res=max(MaxCutR(length-a,a,b,c),max(MaxCutR(length-b,a,b,c),MaxCutR(length-c,a,b,c)));
//     if(res==-1) return res;
//     else return res+1;
// }
// int MaxCutT(int length,int a,int b,int c){
//     int tab[length+1];
//     tab[0]=0;
//     forI(i,1,length+1){
//         tab[i]=-1;
//         if(i-a>=0) tab[i]=max(tab[i],tab[i-a]);
//         if(i-b>=0) tab[i]=max(tab[i],tab[i-b]);
//         if(i-c>=0) tab[i]=max(tab[i],tab[i-c]);
//         if(tab[i]!=-1) tab[i]++;
//     }
//     return tab[length];
// }

// int MinCoinR(int sum,vector<int> deno){
//     if(sum==0) return 0;
//     int res=Pinf;
//     forI(i,0,deno.sz){
//         if(deno[i]<=sum){
//             int tmp=MinCoinR(sum-deno[i],deno);
//             if(tmp!=Pinf) res=min(res,tmp+1);
//         }
//     }
//     return res;
// }
// int MinCoinT(int sum,vector<int> deno){
//     int tab[sum+1];
//     tab[0]=0;
//     forI(i,1,sum+1){
//         tab[i]=Pinf;
//         forI(j,0,deno.sz){
//             if(deno[j]<=i){
//                 if(tab[i-deno[j]]!=Pinf){
//                     tab[i]=min(tab[i],tab[i-deno[j]]+1);
//                 }
//             }
//         }
//     }
//     return tab[sum];
// }
// int getminjumpR(vector<int> v,int n){
//     if(n==1) return 0;
//     int res=Pinf;
//     forI(i,0,n-1){
//         if(i+v[i]>=n-1){
//             int tmp=getminjumpR(v,i+1);
//             if(tmp!=Pinf){
//                 res=min(res,tmp+1);
//             }
//         }
//     }
//     return res;
// }

// Optimal Game Startegy:
// int sol2(int *arr,int i,int j){
//     if(i+1==j) return max(arr[i],arr[j]);
//     return max(arr[i]+min(sol2(arr,i+2,j),sol2(arr,i+1,j-1)),arr[j]+min(sol2(arr,i,j-2),sol2(arr,i+1,j-1)));
// }

// Egg Droping Puzzle: finding threashold floor(minimum trials required to find from which floor egg breaks if it is dropped)
// int MinEggDropTrial(int f,int e){
//     if(f==0) return 0; // if we are on ground then we would not be able to do trial
//     if(f==1) return 1; // if we have one floor then we will be able to do only one trial
//     if(e==1) return f; // if only one egg is there then we need to try all f floors in worst case
//     int res=Pinf;
//     forI(i,1,f+1){
//         res=min(res,max(MinEggDropTrial(i-1,e-1),MinEggDropTrial(f-i,e))+1);
//     }
//     return res;
// }

// CountUniqueBST:It is also called Catalan Number res(n)=1/(n+1)*2nCn
// Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.
// The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
// 1)Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
// 2)Count the number of possible Binary Search Trees with n keys
// Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
// 3)Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.

// int mChainR(int *arr,int i,int j){
//     if(i+1==j) return 0;
//     int res=Pinf;
//     forI(k,i+1,j){
//         res=min(res,mChainR(arr,i,k)+mChainR(arr,k,j)+(arr[i]*arr[k]*arr[j]));
//     }
//     return res;
// }

// bool isPalindrome(string s,int i,int j){
//     while(i<j){
//         if(s[i]!=s[j]){
//             return false;
//         }
//         i++;
//         j--;
//     }
//     return true;
// }
// int PalindromePart(string s,int i,int j){
//     if(isPalindrome(s,i,j)){
//         return 0;
//     }
//     int res=Pinf;
//     forI(k,i,j){
//         res=min(res,PalindromePart(s,i,k)+PalindromePart(s,k+1,j)+1);
//     }
//     return res;
// }

// int sumpage(int *arr,int i,int j){
//     int sum=0;
//     forI(l,i,j+1){
//         sum+=arr[l];
//     }
//     return sum;
// }
// int MinPage(int *arr,int n,int k){
//     if(n==1) return arr[0];
//     if(k==1) return sumpage(arr,0,n-1);
//     int res=Pinf;
//     forI(i,1,n){
//         res=min(res,max(MinPage(arr,i,k-1),sumpage(arr,i,n-1)));
//     }
//     return res;
// }

// nice question of 1D dp
// GIven three prime numbers A, B and C and an integer D. You need to find the first(smallest) D integers which only have A, B, C or a combination of them as their prime factors.
// vector<int> solve(int A, int B, int C, int D) {
//     vector<int> tab(D+1);
//     tab[0]=1;
//     int i=0,j=0,k=0;
//     for(int l=1;l<=D;l++){
//         tab[l]=min(A*tab[i],min(B*tab[j],C*tab[k]));
//         if(tab[l]==A*tab[i]) i++;
//         if(tab[l]==B*tab[j]) j++;
//         if(tab[l]==C*tab[k]) k++;
//     }
//     tab.erase(tab.begin());
//     return tab;
// }

// void Inorder(node *root){
//     if(root==NULL) return;
//     Inorder(root->left);
//     cout<<root->val<<" ";
//     Inorder(root->right);
// }

// void InorderI(TreeNode* root){
//     stack<TreeNode*> stk;
//     do{
//         if(root->left){
//             stk.push(root);
//             root=root->left;
//         }
//         else{
//             cout<<root->val<<" ";
//             if(root->right){
//                 root=root->right;
//             }
//             else{
//                 while(!stk.empty() && !stk.top()->right){
//                     cout<<stk.top()->val<<" ";
//                     stk.pop();
//                 }
//                 if(!stk.empty()){
//                     cout<<stk.top()->val<<" ";
//                     root=stk.top()->right;
//                     stk.pop();
//                 }
//                 else break;
//             }
//         }
//     }while(1);
// }

// void Preorder(node *root){
//     if(root==NULL) return;
//     cout<<root->val<<" ";
//     Inorder(root->left);
//     Inorder(root->right);
// }

// void PreorderI(TreeNode* root){
//     stack<TreeNode*> stk;
//     do{
//         cout<<root->val<<" ";
//         if(root->left){
//             if(root->right){
//                 stk.push(root->right);
//             }
//             root=root->left;
//         }
//         else{
//             if(root->right) root=root->right;
//             else{
//                 if(!stk.empty()){
//                     root=stk.top();
//                     stk.pop();
//                 }
//                 else break;
//             }
//         }
//     }while(1);
// }

// void Postorder(node *root){
//     if(root==NULL) return;
//     Inorder(root->left);
//     Inorder(root->right);
//     cout<<root->val<<" ";
// }

// int TreeHeight(node *root){
//     if(root==NULL) return 0;
//     else{
//         return max(TreeHeight(root->left),TreeHeight(root->right))+1;
//     }
// }

// void levelorderwithnewline2(node *root){
//     if(root==NULL) return; 
//     queue<node*> q;
//     q.push(root);
//     while(!q.empty()){
//         int n=q.size();
//         forI(i,0,n){
//             node *tmp=q.front();
//             q.pop();
//             cout<<tmp->val<<" ";
//             if(tmp->left) q.push(tmp->left);
//             if(tmp->right) q.push(tmp->right);
//         }
//         cout<<'\n';
//     }
// }

// void VerticalSum(node *root,int x,map<int,int> &m){
//     if(root==NULL) return;
//     VerticalSum(root->left,x-1,m);
//     m[x]+=root->val;
//     VerticalSum(root->right,x+1,m);
// }

// void VerticalTraversal(node *root,map<int,vector<int>> &m){
//     queue<pair<node*,int>> q;
//     q.push({root,0});
//     while(!q.empty()){
//         pair<node*,int> p;
//         p=q.front();
//         q.pop();
//         if(p.first->left) q.push({p.first->left,p.second-1});
//         if(p.first->right) q.push({p.first->right,p.second+1});
//         m[p.second].pb(p.first->val);
//     }
// }

// Fastest Implementation of LRU Cache

// struct DLL{
//     int ky;
//     int val;
//     DLL* prev;
//     DLL* next;
//     DLL(int x,int y){
//         ky=x;
//         val=y;
//         prev=NULL;
//         next=NULL;
//     }
// };
// class LRUCache {
//     unordered_map<int,DLL*> mp;
//     DLL* head;
//     DLL* lst;
//     int sz;
//     int cap;
// public:
//     LRUCache(int capacity) {
//         mp=unordered_map<int,DLL*>();
//         head=new DLL(-1,-1);
//         lst=new DLL(-1,-1);
//         head->next=lst;
//         lst->prev=head;
//         sz=0;
//         cap=capacity;
//     }
//     int get(int key) {
//         if(mp.find(key)!=mp.end()){
//             DLL* tmp=mp[key];
//             tmp->prev->next=tmp->next;
//             tmp->next->prev=tmp->prev;
//             tmp->next=head->next;
//             tmp->prev=head;
//             head->next->prev=tmp;
//             head->next=tmp;
//             return tmp->val;
//         }
//         return -1;
//     }  
//     void put(int key, int value) {
//         if(sz<cap){
//             if(mp.find(key)==mp.end()){
//                 DLL* tmp=new DLL(key,value);
//                 mp[key]=tmp;
//                 tmp->next=head->next;
//                 tmp->prev=head;
//                 head->next->prev=tmp;
//                 head->next=tmp;
//                 sz++;
//             }
//             else{
//                 DLL* tmp=mp[key];
//                 tmp->prev->next=tmp->next;
//                 tmp->next->prev=tmp->prev;
//                 tmp->next=head->next;
//                 tmp->prev=head;
//                 head->next->prev=tmp;
//                 head->next=tmp;
//                 tmp->val=value;
//             }
//         }
//         else{
//             if(mp.find(key)!=mp.end()){
//                 DLL* tmp=mp[key];
//                 tmp->prev->next=tmp->next;
//                 tmp->next->prev=tmp->prev;
//                 tmp->next=head->next;
//                 tmp->prev=head;
//                 head->next->prev=tmp;
//                 head->next=tmp;
//                 tmp->val=value;
//             }
//             else{
//                 DLL* tmp=new DLL(key,value);
//                 tmp->next=head->next;
//                 tmp->prev=head;
//                 mp[key]=tmp;
//                 head->next->prev=tmp;
//                 head->next=tmp;
//                 DLL* tp=lst->prev;
//                 tp->prev->next=lst;
//                 lst->prev=tp->prev;
//                 mp.erase(tp->ky);
//             }
//         }
//     }
// };

// fastest LFU implementation

// struct DLL{
//     int ky;
//     int val;
//     int cnt;
//     DLL* prev;
//     DLL* next;
//     DLL(int x,int y){
//         ky=x;
//         val=y;
//         prev=NULL;
//         next=NULL;
//         cnt=1;
//     }
// };
// struct List{
//     int siz;
//     DLL* head;
//     DLL* lst;
//     List(){
//         head=new DLL(-1,-1);
//         lst=new DLL(-1,-1);
//         head->next=lst;
//         lst->prev=head;
//         siz=0;
//     }
//     void addnode(DLL* tmp){
//         tmp->next=head->next;
//         tmp->prev=head;
//         head->next->prev=tmp;
//         head->next=tmp;
//         siz++;
//     }
//     void removenode(DLL* tp){
//         tp->prev->next=tp->next;
//         tp->next->prev=tp->prev;
//         siz--;
//     }
// };
// class LFUCache {
//     map<int,List*> freq;
//     unordered_map<int,DLL*> mp;
//     int cap;
//     int lf;
//     int sz;
// public:
//     LFUCache(int capacity) {
//         cap=capacity;
//         lf=0;
//         sz=0;
//         mp=unordered_map<int,DLL*>();
//         freq=map<int,List*>();
//     }
//     void updatefreqList(DLL* node){
//         mp.erase(node->ky);
//         freq[node->cnt]->removenode(node);
//         if(node->cnt==lf && freq[node->cnt]->siz==0){
//             lf++;
//         }
//         List* nexthighfreq;
//         node->cnt+=1;
//         if(freq.find(node->cnt)!=freq.end()){
//             nexthighfreq=freq[node->cnt];
//             nexthighfreq->addnode(node);
//         }
//         else{
//             nexthighfreq=new List();
//             nexthighfreq->addnode(node);
//             freq[node->cnt]=nexthighfreq;
//         }
//         mp[node->ky]=node;
//     }
//     int get(int key) {
//         if(mp.find(key)!=mp.end()){
//             DLL* node=mp[key];
//             int value=node->val;
//             updatefreqList(node);
//             return value;
//         }
//         return -1;
//     }
//     void put(int key, int value) {
//         if(cap==0) return;
//         if(mp.find(key)!=mp.end()){
//             DLL* tp=mp[key];
//             tp->val=value;
//             updatefreqList(tp);
//         }
//         else{
//             if(sz<cap){
//                 sz++;
//                 lf=1;
//                 List* newList;
//                 DLL* tmp=new DLL(key,value);
//                 if(freq.find(lf)!=freq.end()){
//                     newList=freq[lf];
//                 }
//                 else{
//                     newList=new List();
//                     freq[lf]=newList;
//                 }
//                 newList->addnode(tmp);
//                 mp[key]=tmp;
//             }
//             else{
//                 List* min_List=freq[lf];
//                 mp.erase(min_List->lst->prev->ky);
//                 freq[lf]->removenode(min_List->lst->prev);
//                 lf=1;
//                 List* newList;
//                 DLL* tmp=new DLL(key,value);
//                 if(freq.find(lf)!=freq.end()){
//                     newList=freq[lf];
//                 }
//                 else{
//                     newList=new List();
//                     freq[lf]=newList;
//                 }
//                 newList->addnode(tmp);
//                 mp[key]=tmp;
//             }
//         }
//     }
// };

// int dfs(vector<vector<int>> &ip,vector<int> &vst,int src,int mAx,int &ans){
//   vst[src]=1;
//   int val=0;
//   for(auto v:ip[src]){
//     if(vst[v]==0){
//       val+=dfs(ip,vst,v,mAx,ans);
//     }
//   }
//   if(val==0) return mAx;
//   if(val<mAx) return 0;
//   ans++;
//   return 1;
// }

// int main() {
//   int n,m;
//   cin>>n>>m;
//   vector<vector<int>> ip(n);
//   int mAx=1;
//   for(int i=0;i<m;i++){
//     int u,v;
//     cin>>u>>v;
//     ip[u-1].push_back(v-1);
//     int k=ip[u-1].size();
//     mAx=max(mAx,k);
//     ip[v-1].push_back(u-1);
//     k=ip[v-1].size();
//     mAx=max(mAx,k);
//   }
//   vector<int> vst(n,0);
//   int ans=0;
//   for(int i=0;i<n;i++){
//     if(vst[i]==0){
//       if(dfs(ip,vst,i,mAx,ans)>ip[i].size()) ans++;
//     }
//   }
//   cout<<ans;
//   return 0;
// }