//
// Created by ZiHang on 2023/4/25.
//
#ifndef ATTENDANCE_MANAGEMENT_SYSTEM_ABSENCE_RECORDS_H
#define ATTENDANCE_MANAGEMENT_SYSTEM_ABSENCE_RECORDS_H
#include <iostream>
#include "people.h"
using namespace std;
class date{
public:
    string year;
    string month;
    string day;
    date(string,string,string);
    void show();
};
class absence_info{
public:
    absence_info();
    absence_info(string,string,string,string,string,string,string);
    void show();
    string absence_course;
    int course_absence_count=0;
    student absence_stu;
    date absence_date;
    string absence_type;
    absence_info *next;
};
#endif //ATTENDANCE_MANAGEMENT_SYSTEM_ABSENCE_RECORDS_H