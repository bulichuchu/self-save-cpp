#include "score statement.h"
student *delete_member(student *head, int num) {
    student *p1, *p2;

    if (head==NULL){
        cout<<"List is null"<<endl;
        return NULL;
    }
    p1 = head;

    while (p1->next != NULL && p1->num != num) {
        p2 = p1;
        p1 = p1->next;
    }
    if (p1->num == num) {
        if (num == head->num)
            head = p1->next;
        else {
            p2->next = p1->next;
        }
        cnt--;

    } else
        cout << "There is no num in this list." << endl;
    return head;

}

//delete the member of the list

