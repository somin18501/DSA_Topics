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

void lower_char_freq(string s){
    int arr[26]={0};
    forI(i,0,s.len){
        arr[s[i]-97]++;
    }
    forI(i,0,26){
        if(arr[i]!=0) cout<<(char)(i+97)<<"-"<<arr[i]<<endl;
    }
}

bool Naive_paindromechk(string s){ // instead use two pointer approach as it use O(1) aux space
    string tp=s;
    reverse(all(tp));
    return (s==tp);
}

bool subsequence_chkI(string s1,string s2){ // assume s2<s1 in length // also it is naive approach for lcs
    int i1=0,i2=0;
    while(i2<s2.len && i1<s1.len){
        if(s1[i1]==s2[i2]){
            i1++;
            i2++;
        }
        else{
            i1++;
        }
    }
    return (i2==s2.len);
}

bool subsequence_chkR(string s1,string s2,int l1,int l2){ // assume s2<s1 in length
    if(l2==-1){
        return true;
    }
    else if(l1==-1){
        return false;
    }
    else{
        if(s1[l1-1]==s2[l2-1]){
            return subsequence_chkR(s1,s2,l1-1,l2-1);
        }
        else{
            return subsequence_chkR(s1,s2,l1-1,l2);
        }
    }
}

bool anagramchk(string s1,string s2){
    int arr[256]={0};
    if(s1.len!=s2.len) return false;
    forI(i,0,s1.len){
        arr[s1[i]]++;
        arr[s2[i]]--;
    }
    forI(i,0,256){
        if(arr[i]!=0) return false;
    }
    return true;
}

int leftmost_repeat_char(string s){
    int arr[256];
    int ind=-1;
    fil1D(arr,256,false);
    ford(i,s.len-1,0){
        if(arr[s[i]]==false){
            arr[s[i]]=true;
        }
        else{
            ind=i;
        }
    }
    return ind;
}

int leftmost_nonrepeat_char(string s){
    int arr[256];
    fil1D(arr,256,-1);
    forI(i,0,s.len){
        if(arr[s[i]]==-1){
            arr[s[i]]=i;
        }
        else{
            arr[s[i]]=-2;
        }
    }
    int mIn=Pinf;
    forI(i,0,256){
        if(arr[i]>=0){
            mIn=min(mIn,arr[i]);
        }
    }
    return (mIn!=Pinf)?mIn:-1;
}

void reversestring(string &s1,int s,int e){
    while(s<e){
        swap(s1[s],s1[e]);
        s++;
        e--;
    }
}

string reverse_word(string &s1){
    int s=0;
    while(s<s1.len){
        int e=s;
        while(e!=s1.len && s1[e]!=' '){
            e++;
        }
        reversestring(s1,s,e-1);
        s=e+1;
    }
    reverse(all(s1));
    return s1;
}

void Naivepatternsearch(string s1,string s2){ // here we compare all n-m+1 indexs of s1 with the pattern 
    forI(i,0,s1.len-s2.len+1){                // it increase time complexity if all character of pattern are distinct
        int j;
        for(j=0;j<s2.len;j++){
            if(s1[i+j]!=s2[j]) break;
        }
        if(j==s2.len) cout<<i<<" ";
    }
    cout<<endl;
}

void NaivepatternsearchDistinct(string s1,string s2){ // here instead of compareing all indexes we directly jump comparison by 
    forI(i,0,s1.len-s2.len+1){                        // j if pattern does not match substring at index j
        int j;
        for(j=0;j<s2.len;j++){
            if(s1[i+j]!=s2[j]) break;
        }
        if(j==s2.len) cout<<i<<" ";
        else if(j>0) i+=j-1;
    }
    cout<<endl;
}

void RabinKarp(string s1,string s2){ // In this algo we first check hash value of substring at any index with hash value of pattern 
    int h=1,d=5,q=61;                // if it matches than only we compare further
    forI(i,1,s2.len){                // if there are n different character in s1 and s2 then d=n
        h=(h*d)%q;                   // if p="abc" then hash value is 1*d^2+2*d^1+3*d^0
    }                                // here %q is done to prevent higher values
    int p=0,t=0;
    forI(i,0,s2.len){
        p=(p*d+s2[i])%q; // p is hash value of pattern
        t=(t*d+s1[i])%q; // hash value of current window or substring
    }
    forI(i,0,s1.len-s2.len+1){
        if(t==p){
            int f=0;
            forI(j,0,s2.len){
                if(s1[i+j]!=s2[j]){
                    f=1;
                    break;
                }
            }
            if(f==0){
                cout<<i<<" ";
            }
        }
        if(i<s1.len-s2.len){
            t=(d*(t-h*s1[i])+s1[i+s2.len])%q; // t(i+1)=d*(t(i)-s1[i]*d^(m-1))+s1[i+m]
            if(t<0) t+=q;                     // here instead of calculating d^(m-1) always we calculated it earlier as h
        }
    }
}
// always try to use idea of lps where ever something is to be done from starting or prefix
vector<int> construct_lpsArr(string s){ // used to store longest proper prefix which is also a suffix
    vector<int> v;                      // proper prefix of string are one which is not equal to string
    v.push_back(0);                     // for string "aba" proper prefix are "","a","ab" and suffix are "","a","ba"
    int l=0,i=1;                        // so here longest proper prefix which is also a suffix is "a" and has length 1
    while(i<s.len){                     // for string "ababa" lps array will look like
        if(s[i]==s[l]){                 //            [00123] 
            l++;                        // 0 for only string "a",
            v.push_back(l);             // 0 for only string "ab",
            i++;                        // 1 for only string "aba" as it has "a" as both proper prefix and suffix,
        }                               // 2 for only string "abab" as it has "ab" as both proper prefix and suffix,
        else{                           // 3 for only string "ababa" as it has "aba" as both proper prefix and suffix,
            if(l==0){
                v.push_back(0);         // there is O(n^2) Naive solution for it in which we compare
                i++;   // all prefix from length 1->(m-1) to its corresponding suffix from m->2 if it is same then lps is that length
            }                           // but this is O(n) solution as it uses
            else{                       // previously calculated index value for current index
                l=v[l-1];
            }
        }
    }
    return v;
}

// below link is nice application of KMP algo 
// https://leetcode.com/problems/repeated-string-match/description/
void kmp(string s1,string s2){                  // s1="ababcababaad" and s2="ababa" 
    vector<int> v=construct_lpsArr(s2);         // so lps=[00123]
    int i=0,j=0;
    while(i<s1.len){
        if(s2[j]==s1[i]){                       // ababcababaad
            i++;                                // ababa              here i=4  and j=4 mismatch so j=lps[4-1]=lps[3]=2
            j++;                                // ababcababaad
        }                                       //   ababa            here i=4  and j=2 mismatch so j=lps[2-1]=lps[1]=0
        if(j==s2.len){                          // ababcababaad
            cout<<i-j<<" ";                     //     ababa          here i=4  and j=0 mismatch and j=0 so i++ i.e. i=5 and j=0
            j=v[j-1];                           // ababcababaad
        }                                       //      ababa         here i=10 and j=5 so matched index=10-5=5 and j=lps[5-1]=lps[4]=3 
        else if(i<s1.len && s2[j]!=s1[i]){      // ababcababaad 
            if(j==0) i++;                       //        ababa       here i=10 and j=3 mismatch so j=lps[3-1]=lps[2]=1
            else j=v[j-1];                      // ababcababaad 
        }                                       //          ababa     here i=10 and j=1 mismatch so j=lps[1-1]=lps[0]=0
    }                                           // ababcababaad 
}                                               //           ababa    here i=11 and j=1 mismatch so j=lps[1-1]=lps[0]=0
                                                // ababcababaad 
                                                //            ababa   here i=11 and j=0 mismatch and j=0 so i++ i.e. i=12 and j=0
// Nice question using good logic to apply lps
// Given string str of length N. The task is to find the minimum characters to be added at the front to make string palindrome.
int minChar(string s){
    string rev=s;
    reverse(rev.begin(),rev.end());
    s=s+"#"+rev;
    vector<int> lps;
    lps.push_back(0);
    int l=0,i=1;
    while(i<s.length()){
        if(s[l]==s[i]){
            l++;
            lps.push_back(l);
            i++;
        }
        else{
            if(l==0){
                lps.push_back(0);
                i++;
            }
            else{
                l=lps[l-1];    
            }
        }
    }
    int k=lps.back();
    return rev.length()-k;
}

bool strRotchk(string s1,string s2){
    if(s1.len!=s2.len) return false;
    return ((s1+s1).find(s2)!=string::npos);    // nice logic
}

bool anagramsearch(string s1,string s2){
    vector<int> CT(128,0),CP(128,0);
    forI(i,0,s2.len){
        CT[s1[i]]++;
        CP[s2[i]]++;
    }
    forI(i,s2.len,s1.len){
        if(CT==CP) return true;
        else{
            CT[s1[i-s2.len]]--;
            CT[s1[i]]++;
        }
    }
    return false;
}

int facI(int n){
    int pro=1;
    forI(i,2,n+1) pro*=i;
    return pro;
}

int lexi_rankOfString(string s){
    int arr[128]={0};
    forI(i,0,s.len) arr[s[i]]++;
    forI(i,1,128) arr[i]+=arr[i-1];
    int mul=facI(s.len);
    int rank=1;
    forI(i,0,s.len-1){
        mul=mul/(s.len-i);
        rank+=(arr[s[i]]-1)*mul;
        forI(j,s[i],128){
            arr[j]--;
        }
    }
    return rank;
}

int long_distinct_substr(string s){
    int mAx=1,i=0;
    vector<int> v(128,-1);
    forI(j,0,s.len){
        i=max(i,v[s[j]]+1);     // nice logic
        int mAxend=j-i+1;
        mAx=max(mAx,mAxend);
        v[s[j]]=j;
    }
    return mAx;
}

int main(){
    string s="abcadbd";
    // lower_char_freq(s);
    // cout<<Naive_paindromechk(s)<<endl;
    // cout<<leftmost_repeat_char(s)<<endl;
    // cout<<leftmost_nonrepeat_char(s)<<endl;
    // cout<<reverse_word(s)<<endl;
    // vector<int> v=construct_lpsArr(s);
    // for(auto z:v) cout<<z<<" ";
    // cout<<lexi_rankOfString(s)<<endl;
    // cout<<long_distinct_substr(s)<<endl;

    // string t="frge";
    // cout<<subsequence_chkI(s,t)<<endl;
    // cout<<subsequence_chkR(s,t,s.len,t.len)<<endl;
    // cout<<anagramchk(s,t)<<endl;
    // Naivepatternsearch(s,t);
    // NaivepatternsearchDistinct(s,t);
    // cout<<strRotchk(s,t)<<endl;
    // cout<<anagramsearch(s,t)<<endl;

    // RabinKarp(s,t);
    // cout<<endl;
    // kmp(s,t);
    return 0;
}