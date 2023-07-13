// bool mycmp(pair<int,int> p1,pair<int,int> p2){
//     return (p1.ss<p2.ss);
// }
// bool mycmpforobj(struct obj obj1,struct obj obj2){
//     return obj1.val<obj2.val;
// }
// sort(all(v),greater<int>()); // to sort in descending order
// sort(all(v),mycmp); // to sort as per our requirements
// sort(all(v),mycmpforobj); // to sort as per our requirements
// stable sort: bubble,insertion,merge
// unstable sort: selection,quick,heap 
// inplace: quicksort, heap, bubble, insertion, selection

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

void Bubble(vector<int> &v){
    int j=0;
    while(1){
        int fg=0;
        forI(i,1,v.sz-j){
            if(v[i-1]>v[i]){
                swap(v[i-1],v[i]);
                fg=1;
            }
        }
        j++;
        if(fg==0) break;
    }
}

void selection(vector<int> &v){
    forI(i,0,v.sz-1){
        int mIn=Pinf,ind=-1,j;
        forI(j,i+1,v.sz){
            if(v[j]<mIn){
                mIn=v[j];
                ind=j;
            }
        }
        swap(v[i],v[ind]);
    }
}

void insertion(vector<int> &v){
    forI(i,1,v.sz){
        int tp=v[i],j=i-1;
        while(j>=0 && tp<v[j]){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=tp;
    }
}

void solve(vector<int>& nums1, int m, vector<int>& nums2, int n){ // do inplace merging 
    int gap=ceil((m+n)/2.0);                        // assumption is that m>=n, nums1 carry first sorted half and remaining in nums2
    int i=0,j=gap;
    while(gap>0){
        while(j<(m+n)){
            if(j<m){
                if(nums1[j]<nums1[i]){
                    swap(nums1[j],nums1[i]);
                }
            }
            else if(i<m){
                if(nums2[j%m]<nums1[i%m]){
                    swap(nums2[j%m],nums1[i%m]);
                }
            }
            else{
                if(nums2[j%m]<nums2[i%m]){
                    swap(nums2[j%m],nums2[i%m]);
                }
            }
            i++;
            j++;
        }
        if(gap==1) gap=0;
        else gap=ceil(gap/2.0);
        i=0;
        j=gap;
    }
}

void merge(vector<int> &v,int l,int mid,int r){
    vector<int> v1,v2;
    forI(i,l,mid+1) v1.pb(v[i]);
    forI(i,mid+1,r+1) v2.pb(v[i]);
    int i=l,j=0,k=0;
    while(1){
        if(j<mid-l+1 && k<r-mid){
            if(v1[j]<=v2[k]){
                v[i]=v1[j];
                j++;
            }
            else{
                v[i]=v2[k];
                k++;
            }
        }
        else break;
        i++;
    }
    while(j<mid-l+1){
        v[i]=v1[j];
        i++;
        j++;
    }
    while(k<r-mid){
        v[i]=v2[k];
        i++;
        k++;
    }
}

void mergesort(vector<int> &v,int l,int r){ // here we divide and then merge
    if(r>l){
        int mid=l+(r-l)/2;
        mergesort(v,l,mid);
        mergesort(v,mid+1,r);
        merge(v,l,mid,r);
    }
}

void intersection_sortArr(vector<int> v1,vector<int> v2){
    int i=0,j=0;
    while(i<v1.sz && j<v2.sz){
        if(i>0 && v1[i]==v1[i-1]){
            i++;
            continue;
        }
        if(v1[i]==v2[j]){
            cout<<v1[i]<<" ";
            i++;
            j++;
        }
        else if(v1[i]<v2[j]) i++;
        else j++;
    }
}

void Union_sortArr(vector<int> v1,vector<int> v2){
    int i=0,j=0;
    while(i<v1.sz && j<v2.sz){
        if(i>0 && v1[i]==v1[i-1]){
            i++;
            continue;
        }
        if(j>0 && v2[j]==v2[j-1]){
            j++;
            continue;
        }
        if(v1[i]==v2[j]){
            cout<<v1[i]<<" ";
            i++;
            j++;
        }
        else if(v1[i]<v2[j]){
            cout<<v1[i]<<" ";
            i++;
        }
        else{
            cout<<v2[j]<<" ";
            j++;
        }
    }
    while(i<v1.sz){
        if(i>0 && v1[i]!=v1[i-1]){
            cout<<v1[i]<<" ";
        }
        if(i==0){
            cout<<v1[i]<<" ";
        }
        i++;
    }
    while(j<v2.sz){
        if(j>0 && v2[j]!=v2[j-1]){
            cout<<v2[j]<<" ";
        }
        if(j==0){
            cout<<v2[j]<<" ";
        }
        j++;
    }
}
// look at this problem once // pattern 1:
int countANDmerge(vector<int> &v,int l,int mid,int r){
    vector<int> v1,v2;
    forI(i,l,mid+1) v1.pb(v[i]);
    forI(i,mid+1,r+1) v2.pb(v[i]);
    int i=l,j=0,k=0,res=0;
    while(1){
        if(j<mid-l+1 && k<r-mid){
            if(v1[j]<=v2[k]){
                v[i]=v1[j];
                j++;
            }
            else{
                v[i]=v2[k];
                k++;
                res+=(mid-l+1-j); // most imp logic here: as for given v2[k] all elements after v1[j] and v1[j] in v1 will form inversion
            }
        }
        else break;
        i++;
    }
    while(j<mid-l+1){
        v[i]=v1[j];
        i++;
        j++;
    }
    while(k<r-mid){
        v[i]=v2[k];
        i++;
        k++;
    }
    return res;
}

int countinversion(vector<int> &v,int l,int r){
    int res=0;
    if(r>l){
        int mid=l+(r-l)/2;
        res+=countinversion(v,l,mid);
        res+=countinversion(v,mid+1,r);
        res+=countANDmerge(v,l,mid,r);
    }
    return res;
}
// look at this problem once // pattern 2:
void cntandmerge(vector<long long> &a,int s,int mid,int e,int diff,long long &cnt){
    int l=s,r=mid+1;
    while(l<=mid && r<=e){
        if(a[l]<=a[r]+diff){
            cnt+=(e-r+1);
            l++;
        }
        else{
            r++;
        }
    }
    sort(a.begin()+s,a.begin()+e+1);
}
// You are given two integer arrays A and B containing n integers each. You are also given two integers c and d.
// Determine the number of pairs i,j (1<=i<j<=n) satisfying the inequality (Ai-Aj+c)≤(Bi-Bj+d).
void mergesort(vector<long long> &a,int s,int e,int diff,long long &cnt){
    if(s<e){
        int mid=(s+e)/2;
        mergesort(a,s,mid,diff,cnt);
        mergesort(a,mid+1,e,diff,cnt);
        
        cntandmerge(a,s,mid,e,diff,cnt);
    }
}

int partisanNaive(vector<int> &v,int l,int h,int ind){
    vector<int> tp;
    forI(i,l,h+1){
        if(v[i]<v[ind]) tp.pb(v[i]);
    }
    forI(i,l,h+1){
        if(v[i]==v[ind]) tp.pb(v[i]);
    }
    int res=l+tp.sz-1;
    forI(i,l,h+1){
        if(v[i]>v[ind]) tp.pb(v[i]);
    }
    forI(i,l,h+1){
        v[i]=tp[i-l];
    }
    return res;
}

int partisanLomuto(vector<int> &v,int l,int h){ // here by default pivot is last element
    int i=l-1;
    // int piv=rdm(l,h); // for randomized pivot
    // swap(v[piv],v[h]);
    forI(j,l,h){
        if(v[j]<v[h]){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[h]);
    return (i+1);
}

int partisanHoare(vector<int> &v,int l,int h){ // here by default pivot is first element
    // int pv=rdm(l,h); // for randomized pivot
    // swap(v[pv],v[l]);
    int piv=v[l];
    int i=l-1,j=h+1;
    while(1){
        do{
            i++;
        } while (v[i]<piv);
        do{
            j--;
        } while (v[j]>piv);
        if(i>=j) return j;
        swap(v[i],v[j]);
    }
}
// here we partisian across mid and then do same for either side of partisan
void quicksortL(vector<int> &v,int l,int h){
    if(l<h){
        int piv=partisanLomuto(v,l,h);
        quicksortL(v,l,piv-1);
        quicksortL(v,piv+1,h);
    }
}

void quicksortH(vector<int> &v,int l,int h){
    if(l<h){
        int piv=partisanHoare(v,l,h);
        quicksortH(v,l,piv); // observe difference btw this code line and corresponding call in above function
        quicksortH(v,piv+1,h);
    }
}

int kthsmallestL(vector<int> &v,int k){ // also known as Quick select the result can be efficient if pivot is chosen randomize and swaping it with last in lomuto 
    int l=0,h=v.sz-1;
    while(l<=h){
        int p=partisanLomuto(v,l,h);
        if(p==(k-1)) return v[p];
        else if(p<(k-1)) l=p+1;
        else h=p-1;
    }
    return -1;
}

int chocolateDistri(vector<int> &v,int m){
    if(m>v.sz) return -1;
    sort(all(v));
    int mIn=Pinf;
    forI(i,0,v.sz-m+1){
        mIn=min(mIn,v[i+m-1]-v[i]);
    }
    return mIn;
}

void PartisanInTwoType(vector<int> &v){
    int l=-1,h=v.sz;

    // while(1){
    //     do{
    //         l++;
    //     } while (v[l]<0);
    //     do{
    //         h--;
    //     } while (v[h]>0);
    //     if(l>=h) break; 
    //     swap(v[l],v[h]);
    // }

    // while(1){
    //     do{
    //         l++;
    //     } while (v[l]%2==0);
    //     do{
    //         h--;
    //     } while (v[h]%2!=0);
    //     if(l>=h) break; 
    //     swap(v[l],v[h]);
    // }

    // while(1){
    //     do{
    //         l++;
    //     } while (v[l]==0);
    //     do{
    //         h--;
    //     } while (v[h]==1);
    //     if(l>=h) break; 
    //     swap(v[l],v[h]);
    // }
}

// (Dutch National Flag)
void PartisanInThreeType(vector<int> &v,pair<int,int> pq){
    int l=0,mid=0,h=v.sz-1; // see difference in assigning in twotype and three type

    // while(mid<=h){
    //     if(v[mid]==0){
    //         swap(v[l],v[mid]);
    //         l++;
    //         mid++;
    //     }
    //     else if(v[mid]==1){
    //         mid++;
    //     }
    //     else{
    //         swap(v[mid],v[h]);
    //         h--;
    //     }
    // }

    // int piv=v[l];
    // while(mid<=h){
    //     if(v[mid]<piv){
    //         swap(v[l],v[mid]);
    //         l++;
    //         mid++;
    //     }
    //     else if(v[mid]==piv){
    //         mid++;
    //     }
    //     else{
    //         swap(v[mid],v[h]);
    //         h--;
    //     }
    // }

    // while(mid<=h){
    //     if(v[mid]<pq.first){
    //         swap(v[l],v[mid]);
    //         l++;
    //         mid++;
    //     }
    //     else if(v[mid]>=pq.first && v[mid]<=pq.second){
    //         mid++;
    //     }
    //     else{
    //         swap(v[mid],v[h]);
    //         h--;
    //     }
    // } 
}

int mindiff(vector<int> &v){
    sort(all(v));
    int mIn=Pinf;
    forI(i,1,v.sz){
        mIn=min(mIn,v[i]-v[i-1]);
    }
    return mIn;
}

int MergeOverlapInterval(vector<pair<int,int>> &v){
    int res=0;
    sort(all(v));
    forI(i,1,v.sz){
        if(v[i].ff<=v[res].ss){
            v[res].ss=max(v[i].ss,v[res].ss);
        }
        else{
            res++;
            v[res]=v[i];
        }
    }
    return res+1;
}

int MeetMaxGuest(vector<int> ari,vector<int> dep){
    sort(all(ari));
    sort(all(dep));
    int cur=1,mAx=Ninf;
    int i=1,j=0;
    while(i<ari.sz && j<dep.sz){
        if(ari[i]<dep[j]){
            cur++;
            i++;
        }
        else{
            cur--;
            j++;
        }
        mAx=max(mAx,cur);
    }
    return mAx;
}

int NumlessthanN(vector<int> &v,int x){
    int c=0;
    forI(i,0,v.sz){
        if(v[i]<x) c++;
    }
    return c;
}

void CycleSort(vector<int> &v){
    forI(i,0,v.sz){
        int item=v[i];
        while(i!=NumlessthanN(v,item)){
            swap(item,v[NumlessthanN(v,item)]);
        }
        v[NumlessthanN(v,item)]=item;
    }
}

void maxheapyfy(vector<int> &v,int i,int siz){
    int large=i,left=2*i+1,right=2*i+2;
    if(left<siz && v[left]>v[large]) large=left;
    if(right<siz && v[right]>v[large]) large=right;
    if(large!=i){
        swap(v[large],v[i]);
        maxheapyfy(v,large,siz);
    }
}

void buildheap(vector<int> &v,int siz){
    ford(i,(siz-2)/2,0){
        maxheapyfy(v,i,siz);
    }
}

void HeapSort(vector<int> &v){
    int k=v.sz;
    buildheap(v,k);
    while(k>1){
        swap(v[0],v[k-1]);
        k--;
        maxheapyfy(v,0,k);
    }
}

void naiveCountSort(vector<int> &v,int k){ // all elements in v are less than k and positive
    int arr[k]={0};
    forI(i,0,v.sz){
        arr[v[i]]++;
    }
    int ind=0;
    forI(i,0,k){
        while(arr[i]){
            v[ind]=i;
            arr[i]--;
            ind++;
        }
    }
}

void CountSortOP(vector<int> &v,int k){ // all elements in v are less than k and positive
    int arr[k]={0};
    forI(i,0,v.sz){
        arr[v[i]]++;
    }
    forI(i,1,v.sz){
        arr[i]=arr[i-1]+arr[i];
    }
    int op[v.sz]={0};
    ford(i,v.sz-1,0){
        op[arr[v[i]]-1]=v[i];
        arr[v[i]]--;
    }
    forI(i,0,v.sz) v[i]=op[i];
}

void CountSortRad(vector<int> &v,int k,int exp){ // all elements in v are less than k and positive
    int arr[k]={0};
    forI(i,0,v.sz){
        arr[v[i]/exp%10]++;
    }
    forI(i,1,k){
        arr[i]=arr[i-1]+arr[i];
    }
    int op[v.sz]={0};
    ford(i,v.sz-1,0){
        op[arr[v[i]/exp%10]-1]=v[i];
        arr[v[i]/exp%10]--;
    }
    forI(i,0,v.sz) v[i]=op[i];
}

void RadixSort(vector<int> &v){
    int mAx=Ninf;
    forI(i,0,v.sz){
        mAx=max(mAx,v[i]);
    }
    int digit=floor(log10(mAx)+1);
    for(int i=1;i<pow(10,digit);i*=10){
        CountSortRad(v,10,i);
    }
}

void BucketSort(vector<int> &v,int k){
    int mAx=Ninf;
    forI(i,0,v.sz) mAx=max(mAx,v[i]);
    mAx++;
    vector<int> bkt[k]; 
    forI(i,0,v.sz){
        int ind=k*v[i]/mAx;
        bkt[ind].push_back(v[i]);
    }
    forI(i,0,k){
        sort(bkt[i].begin(),bkt[i].end());
    }
    int m=0;
    forI(i,0,k){
        forI(j,0,bkt[i].sz){
            v[m]=bkt[i][j];
            m++;
        }
    }
}

// kth smallest in matrix
int kthSmallest(vector<vector<int>>& mat, int k) {
    int mAx=INT_MIN;
    int mIn=INT_MAX;
    int n=mat.size();
    for(int i=0;i<n;i++){
        mAx=max(mAx,mat[i][n-1]);
        mIn=min(mIn,mat[i][0]);
    }
    int ans=-1;
    while(mIn<=mAx){
        int mid=(mIn+mAx)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
        }
        if(cnt>=k){
            ans=mid;
            mAx=mid-1;
        }
        else{
            mIn=mid+1;
        }
    }
    int i=0,j=n-1,ans2=-1;
    while(j>=0 && i<n){
        if(mat[i][j]>ans){
            j--;
        }
        else if(mat[i][j]<ans){
            ans2=mat[i][j];
            i++;
        }
        else{
            return ans;
        }
    }
    return ans2;
}

int main(){
    // srand(time(NULL));

    vector<int> v={30,40,10,80,5,12,70};
    
    // Bubble(v);
    // selection(v);
    // insertion(v);

    // merge(v,0,3,6);
    // mergesort(v,0,v.sz-1);
    // for(auto z:v) cout<<z<<" ";
    // vector<int> w={3,20,40};
    // intersection_sortArr(v,w);
    // cout<<endl;
    // Union_sortArr(v,w);
    // cout<<countinversion(v,0,v.sz-1)<<endl;

    // cout<<partisanNaive(v,0,v.sz-1,1)<<endl;
    // cout<<partisanLomuto(v,0,v.sz-1)<<endl;
    // cout<<partisanHoare(v,0,v.sz-1)<<endl;
    // quicksortL(v,0,v.sz-1);
    // quicksortH(v,0,v.sz-1);
    // for(auto z:v) cout<<z<<" ";
    // cout<<kthsmallestL(v,5)<<endl;
    
    // cout<<chocolateDistri(v,3)<<endl;

    // PartisanInTwoType(v);
    // for(auto z:v) cout<<z<<" ";

    // PartisanInThreeType(v,{5,9});
    // for(auto z:v) cout<<z<<" ";

    // cout<<mindiff(v)<<endl;

    // vector<pair<int,int>> w={{1,3},{2,4},{5,7},{6,8}};
    // forI(i,0,MergeOverlapInterval(w)) cout<<w[i].ff<<"-"<<w[i].ss<<endl;

    // vector<int> w={530,840,830,820};
    // cout<<MeetMaxGuest(v,w)<<endl;

    // CycleSort(v);
    // for(auto z:v) cout<<z<<" ";

    // HeapSort(v);
    // for(auto z:v) cout<<z<<" ";

    // naiveCountSort(v,5);
    // CountSortOP(v,5);
    // for(auto z:v) cout<<z<<" ";

    // RadixSort(v);
    // for(auto z:v) cout<<z<<" ";

    // BucketSort(v,4);
    // for(auto z:v) cout<<z<<" ";
    return 0;
}