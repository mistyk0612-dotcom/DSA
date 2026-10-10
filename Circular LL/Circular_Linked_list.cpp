#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
int main(){
    int n;
    cout << "Enter number of Nodes: ";
    cin >> n;
    Node *head = nullptr;
    for(int i=0;i<n;i++){
        int val;
        cout << "Enter the value of the Node: ";
        cin >> val;
        Node *N = new Node;
        N -> data = val;
        if(head == nullptr){
            head = N;
            N -> next = head;
        }
        else{
            Node *temp = head;
            while(temp -> next !=head){
                temp = temp ->next;
            }
            temp ->next = N;
            N ->next = head;
        }
    }
        if(head != nullptr){
            Node * temp = head;
        do{
            cout << temp -> data << " ";
            temp = temp ->next;
        }
        while(temp != head);
    }
    else{
        cout << "linked list is empty";
    }

}