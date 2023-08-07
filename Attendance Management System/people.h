//
// Created by ZiHang on 2023/4/25.
//

#ifndef ATTENDANCE_MANAGEMENT_SYSTEM_PEOPLE_H
#define ATTENDANCE_MANAGEMENT_SYSTEM_PEOPLE_H

#include <iostream>
using namespace std;
class people{
public:
    string name;
    string ID;
    people(string,string);
    virtual void show() const;
};

class student: public people{
public:
    student(string,string);
    int absence_count=0;
    void show() const;
};

#endif //ATTENDANCE_MANAGEMENT_SYSTEM_PEOPLE_H