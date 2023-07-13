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
// srand(time(NULL));

struct chaining{ // (closed hashing) means closed in sense of space as it handle collision by using chaining technique
    int bkt;
    list<int> *tab;
    chaining(int n){
        bkt=n;
        tab=new list<int>[n];
    }
    int hash(int key){
        return key%bkt;
    }
    void insertkey(int key){
        tab[hash(key)].push_back(key);
    }
    bool searchkey(int key){
        for(auto it=tab[hash(key)].begin();it!=tab[hash(key)].end();it++){
            if(*it==key) return true;
        }
        return false;
    }
    void removekey(int key){
        tab[hash(key)].remove(key);
    }
    void Printtab(){
        forI(i,0,bkt){
            cout<<i<<": ";
            for(auto z:tab[i]) cout<<z<<" ";
            cout<<endl;
        }
    }
};

struct openhashing{// (open hashing) means open in sense of space as it handle collision by storing in nearest empty site which increase space
    int siz;
    int cap;
    int *arr;
    openhashing(int x){
        cap=x;
        siz=0;
        forI(i,0,cap) arr[i]=-1;
    }
    int hash(int key){
        return key%cap;
    }
    bool insertkey(int key){
        if(siz==cap) return false;
        else{
            int k=0;
            int i=hash(key);
            while(arr[hash(i+k)]!=-1 && arr[hash(i+k)]!=-2 && arr[hash(i+k)]!=key) k++;
            if(arr[hash(i+k)]==key) return false;
            else{
                arr[hash(i+k)]=key;
                siz++;
                return true;
            }
        }
    }
    bool searchkey(int key){
        if(siz==0) return false;
        else{
            int k=0;
            int i=hash(key);
            while(arr[hash(i+k)]!=-1){
                if(arr[hash(i+k)]==key) return true;
                k++;
                if(hash(i+k)==i) return false;
            }
            return false;
        }
    }
    bool removekey(int key){
        if(siz==0) return false;
        else{
            int k=0;
            int i=hash(key);
            while(arr[hash(i+k)]!=-1){
                if(arr[hash(i+k)]==key){
                    arr[hash(i+k)]=-2;
                    siz--;
                    return true;
                }
                k++;
                if(hash(i+k)==i) return false;
            }
            return false;
        }
    }
    void Printtab(){
        forI(i,0,cap){
            if(arr[i]!=-1 && arr[i]!=-2){
                cout<<arr[i]<<endl;
            }
        }
    }
};

int CountDistinct(vector<int> v){
    unordered_set<int> s(all(v));
    return s.size();
}

void FrequencyArrelements(vector<int> v){
    unordered_map<int,int> m;
    forI(i,0,v.sz) m[v[i]]++;
    for(auto z:m){
        cout<<z.ff<<":"<<z.ss<<endl;
    }
}

int InsersectArr(vector<int> v1,vector<int> v2){
    unordered_set<int> s(all(v1));
    int c=0;
    forI(i,0,v2.sz){
        if(s.find(v2[i])!=s.end()){
            cout<<v2[i]<<" ";
            c++;
            s.erase(v2[i]);
        }
    }
    cout<<endl;
    return c;
}

int UnionArr(vector<int> v1,vector<int> v2){
    unordered_set<int> s;
    forI(i,0,v1.sz) s.insert(v1[i]);
    forI(i,0,v2.sz) s.insert(v2[i]);
    for(auto z:s) cout<<z<<" ";
    cout<<endl;
    return s.size();
}

bool pair_with_giv_sum(vector<int> v,int sum){
    unordered_set<int> s;
    forI(i,0,v.sz){
        if(s.find(sum-v[i])!=s.end()){
            cout<<*(s.find(sum-v[i]))<<"+"<<v[i]<<"="<<sum<<endl;
            return true;
        }
        else s.insert(v[i]);
    }
    return false;
}

bool max_subarr_zerosum(vector<int> v){ // sum till v[i] + 0 = sum till v[j] where j>i 
    unordered_set<int> s;               // hence this give us subarray from j to index i with sum = 0;
    int add=0;
    forI(i,0,v.sz){
        add+=v[i];
        if(add==0) return true;
        else if(s.find(add-0)!=s.end()) return true;
        else s.insert(add);
    }
    return false;
}

int solve(vector<int> &A, int B) { // Count the number of subarrays with given xor K, nice variation in zerosum due to property of Xor
    unordered_map<int,int> mp;
    int pre=0;
    long long c=0;
    for(int i=0;i<A.size();i++){
        pre=(pre^A[i]);
        if(pre==B){
            c++;
        }
        if(mp.find(pre^B)!=mp.end()){
            c+=mp[pre^B];
        }
        mp[pre]++;
    }
    return c;
}

bool max_subarr_givsum(vector<int> v,int sum){
    unordered_set<int> s;
    int add=0;
    forI(i,0,v.sz){
        add+=v[i];
        if(add==sum) return true;
        else if(s.find(add-sum)!=s.end()) return true;
        else s.insert(add);
    }
    return false;
}

int long_subarr_givsum(vector<int> v,int sum){
    unordered_map<int,int> m;
    int add=0,mAx=0;
    forI(i,0,v.sz){
        add+=v[i];
        if(add==sum) mAx=max(mAx,i+1);
        if(m.find(add)==m.end()) m[add]=i;
        if(m.find(add-sum)!=m.end()) mAx=max(mAx,i-m[add-sum]);
    }
    return mAx;
}

int long_subarr_eq0AND1(vector<int> v){
    unordered_map<int,int> m;
    forI(i,0,v.sz){
        if(v[i]==0) v[i]=-1; // nice technique to convert this question into max_subarr_zerosum
    }
    int add=0,mAx=0;
    forI(i,0,v.sz){
        add+=v[i];
        if(add==0) mAx=max(mAx,i+1);
        if(m.find(add)==m.end()) m[add]=i;
        else mAx=max(mAx,i-m[add]);
    }
    return mAx;
}

int long_spanof_eq0AND1(vector<int> v1,vector<int> v2){ // size of v1 and v2 needs to be same
    vector<int> v;
    forI(i,0,v1.sz) v.push_back(v1[i]-v2[i]); // nice trick to convert this question into max_subarr_zerosum
    unordered_map<int,int> m;
    int add=0,mAx=0;
    forI(i,0,v.sz){
        add+=v[i];
        if(add==0) mAx=max(mAx,i+1);
        if(m.find(add)==m.end()) m[add]=i;
        else mAx=max(mAx,i-m[add]);
    }
    return mAx;
}

int long_consecutive_subseq(vector<int> v){
    unordered_set<int> s(all(v));
    int mAx=1;
    forI(i,0,v.sz){
        if(s.find(v[i]-1)==s.end()){                    // finding the starting element
            int c=1;
            while(s.find(v[i]+c)!=s.end()){
                c++;
            }
            mAx=max(mAx,c);
        }
    }
    return mAx;
}

void distinct_in_Window(vector<int> v,int k){
    unordered_map<int,int> m;
    forI(i,0,k){
        m[v[i]]++;
    }
    int j=k;
    while(j<v.sz){
        cout<<m.size()<<" ";
        m[v[j-k]]--;
        if(m[v[j-k]]==0) m.erase(v[j-k]);
        m[v[j]]++;
        j++;
    }
    cout<<m.size()<<endl;
}

void freq_of_most_frequent_in_Window(vector<int> arr,int k){
    unordered_map<int,int> mp;
    multiset<int> s; 
    //Reason for using the multiset 
    //as its underlying implementation is binary search tree
    //since we are storing the frequencies of elements
    //--s.end() it gives the greater element which is already present in the tree
    // O(1)-->complexity and for insert and find O(logn)
    for(int i=0;i<arr.size();i++){
      if(mp[arr[i]]!=0){
        s.erase(s.find(mp[arr[i]]));
      }
      mp[arr[i]]++;
      s.insert(mp[arr[i]]);
      if(i>=k){
        s.erase(s.find(mp[arr[i-k]]));
        mp[arr[i-k]]--;
        if(mp[arr[i-k]]!=0){
          s.insert(mp[arr[i-k]]);
        }
      }
      if(i>=k-1){
        cout<<*(--s.end())<<" ";
      }
    }
}

void print_occurances_more_nbyk1(vector<int> v,int k){
    unordered_map<int,int> m;
    forI(i,0,v.sz) m[v[i]]++;
    for(auto z:m){
        if(z.second>v.sz/k) cout<<z.first<<" ";
    }
    cout<<endl;
}

void print_occurances_more_nbyk2(vector<int> v,int k){ // imp
    unordered_map<int,int> m;
    forI(i,0,v.sz){
        if(m.find(v[i])!=m.end()) m[v[i]]++;
        else if(m.size()<(k-1)) m[v[i]]++;
        else{
            for(auto z:m){
                z.second-=1;
                if(z.second==0) m.erase(z.first);
            }
        }
    }
    for(auto z:m){
        int c=0;
        forI(i,0,v.sz){
            if(v[i]==z.first) c++;
        }
        if(c>v.sz/k) cout<<z.first<<" ";
    }
    cout<<endl;
}

int lengthOfLongestSubstring(string s) { // nice combo of two pointer and hashing
    if(s.length()==0) return 0;
    unordered_map<char,int> mp;
    int j=0,mAx=1;
    mp[s[0]]=0;
    for(int i=1;i<s.length();i++){
        if(mp.find(s[i])==mp.end()){
            mp[s[i]]=i;
        }
        else{
            j=max(j,mp[s[i]]+1);
            mp[s[i]]=i;
        }
        mAx=max(mAx,i-j+1);
    }
    return mAx;
}

int main(){
// for chaining or close addressing 
    // struct chaining closehash(7);
    // closehash.insertkey(70);
    // closehash.insertkey(71);
    // closehash.insertkey(9);
    // closehash.insertkey(56);
    // closehash.insertkey(72);
    // closehash.Printtab();
    // cout<<closehash.searchkey(56)<<endl;
    // cout<<closehash.searchkey(81)<<endl;
    // closehash.removekey(9);
    // closehash.Printtab();
    // closehash.removekey(10);
    // closehash.Printtab();
// for open hashing
    // struct openhashing openhash(7);
    // cout<<openhash.insertkey(70)<<endl;
    // cout<<openhash.insertkey(71)<<endl;
    // cout<<openhash.insertkey(9)<<endl;
    // cout<<openhash.insertkey(56)<<endl;
    // cout<<openhash.insertkey(72)<<endl;
    // openhash.Printtab();
    // cout<<openhash.searchkey(56)<<endl;
    // cout<<openhash.searchkey(81)<<endl;
    // cout<<openhash.removekey(9)<<endl;
    // openhash.Printtab();
    // cout<<openhash.removekey(10)<<endl;
    // openhash.Printtab();

    vector<int> v={3,2,3};
    // cout<<CountDistinct(v)<<endl;
    // FrequencyArrelements(v);
    // cout<<long_consecutive_subseq(v)<<endl;

    // vector<int> w={1,1,1,1};
    // cout<<InsersectArr(v,w)<<endl;
    // cout<<UnionArr(v,w)<<endl;

    // cout<<long_spanof_eq0AND1(v,w)<<endl;

    // cout<<pair_with_giv_sum(v,6)<<endl;
    // cout<<max_subarr_zerosum(v)<<endl;
    // cout<<max_subarr_givsum(v,4)<<endl;
    // cout<<long_subarr_givsum(v,4)<<endl;
    // cout<<long_subarr_eq0AND1(v)<<endl;

    // distinct_in_Window(v,2);
    // print_occurances_more_nbyk1(v,3);
    print_occurances_more_nbyk2(v,3);
    return 0;
}