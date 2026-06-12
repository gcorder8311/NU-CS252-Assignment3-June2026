//Critter is an ePet. It has a name!

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Critter
{
private: // All data attributes must be declared in the Private section - ENCAPSULATION
    string name;
    int hunger;
    int boredom;


public: 
    Critter(string n, int h, int b)      // Need a constructor
    {
        name = n;
        hunger = h;
        boredom = b;
    }

    Critter() // Default constructor = A constructor with an empty parameter list
    {
        name = " "; hunger = 0; boredom = 0;
    }

    virtual void greet() = 0; // Pure virtual method
                              // A class with at least one pure virtual method is an abstract class. 
                              // Always lovated in the base class. 
    /*{
        cout << "My name is "
            << name << ". ";
        cout << "My hunger level is "
            << hunger << ". ";
        cout << "My boredom level is "
            << boredom << ". ";
    }*/
    // Getter method 
    string getName() const
    {
        return name;
    }

    // Setter method
    void setName(string newName)
    {
        name = newName;
    }
};

class Dog :public Critter
{
private:
    string breed;

public:
    // always provide a constructor
    Dog(string n, int h, int b, string bre)
        :Critter(n, h, b), breed(bre) {
    }
    Dog() :Critter() {}
    
    void greet() override  // Always located in the derived class. 
    {
        cout << "Woof, woof, woof...." << endl;
    }
};

class Snake :public Critter
{
public:
    Snake() :Critter() {}
    void greet() override {
        cout << "Hissss, Hisss, Hisss ..." << endl;
    }

};

class Duck :public Critter
{
public:
    Duck() :Critter() {}
    void greet() override {
        cout << "Quack, quack, quack...." << endl;
    }
};

class Bear :public Critter
{
public:
    Bear() :Critter() {}
    void greet() override {
        cout << "Growl, growl, gorwl...." << endl;
    }
};



int main() // In the main function we don't have access to the Private data
{
    //Critter c("Charlie", 5, 10);
    //c.greet(); // How to call a method/function - Call an object
    //cout << endl;
    //cout << "What is your name? " << endl;
    //cout << "My name is " << c.getName() << endl; // We must access attributes from the private data with the getter method. 

    //cout << "I want to change your name to David. \n";
    //c.setName("David"); // To modify the data, we need to use the setter method
    //c.greet();
    //cout << endl << endl;

    //Dog d("Carey", 2, 7, "Greyhound");
    //d.greet();

    vector<Critter*> critters;

    Critter* demo = new Dog();
    critters.push_back(demo);


    critters.push_back(new Dog());
    critters.push_back(new Snake());
    critters.push_back(new Duck());
    critters.push_back(new Bear());
    critters.push_back(new Dog());
    critters.push_back(new Snake());
    critters.push_back(new Duck());
    critters.push_back(new Bear());
    for (auto c : critters) {
        c->greet();
        delete c;
    }

}


