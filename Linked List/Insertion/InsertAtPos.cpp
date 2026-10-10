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

Node *InsertAtPos(Node* head,int value,int pos){
    Node *newNode = new Node;
    newNode -> data = value;
    if(pos == 1){
        newNode -> next = head;
        head = newNode;
        return head;
    }
    else{
        Node *curr = head;
        for(int i=1;i<pos-1 && curr != nullptr;i++){
            curr = curr -> next;
        }
        if(curr == nullptr){
            cout << "Invalid Position";
            delete newNode;
            return head;
        }
            newNode -> next = curr -> next;
            curr -> next = newNode;
            return head;
    }
}

int main(){
    int n;
    cout << "Enter the no. of nodes: ";
    cin >>n;
    Node *head = nullptr;
    head = LinkedListCreation(head,n);
    cout << "Original Linked List: " << endl;
    Traversal(head);
    int value;
    cout << "Enter Value: ";
    cin >> value;
    int pos;
    cout << "Enter Position: " ;
    cin >> pos;
    head = InsertAtPos(head,value,pos);
    cout << "After Insertion: ";
    Traversal(head);
    return 0;
}