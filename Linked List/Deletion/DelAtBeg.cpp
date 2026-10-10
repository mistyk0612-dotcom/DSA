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
Node *DeleteAtBeg(Node *head){
    if(head == nullptr){
        cout << "Linked list is empty";
        return head;
    }
    Node *temp = head;
    head = head -> next;
    delete temp;
    return head;
}

int main(){
    int n;
    cout << "Enter the no. of nodes: ";
    cin >>n;
    Node *head = nullptr;
    head = LinkedListCreation(head,n);
    cout << "Original Linked List: " << endl;
    Traversal(head);
    head = DeleteAtBeg(head);
    cout << "After deletion: ";
    Traversal(head);
    return 0;
}