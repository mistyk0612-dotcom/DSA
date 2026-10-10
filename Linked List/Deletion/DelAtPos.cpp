#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void Traversal(Node* head){       // Traversal code
    Node *temp = head;
    while(temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


Node* LinkedListCreation(Node * head,int n){ //Linked List Creation
    for(int i=0;i<n;i++){
        Node *N = new Node;
        int value;
        cout << "Enter the data for node: ";
        cin >> value;
        N -> data = value;
        N -> next = nullptr;
        if(head == nullptr){
            head = N;
        }
        else{
            Node *temp = head;
            while(temp -> next != nullptr){
                temp = temp ->next;
            }
            temp -> next = N;
        }
    }
    return head;
}


void DeleteAtPos(Node *head,int pos){
if(head == nullptr){
    cout << "Linked List is empty";
    return;
}
if(pos < 1){
    cout << "Invalid Position";
    return;
}
if(pos == 1){
    Node *temp = head;
    head = head -> next;
    cout << "Deleted value: " << temp -> data;
    temp -> next = nullptr;
    delete temp;
    return;
} 
Node *temp = head;
for(int i = 1;i<pos-1 && temp!= nullptr;i++){
    temp = temp -> next;
}
if(temp == nullptr || temp -> next == nullptr){
    cout << "Position doesn't exist";
    return;
}
Node *toDelete = temp -> next;
temp -> next = toDelete -> next;
delete toDelete;
return;
}
int main(){
    int n;
    cout << "Enter the no. of nodes: ";
    cin >>n;
    Node *head = nullptr;
    head = LinkedListCreation(head,n);
    cout << "Original Linked List: " << endl;
    Traversal(head);
    int pos;
    cout << "Enter Position: ";
    cin >> pos;
    DeleteAtPos(head,pos);
    cout << "After Deletion: ";
    Traversal(head);
    return 0;
}