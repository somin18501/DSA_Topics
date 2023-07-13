// Common time complexities
// Let n be the main variable in the problem.

// If n ≤ 12, the time complexity can be O(n!).
// If n ≤ 25, the time complexity can be O(2^n).
// If n ≤ 100, the time complexity can be O(n^4).
// If n ≤ 500, the time complexity can be O(n^3).
// If n ≤ 10^4, the time complexity can be O(n^2).
// If n ≤ 10^6, the time complexity can be O(n log n).
// If n ≤ 10^8, the time complexity can be O(n).
// If n > 10^8, the time complexity can be O(log n) or O(1)

// Examples of each common time complexity

// O(n!) [Factorial time]: Permutations of 1 ... n
// O(2^n) [Exponential time]: Exhaust all subsets of an array of size n
// O(n^3) [Cubic time]: Exhaust all triangles with side length less than n
// O(n^2) [Quadratic time]: Slow comparison-based sorting (eg. Bubble Sort, Insertion Sort, Selection Sort)
// O(n log n) [Linearithmic time]: Fast comparison-based sorting (eg. Merge Sort)
// O(n) [Linear time]: Linear Search (Finding maximum/minimum element in a 1D array), Counting Sort
// O(log n) [Logarithmic time]: Binary Search, finding GCD (Greatest Common Divisor) using Euclidean Algorithm
// O(1) [Constant time]: Calculation (eg. Solving linear equations in one unknown)

#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Ch-1

    // int a,b;
    // string x;

    

    // input/output methods for competitive programing

    // cin>>a>>b>>x;    // it use space as deliminater to stop taking input
    // cout<<a<<"\n"<<b<<"\n"<<x<<"\n";
    // getline(cin,x); // used to read whole line with space in btw // it use '\n' (next line character) as deliminater to stop taking input
    // cout<<x<<"\n";
    // freopen("input.txt","r",stdin);  // read input from input.txt
    // freopen("output.txt","w",stdout); // writes output to output.txt

    // in 32bit int range from -2*10^9 - 2*10^9
    // in 64bit long long range from -9*10^18 - 9*10^18
    // in 64bit double/long double for float point number // printf("%0.9f",num); for precision till 9 place
    // long long a=123456789;
    // cout<<a*a<<"\n"<<(int)(a*a);
    // double x=0.3*3+0.1;
    // printf("%0.2f\n",x);

    // typedef $long name$ $short name$; // to shorten code
    // eg:
    // typedef long long ll;
    // MACROS: // certain shortname will change to long name before compilation
    // eg:
    // #define $short name$ $long name$
    // can also macro short function // it just replace variable in function by value given during calling without performing any calculation
    // eg:
    // #define REP(i,a,b) for(int i=a;i<=b;i++)

    // number of digit of an int x base b floor(logb(x) + 1)

    // ch-2

    // O(1) => constant time
    // O(log n) => logarithmic {data structure operation}
    // O(sqrt(n)) => sqrt algo
    // O(n) => linear
    // O(n log n) => {efficient sorting algos}
    // O(n^2) => quadratic
    // O(n^3) => cubic
    // O(2^n) => {recursive algos}
    // O(n!) => {recursive algo}

    // O(1) < O(log n) < O(n) < O(n log n) < O(n^2) < O(2^n) < O(n!)

    // ch-3

    // #include<vector>

    // vector<int> v;
    // v.push_back(3);
    // v.push_back(2);
    // v.push_back(5);
    // v.push_back(9);
    // for(int i=0;i<v.size();i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    // cout<<"\n";
    // v.pop_back();
    // for(auto x:v)  // shorter way to iterate
    // {
    //     cout<<x<<" ";
    // }
    // cout<<"\n";

    // vector<int> vec={1,2,3,4};  // to initalize in starting
    // vector<int> v1(4,-1);       // 4 represent size and fill all 4 indexs with -1 // default is 0
    // for(auto x:vec)  // shorter way to iterate
    // {
    //     cout<<x<<" ";
    // }
    // cout<<"\n";
    // for(auto y:v1)  // shorter way to iterate
    // {
    //     cout<<y<<" ";
    // }

    // #include<string>

    // string name = "somin";
    // cout << name.substr(1, 2) << "\n"
    //      << name + "hi" << "\n"
    //      << name.find("om") << "\n"
    //      << &name[3] << "\n";

    // #include<set> // O(log n) // due to use of balanced tree to maintain order
    // #include<unordered_set> // O(1) // due to use of hash table as it don't care for order
    // both set and unordered_set insert unique value but in different time complexity

    // set<int> s; // set is used mostly like vector but not possible to access the element using []
    // s.insert(3); // also unlike vector it do not store duplicate value
    // s.insert(3);
    // s.insert(4);
    // s.erase(4);
    // s.insert(5);
    // cout << s.count(3) << "\n" // though 3 is inserted twice but the count will be 1 as the uniqness/distinct property of sets
    //      << s.count(4) << "\n"
    //      << s.count(5) << "\n"
    //      << s.count(8) << "\n"
    //      << s.size() << "\n";
    // for(auto y:s)  // shorter way to iterate
    // {
    //     cout<<y<<" ";
    // }

    // #include<unordered_multiset>
    // #include<multiset>
    // both work same as above structures but allow duplicate insertion without maintaining the property of uniqueness/distinct

    // multiset<int> s; // set is used mostly like vector but not possible to access the element using []
    // s.insert(3); // also unlike vector it do store duplicate value
    // s.insert(3);
    // s.insert(3);
    // s.insert(4);
    // s.erase(4);
    // s.insert(5);
    // cout << s.count(3) << "\n" // 3 is inserted twice so the count will be 2 as the uniqness/distinct property of sets is not followed here
    //      << s.count(4) << "\n"
    //      << s.count(5) << "\n"
    //      << s.count(8) << "\n"
    //      << s.size() << "\n";
    // for(auto y:s)  // shorter way to iterate
    // {
    //     cout<<y<<" ";
    // }

    // erasing without using find delete all instances of an element in set
    // s.erase(s.find(3));
    // cout<<"\n"<< s.count(3) << "\n";
    // for(auto y:s)
    // {
    //     cout<<y<<" ";
    // }
    // s.erase(3);
    // cout<<"\n"<< s.count(3) << "\n";
    // for(auto y:s)
    // {
    //     cout<<y<<" ";
    // }

    // #include<map> // O(log n) // due to use of balanced tree to maintain order
    // #include<unordered_map> // O(1) // due to use of hash table as it don't care for order

    // map<string, int> m; // the parameter before comma is key and after comma is value like frequency of key
    // m["somin"] = 4;
    // m["poojan"] = 3;
    // m["om"] = 8;
    // cout << m["om"] << "\n"
    //      << m["dhruv"] << "\n"; // if key not present in map then its default value or frequency is 0
    // if(m.count("om"))
    // {
    //     m["om"]++;
    // }
    // for(auto y:m)
    // {
    //     cout<<y.first<<" "<<y.second<<"\n";
    // }

    // Iterator

    // DS.begin() points to the first element in the data structure DS
    // DS.end() points to the position after the last element

    // eg: sort(DS.begin(),DS.end()); // sort the elements of data structure
    // eg: reverse(DS.begin(),DS.end()); // reverse the element of data structure
    // eg: random_shuffle(DS.begin(),DS.end()); // shuffles the order of the element
    // for any ordinary array a[n] sort(a,a+n);

    // DS<data_type>::iterator it=DS.begin(); or auto it=DS.begin();
    // *it prints value at address it in data structure DS
    // for(auto it=DS.begin();it!=DS.end();it++){} // this can be used directly without initializing iterator
    // it->first/second prints value at address it in data structure DS like map or in one which has pair as a data_type
    // auto it=DS.find(x); return iterator/address that store value x ,if x do not exits in DS the it points to end pointer
    // auto it=lower_bound(x); return address of element just>=x ,if x is greater than greatest in DS then it points to end pointer;
    // auto it=upper_bound(x); return address of element just>x ,if x is greater than greatest in DS then it points to end pointer;
    // above two are not supported by unordered data structure in stl

    // #include<bitset> // store only 0 and 1 default is 0

    // bitset<5> b; // store 5 values indexing from 1-5
    // b[2] = 1;
    // b[4] = 1;
    // bitset<5> b(string("10101")); // start assigning from right to left to index 1
    // cout << b[1] << " " << b[4] << "\n"
    //      << b.count(); // return number of one in the bitset
    // bitset<5> x(string("10101")), y(string("01110"));
    // cout << (x & y) << "\n" // AND gate
    //      << (x | y) << "\n" // OR gate
    //      << (x ^ y) << "\n";// XOR gate

    // include<deque> 

    // deque<int> d; // it is like vector but also allow push and pop from front due to which deque is quite slower than vector 
    // d.push_back(2);
    // d.push_back(3);
    // d.push_front(8);
    // d.push_front(9);
    // for(auto x:d)
    // {
    //     cout<<x<<" ";
    // }
    // cout<<"\n";
    // d.pop_back();
    // d.pop_front();
    // for(auto x:d)
    // {
    //     cout<<x<<" ";
    // }

    // #include<stack> // based on LIFO

    // stack<int> stk;
    // stk.push(5);
    // stk.push(4);
    // stk.push(8);
    // stk.push(9);
    // cout<<stk.top()<<"\n";
    // stk.pop();
    // cout<<stk.top()<<"\n";

    // #include<queue> // based on FIFO

    // queue<int> q;
    // q.push(5);
    // q.push(4);
    // q.push(8);
    // q.push(9);
    // cout<<q.front()<<"\n";
    // q.pop();
    // cout<<q.front()<<"\n";

    // #include<priority_queue>

    // priority_queue<int> pq; // insertion/removal O(log n) & retrival O(1) // values are sorted in decreasing order // work as MAX heap
    // pq.push(5);
    // pq.push(4);
    // pq.push(8);
    // pq.push(1);
    // cout<<pq.top()<<"\n";
    // pq.pop();
    // cout<<pq.top()<<"\n";

    // priority_queue<int,vector<int>,greater<int>> pq; // values are sorted in increasing order // work as MIN heap
    // pq.push(5);
    // pq.push(4);
    // pq.push(8);
    // pq.push(1);
    // cout<<pq.top()<<"\n";
    // pq.pop();
    // cout<<pq.top()<<"\n";

    // Dynamic memory allocation using 
    // Using malloc and calloc
    // int x=5;
    // int *ptr=(int *)malloc(x*sizeof(int));
    // for(int i=0;i<x;i++){
    //     cout<<ptr[i]<<" "; // or
    //     cout<<*(ptr+i)<<" "
    // }
    // free(ptr); 

    // difference in malloc and calloc is that all bits are set to zero by default
    // int x=5;
    // int *ptr=(int *)calloc(x*sizeof(int));
    // for(int i=0;i<x;i++){
    //     cout<<ptr[i]<<" "; // or
    //     cout<<*(ptr+i)<<" "
    // }
    // free(ptr); 

    // int x=5;
    // // for array
    // int *arr=new int[x];
    // delete [] arr;
    // // for variable or node of any class
    // node* head=new node;
    // delete node;
    return 0;
}