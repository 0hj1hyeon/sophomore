#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person();
    Person(string n,int a);


    string getName() { return name; };
    void setName(string n) { name = n; };
    int getAge() { return age; };
    void setAge(int a) { age = a; };

};

Person::Person() {
    name = "";
    age = 0;
}


Person::Person(string n, int a) {

    name = n;
    age = a;
}

class Family {
private:
    string surname;
    int nummembers;
    Person fp[100];
    
public:
    Family(string sn, int m);

    string getSurname() { return surname; };
    void setSurname(string sn) { surname = sn; };
    int getNummembers() { return nummembers; };
    void setNUmmembers(int m) { nummembers = m; };
    void showMembers(int n) {
        for (int i = 1; i <= n; i++) {
            string name = fp[i].getName();
            int age = fp[i].getAge();
            cout << name << "            " << age << endl;
        }
    
    }
    void setMembers() {
        string name;
        int age;
      
        for (int i = 1; i <= nummembers; i++) {
            cout << "Enter a name: "; 
            cin >> name;
            cout << "Enter a age: ";
            cin >> age;
            fp[i].setName(name);
            fp[i].setAge(age);
        }
        

    }
};

Family::Family(string sn, int m) {
    surname = sn;
    nummembers = m;
}

void show(Family *f) {
    cout << "Name         Age" << endl;
    int n = f->getNummembers();
    f->showMembers(n);
}


int main()
{
    Family* f;
    string surname;
    int num;

    cout << "Enter your family name: ";
    cin >> surname;
    cout << "Enter How many people?: ";
    cin >> num;
    
    f = new Family(surname, num);
    cout << "당신의 가족의 각 구성원에 대해서 이름과 나이를 입력하세요." << endl;
    f->setMembers();
    show(f);

    delete f;
}

    