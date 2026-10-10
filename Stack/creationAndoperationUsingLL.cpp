#include <iostream>
using namespace std; // taaki top update hota rahe
class Stack{
    private:
    struct Node{
        int data;
        Node *next;
    };
    Node *top ;
    public:
    Stack(){
        top = nullptr;
    }
    void push(int val){
        Node *N = new Node;
        N -> data = val;
        N -> next = top;
        top = N;
        cout << "Inserted value is: "<< N->data <<endl;;
    }
    void pop(){
        if(top == nullptr){
            cout << "Underflow";
            return;
        }
        Node *temp = top;
        cout << "Deleted value = " << top ->data << endl;
        top = top -> next;
        delete temp;
        // temp -> next = nullptr;
        // delete temp; // temp me jo value store goti hai wo delete hoti na ki node
    }
    void peek(){
        if(top == nullptr){
            cout << "Underflow";
            return;
        }
        cout << "Top element: " << top -> data << endl;;
    }
    void Traversal(){
        if(top == nullptr){
            cout << "Underflow";
            return;
        }
        Node *temp = top;
        while(temp != nullptr){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << "Not Empty";
    }
    void CheckEmpty(){
        if(top == nullptr){
            cout << "Empty";
        }
        else{
            cout << "Not empty";
        }
    }
};


int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.Traversal();
    s.CheckEmpty();
    return 0;
}