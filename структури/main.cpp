#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Subscriber {
    string firstName;
    string lastName;
    string phoneNumber;
};

void printSubscribersWithPhoneNumberContains(const vector<Subscriber>& subscribers, const string& pattern) {
    cout  << "Subscribers in the request, with digits " << pattern << " :" << endl ;
    for (const auto& subscriber : subscribers) {
        if (subscriber.phoneNumber.find(pattern) != string::npos) {
            cout << subscriber.firstName << " " << subscriber.lastName << " - " << subscriber.phoneNumber << endl;
        }
    }
}

int main() {
    vector<Subscriber> phoneBook = {
        {"Ivan", "Ivanov", "331123456"},
        {"Petro", "Ivanov", "456331789"},
        {"Olena", "Ivanova", "221987654"},
        {"Andriy", "Ivanov", "123456331"},
        {"Maria", "Ivanova", "442345678"}
    };

    printSubscribersWithPhoneNumberContains(phoneBook, "331");

    return 0;
}
