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
}

void insertPosition(Node*& head,int value,int pos){
    if(pos < 1)
        return;

    Node* newNode = new Node(value);
    newNode->data = value;

    if(pos == 1){
        newNode->prev = NULL;
        newNode->next = head;

        if(head != NULL)
            head->prev = newNode;

        head = newNode;
        return;
    }

    Node* curr = head;

    for(int i=1;i<pos-1 && curr!=NULL;i++)
        curr = curr->next;

    if(curr == NULL){
        cout << "Invalid position" << endl;
        delete newNode;
        return;
    }

    newNode->prev = curr;
    newNode->next = curr->next;

    if(curr->next != NULL)
        curr->next->prev = newNode;

    curr->next = newNode;
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
    int pos;
    cout << "Enter position: ";
    cin >> pos;
    int value;
    cout << "Enter the data value: ";
    cin >> value;
    insertPosition(head,value,pos);
    Forward_Traversal(head);
    return 0;
}
