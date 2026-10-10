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

Node *Creation(Node *head,Node *&tail,int n){
    for(int i=1;i<=n;i++){
        int value;
        cout << "Enter the value of node " << i << endl;
        cin >> value;

        Node *N = new Node(value);

        if(head == nullptr){
            head = N;
            tail = N;
        }
        else{
            N->prev = tail;
            tail->next = N;
            tail = N;
        }
    }

    return head;
}

void Forward_Traversal(Node *head){
    Node *temp = head;

    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void Backward_Traversal(Node *tail){
    Node *temp = tail;

    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

bool Delete_Position(Node *&head,Node *&tail,int pos){
    if(head == nullptr){
        cout << "Deletion not possible. List is empty." << endl;
        return false;
    }

    if(pos < 1){
        cout << "Invalid position." << endl;
        return false;
    }

    Node *temp = head;

    for(int i=1;i<pos && temp!=nullptr;i++)
        temp = temp->next;

    if(temp == nullptr){
        cout << "Invalid position." << endl;
        return false;
    }

    if(temp == head){
        head = head->next;

        if(head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;
    }
    else if(temp == tail){
        tail = tail->prev;
        tail->next = nullptr;
    }
    else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
    return true;
}

int main(){
    int n;

    cout << "Enter the Number of nodes: ";
    cin >> n;

    Node *head = nullptr;
    Node *tail = nullptr;

    head = Creation(head,tail,n);

    cout << "Before Deletion:" << endl;

    cout << "Forward Traversal: ";
    Forward_Traversal(head);
    cout << endl;

    cout << "Backward Traversal: ";
    Backward_Traversal(tail);
    cout << endl;

    int pos;

    cout << "Enter the position to delete: ";
    cin >> pos;

    if(Delete_Position(head,tail,pos)){
        cout << "After Deletion:" << endl;

        cout << "Forward Traversal: ";
        Forward_Traversal(head);
        cout << endl;

        cout << "Backward Traversal: ";
        Backward_Traversal(tail);
    }

    return 0;
}