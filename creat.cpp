#include "score statement.h"
student *creat() {
    student *p1, *p2, *head;
    p1 = p2 = head = new student[len];
    cout << "Please input number and score of students, input \"0 0\" to end." << endl;
    cin >> p1->num >> p1->score;
    while (p1->num != 0) {
        p1 = new student[len];
        cin >> p1->num >> p1->score;
        if (p1->num == 0) {
            p2->next = NULL;
            return head;
        } else {
            p2->next = p1;
            p2 = p1;
        }
        cnt++;
    }
    return head;
}
//creat a list