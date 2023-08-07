//
// Created by ZiHang on 2023/4/25.
//
#include "Absence records.h"
#include <iostream>

using namespace std;

date::date(string year, string month, string day) {
    this->year=year;
    this->month=month;
    this->day=day;
}

void date::show() {
    cout<<year<<":"<<month<<":"<<day<<endl;
}

absence_info::absence_info(string absence_course, string name, string ID, string year, string month, string day, string absence_type)
        : absence_stu(name,ID), absence_date(year,month,day)
{
    this->absence_course = absence_course;
    this->absence_type = absence_type;

}

absence_info::absence_info() : absence_stu("0","0"), absence_date("0","0","0"){
    absence_course = "0";
    absence_type = "0";
    next = nullptr;
}

void absence_info::show() {
    cout<<"Course: "<<absence_course<<endl;
    absence_stu.show();
    cout<<"Date: ";
    absence_date.show();
    cout<<"Type: "<<absence_type<<endl;
}

