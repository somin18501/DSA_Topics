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

struct DS{
    deque<int> dq;
    void insertmin(int x){
        dq.push_front(x);
    }
    void insertmax(int x){
        dq.push_back(x);
    }
    int getmin(){
        return dq.front();
    }
    int getmax(){
        return dq.back();
    }
    void deletemin(){
        dq.pop_front();
    }
    void deletemax(){
        dq.pop_back();
    }
    int givesize(){
        return dq.size();
    }
};
// imp;
void MaxInSubArrofSZk(vector<int> v,int k){
    deque<int> dq;
    for(int i=0;i<v.sz;i++){
        while(dq.size() && dq.front()<=i-k) dq.pop_front();
        while(dq.size() && v[i]>=v[dq.back()]) dq.pop_back();
        dq.push_back(i);
        if(i>=k-1) cout<<v[dq.front()]<<" ";
    }
    cout<<endl;
}

int FirstCircTour1(vector<int> pet,vector<int> dist){
    int i=0,curr=0;
    deque<int> dq;
    while(dq.sz<pet.sz){
        dq.push_back(i);
        curr+=(pet[i]-dist[i]);
        while(curr<0){
            curr-=(pet[dq.front()]-dist[dq.front()]);
            dq.pop_front();
        }
        i=(i+1)%pet.sz;
    }
    return dq.front()+1;
}

int FirstCircTour2(vector<int> pet,vector<int> dist){
    int curr_pet=0,start=0;
    int prev_pet=0;
    forI(i,0,pet.sz){
        curr_pet+=(pet[i]-dist[i]);
        if(curr_pet<0){
            start=i+1;
            prev_pet+=curr_pet;
            curr_pet=0;
        }
    }
    return ((curr_pet+prev_pet)>=0)?start+1:-1; // based on 1 indexing
}

int main(){
    // DS tp;
    // tp.insertmin(5);
    // cout<<tp.givesize()<<endl;
    // tp.insertmax(10);
    // cout<<tp.givesize()<<endl;
    // tp.insertmin(3);
    // tp.insertmax(12);
    // cout<<tp.getmin()<<endl;
    // cout<<tp.getmax()<<endl;
    // cout<<tp.givesize()<<endl;

    // vector<int> v={20,40,30,10,60};
    // MaxInSubArrofSZk(v,3);

    // vector<int> pet={50,10,60,100},dist={30,20,100,10};
    // cout<<FirstCircTour1(pet,dist)<<endl;
    // cout<<FirstCircTour2(pet,dist)<<endl;
    return 0;
}