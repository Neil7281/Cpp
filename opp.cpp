#include <iostream>
using namespace std;

// Class that represents a person
class Person {
    
    // private members that will be hidden
    int socialID;
    
public:
     string name;
    // public members that are accessible
    // Person(string name, int socialID) {   // constructor 
    //     this->name = name;
    //     this->socialID = socialID;
    // }
    string getName() {
        return name;
    }
    bool validateID() {
        if (socialID <= 1001 && socialID >= 0)
            return true;
        else
            return false;
    }
    ~Person(){
        cout<<"parent class"<<endl;
    }
};
class adult: public Person {  // inheritance
    public: 
    ~adult(){
    cout<<"child class"<<endl;
    }

};

int main() {
    
    // Person p1("Shubham", 503);
    // if (!p1.validateID()) cout << "Invalid SocialID\n"<<endl;
    
    // cout << p1.getName()<<endl;
    // Person p2(p1);
    // p2.name = "Neel";
    // cout << p2.getName();
    adult a1;
    return 0;
}
