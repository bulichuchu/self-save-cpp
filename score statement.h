#include <iostream>
using namespace std;
#define len sizeof(struct student)
struct student{
    int num;
    float score;
    student *next;
};
extern int cnt;

student *creat();
void print(student *head);
student *delete_member(student *head, int num);
student* insert(student* head, int num, int score);
