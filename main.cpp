#include <iostream>
#include "score statement.h"
using namespace std;
int cnt=0;
int main(){
    student *head=NULL;
    head=creat();
    print(head);
    int delete_num;
    int choice;
    cout<<"Input \"1\" to delete a member"<<endl<<"Input \"2\" to insert a member"<<endl<<"Input \"0\" to exit"<<endl;
    cin>>choice;
    do {

        switch (choice) {
            case 1:{ //delete
                while (true) {
                    cout << "Enter number to delete (0 to exit): "<<endl;
                    cin >> delete_num;
                    if (delete_num == 0) {
                        break;
                    }
                    head = delete_member(head, delete_num);
                    print(head);
                }
                break;
            }
            case 2:{
                //insert
                while (true) {
                    int num, score;
                    cout << "Enter number and score to insert (\"0 0\" to exit): " << endl;
                    cin >> num >> score;
                    if (num == 0 && score == 0) {
                        break;
                    }
                    head = insert(head, num, score);
                    print(head);
                }
                break;
            }
        }
        cout<<"Input \"1\" to delete a member"<<endl<<"Input \"2\" to insert a member"<<endl<<"Input \"0\" to exit"<<endl;
    }
    while (cin>>choice&&choice!=0);{
    }



    system("pause");
}
