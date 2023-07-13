#include <bits/stdc++.h>

using namespace std;

// In heap complete binary tree is used where all levels are fully filled except last 
// left child = 2*i+1
// right child = 2*i+2
// parent = floor((i-1)/2)
// to sort array in increaseing order use max heap
// to sort array in decreaseing order use min heap

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

struct MINHEAP{
    int *arr;
    int size;
    int cap;
    MINHEAP(int x){
        arr=new int[x];
        size=0;
        cap=x;
    }
    int left(int i) {return 2*i+1;}
    int right(int i) {return 2*i+2;}
    int parent(int i) {return floor((i-1)/2);}
    void insert(int n){
        if(size+1<=cap){
            arr[size]=n;
            int k=size;
            while(k!=0 && arr[parent(k)]>arr[k]){
                swap(arr[parent(k)],arr[k]);
                k=parent(k);
            }
            size++;
        }
        else return;
    }
    void minHeapyfy(int i){
        int lt=left(i),rt=right(i);
        int small=i;
        if(lt<size && arr[lt]<arr[small]) small=lt;
        if(rt<size && arr[rt]<arr[small]) small=rt;
        if(small!=i){
            swap(arr[small],arr[i]);
            minHeapyfy(small);
        }
    }
    int getmin() {return (size>0)?arr[0]:Pinf;}
    int extractmin(){
        if(size>0){
            swap(arr[0],arr[size-1]);
            size--;
            minHeapyfy(0);
            return arr[size];
        }
        return Pinf;
    }
    void DecreaseKey(int i,int x){
        arr[i]=x;
        while(i!=0 && arr[parent(i)]>arr[i]){
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }
    void DeleteKey(int i){
        DecreaseKey(i,Ninf);
        int k=extractmin();
    }
    void BuildHeap(){
        ford(i,parent(size-1),0){
            minHeapyfy(i);
        }
    }
    void SortDesc(){
        BuildHeap();
        while(size){
            swap(arr[0],arr[size-1]);
            size--;
            minHeapyfy(0);
        }
    }

};

struct MAXHEAP{
    int *arr;
    int size;
    int cap;
    MAXHEAP(int x){
        arr=new int[x];
        size=0;
        cap=x;
    }
    int left(int i) {return 2*i+1;}
    int right(int i) {return 2*i+2;}
    int parent(int i) {return floor((i-1)/2);}
    void insert(int n){
        if(size+1<=cap){
            arr[size]=n;
            int k=size;
            while(k!=0 && arr[parent(k)]<arr[k]){
                swap(arr[parent(k)],arr[k]);
                k=parent(k);
            }
            size++;
        }
        else return;
    }
    void maxHeapyfy(int i){
        int lt=left(i),rt=right(i);
        int large=i;
        if(lt<size && arr[lt]>arr[large]) large=lt;
        if(rt<size && arr[rt]>arr[large]) large=rt;
        if(large!=i){
            swap(arr[large],arr[i]);
            maxHeapyfy(large);
        }
    }
    int getmax() {return (size>0)?arr[0]:Ninf;}
    int extractmax(){
        if(size>0){
            swap(arr[0],arr[size-1]);
            size--;
            maxHeapyfy(0);
            return arr[size];
        }
        return Ninf;
    }
    void IncreaseKey(int i,int x){
        arr[i]=x;
        while(i!=0 && arr[parent(i)]<arr[i]){
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }
    void DeleteKey(int i){
        IncreaseKey(i,Pinf);
        int k=extractmax();
    }
    void BuildHeap(){
        ford(i,parent(size-1),0){
            maxHeapyfy(i);
        }
    }
    void SortAsce(){
        BuildHeap();
        while(size){
            swap(arr[0],arr[size-1]);
            size--;
            maxHeapyfy(0);
        }
    }
    
};

void MINHEAPYFY(vector<int> &arr,int i,int size){
    int lt=2*i+1,rt=2*i+2;
    int small=i;
    if(lt<size && arr[lt]<arr[small]) small=lt;
    if(rt<size && arr[rt]<arr[small]) small=rt;
    if(small!=i){
        swap(arr[small],arr[i]);
        MINHEAPYFY(arr,small,size);
    }
}

void SortforgivenKsortarray(vector<int> &v,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    forI(i,0,k+1){
        pq.push(v[i]);
    }
    int ind=0;
    forI(i,k+1,v.sz){
        v[ind]=pq.top();
        ind++;
        pq.pop();
        pq.push(v[i]);
    }
    while(pq.sz){
        v[ind]=pq.top();
        ind++;
        pq.pop();
    }
}

void BuildHeap(vector<int> &v,int size){
    ford(i,(size-2)/2,0){
        MINHEAPYFY(v,i,v.sz);
    }
}

int PurchaseMax(vector<int> &v, int sum){
    int c=0;
    int s=v.sz;
    BuildHeap(v,s);
    while(sum>=0){
        sum-=v[0];
        c++;
        swap(v[0],v[s-1]);
        s--;
        MINHEAPYFY(v,0,s);
    }
    c--;
    return c;
}

void kthLargest(vector<int> &v,int k){
    int s=k;
    BuildHeap(v,s);
    forI(i,k,v.sz){
        if(v[i]>v[0]){
            swap(v[0],v[i]);
            MINHEAPYFY(v,0,s);
        }
    }
    forI(i,0,k){cout<<v[i]<<" ";}
}

void kthclosedele(vector<int> &v,int k,int x){
    priority_queue<pair<int,int>> pq;
    forI(i,0,k){
        pq.push({abs(v[i]-x),i});
    }
    forI(i,k,v.sz){
        if(abs(v[i]-x)<pq.top().first){
            pq.pop();
            pq.push({abs(v[i]-x),i});
        }
    }
    while(!pq.empty()){
        cout<<v[pq.top().second]<<" ";
        pq.pop();
    }
}
// -----------------------------------------------------------------------------------
struct obj{
    int val;
    int rnum;
    int cnum;
};

bool operator<(const struct obj& obj1,const struct obj& obj2){ // will have max height on the top
    return obj1.val<obj2.val;
}

// struct compare{
//     bool operator()(node* n1/struct obj obj1/pair<dtype1,dtype2> p1,node* n2/struct obj obj2/pair<dtype1,dtype2> p2){
//         return n1->val<n2->val/ obj1.val<obj2.val/ p1.ss<p2.ss;
//     }
// };

vector<int> mergeksortedarray(vector<vector<int>> &v,int k){
    priority_queue<struct obj> pq;
    vector<int> op;
    forI(i,0,k){
        pq.push({-v[i][0],i,0});
    }
    while(!pq.empty()){
        op.pb(-pq.top().val);
        if(pq.top().cnum+1<v[pq.top().rnum].sz){
            pq.push({-v[pq.top().rnum][pq.top().cnum+1],pq.top().rnum,pq.top().cnum+1});
        }
        pq.pop();
    }
    return op;
}
// -----------------------------------------------------------------------------------
void medianofstream(vector<float> &v){ // imp
    priority_queue<int> s;                  // s is the max heap of all elements that are smaller/should be in first-half of sorted stream
    priority_queue<int,vector<int>,greater<int>> g; // g is the min heap of all elements that are larger/should be in second-half of sorted stream
    s.push(v[0]);                          
    forI(i,1,v.sz){
        int x=v[i];
        if(s.sz>g.sz){                      // ocurrs when total elements in s are 1 more then g
            if(x<s.top()){                  // here motive is to keep total elements in s and g equal so x is inserted in either s or g 
                g.push(s.top());            // so that median is mean of max-element in first half and min-element in second half
                s.pop();                    // as final size of stream will be even 
                s.push(x);
            }
            else g.push(x);
            v[i]=(s.top()+g.top())/2.0;
        }
        else{                               // ocurrs when total elements in s and g are equal
            if(x<=s.top()) s.push(x);       // here motive is to keep total elements in s one more then g so x is inserted in either s or g
            else{                           // so that median is the top of element in first half
                g.push(x);                  // as final size of the stream will be odd
                s.push(g.top());
                g.pop();
            }
            v[i]=s.top();
        }
    }
}
// -----------------------------------------------------------------------------------
struct tup{
    int sum;
    int arr1;
    int arr2;  
};

bool operator<(const struct tup& obj1,const struct tup& obj2){ // will have max height on the top
    return obj1.sum<obj2.sum;
}

vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    int n=A.size();
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    set<pair<int,int>> s;
    priority_queue<struct tup> pq;
    vector<int> op;
    pq.push({A[n-1]+B[n-1],n-1,n-1});
    s.insert({n-1,n-1});
    while(C--){
        struct tup tp=pq.top();
        pq.pop();
        op.push_back(tp.sum);
        if(s.find({tp.arr1-1,tp.arr2})==s.end()){
            pq.push({A[tp.arr1-1]+B[tp.arr2],tp.arr1-1,tp.arr2});
            s.insert({tp.arr1-1,tp.arr2});
        }
        if(s.find({tp.arr1,tp.arr2-1})==s.end()){
            pq.push({A[tp.arr1]+B[tp.arr2-1],tp.arr1,tp.arr2-1});
            s.insert({tp.arr1,tp.arr2-1});
        }
    }
    return op;
}
// imp asked in contest of both leetcode and gfg
// You have k bags. You are given a 0-indexed integer array weights where weights[i] is the weight of the ith marble. 
// You are also given the integer k. Divide the marbles into the k bags according to the following rules:
// 1) No bag is empty.
// 2) If the ith marble and jth marble are in a bag, then all marbles with an index between the ith and jth indices should also be in that same bag.
// 3)If a bag consists of all the marbles with an index from i to j inclusively, then the cost of the bag is weights[i] + weights[j].
// The score after distributing the marbles is the sum of the costs of all the k bags.
// Return the difference between the maximum and minimum scores among marble distributions.
long long putMarbles(vector<int>& arr, int k) {
    long long mAx,mIn;
    int n=arr.size();
    mAx=mIn=arr[0]+arr[n-1];
    priority_queue<int> q1;
    priority_queue<int,vector<int>,greater<int>> q2;
    for(int i=0;i<n-1;i++){
        q1.push(arr[i]+arr[i+1]);
        q2.push(arr[i]+arr[i+1]);
    }
    for(int i=0;i<k-1;i++){
        mAx+=q1.top();
        q1.pop();
        mIn+=q2.top();
        q2.pop();
    }
    return mAx-mIn;
}

int main(){
    struct MINHEAP minh(15);
    vector<int> v={9,8,7,18,19,17};
    SortforgivenKsortarray(v,2);
    for(auto x:v){cout<<x<<" ";}

    vector<int> test={20,10,5,30,100};
    cout<<endl<<PurchaseMax(test,35)<<endl;

    vector<int> test2={5,15,10,20,8,25,18};
    kthLargest(test2,3);
    cout<<endl;

    vector<int> test3={30,40,32,33,36,37};
    kthclosedele(test3,3,38);
    cout<<endl;

    vector<vector<int>> test4={{10,20},{5,15},{4,9,11}};
    vector<int> op;
    op=mergeksortedarray(test4,3);
    for(auto x:op){cout<<x<<" ";}
    cout<<endl;

    vector<float> test5={12,15,10,5,8,7,16}; 
    medianofstream(test5);
    for(auto x:test5){cout<<x<<" ";}
    return 0;
}