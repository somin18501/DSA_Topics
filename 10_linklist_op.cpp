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
// -------------------------------------------------------------------------------------------------------------
struct node{
    int val;
    node *next;
    node(int x){
        val=x;
        next=NULL;
    }
};

void printlistI(node *head){
    node *n1;
    n1=head;
    while(n1){
        cout<<n1->val<<" ";
        n1=n1->next;
    }
    cout<<endl;
}

void printlistR(node *head){
    if(head==NULL){
        cout<<endl;    
        return;
    }
    cout<<head->val<<" ";
    printlistR(head->next);
}

node *Insert_begin(node *head,int x){
    if(head==NULL){
        head=new node(x);
    }
    else{
        node *tmp;
        tmp=new node(x);
        tmp->next=head;
        head=tmp;
    }
    return head;
}

node *Insert_end(node *head,int x){
    if(head==NULL){
        head=new node(x);
    }
    else{
        node *n1;
        n1=head;
        while(n1->next){
            n1=n1->next;
        }
        node *tmp;
        tmp=new node(x);
        n1->next=tmp;
    }
    return head;
}

node *Insert_anypos(node *head,int x,int pos){
    if(head==NULL){
        head=new node(x);
    }
    else{
        if(pos<=1){ // insert at pos means insert before pos^th node 
            node *tmp;
            tmp=new node(x);
            tmp->next=head;
            head=tmp;
        }
        else{
            node *n1=head;
            while(n1->next && pos>2){
                n1=n1->next;
                pos--;
            }
            node *tmp;
            tmp=new node(x);
            tmp->next=n1->next;
            n1->next=tmp;
        }
    }
    return head;
}

node *insertInSortedlist(node *head,int x){
    node *tmp=new node(x);
    if(head==NULL){
        head=tmp;
    }
    else{
        node *curr=head;
        if(curr->val>x){
            tmp->next=head;
            head=tmp;
        }
        else{
            while(curr->next!=NULL){
                if(curr->next->val>x){
                    tmp->next=curr->next;
                    curr->next=tmp;
                    break;
                }
                curr=curr->next;
            }
            if(curr->next==NULL){
                curr->next=tmp;
            }
        }
    }
    return head;
}

node *delete_first(node *head){
    if(head!=NULL){
        node *n1=head;
        head=head->next;
        delete[] n1;
    } 
    return head;
}

node *delete_last(node *head){
    if(head!=NULL){
        if(head->next==NULL){
            node *n1=head;
            head=head->next;
            delete[] n1;
        }
        else{
            node *n1;
            n1=head;
            while(n1->next->next){
                n1=n1->next;
            }
            node *n2=n1->next;
            n1->next=NULL;
            delete[] n2;
        }
    }
    return head;
}

int searchlistI(node *head,int x){
    int pos=0;
    while(head){
        pos++;
        if(head->val==x){
            return pos;
        }
        head=head->next;
    }
    pos=-1;
    return pos;
}

int searchlistR(node *head,int x,int pos){
    if(head==NULL) return -1;
    if(head->val==x){
        return pos+1;
    }
    else{
        return searchlistR(head->next,x,pos+1);
    }
}

void middleoflist(node *head){
    if(head!=NULL){
        node *slow,*fast;
        slow=head;
        fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        cout<<slow->val<<endl;
    }
}

void Nthnodefromlast1(node *head,int n){
    int l=0;
    node *n1=head;
    while(n1){
        l++;
        n1=n1->next;
    }
    if(n>l || n==0) return;
    else{
        int k=l-n;
        n1=head;
        while(k--){
            n1=n1->next;
        }
        cout<<n1->val<<endl;
    }
}

void Nthnodefromlast2(node *head,int n){
    if(n>0){
        node *first=head,*second=head;
        while(first){
            if(n>0){
                first=first->next;
                n--;
            }
            else{
                first=first->next;
                second=second->next;
            }
        }
        if(n==0) cout<<second->val<<endl;
    }
}

node *ReverseI(node *head){
    if(head!=NULL){
        node *curr=head;
        node *prev=NULL;
        while(curr){
            node *tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        return prev;
    }
}

node *ReversekthnodeI(node *head,int k){
    if(head!=NULL){
        node *curr=head;
        node *prev=NULL;
        int c=0;
        while(curr && c<k){
            node *tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
            c++;
        }
        node *newhead=ReversekthnodeI(curr,k);
        head->next=newhead;
        return prev;
    }
    return NULL;
}

// ListNode* getReverse(ListNode* head,ListNode* prev,int k){
//     while(k--){
//         ListNode* tp=head->next;
//         head->next=prev;
//         prev=head;
//         head=tp;
//     }
//     return prev;
// }
    
// ListNode* reverseKGroup(ListNode* head, int k) {
//     if(head==NULL) return NULL;
//     int z=0;
//     ListNode* n1=head;
//     while(n1){
//         z++;
//         n1=n1->next;
//         if(z==k) break;
//     }
//     if(z!=k) return head;
//     return getReverse(head,reverseKGroup(n1,z),z);
// }

node *ReverseR1(node *head){
    if(head==NULL || head->next==NULL) return head;
    node *headend=ReverseR1(head->next);
    node *tailend=head->next;
    tailend->next=head;
    head->next=NULL;
    return headend;
}

node *ReverseR2(node *head,node *prev){
    if(head==NULL) return prev;
    node *n2=head,*n3=n2->next;
    n2->next=prev;
    return ReverseR2(n3,n2);
}

void removeduplicate(node *head){
    if(head!=NULL && head->next!=NULL){
        node *curr=head->next;
        while(curr){
            if(head->val==curr->val){
                head->next=curr->next;
                node *tp=curr;
                curr=curr->next;
                delete[] tp;
            }
            else{
                head=head->next;
                curr=curr->next;
            }
        }
    }
}

// To detect loop: 
    // 1) Naive solution - O(n^2)
    // 2) Changing node structure by adding visited entity - O(n) and on extra entity in each node
    // 3) Dummy node concept - O(n) and one extra node
void loopdetect1(node *head){
    node *dumy=new node(-1);
    if(head==NULL) cout<<"NO\n";
    else{
        while(head->next!=NULL && head->next!=dumy){
            node *tmp=head->next;
            head->next=dumy;
            head=tmp;
        }
        if(head->next==dumy) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
    // 4) Hashing method - O(n) and O(n) aux space
bool loopdetect2(node *head){
    unordered_set<node *> s;
    while(head!=NULL && s.find(head)==s.end()){
        s.insert(head);
        head=head->next;
    }
    if(s.find(head)!=s.end()) return true;
    return false;
}
    // 5) slow/fast method
bool loopdetect3(node *head){
    if(head==NULL || head->next==NULL) return false;
    node *slow,*fast;
    slow=head->next;
    fast=head->next->next;
    while(fast!=NULL && fast->next!=NULL && slow!=fast){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow==fast) return true;
    return false;
}

bool loopdetectANDremove(node *head){
    if(head==NULL || head->next==NULL) return false;
    node *slow,*fast;
    slow=head->next;
    fast=head->next->next;
    while(fast!=NULL && fast->next!=NULL && slow!=fast){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow==fast){
        slow=head;
        while(slow!=fast && slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        if(slow==fast){
            while(slow!=fast->next){
                fast=fast->next;
            }
        }
        fast->next=NULL;
        return true;
    }
    return false;
}

void deletebyrefrence(node *ref){ // ref is never a last node
    ref->val=ref->next->val;
    node *tmp=ref->next;
    ref->next=ref->next->next;
    delete[] tmp;
}

node *segregateveodd(node *head){
    node *evs=NULL,*eve=NULL;
    node *ods=NULL,*ode=NULL;
    while(head){
        if(head->val%2==0){
            if(evs==NULL){
                evs=head;
                eve=head;
            }
            else{
                eve->next=head;
                eve=eve->next;
            }
        }
        else{
            if(ods==NULL){
                ods=head;
                ode=head;
            }
            else{
                ode->next=head;
                ode=ode->next;
            }
        }
        head=head->next;
    }
    if(eve!=NULL && ode!=NULL){
        eve->next=ods;
        ode->next=NULL;
        return evs;
    }
    return (evs==NULL)?ods:evs;
}

int intersectionoftwolist(node *head1,node *head2){
    node *n1=head1,*n2=head2;
    int c1=0,c2=0;
    while(n1){
        c1++;
        n1=n1->next;
    }
    while(n2){
        c2++;
        n2=n2->next;
    }
    node *tmp1,*tmp2;
    tmp1=(c1>=c2)?head1:head2;
    tmp2=(c1>=c2)?head2:head1;
    for(int i=0;i<abs(c1-c2);i++){
        tmp1=tmp1->next;
    }
    while(tmp1!=NULL && tmp2!=NULL){
        if(tmp1==tmp2) return tmp1->val;
        tmp1=tmp1->next;
        tmp2=tmp2->next;
    }
    return -1;
}

node *swapnode(node *head){
    if(head!=NULL && head->next!=NULL){
        node *curr=head;
        node *prev=NULL;
        node *tmp=curr->next;
        curr->next=prev;
        prev=curr;
        tmp->next=prev;
        return tmp;
    }
    return head;
}
node *swappairwise(node *head){
    node *n,*m=head;
    if(head==NULL || head->next==NULL) return head;
    else{
        m=m->next;
        while(head!=NULL && head->next!=NULL){
            node *tp=head->next->next;
            n=swapnode(head);
            if(tp!=NULL) n->next->next=tp->next;
            head=tp;
        }
        if(head!=NULL) n->next->next=head; 
        return m;
    }
}

// clone linklist:
    // 1) use hashmap to store random pointer
    // 2) making duplicate node next to original and then deleting original after setting random pointer

// LRU using hashmap(for maintaining rescenty) and doubly link list

node *mergetwolist(node *head1,node *head2){
    node *head=NULL,*tail=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head==NULL){
            if(head1->val<=head2->val){
                head=head1;
                head1=head1->next;
            }
            else{
                head=head2;
                head2=head2->next;
            }
            tail=head;
        }
        else{
            if(head1->val<=head2->val){
                tail->next=head1;
                head1=head1->next;
            }
            else{
                tail->next=head2;
                head2=head2->next;
            }
            tail=tail->next;
        }
    }
    while(head1){
        tail->next=head1;
        head1=head1->next;
        tail=tail->next;
    }
    while(head2){
        tail->next=head2;
        head2=head2->next;
        tail=tail->next;
    }
    return head;
}

node *middlenodeoflist(node *head){
    if(head!=NULL){
        node *slow,*fast;
        slow=head;
        fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    return head;
}
bool palindromlistcheck(node *head){
    node *mid=middlenodeoflist(head);    // nice logic
    node *head2=ReverseI(mid);
    while(head!=mid){
        if(head->val!=head2->val) return false;
        head=head->next;
        head2=head2->next;
    }
    return true;
}

// -------------------------------------------------------------------------------------------------------------
struct Dnode{
    int val;
    Dnode *prev;
    Dnode *next;
    Dnode(int x){
        val=x;
        prev=NULL;
        next=NULL;
    }
};

void printDlist(Dnode *head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

Dnode *Insert_starting(Dnode *head,int x){
    Dnode *tmp;
    tmp=new Dnode(x);
    if(head==NULL){
        head=tmp;
    }
    else{
        tmp->next=head;
        head->prev=tmp;
        head=tmp;
    }
    return head;
}

Dnode *Insert_ending(Dnode *head,int x){
    Dnode *tmp;
    tmp=new Dnode(x);
    if(head==NULL){
        head=tmp;
    }
    else{
        Dnode *n1;
        n1=head;
        while(n1->next){
            n1=n1->next;
        }
        tmp->prev=n1;
        n1->next=tmp;
    }
    return head;
}

Dnode *ReverseDlist(Dnode *head){
    Dnode *n1;
    n1=head;
    while(n1){
        Dnode *t;
        t=n1->next;
        n1->next=n1->prev;
        n1->prev=t;
        if(t==NULL){
            head=n1;
        }
        n1=t;
    }
    return head;
}

Dnode *delete_head(Dnode *head){
    if(head!=NULL){
        Dnode *n1;
        n1=head;
        head=head->next;
        if(head!=NULL) head->prev=NULL;
        delete[] n1;
    }
    return head;
}

Dnode *delete_tail(Dnode *head){
    if(head!=NULL){
        Dnode *n1;
        n1=head;
        while(n1->next){
            n1=n1->next;
        }
        if(n1->prev!=NULL) n1->prev->next=NULL;
        else head=NULL;
        delete[] n1;
    } 
    return head;
}
// -------------------------------------------------------------------------------------------------------------
void printClist(node *head){
    if(head!=NULL){
        node *n1;
        n1=head;
        do{
            cout<<n1->val<<" ";
            n1=n1->next;
        }while(n1!=head);
        cout<<endl;
    }
    
}

node *Insert_first(node *head,int x){
    node *tmp=new node(x);
    if(head==NULL){
        head=tmp;
        head->next=head;
    }
    else{
        tmp->next=head->next;
        head->next=tmp;
        swap(head->val,head->next->val);
    }
    return head;
}

node *Insert_last(node *head,int x){
    node *tmp=new node(x);
    if(head==NULL){
        head=tmp;
        head->next=head;
    }
    else{
        tmp->next=head->next;
        head->next=tmp;
        swap(head->val,head->next->val);
        head=head->next;
    }
    return head;
}

node *delete_starting(node *head){
    if(head!=NULL){
        if(head->next==head){
            delete[] head;
            head=NULL;
        }
        else{
            node *n1=head->next;
            head->val=head->next->val;
            head->next=head->next->next;
            delete[] n1;
        } 
    }
    return head;
}

node *delete_kthpos(node *head,int pos){ // assumption pos less than or equal to total no. of nodes 
    if(head!=NULL){
        if(pos==1){
            head=delete_starting(head);
        }
        else{
            node *n1=head;
            while(pos>2){
                n1=n1->next;
                pos--;
            }
            node *n2=n1->next;
            n1->next=n1->next->next;
            delete[] n2;
        }
        return head;
    }
    return head;
}
// -------------------------------------------------------------------------------------------------------------
Dnode *Insert(Dnode *head,int x){
    Dnode *tmp=new Dnode(x);
    if(head==NULL){
        tmp->next=tmp;
        tmp->prev=tmp;
        head=tmp;
    }
    else{
        tmp->next=head;
        tmp->prev=head->prev;
        head->prev->next=tmp;
        head->prev=tmp;
        head=tmp;
    }
    return head;
}

void printCDlist(Dnode *head){
    if(head!=NULL){
        Dnode *n1=head;
        do{
            cout<<n1->val<<" ";
            n1=n1->next;
        }while(n1!=head);
    }
    cout<<endl;
}
// -------------------------------------------------------------------------------------------------------------
int main(){
    // node *head=NULL;
    // node *head=new node(1);
    // head->next=new node(2);
    // head->next->next=new node(3);
    // printlistR(head);
    // head=Insert_begin(head,5);
    // head=Insert_end(head,7);
    // printlistI(head);
    // head=delete_first(head);
    // printlistI(head);
    // head=delete_last(head);
    // printlistI(head);
    // head=Insert_anypos(head,7,9);
    // printlistI(head);
    // head=Insert_anypos(head,5,4);
    // printlistI(head);
    // head=Insert_anypos(head,5,1);
    // printlistI(head);
    // head=Insert_anypos(head,6,2);
    // printlistI(head);
    // cout<<searchlistI(head,5)<<endl;
    // cout<<searchlistR(head,2,0)<<endl;

    // Dnode *head=NULL;
    // Dnode *head=new Dnode(1);
    // head->next=new Dnode(2);
    // head->next->prev=head;
    // head->next->next=new Dnode(3);
    // head->next->next->prev=head->next;
    // printDlist(head);
    // head=Insert_starting(head,7);
    // printDlist(head);
    // head=Insert_ending(head,5);
    // printDlist(head);
    // head=ReverseDlist(head);
    // printDlist(head);
    // head=delete_head(head);
    // printDlist(head);
    // head=delete_tail(head);
    // printDlist(head);
    
    // node *head=NULL;
    // node *head=new node(1);
    // head->next=new node(2);
    // head->next->next=new node(3);
    // head->next->next->next=head;
    // printClist(head);
    // head=Insert_first(head,7);
    // printClist(head);
    // head=Insert_last(head,5);
    // printClist(head);
    // head=delete_starting(head);
    // printClist(head);
    // head=delete_kthpos(head,2);
    // printClist(head);
    // head=delete_kthpos(head,1);
    // printClist(head);
    // head=delete_kthpos(head,2);
    // printClist(head);
    // head=delete_kthpos(head,1);
    // printClist(head);

    // Dnode *head=NULL;
    // Dnode *head=new Dnode(1);
    // head->next=new Dnode(2);
    // head->next->next=new Dnode(3);
    // head->next->prev=head;
    // head->next->next->prev=head->next;
    // head->next->next->next=head;
    // head->prev=head->next->next;
    // printCDlist(head);
    // head=Insert(head,7);
    // printCDlist(head);
    // head=Insert(head,5);
    // printCDlist(head);
    
    // node *head=NULL;
    // node *head=new node(1);
    // head->next=new node(5);
    // head->next->next=new node(5);
    // printlistR(head);
    // middleoflist(head);
    // head=insertInSortedlist(head,2);
    // head=insertInSortedlist(head,9);
    // head=insertInSortedlist(head,9);
    // printlistR(head);
    // middleoflist(head);
    // Nthnodefromlast1(head,0);
    // Nthnodefromlast1(head,6);
    // Nthnodefromlast1(head,3);
    // Nthnodefromlast1(head,9);
    // Nthnodefromlast2(head,0);
    // Nthnodefromlast2(head,6);
    // Nthnodefromlast2(head,3);
    // Nthnodefromlast2(head,9);
    // head=ReverseI(head);
    // printlistR(head);
    // head=ReverseR1(head);
    // printlistR(head);
    // // head=ReverseR2(head,NULL);
    // // printlistR(head);
    // removeduplicate(head);
    // printlistR(head);
    // head=ReversekthnodeI(head,2);
    // printlistR(head);

    // node *head=NULL;
    // node *head=new node(15);
    // head->next=new node(10);
    // head->next->next=new node(12);
    // head->next->next->next=new node(20);
    // head->next->next->next->next=head->next;
    // loopdetect1(head);
    // cout<<loopdetect2(head)<<endl;
    // cout<<loopdetect3(head)<<endl;
    // cout<<loopdetectANDremove(head)<<endl;
    // printlistR(head);
    // deletebyrefrence(head->next);
    // printlistR(head);

    // node *head=NULL;
    // node *head=new node(7);
    // head->next=new node(3);
    // head->next->next=new node(8);
    // head->next->next->next=new node(4);
    // printlistR(head);
    // head=segregateveodd(head);
    // printlistR(head);

    // node *head1=new node(2);
    // head1->next=new node(3);
    // head1->next->next=new node(7);
    // head1->next->next->next=new node(5);
    // head1->next->next->next->next=new node(9);
    // node *head2=new node(4);
    // head2->next=head1->next->next->next;
    // printlistR(head1);
    // printlistR(head2);
    // cout<<intersectionoftwolist(head1,head2)<<endl;

    // node *head=NULL;
    // node *head=new node(1);
    // head->next=new node(2);
    // head->next->next=new node(3);
    // head->next->next->next=new node(4);
    // head->next->next->next->next=new node(5);
    // head->next->next->next->next->next=new node(6);
    // printlistR(head);
    // head=swappairwise(head);
    // printlistR(head);

    // node *head1=new node(10);
    // head1->next=new node(20);
    // head1->next->next=new node(30);
    // head1->next->next->next=new node(40);
    // printlistR(head1);
    // node *head2=new node(5);
    // head2->next=new node(15);
    // head2->next->next=new node(17);
    // head2->next->next->next=new node(18);
    // head2->next->next->next->next=new node(35);
    // printlistR(head2);
    // node *head=mergetwolist(head1,head2);
    // printlistR(head);

    // node *head=new node(4);
    // head->next=new node(2);
    // head->next->next=new node(3);
    // head->next->next->next=new node(2);
    // head->next->next->next->next=new node(1);
    // // head->next->next->next->next->next=new node(1);
    // cout<<palindromlistcheck(head)<<endl;
    return 0;
}