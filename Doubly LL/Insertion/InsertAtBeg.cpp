#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int value){
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

Node *Creation(Node *head , Node *&tail,int n){
    for(int i = 1;i<=n;i++){
        int value;
        cout << "Enter the value of node " << i << endl;
        cin >> value;
        Node *N  = new Node(value); // Creating object of this constructor
        if(head == nullptr){
            head = N;
            tail = N;
        }
        else{
            N -> prev = tail;
            tail -> next = N;
            tail = N;
        }
    }
    return head;
}
void Forward_Traversal(Node *head){
    Node *temp = head;
        while(temp != nullptr){
            cout << temp -> data << " " ;
            temp = temp -> next;
        }
}
void Backward_Traversal(Node *tail){
    Node *temp = tail;
    while(temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> prev;
    }
    cout << endl;
}

void insertBeginning(Node*& head,int value){
    Node* newNode = new Node(value);
    // newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
        head->prev = newNode;

    head = newNode;
}

int main(){
    int n;
    cout << "Enter the Number of nodes: ";
    cin >> n;
    Node *head = nullptr;
    Node *tail = nullptr;
    head = Creation(head,tail,n);
    cout << "Forward Traversal: ";
    Forward_Traversal(head);
    cout << endl;
    cout << "Backward Traversal: ";
    Backward_Traversal(tail);
    int value;
    cout << "Enter the value: ";
    cin >> value;
    insertBeginning(head,value);
    Forward_Traversal(head);
    return 0;
}
