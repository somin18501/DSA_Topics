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
#define mod 1000000007
#define all(v) v.begin(),v.end()
// ----------------------------------------------------------------------------------
int digit_count(int n){
    int c=0;
    while(n){
        c++;
        n/=10;
    }
    // number of digit of an int n base b floor(logb(x) + 1), here b=10(decimal)
    return c;
}
// ----------------------------------------------------------------------------------
bool palindrom_num(int n){
    int c=0,n2=0,tp=n;
    while(tp){
        n2=n2*10+(tp%10);
        tp/=10;
    }
    return (n==n2);
}
// ----------------------------------------------------------------------------------
int facR(int n){
    if(n==0) return 1;
    else return n*facR(n-1);
}

int facI(int n){
    int pro=1;
    forI(i,2,n+1) pro*=i;
    return pro;
}

int trailing_zeros_fac(int n){
    int c=0;
    for(int i=1;1;i++){
        if(n/pow(5,i)) c+=(n/pow(5,i));
        else break;
    } 
    return c;
}
// ----------------------------------------------------------------------------------
int gcdI1(int a,int b){
    int z=min(a,b);
    ford(i,z,2) 
        if(a%i==0 && b%i==0) return i;
    return 1;
}

int gcdI2(int a,int b){
    while(a!=b){
        if(a<b) b-=a;
        else a-=b;
    }
    return a;
}

int gcdR1(int a,int b){
    if(a<b) b-=a;
    else if(b<a) a-=b;
    else return a;
    return gcdR1(a,b);
}

int gcdR2(int a,int b){
    if(b==0) return a;
    else return gcdR2(b,a%b);
}
// ----------------------------------------------------------------------------------
int lcm1(int a,int b){
    int z=max(a,b);
    while(1){
        if(z%a==0 && z%b==0) return z;
        else z++;
    }
}

int lcm2(int a,int b){
    return (a*b)/gcdR2(a,b);
}
// ----------------------------------------------------------------------------------
bool check_prime1(int n){
    if(n==1) return false;
    if(n==2) return true;
    forI(i,2,n) 
        if(n%i==0) return false;
    return true;
}

bool check_prime2(int n){
    if(n==1) return false;
    if(n==2) return true;
    for(int i=2;i*i<=n;i++) 
        if(n%i==0) return false;
    return true;
}
// IMP: sieve of erathosthenes technique i.e. remove all element that are divisible by i and greater than square of 
// i(where i varies from 5 to i*i<=n with increment of 6) to check wether number is prime or not if not divisible by 2 or 3 
bool check_prime3(int n){  
    if(n==1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i+=6) 
        if(n%i==0 || n%(i+2)==0) return false;
    return true;
}
// ----------------------------------------------------------------------------------
void prime_fac1(int n){
    forI(i,2,n+1)
        if(check_prime3(i)) 
            while(n%i==0){
                n/=i;
                cout<<i<<" ";
            }
    cout<<endl;
}

void prime_fac2(int n){
    for(int i=2;i*i<=n;i++)
        if(check_prime3(i)) 
            while(n%i==0){
                n/=i;
                cout<<i<<" ";
            }
    if(n>1) cout<<n;
    cout<<endl;
}

void prime_fac3(int n){
    while(n%2==0){
        n/=2;
        cout<<2<<" ";
    }
    while(n%3==0){
        n/=3;
        cout<<3<<" ";
    }
    int i;
    for(i=5;i*i<=n;i+=6) 
        if(check_prime3(i)) 
            while(n%i==0){
                n/=i;
                cout<<i<<" ";
            }
            while(n%(i+2)==0){
                n/=(i+2);
                cout<<i+2<<" ";
            }
    if(n>3) cout<<n;
    cout<<endl;
}
// ----------------------------------------------------------------------------------
void all_factors1(int n){
    forI(i,1,n+1) 
        if(n%i==0) cout<<i<<" ";
    cout<<endl;
}

void all_factors2(int n){
    int i;
    for(i=1;i*i<=n;i++)
        // if(n%i==0) cout<<i<<" "<<n/i<<" "; // do not give in sorted order
        if(n%i==0) cout<<i<<" ";
    for(i--;i>0;i--)
        if(n%i==0) cout<<n/i<<" ";
    cout<<endl;
}
// ----------------------------------------------------------------------------------
void print_prrimes1(int n){
    for(int i=2;i<=n;i++) 
        if(check_prime3(i)) cout<<i<<" ";
    cout<<endl;
}

void print_primes2_Sieve_Eratosthenes(int n){
    int arr[n+1];
    fil1D(arr,n+1,true);
    arr[0]=false;
    arr[1]=false;
    for(int i=2;i*i<=n;i++){
        int k=i*i;
        if(arr[i]){
            while(k<=n){
                arr[k]=false;
                k+=i;
            }
        }
    }
    forI(i,2,n+1) 
        if(arr[i])
            cout<<i<<" ";
    cout<<endl;
}
// ----------------------------------------------------------------------------------
int powerR(int x,int n){
    if(n==0) return 1;
    else if(eve_chk(n)) return powerR(x,n/2)*powerR(x,n/2);
    else return powerR(x,n/2)*powerR(x,n/2)*x;
}

int powerI1(int x,int n){
    int pro=1;
    forI(i,1,n+1) pro*=x;
    return pro;
}

int powerI2(int x,int n){ // it is also implemented using bitwise operators in bit magic.cpp
    int pro=1;
    while(n){
        if(n%2!=0) pro*=x;
        n/=2;
        x*=x;
    }
    return pro;
}
// ----------------------------------------------------------------------------------
// template for matrix exponentialtion
vector<vector<ll>> matMul(vector<vector<ll>> a, vector<vector<ll>> b){
    ll x,y,z;
    x=a.size();
    y=b.size();
    z=b[0].size();
    vector<vector<ll>> ans(x,vector<ll>(z,0));
    forI(i,0,x){
        forI(j,0,z){
            forI(k,0,y){
                ans[i][j]=(ans[i][j]+(a[i][k]*b[k][j])%mod)%mod;
            }
        }
    }
    return ans;
}

vector<vector<ll>> matExp(vector<vector<ll>> &a,ll b){
    if(b==0){
        vector<vector<ll>> op(a.size(),vector<ll>(a[0].size(),0));
        forI(i,0,a.size()) op[i][i]=1;
        return op;
    }
    if(b%2==0){
        vector<vector<ll>> tmp=matExp(a,b/2);
        return matMul(tmp, tmp);
    }
    else{
        vector<vector<ll>> tmp=matExp(a,b/2);
        return matMul(matMul(tmp, tmp),a);
    }
}
// int main(){
//     vector<vector<ll>> ip={{1,1},{1,0}}; // change the matrix for exponentiation
//     ll n;
//     cin>>n;
//     if(n==0) cout<<0<<endl; // change 
//     else{
//         vector<vector<ll>> con={{1},{0}}; // change constant/base condition matrix
//         vector<vector<ll>> tmp=matExp(ip,n-1); // chnage exponent
//         tmp=matMul(tmp,con);
//         cout<<tmp[0][0]<<endl;
//     }
//     return 0;
// }

// ----------------------------------------------------------------------------------
int main(){
    // int n;
    // cin>>n;
    // cout<<digit_count(n)<<endl;
    // cout<<palindrom_num(n)<<endl;
    // cout<<facR(n)<<endl;
    // cout<<facI(n)<<endl;
    // cout<<trailing_zeros_fac(n)<<endl;
    // cout<<check_prime1(n)<<endl;
    // cout<<check_prime2(n)<<endl;
    // cout<<check_prime3(n)<<endl;

    // prime_fac1(n);
    // prime_fac2(n);
    // prime_fac3(n);
    // all_factors1(n);
    // all_factors2(n);
    // print_prrimes1(n);
    // print_primes2_Sieve_Eratosthenes(n);

    // int a,b;
    // cin>>a>>b;
    // cout<<gcdI1(a,b)<<endl;
    // cout<<gcdI2(a,b)<<endl;
    // cout<<gcdR1(a,b)<<endl;
    // cout<<gcdR2(a,b)<<endl;
    // cout<<lcm1(a,b)<<endl;
    // cout<<lcm2(a,b)<<endl;
    // cout<<powerI1(a,b)<<endl;
    // cout<<powerI2(a,b)<<endl;
    // cout<<powerR(a,b)<<endl;
    return 0;
}