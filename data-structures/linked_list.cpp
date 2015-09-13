#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node* Insert(Node *head, int data); 
Node* InsertNth(Node *head, int data, int position);
void Spit(Node *head);

int main() {
    cout << "Hello world!" << endl;
    Node *head = NULL;

    head = Insert(head, 0);
    head = Insert(head, 1);
    head = Insert(head, 2);
    head = Insert(head, 3);
    head = Insert(head, 4);
    head = Insert(head, 5);

    head = InsertNth(head, 69, 6);

    Spit(head);

}

Node* InsertNth(Node *head, int data, int position) {
    Node *newNode = new Node;
    Node *current = head;
    newNode->data = data;

    if (position == 0) {
        newNode->next = head;
        return newNode;
    }
    
    for (int i = 0; i < position && current != NULL; i++) {
        if (i+1 == position) {
            newNode->next = current->next;
            current->next = newNode;
            break;
        }

        current = current->next;
    }
    
    return head;
}

Node* Insert(Node *head, int data) {
    Node *tail = new Node;
    tail->data = data;
    tail->next = NULL;

    if (head == NULL) {
        return tail;
    }

    for (Node *current = head; current != NULL; current = current->next) {
        if (current->next == NULL) {
            current->next = tail;
            break;
        }
    }

    return head;
}

void Spit(Node *head) {
    if (head == NULL) {
        cout << endl;
        return;
    }
    else {
        cout << head->data << " - ";
        Spit(head->next);
    }

    return;
}
