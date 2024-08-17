#include <iostream>
#include <cassert>
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

class Correspondence {
private:
    string date;
    string subject;
    string sender;

public:
    Correspondence() : date("Unknown"), subject("Unknown"), sender("Unknown") {
        cout << "Default constructor of Correspondence called" << endl;
    }
    Correspondence(const string& d, const string& s, const string& se)
        : date(d), subject(s), sender(se) {
        cout << "Parameterized constructor of Correspondence called" << endl;
    }
    ~Correspondence() {
        cout << "Destructor of Correspondence called" << endl;
    }
    void display() const {
        cout << "Date: " << date << ", Subject: " << subject << ", Sender: " << sender << endl;
    }
};
class Journal {
private:
    int number;
    string name;
    Correspondence* correspondences;
    int count;
public:
    Journal() : number(0), name("Unknown"), correspondences(nullptr), count(0) {
        cout << "Default constructor of Journal called" << endl;
    }
    Journal(int num, const string& nm) : number(num), name(nm), correspondences(nullptr), count(0) {
        cout << "Parameterized constructor of Journal called" << endl;
    }
    ~Journal() {
        delete[] correspondences;
        cout << "Destructor of Journal called" << endl;
    }
    void addCorrespondence(const Correspondence& corr) {
        Correspondence* temp = new Correspondence[count + 1];
        for (int i = 0; i < count; ++i) {
            temp[i] = correspondences[i];
        }
        temp[count] = corr;
        delete[] correspondences;
        correspondences = temp;
        ++count;
    }


    void displayCorrespondences() const {
        cout << "Journal Number: " << number << ", Name: " << name << endl;
        cout << "Correspondences:" << endl;
        for (int i = 0; i < count; ++i) {
            correspondences[i].display();
        }
    }
};
int main() {
    SetConsoleOutputCP(CP_UTF8);
    Journal journal1(1, "Journal of Records");


    Correspondence corr1("2024-08-01", "Зустріч", "Степан Гіга");
    Correspondence corr2("2024-08-05", "Звіт", "Богдан Ступка");

    journal1.addCorrespondence(corr1);
    journal1.addCorrespondence(corr2);

    journal1.displayCorrespondences();

    return 0;
}
