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

void Delete_Beginning(Node *&head,Node *&tail){
    if(head == nullptr){
        cout << "Deletion not possible. List is empty." << endl;
        return;
    }

    Node *temp = head;

    if(head == tail){
        head = nullptr;
        tail = nullptr;
    }
    else{
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
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

    Delete_Beginning(head,tail);

    cout << "After Deletion at Beginning:" << endl;

    cout << "Forward Traversal: ";
    Forward_Traversal(head);
    cout << endl;

    cout << "Backward Traversal: ";
    Backward_Traversal(tail);

    return 0;
}