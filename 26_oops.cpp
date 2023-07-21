#include <bits/stdc++.h>

// #include "Hero.cpp" // to include external class file
using namespace std;

class Hero{
    // properties // by default access modifier is private
    private: // can be access only from within the class
    int health;
    public:
    int level; // data members
    char *name;
    static int timeLeft;

    int getHealth(){
        return health;
    }
    void setHealth(int x){
        health = x;
    }
    void setName(char *name){
        strcpy(this->name,name);
    }
    void PrintMembers(){
        cout<<this->name<<" "<<this->level<<" "<<health<<endl;
    }

    Hero(){ // as we create our contructor the default contructor of system does not exists 
        cout<<"our constructor called"<<endl;
        name=new char[100];
    }
    Hero(int health){
        cout<<"address of this: "<<this<<endl;
        this->health = health; // this is a pointer that points to address of current object 
    }
    Hero(int x,int y){
        this->level=x;
        health=y;
    }
    Hero(Hero &temp){ // always pass by reference in copy contructor
        char *ch=new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        name=ch;
        cout<<"Hi I am copy contructor\n";
        this->level=temp.level;
        health=temp.health;
    }

    ~Hero(){
        cout<<"Our Destructor called"<<endl;
    }

    static int random(){
        return timeLeft;
    }
};

// its value is same for all object of this class 
int Hero::timeLeft =5; // to initialize static data member

// Classes for Inheritance:

// Here Human is Base/Super Class
// Private data members of any class can not be inherited
class Human{
private:
    int age;
protected:
    int weight;
public:
    int height;

    void setWeight(int x){
        this->weight=x;
    }
    void Sound(){
        cout<<"Humans speaks\n";
    }
};

class Animal{
public:
    // below is pure virtual function
    virtual void category() = 0; 

    // below is normal member function 
    void Sound(){
        cout<<"Animals barks\n";
    }
};

// Here Male is Child/Sub class 
class Male:public Human,public Animal{
    public:
    string col;

    void sleep(){
        cout<<"Male is sleeping\n";
    }

    // for protected/private mode
    int getHeight(){
        return this->height;
    }
    int getWeight(){
        return this->weight;
    }
    // // Not allowed as age is private in super class and hence can not be inherited in any mode
    // int getAge(){
    //     return this->age;
    // }
};
// protected is similar to private as it do not allow to access data members from outside the class
// But we can access it outside the class only from inside the child/sub class if it exist or from any class derived from child class which inherits the base class in protected mode

class Dog:public Animal{
public:
    void category(){
        cout<<"Dog is mamal\n";
    }
}; 

class A{
public:
    void sayHello(){
        cout<<"Helu Somin\n";
    }
    void sayHello(string x){
        cout<<"Hello "<<x<<endl;
    }
    int sayHello(char *x){
        cout<<"Hello "<<x<<endl;
        return 1;
    }
};

class B{
public:
    int a;

    void operator+(B &obj){
        cout<<this->a-obj.a<<endl;
        cout<<"Hi Somin\n";
    }
    void operator()(){
        cout<<"hi Somin "<<this->a<<endl;
    }
};

class parent{
public:
    void Print(){
        cout<<"I am Parent\n";
    }
};

class child1:public parent{
public:
    void Print(){
        cout<<"I am child 1\n";
    }
};

class Rectangle{
private:
    int l;
protected:
    int w;
public:
    Rectangle(){
        l=10;
        w=20;
    }
    // friend function declaration
    friend int getArea(Rectangle);
};

// defining function definition
int getArea(Rectangle R){
    return R.l*R.w;
}

int main(){
    /*
        Hero h1; // it is static allocation

        // cout<<sizeof(h1)<<endl; // as only level is integer type variable so it return 4
        // cout<<sizeof(h1)<<endl; // if class is empty then also 1byte is assigned as for its identification
        
        h1.level = 18;
        cout<<h1.level<<endl;

        // h1.health = 18; // can not assign as it is private member
        // cout<<h1.health<<endl; // gives error as health is private

        // to access private members we can create member functions to get and set their value 
        h1.setHealth(18);
        cout<<h1.getHealth()<<endl;
    */

    /*
        Hero *h2 = new Hero;
        h2->level=18;
        cout<<h2->level<<endl;
        cout<<(*h2).level<<endl;
        h2->setHealth(18);
        cout<<(*h2).getHealth()<<endl;
    */

    /*
        // when ever we create object constructor is first called and has no return type it may or may not be parameterized
        cout<<"hi\n";
        Hero h3;
        Hero *h4=new Hero;
        cout<<"by\n";

        Hero h5(20);
        cout<<"Address of object: "<<&h5<<endl;
        cout<<h5.getHealth()<<endl;

        Hero* h6=new Hero(20);
        cout<<h6->getHealth()<<endl;

        Hero h7(27,30);
        cout<<h7.level<<endl;
        cout<<h7.getHealth()<<endl;

        Hero h8(19);
        cout<<h8.level<<endl;
        cout<<h8.getHealth()<<endl;
    */

    /*
        // copy constructor
        // default copy constructor do shallow copy and do not exists if we create our own copy constructor
        Hero h9(19,20);
        h9.PrintMembers();
        Hero h10(h9); // generate inbuilt copy constructor
        Hero h11 = h9;
        h10.PrintMembers();
        h11.PrintMembers();
    */

    /*
        // Shallow copy example
        Hero s1;
        s1.setHealth(27);
        s1.level=30;
        char name[6]="somin";
        s1.setName(name);
        s1.PrintMembers();
        // create Hero s2 with default copy constructor
        Hero s2=s1;
        s2.PrintMembers();
        s1.name[0]='t';
        s1.PrintMembers();
        s2.PrintMembers();// change in s1 reflected in s2 as default copy constructor pass the reference instead of creating seperate copy
    */

    /*
        Hero s1;
        s1.setHealth(27);
        s1.level=30;
        char name[6]="somin";
        s1.setName(name);
        s1.PrintMembers();
        // create Hero s2 with our copy constructor
        Hero s2=s1;
        s2.PrintMembers();
        s1.name[0]='t';
        s1.PrintMembers();
        s2.PrintMembers();// now it do not changed in s2 as we did deep copy in our copy constructor
    */

    /*
        Hero s1;
        s1.setHealth(27);
        s1.level=30;
        char name[6]="somin";
        s1.setName(name);
        s1.PrintMembers();

        Hero s2;
        s2.setHealth(28);
        s2.level=40;
        char name2[6]="poo";
        s2.setName(name2);
        s2.PrintMembers();

        s1=s2; // it is copy assignment operator as it copies assign value of s2 to s1
        s1.PrintMembers();
        s2.PrintMembers();
    */

    /*
        // destructor: it has no return type and take no i/p parameters, used to deallocate memory
        // static object // destructor is called automatically only for static objects not for dynamic
        Hero s1;
        // Dynamic object // for dynamic objects we need to call destructor manually
        Hero *s2=new Hero;
        delete s2; // this will call destructor for dynamic object now
    */

    /*
        // static keyword
        // static members // we do not need to create the object to access static variables
        cout<<Hero::timeLeft<<endl;
        // static functions: similarly we do not need to create object to call static objects
        // static functions do not have this keyword as this points to current object and static keywords make it independent of object 
        // static functions can only access static members
        cout<<Hero::random()<<endl;
    */

    // Encapsulation: Infomation hiding 
    // In fully encapsulated class all data members are private

    /*
        // About Inheritance
        Male obj;
        obj.setWeight(51);
        cout<<obj.height<<endl;
        cout<<obj.weight<<endl;
        cout<<obj.col<<endl;
        obj.sleep();
    */

    /*
        // Mode of inheritance
        // Male m1;
        // Base class access modifier: Public, Mode: Public
        // cout<<m1.height<<endl; // accessible

        // Base class access modifier: Public, Mode: Protected
        // cout<<m1.height<<endl; // not accessible
        // cout<<m1.getHeight()<<endl; // accessible

        // Base class access modifier: Public, Mode: Private
        // cout<<m1.height<<endl; // not accessible
        // cout<<m1.getHeight()<<endl; // accessible

        // Base class access modifier: Protected, Mode: Public
        // cout<<m1.weight<<endl; // not accessible
        // cout<<m1.getWeight()<<endl; // accessible

        // Base class access modifier: Protected, Mode: Protected
        // cout<<m1.weight<<endl; // not accessible
        // cout<<m1.getWeight()<<endl; // accessible

        // Base class access modifier: Protected, Mode: Private
        // cout<<m1.weight<<endl; // not accessible
        // cout<<m1.getWeight()<<endl; // accessible
    */

    // Types of Inheritance
    // 1) Single
    // 2) Multi-level (extending single)
    // 3) Multiple (sub class inherit from two different parent class)
    // 4) Hierarchical (1 Parent class may be inherited by more than 1 sub classes)
    // 5) Hybrid (combination of multiple and hierarchical)

    /*
        // ambiguity in inheritance can be solved using scope resolution operator
        // Male m1; // this is also example of multiple inheritance
        // m1.Human::Sound();
        // m1.Animal::Sound();
    */

    // Types of Polymorphism
    // 1) Complie time(also known as static polymorphism)
    // 2) Run time(also known as dynamic polymorphism)

    // Compile Time Polymorphism:
    // 1) Function Overloading
    // 2) Operator Overloading

    // Function Overloading allowed only when there is a change in the input arguments of two functions with same name
    // A obj;
    // obj.sayHello();

    // Operator overloading: in c++ all operators can be operloaded except 4 (look on internet for that) 
    // B obj1;
    // obj1.a=10;
    // B obj2;
    // obj2.a=5;
    // obj1+obj2; // obj1 calls overloaded + function taking obj2 as second operand
    // obj1(); // obj1 calls overloaded () function
    
    // Run Time Polymorphism:
    // 1) Method Overriding: function name same, function argument same, inherited

    // child1 obj;
    // // it overrids the Print function of parent
    // obj.Print(); // it runs function of subclass rather than base if Print is defined in sub class;
    // obj.parent::Print(); // it runs function of parent class due to definition of scope
    
    // Abstraction: Implementation hiding
    
    // Interface (creating abstract class using pure virtual function)
    // Dog dg;
    // dg.category();
    // dg.Sound();

    // friend function concept
    // Rectangle R;
    // cout<<getArea(R)<<endl;
    return 0;
}