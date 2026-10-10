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
void Back_Traversal(Node* head){       // Traversal code
    if(head == nullptr){
        return;
    }
    Back_Traversal(head->next);
    cout << head->data << " ";
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
int main(){
    int n;
    cout << "Enter the no. of nodes: ";
    cin >>n;
    Node *head = nullptr;
    head = LinkedListCreation(head,n);
    cout << "Original Linked List: " << endl;
    Back_Traversal(head);
    cout << endl;
    Traversal(head);
    return 0;
}