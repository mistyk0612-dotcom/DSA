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

int main(){
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    Node *head = nullptr;
    head = Creation(head,n);
    cout << "Original Circular Linked List: ";
    Traversal(head);
    return 0;
}

