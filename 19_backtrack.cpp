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

// Backtracking means cutting or preventing unnecessary recursive calls by writing recursive call under condition check function 
// ---------------------------------------------------------------------
bool IsSafe(string op,char incom){
    if(op.len>0 && op[op.len-1]=='A' && incom=='B') return false;
    return true;
}

void PermuteWithoutABassubstring(string ip,string op,int i){
    if(i==ip.len){
        cout<<op<<endl;
        return;
    }
    forI(j,i,ip.len){
        if(IsSafe(op,ip[j])){
            swap(ip[i],ip[j]);
            PermuteWithoutABassubstring(ip,op+ip[i],i+1);
            swap(ip[i],ip[j]);
        }
    }
}
// ---------------------------------------------------------------------
const int n=4;
int sol[n][n];

bool IsSafe2(int (*arr)[n],int i,int j){
    if(i<n && j<n && arr[i][j]==1){
        return true;
    }
    return false;
}

bool SolveMaze(int (*arr)[n],int i,int j){
    if(i==n-1 && j==n-1){
        sol[i][j]=1;
        return true;
    }
    if(IsSafe2(arr,i,j)){
        sol[i][j]=1;
        if(SolveMaze(arr,i+1,j)) return true;
        else if(SolveMaze(arr,i,j+1)) return true;
        else sol[i][j]=0;
    }
    return false;
}

void PrintifSolved(int (*arr)[n]){
    if(SolveMaze(arr,0,0)){
        forI(i,0,n){
            forI(j,0,n){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else cout<<"No\n";
}
// ---------------------------------------------------------------------
const int m=4;
int board[m][m];
// fil2D(board,m,0);

bool IsSafe3(int l,int k){
    if(k>0){
        forI(i,0,k+1){
            if(board[l][i]==1){
                return false;
            }
        }
        int r=l,c=k;
        while(r>-1 && c>-1){
            if(board[r][c]==1){
                return false;
            }
            r--;
            c--;
        }
        r=l,c=k;
        while(r<m && c>-1){
            if(board[r][c]==1){
                return false;
            }
            r++;
            c--;
        }
    }
    return true;
}

bool SolveBoard(vector<int> &v,int k){
    if(k==v.sz){
        return true;
    }
    forI(i,k,v.sz){
        swap(v[i],v[k]);
        if(IsSafe3(v[k],k)){
            board[v[k]][k]=1;
            if(SolveBoard(v,k+1)) return true;
            else board[v[k]][k]=0;
        }   
        swap(v[i],v[k]);    
    }
    return false;
}

void PrintifFound(){
    vector<int> v;
    forI(i,0,m){
        v.pb(i);
    }
    if(SolveBoard(v,0)){
        forI(i,0,m){
            forI(j,0,m){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else cout<<"No\n";
}
// ---------------------------------------------------------------------
bool IsSafe4(vector<vector<int>> &ip,int k,int r,int c,int size){
    int n=sqrt(size);
    forI(i,0,size){
        if(ip[r][i]==k) return false;
    }
    forI(i,0,size){
        if(ip[i][c]==k) return false;
    }
    if(r<n && c<n){
        forI(i,0,n){
            forI(j,0,n){
                if(ip[i][j]==k) return false;
            }
        }
    }
    else if(r>=n && c<n){
        forI(i,n,size){
            forI(j,0,n){
                if(ip[i][j]==k) return false;
            }
        }
    }
    else if(r<n && c>=n){
        forI(i,0,n){
            forI(j,n,size){
                if(ip[i][j]==k) return false;
            }
        }
    }
    else{
        forI(i,n,size){
            forI(j,n,size){
                if(ip[i][j]==k) return false;
            }
        }
    }
    return true;
}

bool SolveSoduko(vector<vector<int>> &ip,int size){
    int r=-1,c=-1;
    forI(i,0,size){
        forI(j,0,size){
            if(ip[i][j]==0){
                r=i;
                c=j;
                break;
            }
        }
        if(r!=-1) break;
    }
    if(r==-1 && c==-1){
        forI(i,0,size){
            forI(j,0,size){
                cout<<ip[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    forI(k,1,size+1){
        if(IsSafe4(ip,k,r,c,size)){
            ip[r][c]=k;
            if(SolveSoduko(ip,size)) return true;
            else ip[r][c]=0;
        }
    }
    return false;
} 
// ---------------------------------------------------------------------

int main(){
    // PermuteWithoutABassubstring("ABC","",0);

    // int arr[n][n]={{1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1}};
    // PrintifSolved(arr);
    
    // cout<<endl;
    // PrintifFound();

    // cout<<endl;
    // vector<vector<int>> ip={{1,0,3,0},{0,0,2,1},{0,1,0,2},{2,4,0,0}};
    // cout<<SolveSoduko(ip,4)<<endl;

    // int A=3,B=4;
    // string s="";
    // string ip="";
    // for(int i=1;i<=A;i++){
    //     ip+=(i+48);
    // }
    // getkthpermute(ip,0,s,B,A-1,0);
    // cout<<s<<endl;
    return 0;
}