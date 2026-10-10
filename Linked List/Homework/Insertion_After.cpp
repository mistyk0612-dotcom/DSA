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
    Node *temp = head;

    while (temp != nullptr) {
        if (temp->data == key)
            return pos;

        temp = temp->next;
        pos++;
    }

    return -1;
}

Node* insertAtPosition(Node* head, int pos, int value) {
    Node* newNode = new Node(value);

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node* curr = head;

    for (int i = 1; i < pos - 1; i++) {
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Invalid position: ";
        delete newNode;
        return head;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

void display(Node* head) {
    Node *temp = head;

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

    int key, value;
    cin >> key >> value;

    int pos = findPosition(head, key);

    if (pos != -1)
        head = insertAtPosition(head, pos + 1, value);

    display(head);

    return 0;
}