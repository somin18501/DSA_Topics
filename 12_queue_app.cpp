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

void reverseQI(queue<int> &q){
    stack<int> stk;
    while(!q.empty()){
        stk.push(q.front());
        q.pop();
    }
    while(!stk.empty()){
        q.push(stk.top());
        stk.pop();
    }
}

void reverseQR(queue<int> &q){
    if(q.empty()) return;
    int x=q.front();
    q.pop();
    reverseQR(q);
    q.push(x);
}

void printfirstN(int n,int a,int b){ // if a=1 & b=2 & n=6 then it forms a,b,aa,ab,ba,bb;
    queue<string> q;
    q.push(to_string(a));
    q.push(to_string(b));
    forI(i,0,n){
        string curr=q.front();
        cout<<curr<<" ";
        q.pop();
        q.push(curr+to_string(a));
        q.push(curr+to_string(b));
    }
    cout<<endl;
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.front()<<" "<<q.back()<<endl;
    reverseQI(q);
    cout<<q.front()<<" "<<q.back()<<endl;
    reverseQR(q);
    cout<<q.front()<<" "<<q.back()<<endl;
    printfirstN(10,5,6);
    return 0;
}