#include <iostream>
#include <string>
using namespace std;

class Student {

    public:

    string name;
    int age;
    int rank;


    public:

    void setVal(string name, int age, int rank) {
        this->name = name;
        this->age = age;
        this->rank = rank;
    }

    void print() {
        cout << name << ", age: " << age << ", rank: " << rank << endl;
    }

};

int main() {

    Student s1;
    s1.setVal("aaa", 19, 12);
    s1.print();

    Student s3(s1);
    s3.print();

    s1.age = 100;
    s1.print();
    s3.print();

}