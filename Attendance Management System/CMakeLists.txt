cmake_minimum_required(VERSION 3.23)
project(Attendance_Management_System)

set(CMAKE_CXX_STANDARD 14)

add_executable(Attendance_Management_System
        main.cpp
        people.h
        "Absence records.h" "Absence records.cpp" people.cpp "for list.cpp" list.h)
