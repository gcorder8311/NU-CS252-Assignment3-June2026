// Lecture06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person
{
private: // Data members are defined in the private section
    string name;
    string phone;
    string email;
public:
    Person(string n, string p, string e)
    {
        name = n;
        phone = p;
        email = e;
    }
    virtual string toString()
    {
        string res = "Person named " + name + " has phone number " + phone + " and can be reached at " + email;
        return res;
    }

};

class Student :public Person
{
private:
    string year;
public:
    Student(string n, string p, string e, string y)
        :Person(n, p, e), year(y) { }
    string toString() override
    {
        string res = Person::toString();
        res += " is in the " + year + " year.";
        return res;

    }
};

class Employee :public Person
{
private: 
    double salary;
public:
    Employee(string n, string p, string e, double s)
        :Person(n, p, e), salary(s) { } // Initialize the salady data member
    string toString() override
    {
        string res = Person::toString();
        res += " earns " + to_string(salary) + " annually ";
        return res;
    }

};

class Faculty :public Employee
{
private:
    string title;
public: 
    Faculty(string n, string p, string e, double s, string t)
        :Employee(n, p, e, s), title(t){ }

    string toString() override
    {
        string res = Employee::toString();
        res += "is a/an " + title;
        return res;
    }
};



//PENDING: Class called Staff that subclasses Employee and adds a role



int main()
{
    //Implement polymorphism
    vector<Person*> list;

    //Person* temp = new Student("Alice", "456-123-7890", "alice@nu.edu", "second");
    list.push_back(new Student("Alice", "456-123-7890", "alice@nu.edu", "freshman"));
    list.push_back(new Person("David", "123-456-7890", "david@nu.edu"));
    list.push_back(new Employee("Mary", "159-845-1948", "mary@nu.edu", 15000));
    list.push_back(new Faculty("Jerry", "159-789-4958", "jerry@nu.edu", 10000, "adjuct faculty"));

    for (auto m : list)
    {
        cout << m->toString() << endl;
        delete m;
    }

   /* Person p("David", "123-456-7890", "david@nu.edu");
    cout << p.toString() << endl;
    Student s("Alice", "456-123-7890", "alice@nu.edu", "freshman");
    cout << s.toString() << endl;
    Employee e("Mary", "159-845-1948", "mary@nu.edu", 15000);
    cout << e.toString() << endl;
    Faculty f("Jerry", "159-789-4958", "jerry@nu.edu", 10000, "adjuct faculty");*/


}


