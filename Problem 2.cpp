// Lecture06.cpp : This file contains the 'main' function. Program execution begins and ends there.

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
        return "Person named " + name + " has phone number " + phone + " and can be reached at " + email;
        // updated formatting - see previous below
        // string res = "Person named " + name + " has phone number " + phone + " and can be reached at " + email;
        // return res;
    }
    virtual ~Person()
    {
    }

};

class Student :public Person
{
private:
    string year;
public:
    Student(string n, string p, string e, string y)
        :Person(n, p, e), year(y) {
    }
    string toString() override
    {
        return Person::toString() + " is in the " + year + " year";
        // updated formatting - see previous below
        // string res = Person::toString();
        // res += " is in the " + year + " year.";
        // return res;

    }
};

class Employee :public Person
{
private:
    double salary;
public:
    Employee(string n, string p, string e, double s)
        :Person(n, p, e), salary(s) {
    } // Initialize the salady data member
    string toString() override
    {
        return Person::toString() + " earns " + to_string(salary) + " annually";
        // updated formatting - see previous below
        // string res = Person::toString();
        // res += " earns " + to_string(salary) + " annually ";
        // return res;
    }

};

class Faculty :public Employee
{
private:
    string title;
public:
    Faculty(string n, string p, string e, double s, string t)
        :Employee(n, p, e, s), title(t) {
    }

    string toString() override
    {
        return Employee::toString() + " is a/an " + title;
        // updated formatting - see previous below
        // string res = Employee::toString();
        // res += "is a/an " + title;
        // return res;
    }
};

class Staff :public Employee
{
private:
    string role;
public:
    Staff(string n, string p, string e, double s, string r)
        :Employee(n, p, e, s), role(r) {
    }

    string toString() override
    {
        return Employee::toString() + " handles " + role;
    }
};

int main()
{
    //Implement polymorphism
    vector<Person*> list;

    //Person* temp = new Student("Alice", "456-123-7890", "alice@nu.edu", "second");
    list.push_back(new Student("Alice", "456-123-7890", "alice@nu.edu", "freshman"));
    list.push_back(new Person("David", "123-456-7890", "david@nu.edu"));
    list.push_back(new Employee("Mary", "159-845-1948", "mary@nu.edu", 150000));
    list.push_back(new Faculty("Jerry", "159-789-4958", "jerry@nu.edu", 25000, "adjunct faculty"));
    list.push_back(new Staff("Jessica", "987-555-0909", "jessica@nu.edu", 110000, "registration"));

    for (Person* p : list)
    {
        cout << p->toString() << endl;
        delete p;
    }
    return 0;
}
