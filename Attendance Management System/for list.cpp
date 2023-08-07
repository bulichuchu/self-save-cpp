//
// Created by ZiHang on 2023/5/20.
//
#include "list.h"
#include <iostream>
#include "Absence records.h"
using namespace std;

absence_info * input_node() {
    absence_info *p1=new absence_info;
    cout << "Please input absence course, student name, ID, date (follow year, month, day) and absence type." << endl;

    cout << "course: (0 to exit)";
    cin >> p1->absence_course;

    if (p1->absence_course == "0") {
        delete p1;
        return nullptr;
    }
    cout << "name: ";
    cin >> p1->absence_stu.name;
    cout << "ID: ";
    cin >> p1->absence_stu.ID;
    cout << "date: ";
    cout << "year: ";
    cin >> p1->absence_date.year;
    //judge the year is correct or not,if not ,let user input again until it is correct
    while (p1->absence_date.year < "2000") {
        cout << "Please input correct year" << endl;
        cin >> p1->absence_date.year;
    }
    //judge the month is correct or not,if not ,let user input again until it is correct
    cout << "month: ";
    cin >> p1->absence_date.month;
    while (stoi(p1->absence_date.month) < 1 || stoi(p1->absence_date.month) > 12) {
        cout << "Please input correct month" << endl;
        cin >> p1->absence_date.month;
    }
    cout << "day: ";
    cin >> p1->absence_date.day;
    while (stoi(p1->absence_date.day) < 1 || stoi(p1->absence_date.day) > 31) {
        cout << "Please input correct day" << endl;
        cin >> p1->absence_date.day;
    }
    cout << "type: ";
    cin >> p1->absence_type;//make sure the type is correct

    cout << "input this person absence count : ";
    int modifyOption;
    cin >> modifyOption;
    p1->absence_stu.absence_count=modifyOption;//increase absence count

    cout<< "input this course absence count : ";
    cin >> modifyOption;
    p1->course_absence_count=modifyOption;//increase course absence count
    return p1;
}

void show(absence_info *head){
    absence_info *p;
    p=head;
    while (p!= nullptr){
        cout<<"Course: "<<p->absence_course<<" student: "<<p->absence_stu.name<<" ID: "<<p->absence_stu.ID<<" time: "<<
        p->absence_date.year<<" "<<p->absence_date.month<<" "<<p->absence_date.day<<" type: "<<p->absence_type<<
        " absence count: "<<p->absence_stu.absence_count<<" course absence count: "<<p->course_absence_count<<endl;
        p=p->next;
    }
}

void save_file(absence_info *head){
    ofstream outfile("D:/CLionProjects/Attendance Management System/absence.txt",ios::out);
    if (!outfile) {
        cout << "Failed to open the file." << std::endl;
        return;
    }
    absence_info *p;
    p=head;
    while (p!= nullptr){
        outfile<<p->absence_course<<" "<<p->absence_stu.name<<" "<<p->absence_stu.ID<<" "<<p->absence_date.year
        <<" "<<p->absence_date.month<<" "<<p->absence_date.day<<" "<<p->absence_type<<p->absence_stu.absence_count<<
        " "<<p->course_absence_count<<endl;
        p=p->next;
    }
    outfile.close();
}

absence_info *creat() {
    absence_info *head = nullptr;
    absence_info *p1, *p2;
    p1 = p2 = input_node();

    while (p1 != nullptr) {
        if (head == nullptr) {
            head = p1;
        } else {
            p2->next = p1;
        }
        p2 = p1;
        p1 = input_node();
    }
    if (p2 != nullptr) {
        p2->next = nullptr;
    }
    return head;
}

absence_info *revise_member(absence_info *head,string name) {
    absence_info *p1, *p2;

    if (head==nullptr){
        cout<<"List is null"<<endl;
        return nullptr;
    }
    p1 = head;

    while (p1->next != nullptr && p1->absence_stu.name != name) {
        p2 = p1;
        p1 = p1->next;
    }
    if (p1->absence_stu.name == name) {
        p1=input_node();
    } else
        cout << "There is no student in this list." << endl;
    return head;

}


absence_info * insert(absence_info *head){

    absence_info *p1,*p2;
    p1=p2=head;
    p1=input_node();
    if (head==nullptr){// if list is null
        head=p1;
        p1->next=nullptr;
        return head;
    }
    while (p1->absence_stu.ID > p2->absence_stu.ID&&p2->next!=nullptr){
        p2=p2->next;//find the position to insert
    }
    if (p1->absence_stu.ID<=p2->absence_stu.ID){//insert before p2
        if (p1->absence_stu.ID==head->absence_stu.ID){
            p1->next=head;
            head=p1;
        }
        else{//insert between p1 and p2
            p1->next=p2;
            p2=head;
            while (p2->next!=p1->next){
                p2=p2->next;
            }
            p2->next=p1;
        }
    }
    else{//insert after p2
        p2->next=p1;
        p1->next=nullptr;
    }
    return head;
}


absence_info * sort_count(absence_info * head){
    if (head == nullptr || head->next == nullptr) {
        return head; // don't need to sort
    }

    absence_info *sorted_head = nullptr;// sorted list head
    absence_info *current = head; // current node to be sorted

    while (current != nullptr) {
        absence_info *next_node = current->next;
        if (sorted_head == nullptr || current->absence_stu.absence_count > sorted_head->absence_stu.absence_count) {
            // insert current node to sorted list head and handle the first node
            current->next = sorted_head;
            sorted_head = current;
        }
        else {
            absence_info *temp = sorted_head;

            while (temp->next != nullptr && temp->next->absence_stu.absence_count > current->absence_stu.absence_count)
                temp = temp->next;
            current->next = temp->next;
            temp->next = current;//find the correct head
        }

        current = next_node;// move to next node
    }

    return sorted_head;
}

absence_info * sort_course_count(absence_info * head){
    if (head == nullptr || head->next == nullptr) {
        return head; // don't need to sort
    }

    absence_info *sorted_head = nullptr;// sorted list head
    absence_info *current = head; // current node to be sorted

    while (current != nullptr) {
        absence_info *next_node = current->next;
        if (sorted_head == nullptr || current->course_absence_count > sorted_head->course_absence_count) {
            // insert current node to sorted list head and handle the first node
            current->next = sorted_head;
            sorted_head = current;
        }
        else {
            absence_info *temp = sorted_head;

            while (temp->next != nullptr && temp->next->course_absence_count > current->course_absence_count)
                temp = temp->next;
            current->next = temp->next;
            temp->next = current;//find the correct head
        }

        current = next_node;// move to next node
    }

    return sorted_head;
}
void search(absence_info *head, string name) {//show each member's absence count
    absence_info *p;
    p = head;
    while (p != nullptr) {
        if (p->absence_stu.name == name) {
            cout << "Course: " << p->absence_course << " student: " << p->absence_stu.name << " ID: " << p->absence_stu.ID << " time: " <<
                 p->absence_date.year << " " << p->absence_date.month << " " << p->absence_date.day << " type: " << p->absence_type <<
                 " absence count: " << p->absence_stu.absence_count << endl;
        }
        p = p->next;
    }
}

absence_info *load_file() {
    absence_info *head = nullptr;
    absence_info *p1, *p2;

    ifstream infile("D:/CLionProjects/Attendance Management System/absence.txt", ios::in);
    if (!infile) {
        cout << "Failed to open the file." << std::endl;
        return nullptr;
    }
    while (!infile.eof()) {
        p1 = new absence_info;
        infile >> p1->absence_course >> p1->absence_stu.name >> p1->absence_stu.ID >> p1->absence_date.year
               >> p1->absence_date.month >> p1->absence_date.day >> p1->absence_type>>p1->absence_stu.absence_count
               >>p1->course_absence_count;
        p1->next = nullptr;

        if (head == nullptr) {
            head = p1;
        } else {
            p2->next = p1;
        }
        p2 = p1;
    }

    infile.close();
    return head;
}
