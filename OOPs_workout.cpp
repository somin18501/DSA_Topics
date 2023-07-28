#include<iostream> 
using namespace std;

// class BaseClass1 { 
// public: 
//     BaseClass1() 
//     { cout << "BaseClass1 constructor called" << endl;  } 
// }; 
 
// class BaseClass2 { 
// public: 
//     BaseClass2() 
//     { cout << "BaseClass2 constructor called" << endl;  } 
// }; 
 
// class DerivedClass: public BaseClass1, public BaseClass2 { 
//   public: 
//    DerivedClass() 
//     {  cout << "DerivedClass constructor called" << endl;  } 
// }; 
 
// int main() 
// { 
//   DerivedClass derived_class; 
//  // Run to see Output:
//  // Reason:
//  // The above program demonstrates Multiple inheritances. So when the Derived class’s constructor is called, it automatically calls the Base class's constructors from left to right order of inheritance.
//   return 0; 
// }

 
// class BaseClass{ 
//    int arr[10];      
// }; 
 
// class DerivedBaseClass1: public BaseClass { }; 
 
// class DerivedBaseClass2: public BaseClass { }; 
 
// class DerivedClass: public DerivedBaseClass1, public DerivedBaseClass2{}; 
 
// int main(void) 
// {  
//  cout<<sizeof(DerivedClass);
//  // here DerivedClass is using Multiple inheritance hence it has 2 copies of arr from both derivedBaseClass  
//  return 0; 
// }

// class A { 
// public: 
//   void print() 
//   { cout <<" Inside A::"; } 
// }; 
 
// class B : public A { 
// public: 
//   void print() 
//   { cout <<" Inside B"; } 
// }; 
 
// class C: public B { 
// }; 
 
// int main(void) 
// { 
//  C c; 
 
//  c.print(); 
//  return 0; 
// }