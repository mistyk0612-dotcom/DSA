#include <iostream>
using namespace std; 

struct Node{
    int data;
    Node *next;

};
void Traversal(Node *head){
    if(head != nullptr){
        Node *temp = head;
        do{
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        while(temp != head);
    }
        else{
            cout << "Linked List is empty";
        }
        cout << endl;
}
Node* Creation(Node *head,int n){
    for(int i = 0;i<n;i++){
        int value;
        cout << "Enter the value of Nodes: ";
        cin >> value;
        Node * N = new Node;
        N -> data = value;

        if(head == nullptr){
            head = N;
            N -> next = head;
        }
        else{
            Node *temp = head;
            while(temp -> next != head){
               temp = temp -> next;
            }
            temp -> next = N;
            N -> next = head;
        }
    }
    return head;
}


void InsertAtPos(Node *head,int pos,int value){
    Node *N = new Node;
    N -> data = value;
    N -> next = nullptr;
    if(head == nullptr){
        if(pos==1){
            head = N;
            N -> next = head;
        }
        else{
            cout << "Invalid Position" << endl;
            delete N;
        }
        return;
    }
    if(pos == 1){
        Node *temp = head;
        while(temp -> next != head){
            temp = temp -> next;
        }
        N -> next = head;
        temp -> next = N;
        head = N;
        return;
    }
    Node *temp = head;
    for(int i=1;i<pos-1;i++){
        temp = temp -> next;
    if(temp == head){
        cout << "Invalid Position";
        delete N;
        return;
    }
}
    N -> next = temp -> next;
    temp -> next = N;
    return;

}
int main(){
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    Node *head = nullptr;
    head = Creation(head,n);
    cout << "Original Circular Linked List: ";
    Traversal(head);
    int pos;
    cout << "Enter Position: ";
    cin >> pos;
    int value;
    cout << "Enter data value: ";
    cin >> value;
    InsertAtPos(head,pos,value);
    cout << "After Insertion: ";
    Traversal(head);
    return 0;
}
