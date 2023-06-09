#include "score statement.h"
void print(student *head){
    student *p =head;
    while (p!=NULL){
        cout<<p->num<<' '<<p->score<<endl;
        p=p->next;
    }
}
//print the list
