#include <iostream>

#include "Absence records.h"
#include "list.h"
using namespace std;
int main() {
    int choice;
    string name;
    absence_info *head = nullptr;
    cout << "-----Welcome to Attendance Management System-----\n";
    do {
        cout << "Please input your choice: \n";
        cout << "1. Input student absence record\n";
        cout << "2. Revise student absence record\n";
        cout << "3. Search student absence record\n";
        cout << "4. Print student absence record by absence count\n";
        cout << "5. Print student absence record by absence people\n";
        cout << "6. Load from file\n";
        cout << "0. Quit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                head = creat();
                save_file(head);
                show(head);
                break;
            case 2:
                cout << "Please input student name to revise\n";

                cin >> name;
                revise_member(head, name);
                save_file(head);
                show(head);
                break;
            case 3:
                cout << "Please input student name to search\n";
                cin >> name;
                search(head, name);
                break;
            case 4:
                head = sort_count(head);
                show(head);
                break;
            case 5:
                head = sort_course_count(head);
                show(head);
                break;
            case 6:
                head = load_file();
                show(head);
                break;
            default:
                cout<<"Please input correct choice \n";
        }
    } while (cin>>choice&&choice!=0);
}


