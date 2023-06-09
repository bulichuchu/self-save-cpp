#include "score statement.h"
student* insert(student* head, int num, int score) {
    student *p1, *p2, *p3;
    p1 = head;
    p3 = new student;
    p3->num = num;
    p3->score = score;
    p3->next = NULL;
    if (head == NULL) { // list doesn't exist
        head = p3;
        cnt++;
        return head;
    }
    if (p3->num <= head->num) { // insert at the beginning of the list
        p3->next = head;
        head = p3;
        cnt++;
        return head;
    }
    while (p3->num > p1->num && p1->next != NULL) { // find
        p2 = p1;
        p1 = p1->next;
    }
    if (p3->num <= p1->num) { // insert at the middle of the list
        p2->next = p3;
        p3->next = p1;
        cnt++;
        return head;
    }
    else {
        p1->next = p3; // insert at the end of the list
        cnt++;
        return head;
    }
}


// insert a member in the list
