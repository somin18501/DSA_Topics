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

void PrintSnakePattern(vector<vector<int>> &v){
    int r=v.sz,c=0;
    forI(i,0,r){
        if(i%2==0){
            while(c<v[0].sz){
                cout<<v[i][c]<<" ";
                c++;
            }
        }
        else{
            while(c){
                c--;
                cout<<v[i][c]<<" ";
            } 
        }
    }
}

void BoundaryTraverse(vector<vector<int>> &v){
    int r=v.sz,c=v[0].sz;
    forI(i,0,c) cout<<v[0][i]<<" ";
    forI(i,1,r) cout<<v[i][c-1]<<" ";
    ford(i,c-2,0) cout<<v[r-1][i]<<" ";
    ford(i,r-2,1) cout<<v[i][0]<<" ";
}

void Tranpose(vector<vector<int>> &v){
    int r=v.sz,c=v[0].sz;
    forI(i,0,r){
        forI(j,i+1,c){
            swap(v[i][j],v[j][i]);
        }
    }
}

void Rotate90Anti(vector<vector<int>> &v){
    Tranpose(v);
    forI(i,0,v[0].sz){
        int low=0,high=v.sz-1;
        while(low<high){
            swap(v[low][i],v[high][i]);
            low++;
            high--;
        }
    }
}

void SpiralTraverse(vector<vector<int>> &v){
    int top=0;
    int bot=v.sz-1;
    int right=v[0].sz-1;
    int left=0;
    while(top<=bot && left<=right){
        forI(i,left,right+1){
            cout<<v[top][i]<<" ";
        }
        top++;
        forI(i,top,bot+1){
            cout<<v[i][right]<<" ";
        }
        right--;
        if (top<=bot){
            ford(i,right,left){
                cout<<v[bot][i]<<" ";
            }
            bot--;
        }
        if(left<=right){
            ford(i,bot,top){
                cout<<v[i][left]<<" ";
            }
            left++;
        }
    }
}

// spiral traversal but from inner circle to out circle
    // int p,q,n;
    // cin>>p>>q>>n;
    // vector<vector<int>> mat(p,vector<int>(q,0));
    // fori(i,0,n){
    //     int x,y,val;
    //     cin>>x>>y>>val;
    //     mat[x][y]=val;
    // }
    // int a,b;
    // cin>>a>>b;
    // int top=a,bot=a,left=b,right=b;
    // int curr=1;
    // if(mat[a][b]!=0){
    //     cout<<a<<" "<<b<<" "<<mat[a][b]<<" "<<curr<<endl;
    //     n--;
    // }
    // while(n>0){
    //     if(curr==1){
    //         a=a+1;
    //         if(a>=0 && a<p && b>=0 && b<q && mat[a][b]!=0){
    //             cout<<a<<" "<<b<<" "<<mat[a][b]<<" "<<curr<<endl;
    //             n--;
    //         }
    //         if(a>bot){
    //             bot=a;
    //             curr=2;
    //         }
    //     }
    //     else if(curr==2){
    //         b=b+1;
    //         if(a>=0 && a<p && b>=0 && b<q && mat[a][b]!=0){
    //             cout<<a<<" "<<b<<" "<<mat[a][b]<<" "<<curr<<endl;
    //             n--;
    //         }
    //         if(b>right){
    //             right=b;
    //             curr=3;
    //         }
    //     }
    //     else if(curr==3){
    //         a=a-1;
    //         if(a>=0 && a<p && b>=0 && b<q && mat[a][b]!=0){
    //             cout<<a<<" "<<b<<" "<<mat[a][b]<<" "<<curr<<endl;
    //             n--;
    //         }
    //         if(a<top){
    //             top=a;
    //             curr=4;
    //         }
    //     }
    //     else{
    //         b=b-1;
    //         if(a>=0 && a<p && b>=0 && b<q && mat[a][b]!=0){
    //             cout<<a<<" "<<b<<" "<<mat[a][b]<<" "<<curr<<endl;
    //             n--;
    //         }
    //         if(b<left){
    //             left=b;
    //             curr=1;
    //         }
    //     }
    // }

void SearchInSortMatrix(vector<vector<int>> &v,int key){
    int r=v.sz,c=v[0].sz;
    int i=0,j=c-1,f=0;
    while(i!=r && j!=-1){
        if(v[i][j]==key){
            cout<<"("<<i<<","<<j<<")"<<endl;
            f=1;
            break;
        }
        else if(v[i][j]<key){
            i++;
        }
        else{
            j--;
        }
    }
    if(f==0) cout<<"NOT FOUND\n";
}

// minimum number of operations required to make sum of all row and columns same (IMP: similar to search in sorted matrix)
    // int n;
    // cin>>n;
    // vector<vector<int>> ip(n,vector<int>(n));
    // vector<ll> rsum(n,0);
    // vector<ll> csum(n,0);
    // ll mAx=0;
    // fori(i,0,n){
    //     fori(j,0,n){
    //         cin>>ip[i][j];
    //         rsum[i]+=ip[i][j];
    //         csum[j]+=ip[i][j];
    //     }
    //     if(rsum[i]>mAx){
    //         mAx=rsum[i];
    //     }
    // }
    // fori(j,0,n){
    //     if(csum[j]>mAx){
    //         mAx=csum[j];
    //     }
    // }
    // ll ans=0;
    // int i=0,j=0;
    // while(i<n && j<n){
    //     if(mAx-rsum[i]<mAx-csum[j]){
    //         ans+=mAx-rsum[i];
    //         csum[j]+=mAx-rsum[i];
    //         rsum[i]=mAx;
    //         i++;
    //     }
    //     else{
    //         ans+=mAx-csum[j];
    //         rsum[i]+=mAx-csum[j];
    //         csum[j]=mAx;
    //         j++;
    //     }
    // }
    // cout<<ans;

// assumption: odd sized array and all elements are distinct
int findMedian(vector<vector<int> > &A) {
    int low=INT_MAX,high=INT_MIN;
    for(int i=0;i<A.size();i++){
        low=min(low,A[i][0]);
        high=max(high,A[i][A[0].size()-1]);
    }
    while(low<high){
        int mid=(low+high)/2;
        int k=0;
        for(int i=0;i<A.size();i++){
            k+=upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
        }
        if(k<(A.size()*A[0].size()+1)/2){
            low=mid+1;
            
        }
        else{
            high=mid;
        }
    }
    return low;
}


int main(){
    vector<vector<int>> v={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    // PrintSnakePattern(v);
    // BoundaryTraverse(v);
    // SpiralTraverse(v);

    // Tranpose(v);
    // Rotate90Anti(v);
    // forI(i,0,v.sz){
    //     forI(j,0,v[0].sz) cout<<v[i][j]<<" ";
    //     cout<<endl;
    // }
    // SearchInSortMatrix(v,10);
    cout<<findMedian(v)<<endl;
    return 0;
}