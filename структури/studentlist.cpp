#include <iostream>
#include <string>
#include <windows.h>


using namespace std;

struct STUDENT {
    string name;        
    int group;          
    int ses[6];       
};

void inputStudentData(STUDENT students[], int size) {
    students[0] = {"Марія Горошко", 1, {5, 5, 5, 5, 5, 2}};
    students[1] = {"Єлісєй Коробко", 1, {4, 5, 3, 3, 3, 3}};
    students[2] = {"Матвей Сірий", 1, {5, 3, 4, 5, 4, 3}};
    students[3] = {"Єлизавета Остапенко", 2, {3, 5, 4, 2, 3, 4}};
    students[4] = {"Веніамін Кудряшов", 2, {4, 4, 4, 5, 4, 4}};
    students[5] = {"Савелій Цукорок", 2, {5, 3, 4, 5, 3, 5}};
    students[6] = {"Ірина Білик", 2, {3, 3, 3, 5, 3, 5}};
    students[7] = {"Тіна Кароль", 3, {5, 5, 5, 5, 2, 5}};
    students[8] = {"Степан Бандера", 3, {2, 3, 4, 5, 3, 5}};
    students[9] = {"Степан Гіга", 3, {3, 4, 5, 3, 3, 5}};
    students[10] = {"Анабель Луніна", 3, {4, 3, 4, 5, 5, 3}};
}

void printStudentsWithFailingGrades(const STUDENT students[], int size) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (students[i].ses[j] == 2) {
                if (!found) {
                    cout << "Студенти, які мають хоча б одну оцінку 2:\n";
                    found = true;
                }
                cout << "Прізвище та ініціали: " << students[i].name
                     << ", Номер групи: " << students[i].group << endl;
                break; 
            }
        }
    }
    if (!found) {
        cout << "Студенти з оцінкою 2 не знайдені.\n";
    }
}

int main() {
    const int numStudents = 11; 
    STUDENT students[numStudents]; 
    SetConsoleOutputCP(CP_UTF8);


    inputStudentData(students, numStudents);


    printStudentsWithFailingGrades(students, numStudents);

    return 0;
}
