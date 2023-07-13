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

// IMP: quit similar to reversing queue
void Sortinsert(stack<int> &st,int k){
    if(st.empty() || st.top()<k){
        st.push(k);
        return;
    }
    else{
        int Top=st.top();
        st.pop();
        Sortinsert(st,k);
        st.push(Top);
    }
}
void SortStack(stack<int> &st){
    if(st.empty()) return;
    int k=st.top();
    st.pop();
    SortStack(st);
    Sortinsert(st,k);
}
// -------------------------------------------------------------------------------------------
bool isbraketsbalanced(string s){
    stack<char> stk;
    forI(i,0,s.len){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            stk.push(s[i]);
        }
        else if(s[i]==')' || s[i]==']' || s[i]=='}'){
            if(!stk.empty()){
                if(s[i]==')' && stk.top()=='(') stk.pop();
                else if(s[i]==']' && stk.top()=='[') stk.pop();
                else if(s[i]=='}' && stk.top()=='{') stk.pop();
                else return false;
            }
            else{
                return false;
            }
        }
    }
    if(stk.empty()) return true;
    return false;
}

struct twostkarr{
    int *stk;
    int top1;
    int top2;
    int cap;
    twostkarr(int x){
        top1=-1;
        top2=x;
        cap=x;
        stk=new int[cap];
    }
    bool isety1(){
        return (top1==-1);
    }
    bool isety2(){
        return (top2==cap);
    }
    bool isful1(){
        return (top1==top2);
    }
    bool isful2(){
        return (top2==top1);
    }
    void push1(int x){
        top1++;
        if(isful1()){
            cout<<"stack-1 full\n";
            top1--;
        }
        else{
            stk[top1]=x;
        }
    }
    void push2(int x){
        top2--;
        if(isful2()){
            cout<<"stack-2 full\n";
            top2++;
        }
        else{
            stk[top2]=x;
        }
    }
    int pop1(){
        if(isety1()){
            cout<<"stack-1 already empty\n";
            return -1;
        }
        else{
            top1--;
            return stk[top1+1];
        }
    }
    int pop2(){
        if(isety2()){
            cout<<"stack-2 already empty\n";
            return -1;
        }
        else{
            top2++;
            return stk[top2-1];
        }
    }
    int top_1(){
        return stk[top1];
    }
    int top_2(){
        return stk[top2];
    }
    int size1(){
        return top1+1;
    }
    int size2(){
        return cap-top2;
    }
};

struct kstkarr{
    int *nxt,*top,*arr,cap,n,freetop=0;
    kstkarr(int k,int siz){
        n=k;
        cap=siz;
        nxt=new int[cap];
        arr=new int[cap];
        top=new int[n];
        forI(i,0,cap-1) nxt[i]=i+1;
        nxt[cap-1]=-1;
    }
    void push(int x,int k){
        if(freetop==cap){
            cout<<"stack is full\n";
        }
        else{
            int i=freetop;
            freetop=nxt[i];
            nxt[i]=top[k];
            top[k]=i;
            arr[i]=x;
        }
    }
    int pop(int k){
        int i=top[k];
        top[k]=nxt[i];
        nxt[i]=freetop;
        freetop=i;
        return arr[i];
    }
    int TOP(int k){
        return arr[top[k]];
    }
};

void stockspan(vector<int> v){ // important as it gives no. of elements lessthan or equal to x till x in unsorted array
    stack<int> stk;
    stk.push(0);
    cout<<1<<" ";
    forI(i,1,v.sz){
        while(!stk.empty() && v[stk.top()]<=v[i]){
            stk.pop();
        }
        int k=(stk.empty())?i+1:i-stk.top();
        cout<<k<<" ";
        stk.push(i);
    }
    cout<<endl;
}

void poswiseprevgreater(vector<int> v){
    stack<int> stk;
    stk.push(0);
    cout<<-1<<" ";
    forI(i,1,v.sz){
        while(!stk.empty() && v[stk.top()]<=v[i]){
            stk.pop();
        }
        int k=(stk.empty())?-1:v[stk.top()];
        cout<<k<<" ";
        stk.push(i);
    }
    cout<<endl;
}

void poswisenextgreater(vector<int> v){
    stack<int> stk;
    vector<int> op;
    stk.push(0);
    op.push_back(-1);
    ford(i,v.sz-2,0){
        while(!stk.empty() && v[stk.top()]<=v[i]){
            stk.pop();
        }
        int k=(stk.empty())?-1:v[stk.top()];
        op.push_back(k);
        stk.push(i);
    }
    ford(i,op.sz-1,0) cout<<op[i]<<" ";
    cout<<endl;
}

vector<int> poswiseprevsmaller(vector<int> v){
    stack<int> stk;
    vector<int> op;
    stk.push(0);
    op.push_back(-1);
    forI(i,1,v.sz){
        while(!stk.empty() && v[stk.top()]>v[i]){
            stk.pop();
        }
        int k=(stk.empty())?-1:stk.top();
        op.push_back(k);
        stk.push(i);
    }
    return op;
}

vector<int> poswisenextsmaller(vector<int> v){
    stack<int> stk;
    vector<int> op;
    stk.push(0);
    op.push_back(v.sz);
    ford(i,v.sz-2,0){
        while(!stk.empty() && v[stk.top()]>v[i]){
            stk.pop();
        }
        int k=(stk.empty())?v.sz:stk.top();
        op.push_back(k);
        stk.push(i);
    }
    return op;
}

int largerectarea1(vector<int> v){
    vector<int> v1,v2;
    v1=poswiseprevsmaller(v);
    v2=poswisenextsmaller(v);
    reverse(all(v2));
    int ret=0;
    forI(i,0,v.sz){
        int curr=v[i];
        curr+=(i-v1[i]-1)*v[i];
        curr+=(v2[i]-i-1)*v[i];
        ret=max(ret,curr);
    }
    return ret;
}

int largerectarea2(vector<int> v){
    stack<int> stk;
    int res=0;
    forI(i,0,v.sz){
        while(!stk.empty() && v[stk.top()]>=v[i]){
            int tp=stk.top();
            stk.pop();
            int curr=v[tp]*(stk.empty()?i:(i-stk.top()-1));
            res=max(res,curr);
        }
        stk.push(i);
    }
    while(!stk.empty()){
        int tp=stk.top();
        stk.pop();
        int curr=v[tp]*(stk.empty()?v.sz:(v.sz-stk.top()-1));
        res=max(res,curr);
    }
    return res;
}

int LargeRectAreaWith1s(vector<vector<int>> v){
    vector<int> ip(v[0].sz,0);
    int res=0;
    forI(i,0,v.sz){
        forI(j,0,v[0].sz){
            ip[j]=(v[i][j]==0)?0:ip[j]+1;
        }
        res=max(res,largerectarea2(ip));
    }
    return res;
}

int longestValidParentheses(string A) { // can also be done using DP: for that look interviewbit
    int l=0;
    stack<int> stk;
    stk.push(-1);
    for(int i=0;i<A.size();i++){
        if(A[i]=='(') stk.push(i);
        else{
            if(!stk.empty()){
                stk.pop();
                if(!stk.empty()){
                    l=max(l,i-stk.top());
                }
                else{
                    stk.push(i);
                }
            }
        }
    }
    return l;
}

// Given an array of integers arr, find the sum of min(b), 
// where b ranges over every (contiguous) subarray of arr. 
// Since the answer may be large, return the answer modulo 109 + 7.
int sumSubarrayMins(vector<int>& arr){
    int al[arr.size()];
    int ar[arr.size()];
    stack<int> s1;
    s1.push(0);
    al[0]=-1;
    for(int i=1;i<arr.size();i++){
        while(!s1.empty() && arr[s1.top()]>=arr[i]){
            s1.pop();
        }
        if(s1.empty()) al[i]=-1;
        else al[i]=s1.top();
        s1.push(i);
    }
    stack<int> s2;
    s2.push(arr.size()-1);
    ar[arr.size()-1]=arr.size();
    for(int i=arr.size()-2;i>=0;i--){
        while(!s2.empty() && arr[s2.top()]>arr[i]){
            s2.pop();
        }
        if(s2.empty()) ar[i]=arr.size();
        else ar[i]=s2.top();
        s2.push(i);
    }
    long long sum=0;
    for(int i=0;i<arr.size();i++){
        sum=(sum+(long long)arr[i]*(long long)(i-al[i]+ar[i]-i-1))%(int)(1e9+7);
        sum=(sum+((long long)arr[i]*(long long)(i-al[i]-1))%(int)(1e9+7)*(long long)(ar[i]-i-1))%(int)(1e9+7);
    }
    return sum;
}

// Imp
// getmin() of stack elements:
    // 1) In O(1) time and O(n) aux space : no push and pop affected and min is top of auxilary stack
        // stack<int> main,aux;
        // void push(int x){
        //     if(main.empty()){
        //         main.push(x);
        //         aux.push(x);
        //     }
        //     else if(x<=aux.top()){
        //         main.push(x);
        //         aux.push(x);
        //     }
        //     else{
        //         main.push(x);
        //     }
        // } 
        // void pop(){
        //     if(main.top()==aux.top()){
        //         main.pop();
        //         aux.pop();
        //     }
        //     else{
        //         main.pop();
        //     }
        // }
        // int getmin(){
        //     return aux.top();
        // }
        // int peek(){
        //     return main.top();
        // }
    // 2) only for +ve integer stack : O(1) time and O(1) aux space for minimum element, both push and pop are affected 
        // stack<int> main;
        // int min;
        // void push(int x){
        //     if(main.empty()){
        //         main.push(x);
        //         min=x;
        //     }
        //     else if(x<=min){
        //         main.push(x-min);                   // main.push(x-max);
        //         min=x;                              // max=x
        //     }
        //     else{
        //         main.push(x);
        //     }
        // }
        // void pop(){
        //     if(main.top()<=0){
        //         min=min-main.top();
        //         main.pop();
        //     }
        //     else{
        //         main.pop();
        //     }
        // }
        // int getmin(){
        //     return min;
        // }
        // int peek(){
        //     if(main.top()<=0){
        //         return min;
        //     }
        //     else{
        //         return main.top();
        //     }
        // }
    // 3) only for any integer stack : O(1) time and O(1) aux space for minimum element, both push and pop are affected 
        // stack<int> main;
        // int min;
        // void push(int x){
        //     if(main.empty()){
        //         main.push(x);
        //         min=x;
        //     }
        //     else if(x<=min){
        //         main.push(2*x-min);   // for max ele in stack: main.push(2*y-mAx);
        //         min=x;                                      // mAx=y;
        //     }
        //     else{
        //         main.push(x);
        //     }
        // }
        // void pop(){
        //     if(main.top()<=min){         // for max ele in stack: if(main.top()>=mAx)
        //         min=2*min-main.top();                          //     mAx=2*mAx-stk.top();
        //         main.pop();
        //     }
        //     else{
        //         main.pop();
        //     }
        // }
        // int getmin(){
        //     return min;
        // }
        // int peek(){
        //     if(main.top()<=min){
        //         return min;
        //     }
        //     else{
        //         return main.top();
        //     }
        // }

// LRU cashe // very very IMP // both get and put function works in O(1)

// struct DLL{
//     int ky;
//     int val;
//     DLL* next;
//     DLL* prev;
//     DLL(){
//         next=NULL;
//         prev=NULL;
//     }
// };

// class LRUCache
// {
//     int cap;
//     int sz;
//     DLL* head;
//     DLL* last;
//     unordered_map<int,DLL*> mp;
// public:
//     LRUCache(int capacity)
//     {
//         cap=capacity;
//         sz=0;
//         head=NULL;
//         last=NULL;
//         mp=unordered_map<int,DLL*>();
//     }

//     int get(int key)
//     {
//         if(mp.find(key)!=mp.end()){
//             if(mp[key]!=head){
//                 DLL* n1=mp[key];
//                 n1->prev->next=n1->next;
//                 if(n1!=last){
//                     n1->next->prev=n1->prev;
//                     n1->next=head;
//                     n1->prev=NULL;
//                     head->prev=n1;
//                     head=n1;   
//                 }
//                 else{
//                     last=n1->prev;
//                     n1->next=head;
//                     n1->prev=NULL;
//                     head->prev=n1;
//                     head=n1;      
//                 }
//             }
//             return mp[key]->val;
//         }
//         else{
//             return -1;
//         }
//     }

//     void put(int key, int value)
//     {
//         if(mp.find(key)!=mp.end()){
//             mp[key]->val=value;
//             if(mp[key]!=head){
//                 DLL* n1=mp[key];
//                 n1->prev->next=n1->next;
//                 if(n1!=last){
//                     n1->next->prev=n1->prev;
//                     n1->next=head;
//                     n1->prev=NULL;
//                     head->prev=n1;
//                     head=n1;   
//                 }
//                 else{
//                     last=n1->prev;
//                     n1->next=head;
//                     n1->prev=NULL;
//                     head->prev=n1;
//                     head=n1;      
//                 }
//             }
//         }
//         else{
//             if(sz<cap){
//                 if(head==NULL){
//                     head=new DLL;
//                     head->val=value;
//                     head->ky=key;
//                     mp[key]=head;
//                     last=head;
//                 }
//                 else{
//                     DLL* tmp=new DLL;
//                     tmp->val=value;
//                     tmp->ky=key;
//                     mp[key]=tmp;
//                     tmp->next=head;
//                     head->prev=tmp;
//                     head=tmp;
//                 }
//                 sz++;
//             }
//             else{
//                 mp.erase(last->ky);
//                 last=last->prev;
//                 if(last) last->next=NULL;
//                 DLL* tmp=new DLL;
//                 tmp->val=value;
//                 tmp->ky=key;
//                 mp[key]=tmp;
//                 tmp->next=head;
//                 head->prev=tmp;
//                 head=tmp;   
//                 if(last==NULL) last=head;
//             }
//         }
//     }
// };

// --------------------------------------------------------------------------------------------------

int main(){
    // string s="({()))";
    // cout<<isbraketsbalanced(s)<<endl;

    // 2stkarr st(5);
    // st.push1(10);
    // cout<<st.size1()<<endl;
    // st.push2(20);
    // cout<<st.size2()<<endl;
    // st.push1(5);
    // cout<<st.size1()<<endl;
    // st.push2(25);
    // cout<<st.size2()<<endl;
    // st.push1(15);
    // cout<<st.size1()<<endl;
    // st.push2(1);
    // st.push1(2);
    // cout<<st.size1()<<endl;
    // cout<<st.size2()<<endl;
    // st.pop1();
    // cout<<st.size1()<<endl;
    // st.pop2();
    // cout<<st.size2()<<endl;
    // st.pop1();
    // st.pop2();
    // st.pop1();
    // st.pop2();
    // st.pop1();
    // cout<<st.size1()<<endl;
    // cout<<st.size2()<<endl;

    // kstkarr st(2,5);
    // st.push(10,0);
    // cout<<st.TOP(0)<<endl;
    // st.push(20,1);
    // cout<<st.TOP(1)<<endl;
    // st.push(5,0);
    // cout<<st.TOP(0)<<endl;
    // st.push(25,1);
    // cout<<st.TOP(1)<<endl;
    // st.push(15,0);
    // cout<<st.TOP(0)<<endl;
    // st.push(1,1);
    // st.push(2,0);
    // cout<<st.TOP(0)<<endl;
    // cout<<st.TOP(1)<<endl;
    // cout<<st.pop(0)<<endl;
    // cout<<st.TOP(0)<<endl;
    // cout<<st.pop(1)<<endl;
    // cout<<st.TOP(1)<<endl;
    // cout<<st.pop(0)<<endl;
    // cout<<st.pop(1)<<endl;
    // cout<<st.pop(0)<<endl;
    // cout<<st.pop(1)<<endl;
    // cout<<st.pop(0)<<endl;
    // cout<<st.TOP(0)<<endl;
    // cout<<st.TOP(1)<<endl;
    
    // vector<int> v={6,2,5,4,1,5,6};
    // stockspan(v);
    // poswiseprevgreater(v);
    // poswisenextgreater(v);
    // cout<<largerectarea1(v)<<endl;
    // cout<<largerectarea2(v)<<endl;

    // vector<vector<int>> v={{1,1,1}};
    // cout<<LargeRectAreaWith1s(v)<<endl;
    
    
    return 0;
}