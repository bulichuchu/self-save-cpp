//
// Created by ZiHang on 2023/4/25.
//
#include "people.h"
#include <iostream>

void people::show() const {
    cout<<"Name: "<<name<<endl;
    cout<<"ID: "<<ID<<endl;
}

people::people(string name, string ID){
    this->name=name;
    this->ID=ID;
}

student::student(string name, string ID) : people(name,ID){
    this->absence_count=0;

}

void student::show() const {
    people::show();
    cout<<"absence count :" <<absence_count<<endl;
}


