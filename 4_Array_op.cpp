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

int max_in_array(vector<int> v){
    int mAx=v[0];
    forI(i,1,v.sz){
        if(v[i]>mAx) mAx=v[i];
    }
    return mAx;
}

int max2_in_array(vector<int> v){
    int l1=v[0],l2=-1;
    forI(i,1,v.sz){
        if(v[i]>l1){
            swapI(l1,l2);
            l1=v[i];
        }
        else if(v[i]>l2 && v[i]!=l1){
            l2=v[i];
        }
    }
    return l2;
}

bool sort_check(vector<int> v){
    forI(i,1,v.sz){
        if(v[i]<v[i-1]) return false;
    }
    return true;
}

vector<int> reverseArray(vector<int> &v){
    int i=0,j=v.sz-1;
    while(i<j){
        swapI(v[i],v[j]);
        i++;
        j--;
    }
    return v;
}

void reverseArr(vector<int> &v,int s,int e){
    while(s<e){
        swapI(v[s],v[e]);
        s++;
        e--;
    }
}

int removeduplicate(vector<int> &v){
    int j=v.sz;
    forI(i,1,v.sz){
        if(v[i]==v[i-1] && j==v.sz) j=i;
        else if(v[i]>v[i-1] && j!=v.sz){
            swapI(v[i],v[j]);
            j++;
            i++;
        }
    }
    return j;
}

int ZerotoEnd(vector<int> &v){
    int j=v.sz;
    forI(i,0,v.sz){
        if(v[i]==0 && j==v.sz) j=i;
        else if(v[i]!=0 && j!=v.sz){
            swapI(v[i],v[j]);
            j++;
        }
    }
    return j;
}

void leftRotatebyD(vector<int> &v,int d){
    reverseArr(v,0,d-1);
    reverseArr(v,d,v.sz-1);
    reverseArr(v,0,v.sz-1);
}

vector<int> Leader_in_arr(vector<int> v){ // return array of elements that are greater than(sometime it might be give equal also) latter values in array
    vector<int> op;
    op.pb(v[v.sz-1]);
    ford(i,v.sz-2,0){
        if(v[i]>op.back()) op.pb(v[i]);
    }
    reverseArr(op,0,op.sz-1);
    return op;
}

int MaxDiffPro(vector<int> v){  // used when profit is calculated for only one buy and sell 
    int mIn=v[0];               // i.e. by updateing min price and calculating profit using that on further days
    int maxdiff=0;
    forI(i,1,v.sz){
        maxdiff=max(maxdiff,v[i]-mIn);
        if(v[i]<mIn) mIn=v[i];
    }
    return maxdiff;
}

void freq_sortarr(vector<int> v){ 
    int c=1;
    forI(i,1,v.sz){
        if(v[i]==v[i-1]) c++;
        else{
            cout<<v[i-1]<<"-"<<c<<endl;
            c=1;
        }
    }
    cout<<v[v.sz-1]<<"-"<<c<<endl;
}

int stock_ByADSell(vector<int> v){  // used when profit is calculated for more than one buy and sell
    int proft=0;                    // i.e. by calculating +ve profit for consecutive buy and sell 
    forI(i,1,v.sz){
        if(v[i]>v[i-1]) proft+=v[i]-v[i-1]; 
    }
    return proft;
}

int trap_rainwater(vector<int> v){ // imp
    int lmax[v.sz],rmax[v.sz]={0};
    lmax[0]=v[0];
    rmax[v.sz-1]=v[v.sz-1];
    forI(i,1,v.sz){
        if(v[i]>lmax[i-1]){
            lmax[i]=v[i];
        }
        else{
            lmax[i]=lmax[i-1];
        }
    }
    ford(i,v.sz-2,0){
        if(v[i]>rmax[i+1]){
            rmax[i]=v[i];
        }
        else{
            rmax[i]=rmax[i+1];
        }
    }
    int water=0;
    forI(i,0,v.sz){
        if(v[i]!=lmax[i] && v[i]!=rmax[i]){
            water+=(min(lmax[i],rmax[i])-v[i]);
        }
    }
    return water;
}

int max_con_1s(vector<int> v){
    int mAx=0,c=0;
    forI(i,0,v.sz){
        if(v[i]==1) c++;
        else{
            mAx=max(mAx,c);
            c=0;
        }
    }
    mAx=max(mAx,c);
    return mAx;
}

int long_eve_odd_subarr(vector<int> v){
    int c=1,mAx=0,i=1;
    while(i<v.sz){
        if(v[i-1]%2==0){
            if(v[i]%2!=0){
                c++;
            }
            else{
                mAx=max(mAx,c);
                c=1;
            }
        }
        else{
            if(v[i]%2==0){
                c++;
            }
            else{
                mAx=max(mAx,c);
                c=1;
            }
        }
        i++;
    }
    mAx=max(mAx,c);
    return mAx;
}

int max_sum_subarr_kadane(vector<int> v){ // imp
    int maxend[v.sz],mAx=v[0];
    maxend[0]=v[0];
    forI(i,1,v.sz){
        maxend[i]=max(maxend[i-1]+v[i],v[i]);
        mAx=max(mAx,maxend[i]);
    }
    return mAx;
}

int max_sum_circular_subarr(vector<int> &v){ // imp
    int nor=max_sum_subarr_kadane(v);
    if(nor<0){
        return nor;
    }
    else{
        int sum=0;
        forI(i,0,v.sz){
            sum+=v[i];
            v[i]=-v[i];
        }
        int minsum=max_sum_subarr_kadane(v);
        return max(nor,sum+minsum);
    }
}

ll o1_hole(vector<ll> ip){
    ll mAx=ip[0];
    ll dp0=ip[0];
    ll dp1=0;
    for(int i=1;i<ip.size();i++){
        dp1=max(dp0,dp1+ip[i]);
        dp0=max(dp0+ip[i],ip[i]);
        mAx=max(mAx,max(dp0,dp1));
    }
    return mAx;
}

int majority_ele(vector<int> v){  // imp // Moore’s Voting Algorithm
    int count=1,res=0;
    forI(i,1,v.sz){
        if(v[i]==v[res]) count++;
        else count--;
        if(count==0){
            count=1;
            res=i; 
        }
    }
    int c=0;
    forI(i,0,v.sz){
        if(v[res]==v[i]) c++;
    }
    if(c>v.sz/2) return res;
    return -1;
}

void min_con_flip(vector<int> v){
    int inst=1;
    if(v[0]==v[v.sz-1]){
        if(v[0]) inst=0;
    }
    else{
        if(v[0]) inst=0;
    }
    int k=0;
    forI(i,1,v.sz){
        if(v[i]!=v[i-1] && v[i]==inst){
            cout<<"from "<<i<<" to ";
            k++;
        } 
        else if(v[i]!=v[i-1] && v[i]!=inst){
            cout<<(i-1)<<endl;
            k++;
        }
    }
    if(k%2!=0) cout<<(v.sz-1)<<endl;
}

int maxsubarr_of_szk(vector<int> v,int k){
    int sum=0;
    forI(i,0,k){
        sum+=v[i];
    }
    int mAx=sum;
    forI(j,k,v.sz){
        sum+=(v[j]-v[j-k]);
        mAx=max(mAx,sum);
    }
    return mAx;
}

bool subarr_of_anywindow(vector<int> v,int sum){
    int tot=v[0],c=0;
    int s=0,e=0;
    forI(i,1,v.sz){
        if(tot<sum){
            tot+=v[i];
            e++;
        }
        if(tot>sum){
            while(tot>sum){
                tot-=v[s];
                s++;
            }
        }
        if(tot==sum){
            return true;
        }
    }
    return false;
}

// int prefixsum(vector<int> v,int r){
//     int arr[v.sz];
//     arr[0]=v[0];
//     forI(i,1,v.sz){
//         arr[i]=arr[i-1]+v[i];
//     }
//     return arr[r];
// }

int getsum(vector<int> v,int l,int r){
    if(l==0) return v[r];
    return (v[r]-v[l-1]);
}

bool isequilirium(vector<int> v){
    int tot=0;
    forI(i,0,v.sz){
        tot+=v[i];
    }
    int lsum=0;
    forI(i,0,v.sz){
        if(lsum==(tot-lsum-v[i])) return true; 
        lsum+=v[i];
    }
    return false;
}

int N_withmaxinRange(vector<int> l,vector<int> r,int n){
    int arr[n+1]={0};
    forI(i,0,l.sz){
        arr[l[i]]++;
        arr[r[i]+1]--;
    }
    int sum=arr[0],ind=0;
    forI(i,1,n+1){
        arr[i]=arr[i-1]+arr[i];
        if(sum<arr[i]){
            ind=i;
            sum=arr[i];
        }  
    }
    return ind;
}

// void nextPermutation(vector<int>& nums) {
//     int i1=-1;
//     for(int i=nums.size()-2;i>=0;i--){
//         if(nums[i]<nums[i+1]){
//             i1=i;
//             break;
//         }
//     }
//     if(i1==-1) reverse(nums.begin(),nums.end());
//     else{
//         int i2;
//         for(int i=nums.size()-1;i>=0;i--){
//             if(nums[i]>nums[i1]){
//                 i2=i;
//                 break;
//             }
//         }
//         swap(nums[i1],nums[i2]);
//         int l=i1+1,h=nums.size()-1;
//         while(l<h){
//             swap(nums[l],nums[h]);
//             l++;
//             h--;
//         }   
//     }
// }

int main(){
    vector<int> v={4,2,2};
    
    // cout<<max_in_array(v)<<endl;
    // cout<<max2_in_array(v)<<endl;
    // cout<<sort_check(v)<<endl;

    // v=reverseArray(v);

    // cout<<removeduplicate(v)<<endl; // return size of array with distict value
    // for(auto z:v) cout<<z<<" ";

    // cout<<ZerotoEnd(v)<<endl;
    // for(auto z:v) cout<<z<<" ";

    // int d;
    // cin>>d;
    // leftRotatebyD(v,d%v.sz);
    // for(auto z:v) cout<<z<<" ";

    // v=Leader_in_arr(v);
    // for(auto z:v) cout<<z<<" ";

    // cout<<MaxDiffPro(v)<<endl;

    // freq_sortarr(v);

    // cout<<stock_ByADSell(v)<<endl;

    // cout<<trap_rainwater(v)<<endl;

    // cout<<max_con_1s(v)<<endl;

    // cout<<long_eve_odd_subarr(v)<<endl;

    // cout<<max_sum_subarr_kadane(v)<<endl;

    // cout<<max_sum_circular_subarr(v)<<endl;

    // cout<<majority_ele(v)<<endl;

    // min_con_flip(v);

    // cout<<maxsubarr_of_szk(v,3)<<endl;

    // cout<<subarr_of_anywindow(v,33)<<endl;

    // vector<int> presum;
    // presum.pb(v[0]);
    // forI(i,1,v.sz){
    //     presum.pb(presum[i-1]+v[i]);
    // }
    // cout<<getsum(presum,0,2)<<endl;

    // cout<<isequilirium(v)<<endl;

    // vector<int> l={1,2,3};
    // vector<int> r={3,5,7};
    // cout<<N_withmaxinRange(l,r,10)<<endl;
    return 0;
}