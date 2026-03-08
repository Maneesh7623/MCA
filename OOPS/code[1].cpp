Program - 1: Enumeration

#include <iostream>
using namespace std;
enum week {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
int main()
{
  week today;
  today = Wednesday;
  cout <<"Day"<<today+1;
  return 0;
}
---------------------------------------------------------------------------------

Program - 2: Function Overloading

#include <iostream>
using namespace std;
void display(int);
void display(float);
void display(int, float);
int main()
{
  int a=5;
  float b=5.5;
  display(a);
  display(b);
  return 0;
}
void display(int var)
{
  cout<<"Integer Number:"<<var<<endl;
}
void display(float var)
{
  cout<<"Float Number:"<<var<<endl;
}
void display(int var1, float var2)
{
    cout<<"Integer Number:"<<var1;
    cout<<"and Float Number:"<<var2;
}
-----------------------------------------------------------------------------------

Program - 3: Scope

#include <iostream>
using namespace std;
int multiply(int a,int b)
{
    return a*b;
}
int main()
{
    int x=3, y=5;
    int z;
    z=multiply(x,y);
    cout<<z<<endl;
    return 0;
}
--------------------------------------------------------------------------------------

Program - 4: Storage Classes

#include <iostream>
using namespace std;
void autoStorageClass()
{
    cout << "Demonstrating auto class\n";
    auto a =32;
    auto b = 3.2;
    auto c = "Program for storage classes";
    auto d = "Storage Classes";
    cout << a << " \n";
    cout <<b <<" \n";
    cout << c <<"\n";
    cout << d <<"\n";
}
int main()
{
    autoStorageClass();
    return 0;
}
-----------------------------------------------------------------------------

Program - 5: Constructor and Destructor

#include <iostream>
using namespace std;
class Line
{
public:
    void setLength(double len);
    double getLength(void);
    Line();
    ~Line();
private:
    double length;
};
Line::Line(void)
{
    cout << "Object is being created" << endl;
}
Line::~Line(void)
{
    cout << "Object is being deleted" << endl;
}
void Line::setLength(double len)
{
    length = len;
}
double Line::getLength(void)
{
    return length;
}
int main()
{
    Line line;
    line.setLength(6.0);
    cout << "Length of Line: " << line.getLength() << endl;
    return 0;
}
---------------------------------------------------------------------------------

Program - 6: Constructor Overloading

#include <iostream>
using namespace std;
class Area
{
private:
    int length;
    int breadth;
public:
    Area() : length(5), breadth(2) {}
    Area(int l, int b) : length(l), breadth(b) {}
    void GetLength()
    {
        cout << "Enter length and breadth respectively: ";
        cin >> length >> breadth;
    }
    int AreaCalculation()
    {
        return length * breadth;
    }
    void DisplayArea(int temp)
    {
        cout << "Area: " << temp << endl;
    }
};
int main()
{
    Area A1, A2(2, 1);
    int temp;
    cout << "Default Area when no argument is passed." << endl;
    temp = A1.AreaCalculation();
    A1.DisplayArea(temp);
    cout << "Area when (2,1) is passed as argument." << endl;
    temp = A2.AreaCalculation();
    A2.DisplayArea(temp);
    return 0;
}
-----------------------------------------------------------------------------------------

Program - 7: Call by Value and Call by Reference

#include <iostream>
using namespace std;
void swap(int &x, int &y);
int main()
{
    int a = 100;
    int b = 200;
    cout << "Before swap, value of a :" << a << endl;
    cout << "Before swap, value of b :" << b << endl;
    swap(a, b);
    cout << "After swap, value of a :" << a << endl;
    cout << "After swap, value of b :" << b << endl;
    return 0;
}
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
-----------------------------------------------------------------------------------

Program - 8: Static Member and Methods

#include <iostream>
using namespace std;
class Demo
{
private:
    static int X;
    static int Y;
public:
    static void Print()
    {
        cout << "Value of X: " << X << endl;
        cout << "Value of Y: " << Y << endl;
    }
};

int Demo::X = 10;
int Demo::Y = 20;
int main()
{
    Demo OB;
    cout << "Printing through object name:" << endl;
    OB.Print();
    cout << "Printing through class name:" << endl;
    Demo::Print();
    return 0;
}
------------------------------------------------------------------------------------------

Program - 9: Bit Fields

#include <stdio.h>
#include <string.h>
struct {
    unsigned int widthValidated;
    unsigned int heightValidated;
} status1;
struct {
    unsigned int widthValidated : 1;
    unsigned int heightValidated : 1;
} status2;
int main()
{
    printf("Memory size occupied by status1: %d\n", sizeof(status1));
    printf("Memory size occupied by status2: %d\n", sizeof(status2));
    return 0;
}
--------------------------------------------------------------------------------------

Program - 10: Overload Binary Operator using Member Function

#include <iostream>
class Cents
{
private:
    int m_cents;
public:
    Cents(int cents) { m_cents = cents; }
    friend Cents operator+(const Cents &cents, int value);
    int getCents() { return m_cents; }
};
Cents operator+(const Cents &cents, int value)
{
    return Cents(cents.m_cents + value);
}
int main()
{
    Cents cents1(6);
    Cents cents2 = cents1 + 2;
    std::cout << "I have " << cents2.getCents() << " cents.\n";
    return 0;
}
------------------------------------------------------------------------------------

Program - 11: Overlaod as Friend

#include <iostream>
using namespace std;
class UnaryFriend
{
    int a = 10;
    int b = 20;
    int c = 30;
public:
    void getvalues()
    {
        cout << "Values of A, B & C\n";
        cout << a << "\n" << b << "\n" << c << "\n" << endl;
    }
    void show()
    {
        cout << a << "\n" << b << "\n" << c << "\n" << endl;
    }
    friend void operator-(UnaryFriend &x);
};
void operator-(UnaryFriend &x)
{
    x.a = -x.a;
    x.b = -x.b;
    x.c = -x.c;
}
int main()
{
    UnaryFriend x1;
    x1.getvalues();
    cout << "Before Overloading\n";
    x1.show();
    cout << "After Overloading\n";
    -x1;
    x1.show();
    return 0;
}
------------------------------------------------------------------------------------------

Program - 12: Overload unary operator in Postfix and Prefix Form

#include <iostream>
using namespace std;
class Integer
{
private:
    int i;
public:
    Integer(int i = 0)
    {
        this->i = i;
    }
    Integer operator++()
    {
        Integer temp;
        temp.i = ++i;
        return temp;
    }
    void display()
    {
        cout << "i = " << i << endl;
    }
};
int main()
{
    Integer i1(3);
    cout << "Before increment: ";
    i1.display();
    Integer i2 = ++i1;
    cout << "After pre increment: ";
    i2.display();
    return 0;
}
----------------------------------------------------------------------------------

Program - 13: Iterators

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    vector<int>::iterator itr;
    for (int i = 0; i < 5; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    for (itr = v.begin(); itr != v.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << "\n";
    v.push_back(10);
    for (int i = 0; i < 6; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    for (itr = v.begin(); itr != v.end(); itr++)
    {
        cout << *itr << " ";
    }
    return 0;
}
--------------------------------------------------------------------------------------------

Program - 14: Containers

#include <iostream>
using namespace std;
class first
{
public:
    first()
    {
        cout << "Hello from first class\n";
    }
};
class second
{
    first f;
public:
    second()
    {
        cout << "Hello from second class\n";
    }
};
int main()
{
    second s;
    return 0;
}
---------------------------------------------------------------------------------------

Program - 15: Function Templates

#include <iostream>
using namespace std;
template <typename T>
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}
int main()
{
    cout << myMax<int>(3, 7) << endl;
    cout << myMax<double>(3.0, 7.0) << endl;
    cout << myMax<char>('g', 'e') << endl;
    return 0;
}
-----------------------------------------------------------------------------------------

Program - 16: Template Class

#include <iostream>
using namespace std;
template <typename T>
class Array
{
private:
    T* ptr;
    int size;
public:
    Array(T arr[], int s);
    void print();
    ~Array();
};
template <typename T>
Array<T>::Array(T arr[], int s)
{
    size = s;
    ptr = new T[size];
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}
template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << " " << ptr[i];
    cout << endl;
}
template <typename T>
Array<T>::~Array()
{
    delete[] ptr;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    Array<int> a(arr, 5);
    a.print();
    return 0;
}
----------------------------------------------------------------------------------------

Program- 17: Virtual Functions

#include <iostream>
using namespace std;
class base
{
public:
    virtual void print()
    {
        cout << "print base class" << endl;
    }
    void show()
    {
        cout << "show base class" << endl;
    }
};
class derived : public base
{
public:
    void print()
    {
        cout << "print derived class" << endl;
    }
    void show()
    {
        cout << "show derived class" << endl;
    }
};
int main()
{
    base* bptr;
    derived d;
    bptr = &d;
    bptr->print(); 
    bptr->show();   
    return 0;
}
---------------------------------------------------------------------------------------

Program - 18: Exception Handling

#include <iostream>
using namespace std;
int main()
{
    int x = -1;

    cout << "Before try\n";
    try
    {
        cout << "Inside try\n";
        if (x < 0)
        {
            throw x;
            cout << "After throw (Never executed)\n";
        }
    }
    catch (int x)
    {
        cout << "Exception Caught\n";
    }
    cout << "After catch (Will be executed)\n";
    return 0;
}
------------------------------------------------------------------------------------------

Program - 19: File Handling - Read

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream myfile;
    myfile.open("example.txt");
    if (myfile.is_open())
    {
        myfile << "Writing this to a file.\n";
        myfile.close();
        cout << "File written successfully.\n";
    }
    else
    {
        cout << "Unable to open file.\n";
    }
    return 0;
}
-----------------------------------------------------------------------------------------

Program - 20: File Handling - Write

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream myfile("example.txt");
    if (myfile.is_open())
    {
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    return 0;
}
------------------------------------------------------------------------------------------

Program - 21: File Handling - Update

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string line;
    ifstream myfile("example.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << endl;
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    return 0;
}
-------------------------------------------------------------------------------------------

Program - 22: Stack with necessary exception handling

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
class MyException {};
class Dummy
{
public:
    Dummy(string s) : MyName(s)
    {
        PrintMsg("Created Dummy: ");
    }
    Dummy(const Dummy& other) : MyName(other.MyName)
    {
        PrintMsg("Copy created Dummy: ");
    }
    ~Dummy()
    {
        PrintMsg("Destroyed Dummy: ");
    }
    void PrintMsg(string s)
    {
        cout << s << MyName << endl;
    }
    string MyName;
    int level;
};
void C(Dummy d, int i)
{
    cout << "Entering FunctionC" << endl;
    d.MyName = "C";
    throw MyException();
    cout << "Exiting FunctionC" << endl; // never executed
}
void B(Dummy d, int i)
{
    cout << "Entering FunctionB" << endl;
    d.MyName = "B";
    C(d, i + 1);
    cout << "Exiting FunctionB" << endl;
}
void A(Dummy d, int i)
{
    cout << "Entering FunctionA" << endl;
    d.MyName = "A";
    Dummy* pd = new Dummy("new Dummy");
    B(d, i + 1);
    delete pd; 
    cout << "Exiting FunctionA" << endl;
}
int main()
{
    cout << "Entering main" << endl;
    try
    {
        Dummy d("M");
        A(d, 1);
    }
    catch (MyException& e)
    {
        cout << "Caught an exception of type: "
             << typeid(e).name() << endl;
    }
    cout << "Exiting main." << endl;
    char c;
    cin >> c;
    return 0;
}
-----------------------------------------------------------------------------------------

Program - 23: Queue with necessary exception handling

#include <iostream>
#include <queue>
int main ()
{
    std::queue<int> myqueue;
    myqueue.push(77);
    myqueue.push(16);
    myqueue.front() -= myqueue.back();
    std::cout << "myqueue.front() is now "
              << myqueue.front() << '\n';
    return 0;
}
------------------------------------------------------------------------------------------

Program - 24: Manage Bank account using Inheritance concept using C++

#include <iostream>
#include <string>
using namespace std;
class Account
{
protected:
    string cust_name;
    int acc_no;
    string acc_type;
public:
    void get_accinfo()
    {
        cout << "Enter Customer Name: ";
        cin >> cust_name;
        cout << "Enter Account Number: ";
        cin >> acc_no;
        cout << "Enter Account Type: ";
        cin >> acc_type;
    }
    void display_accinfo()
    {
        cout << "\nCustomer Name: " << cust_name;
        cout << "\nAccount Number: " << acc_no;
        cout << "\nAccount Type: " << acc_type;
    }
};
class cur_acct : public Account
{
    static float balance;
public:
    void deposit()
    {
        float amt;
        cout << "Enter amount to deposit: ";
        cin >> amt;
        balance += amt;
    }
    void withdraw()
    {
        float amt;
        cout << "Enter amount to withdraw: ";
        cin >> amt;
        if (amt > balance)
            cout << "Insufficient balance\n";
        else
            balance -= amt;
        if (balance < 500)
            balance -= 50;   
    }
    void display()
    {
        cout << "\nCurrent Balance: " << balance << endl;
    }
};
float cur_acct::balance = 1000;
class sav_acct : public Account
{
    static float savbal;
public:
    void deposit()
    {
        float amt;
        cout << "Enter amount to deposit: ";
        cin >> amt;
        savbal += amt;
        savbal += (savbal * 2) / 100; 
    }
    void withdraw()
    {
        float amt;
        cout << "Enter amount to withdraw: ";
        cin >> amt;
        if (amt > savbal)
            cout << "Insufficient balance\n";
        else
            savbal -= amt;
    }
    void display()
    {
        cout << "\nSavings Balance: " << savbal << endl;
    }
};
float sav_acct::savbal = 2000;
int main()
{
    char type;
    cout << "Enter S for Savings or C for Current account: ";
    cin >> type;
    int choice;
    if (type == 'S' || type == 's')
    {
        sav_acct s;
        s.get_accinfo();
        do
        {
            cout << "\n1.Deposit  2.Withdraw  3.Display  4.Exit\n";
            cin >> choice;
            switch (choice)
            {
            case 1: s.deposit(); break;
            case 2: s.withdraw(); break;
            case 3:
                s.display_accinfo();
                s.display();
                break;
            }
        } while (choice != 4);
    }
    else
    {
        cur_acct c;
        c.get_accinfo();
        do
        {
            cout << "\n1.Deposit  2.Withdraw  3.Display  4.Exit\n";
            cin >> choice;
            switch (choice)
            {
            case 1: c.deposit(); break;
            case 2: c.withdraw(); break;
            case 3:
                c.display_accinfo();
                c.display();
                break;
            }
        } while (choice != 4);
    }
    return 0;
}
-----------------------------------------------------------------------------------------------------------------


--------------------------------------------------------------------------------------------
