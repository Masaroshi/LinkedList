#include <iostream>
#include "headers\Linked List Header.hpp"
#include "headers\Functions.hpp"
using namespace std;

Node *head = nullptr;
Node *tail = nullptr;

void createSNode(int data);
void createSNodeStart(int data);
void createSNodePosition(int position, int data);
void deallocateSNodeByValue(int data);
void deallocateSNodeByItem(int item);
void deallocateLastSNode();
void deallocateFirstSNode();
void SLLtoDLL();

//                                     tail
//              Node1             Node2 | 
// head -> [data | next -]-> [data | next-]-> nullptr 

// ======================================================================================//

void createSNode(int data) {
    Node *tmpNode =  new Node; // (Node*)malloc(sizeof(Node)); memory allocation for new node
    tmpNode -> data = data;
    tmpNode -> next = nullptr;

    if (nullptr == head) {
        head = tmpNode;
        tail = tmpNode; // we set tail to the new node because it's the only node in the list
    }
    else {
        tail -> next = tmpNode; // we connect the new node to the current tail
        tail = tmpNode; // tail points to the new node
    }
}

void createSNodeStart(int data) {
    Node *tmpNode = new Node;
    tmpNode -> data = data;
    tmpNode -> next = head;
    head = tmpNode;
}

void createSNodePosition(int position, int data) {
    if (nullptr == head){ // if list is empty create a new node
        createSNode(data);
        return;
    }
    else if (position > length() + 1){
        return;
    }

    Node *tmpNode = head;
    Node *prevNode = nullptr;
    Node *tmpNode2 = new Node;
    tmpNode2 -> data = data; // assigning data to node

    for (int i = 0; i < position; i++){ // changing nodes and adresses until we get to the position
        prevNode = tmpNode;
        tmpNode = tmpNode -> next;
    }
    if (prevNode != nullptr){
        prevNode -> next = tmpNode2;
    }
    tmpNode2 -> next = tmpNode;
}

void deallocateSNodeByValue(int data) {
    Node *tmpNode = head;
    Node *prevNode = nullptr;
    
    while (tmpNode != nullptr) {
        if (tmpNode -> data == data) { // finding a node with the same data
            if (head == tmpNode) {
                head = tmpNode -> next; // Update head if tmpNode is the head node
            }

            if (tail == tmpNode) {
                tail = prevNode; // Update tail if tmpNode is the tail node
            }

            if (prevNode != nullptr) {
                prevNode -> next = tmpNode -> next; // Skip over the tmpNode
            }
            delete tmpNode; // free(tmpNode) Deallocate the memory of tmpNode (the node with same data)
            return;
        }
        prevNode = tmpNode;
        tmpNode = tmpNode -> next; // to go through the list
    }
}

void deallocateSNodeByItem(int item) {
    if (nullptr == head) { // List is empty, nothing to delete
        return;
    }

    Node *tmpNode = head;
    Node *prevNode = nullptr;

    if (0 == item) {
        head = tmpNode -> next;
        delete tmpNode;
        return;
    }

    for (int i = 0; i < item && tmpNode != nullptr && tmpNode -> next != head; i++){  // Loop until we reach the item
        prevNode = tmpNode;
        tmpNode = tmpNode -> next;
    }
    if (nullptr == tmpNode) { // node not found
        return;
    }
    // Skip over the deleted node and handling the last node
    if (prevNode != nullptr) {
        prevNode -> next = tmpNode -> next;
    }
    delete tmpNode;
}

void deallocateLastSNode() {
    if (nullptr == head) { // List is empty, nothing to delete
        return;
    }

    Node *tmpNode = head;
    Node *prevNode = nullptr;

    for (int i = 0; tmpNode -> next != nullptr; i++){ // Loop until we reach the last node
        prevNode = tmpNode;
        tmpNode = tmpNode -> next;
    }
    // Skip over the deleted node and handling the last node
    if (prevNode != nullptr) {
        prevNode -> next = nullptr;
    }
    tail = prevNode; // connecting last node to tail
    delete tmpNode;
}

void deallocateFirstSNode() {
    if (nullptr == head) { // List is empty, nothing to delete
        return;
    }
    Node *tmpNode = head;
    head = head -> next;
    delete tmpNode;
}
