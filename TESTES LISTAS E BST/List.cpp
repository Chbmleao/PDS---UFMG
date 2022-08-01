#include "List.hpp"
void List::insertNode(int data) {
    Node* aux = new Node;
    aux->data = data;
    aux->next = nullptr;

    if (head == nullptr) {
        head = aux;
        tail = aux;
    } else {
        tail->next = aux;
        tail = aux;
    }
    size += 1;
}

void List::removeNode(int data) {
    Node *current = head;
    Node *previous = nullptr;
    while (current != nullptr) {
        if (current->data == data) {
            if (previous == nullptr) { // HEAD
                head = current->next;
            } else if (current->next == nullptr) { //TAIL
                previous->next = nullptr;
                tail = previous;
            } else {
                previous->next = current->next;
            }
            delete current;
            size -= 1;
            return;
        }

        previous = current;
        current = current->next;
    }
    
}


void List::display() {

    Node *aux = head;
    while (aux != nullptr) {
        cout << aux->data << "\t";
        aux = aux->next;
    }
    cout << "Size = " << size; 
    cout << endl;
}

bool List::verifyNode(int data) {
    Node *current = head;
    while(current != nullptr){
        if (current->data == data)
            return true;
        current = current->next;
    }
    return false;
}

