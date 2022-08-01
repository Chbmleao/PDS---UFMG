#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    double size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
    void insertNode(int data);
    void removeNode(int data);
    void display();
    bool verifyNode(int data);
};

#endif