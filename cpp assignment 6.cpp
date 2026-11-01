#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
        cout << "Person Constructor Called" << endl;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    ~Person() {
        cout << "Person Destructor Called" << endl;
    }
};

class Student : public Person {
protected:
    int rollNo;
    float marks;

public:
    Student(string n, int a, int r, float m)
        : Person(n, a) {
        rollNo = r;
        marks = m;
        cout << "Student Constructor Called" << endl;
    }

    void displayStudent() {
        displayPerson();
        cout << "Roll Number: " << rollNo << endl;
        cout << "Marks: " << marks << endl;
    }

    ~Student() {
        cout << "Student Destructor Called" << endl;
    }
};

class Sports {
protected:
    string sport;
    int score;

public:
    Sports(string s, int sc) {
        sport = s;
        score = sc;
        cout << "Sports Constructor Called" << endl;
    }

    void displaySports() {
        cout << "Sport: " << sport << endl;
        cout << "Sports Score: " << score << endl;
    }

    ~Sports() {
        cout << "Sports Destructor Called" << endl;
    }
};

class StudentAthlete : public Student, public Sports {
public:
    StudentAthlete(string n, int a, int r, float m,
                   string s, int sc)
        : Student(n, a, r, m), Sports(s, sc) {
        cout << "StudentAthlete Constructor Called" << endl;
    }

    void displayAthlete() {
        displayStudent();
        displaySports();
    }

    ~StudentAthlete() {
        cout << "StudentAthlete Destructor Called" << endl;
    }
};

class GraduateStudent : public Student {
private:
    string specialization;

public:
    GraduateStudent(string n, int a, int r, float m,
                    string sp)
        : Student(n, a, r, m) {
        specialization = sp;
        cout << "GraduateStudent Constructor Called" << endl;
    }

    void displayGraduate() {
        displayStudent();
        cout << "Specialization: " << specialization << endl;
    }

    ~GraduateStudent() {
        cout << "GraduateStudent Destructor Called" << endl;
    }
};

class Teacher : public Person {
private:
    string subject;
    float salary;

public:
    Teacher(string n, int a, string sub, float sal)
        : Person(n, a) {
        subject = sub;
        salary = sal;
        cout << "Teacher Constructor Called" << endl;
    }

    void displayTeacher() {
        displayPerson();
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << salary << endl;
    }

    ~Teacher() {
        cout << "Teacher Destructor Called" << endl;
    }
};

class TeachingAssistant : public Student, public Teacher {
private:
    string department;

public:
    TeachingAssistant(string n, int a, int r, float m,
                      string sub, float sal, string dept)
        : Student(n, a, r, m),
          Teacher(n, a, sub, sal) {
        department = dept;
        cout << "TeachingAssistant Constructor Called" << endl;
    }

    void displayTA() {
        cout << "\nStudent Information:" << endl;
        displayStudent();

        cout << "\nTeacher Information:" << endl;
        displayTeacher();

        cout << "Department: " << department << endl;
    }

    ~TeachingAssistant() {
        cout << "TeachingAssistant Destructor Called" << endl;
    }
};

int main() {
    int choice;

    do {
        cout << "\n===== UNIVERSITY MANAGEMENT SYSTEM =====";
        cout << "\n1. Single Inheritance";
        cout << "\n2. Multiple Inheritance";
        cout << "\n3. Multilevel Inheritance";
        cout << "\n4. Hierarchical Inheritance";
        cout << "\n5. Hybrid Inheritance";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            cout << "\n--- Single Inheritance ---" << endl;

            Student s("Pranjali", 20, 101, 85.5);
            s.displayStudent();
            break;
        }

        case 2: {
            cout << "\n--- Multiple Inheritance ---" << endl;

            StudentAthlete sa("Prajakta", 20, 102, 90.5,
                              "Basketball", 95);
            sa.displayAthlete();
            break;
        }

        case 3: {
            cout << "\n--- Multilevel Inheritance ---" << endl;

            GraduateStudent gs("Siddesh", 22, 103, 88.5,
                               "Artificial Intelligence");
            gs.displayGraduate();
            break;
        }

        case 4: {
            cout << "\n--- Hierarchical Inheritance ---" << endl;

            Student s("Ketan", 19, 104, 91.0);
            Teacher t("Mr. Patil", 40, "C++", 65000);

            cout << "\nStudent Details:" << endl;
            s.displayStudent();

            cout << "\nTeacher Details:" << endl;
            t.displayTeacher();
            break;
        }

        case 5: {
            cout << "\n--- Hybrid Inheritance ---" << endl;

            TeachingAssistant ta("Jaideep", 23, 105, 89.0,
                                 "Data Structures", 50000,
                                 "Computer Engineering");

            ta.displayTA();
            break;
        }

        case 6:
            cout << "\nExiting Program..." << endl;
            break;

        default:
            cout << "\nInvalid Choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}
