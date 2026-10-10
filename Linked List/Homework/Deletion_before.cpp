#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

int findPosition(Node* head, int key) {
    int pos = 1;
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == key)
            return pos;

        temp = temp->next;
        pos++;
    }

    return -1;
}

Node* deleteAtPosition(Node* head, int pos) {
    if (head == nullptr || pos <= 0)
        return head;

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* curr = head;

    for (int i = 1; i < pos - 1; i++) {
        if (curr == nullptr || curr->next == nullptr)
            return head;

        curr = curr->next;
    }

    if (curr == nullptr || curr->next == nullptr)
        return head;

    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;

    return head;
}

void display(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    int key;
    cin >> key;

    int pos = findPosition(head, key);

    if (pos > 1)
        head = deleteAtPosition(head, pos - 1);

    display(head);

    return 0;
}