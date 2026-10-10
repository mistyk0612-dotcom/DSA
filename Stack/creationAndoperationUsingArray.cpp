#include <iostream>
using namespace std;
#define MAX 5

class Stack{
    private:
    int stack[MAX];
    int top ;
    public:
    Stack(){
        top = -1;
    }
    void push(int val){
        if(top == MAX-1){
            cout << "Overflow";
        }
        else{
            top++;
            stack[top] = val;
            cout << "Inserted value is: " << val << endl;
        }
    }
    void pop(){
        if(top == -1){
            cout << "Underflow";
        }
        else{
            cout << stack[top] << " is Deleted value"<< endl;
            top--;
        }
    }
    void peek(){
        if(top == -1){
            cout << "Underflow";
        }
        else{
            cout << "Top element: " <<stack[top] << endl;
        }
    }
    void Traversal(){
        if(top == -1){
            cout << "Underflow";
        }
        else{
            for(int i=top;i>=0;i--){
                cout << stack[i] << " " ;
            }
        }
        cout << endl;
    }
    bool CheckEmpty(){
        return (top == -1);
    }
    bool isFull(){
        return (top == (MAX-1));
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.push(40);
    s.peek();
    s.Traversal();
    cout << s.isFull() << endl;
    cout << s.CheckEmpty();
    return 0;
}