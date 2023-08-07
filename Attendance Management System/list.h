//
// Created by ZiHang on 2023/5/20.
//

#ifndef ATTENDANCE_MANAGEMENT_SYSTEM_LIST_H
#define ATTENDANCE_MANAGEMENT_SYSTEM_LIST_H

#include <iostream>
#include <fstream>
#include "Absence records.h"
#include <iomanip>
using namespace std;
extern ofstream outfile;
void show(absence_info *head);
void save_file(absence_info *head);
absence_info * load_file();
absence_info *creat();
absence_info *revise_member(absence_info *head, string name);
absence_info * insert(absence_info *head);
void search(absence_info *head, string name);
absence_info * sort_count(absence_info * head);
absence_info * sort_course_count(absence_info * head);
absence_info * input_node();

#endif //ATTENDANCE_MANAGEMENT_SYSTEM_LIST_H
