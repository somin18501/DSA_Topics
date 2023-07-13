// & - bitwise and
// | - bitwise or
// ^ - bitwise xor
// ~ - bitwise not
// a<<b left shift makes number a=a*2^b 
// a>>b right shift makes number a=a/2^b
// a+b=(a|b)+(a&b)

// for signed int only
// 2's complement of x in n bits representation is :2^n - abs(x) 
// 2's complement of x is -x

// -------------------------------------------------------------------------
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
// -------------------------------------------------------------------------
int bit_not1(int n){
    return ~n;
}

unsigned int bit_not2(unsigned int n){
    return ~n;
}
// -------------------------------------------------------------------------
void kth_setBitL(int n,int k){
    if((n&(1<<(k-1)))!=0) 
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

void kth_setBitR(int n,int k){
    if((1&(n>>(k-1)))==1) // (k-1) as 1th bit is considered as lsb if not then use k
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
// -------------------------------------------------------------------------
int count_setBit(int n){
    int c=0;
    while(n){
        if((n&1)==1) c++;
        n>>=1;
    }
    return c;
}

int count_SetBitBk(int n){
    int c=0;
    while(n){
        n=n&(n-1); // used to vanish rightmost set bit or do n=n-n&(-n) where -n is 2s complement i.e. (~n+1)
        c++;
    }
    return c;
}

int tab[256]; // here 256 is used as it calculate 32 bit number in pair of 8 bits
void count_SetBitLT(){
    tab[0]=0;
    for(int i=1;i<256;i++){
        tab[i]=(i&1)+tab[i>>1]; // use concept of tabulation method of DP and calculate the set bits in i 
    }                           // by checking for set bit at lsb of i and adding it to value at i/2
}
// Sum of setbits in numbers from 1-N O(1) sol
long long countBits(long long N) {
    int p=log2(N);
    long long c=0;
    for(int i=p;i>=0;i--){
        int tp=N/pow(2,i);
        c+=(tp/2*pow(2,i));
        if(tp%2!=0){
            c+=(N%(int)pow(2,i)+1);
        }
    }
    return c;
}
// -------------------------------------------------------------------------
void pow_of2(int n){
    if(n==0) cout<<"NO\n";
    else{
        if((n&(n-1))==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
// -------------------------------------------------------------------------
int OneOddOccur(vector<int> &v){
    int r=0;
    forI(i,0,v.sz)
        r^=v[i];
    return r;
}

int Missing(vector<int> &v){
    int r=0;
    forI(i,0,v.sz)
        r^=v[i];
    forI(i,1,v.sz+2)
        r^=i;
    return r;
}

void TwoOddOccur(vector<int> &v){
    int r=0;
    forI(i,0,v.sz)
        r^=v[i];       // here r will be sum of both odd occuring numbers
    int tp=(r&~(r-1)); // to find the position of rightmost set bit and for leftmost set bit do log2(n)
    int s=0,r=0;
    forI(i,0,v.sz)
        if((v[i]&tp)==0) r^=v[i]; // one which has 0 at position tp will be obtained
        else s^=v[i];             // while other with 1 at position tp will be obtained
    cout<<r<<" "<<s<<endl; 
}
// -------------------------------------------------------------------------
void print_pow_set(string s){ //IMP for genrating subsets
    int n=s.length();
    int powsz=pow(2,n);
    forI(c,0,powsz){
        forI(j,0,n){
            if((c&(1<<j))!=0)
                cout<<s[j];
        }
        cout<<endl;
    }
}
// -------------------------------------------------------------------------
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
// -------------------------------------------------------------------------
// look for max AND value problem once

// for XOR of first N numbers
// find N%4 
// if(N%4==0) XOR = N
// if(N%4==1) XOR = 1
// if(N%4==2) XOR = N+1
// if(N%4==3) XOR = 0

// Binary Modulo must look on gfg

int main(){
    // cout<<bit_not1(4)<<endl<<bit_not2(4); // effect of data_type on answer

    // int n,k;
    // cin>>n>>k;
    // kth_setBitL(n,k);
    // kth_setBitR(n,k);

    // int n;
    // cin>>n;
    // cout<<count_setBit(n)<<endl;
    // cout<<count_SetBitBk(n)<<endl;
    // int r=0;
    // count_SetBitLT();
    // r=r+tab[n&0xff];
    // n>>=8;
    // r=r+tab[n&0xff];
    // n>>=8;
    // r=r+tab[n&0xff];
    // n>>=8;
    // r=r+tab[n&0xff];
    // cout<<r<<endl;
    // pow_of2(n);

    // vector<int> v={4,3,3,9,4,5,5};
    // cout<<OneOddOccur(v)<<endl;
    // vector<int> v={1,5,3,2};
    // cout<<Missing(v)<<endl;
    // vector<int> v={3,4,3,4,5,4,4,6,7,7};
    // TwoOddOccur(v);

    // print_pow_set("abc");
    // return 0;
}
