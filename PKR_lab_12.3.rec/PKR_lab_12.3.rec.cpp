#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

void Insert(Node** head, Node** tail)
{
    int value;
    cout << "Enter a value (enter -1 to stop): ";
    cin >> value;
    if (value != -1) {
        if (*head == nullptr) {
            *head = new Node;
            (*head)->data = value;
            *tail = *head;
        }
        else {
            if ((*tail)->next == nullptr) {
                (*tail)->next = new Node;
                (*tail)->next->prev = *tail;
                (*tail)->next->data = value;
                *tail = (*tail)->next;
            }
        }
        Insert(head, tail);
    }
}

void Print(Node* current)
{
    if (current == nullptr) {
        cout << endl;
        return;
    }

    cout << current->data << " ";
    Print(current->next);
}

void Pairs(Node* current)
{
    if (current == nullptr || current->next == nullptr) {
        return;
    }

    Node* runner = current->next;
    while (runner != nullptr) {
        if (current->data == runner->data) {
            cout << current->data << " has a pair" << endl;
            break;
        }
        runner = runner->next;
    }

    Pairs(current->next);
}

void Delete(Node** head, Node** tail)
{
    if (*head == nullptr) {
        return;
    }

    if (*head == *tail) {
        delete* head;
        *head = nullptr;
        *tail = nullptr;
        return;
    }

    Node* temp = *tail;
    *tail = (*tail)->prev;
    (*tail)->next = nullptr;
    delete temp;

    Delete(head, tail);
}

int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;

    Insert(&head, &tail);

    cout << "List: ";
    Print(head);

    Pairs(head);

    Delete(&head, &tail);

    return 0;
}

