#include <iostream>
#include "headers\Linked List Header.hpp"
#include "headers\Functions.hpp"
using namespace std;


void createDNode(int data);
void createDNodeStart(int data);
void createDNodePosition(int position, int data);
void deallocateDNodeByValue(int data);
void deallocateDNodeByItem(int item);
void deallocateLastDNode();
void deallocateFirstDNode();

//                                                   tail
//                    Node1                  Node2   | 
// nullptr <-[-prev | data | next-]->[prev | data | next]-> nullptr
//                   head    |<-------|

// ======================================================================================//

void createDNode(int data) {
    Node *tmpNode =  new Node;
    tmpNode -> data = data;
    tmpNode -> next = nullptr;
    tmpNode -> prev = nullptr;

    if (nullptr == head) {
        head = tmpNode;
        tail = tmpNode;
    }
    else {
        tail ->next = tmpNode;
        tmpNode -> prev = tail;
        tail = tmpNode;
    }
}

void createDNodeStart(int data) {
    Node *tmpNode = new Node;
    tmpNode -> data = data;
    tmpNode -> next = head;
    tmpNode -> prev = nullptr;
    if (head != nullptr) {
        head -> prev = tmpNode; 
    }
    head = tmpNode;
}

void createDNodePosition(int position, int data) {
    if (nullptr == head){
        createDNode(data);
        return;
    }

    Node *tmpNode = head;
    Node *prevNode = nullptr;
    Node *tmpNode2 = new Node;
    tmpNode2 -> data = data;

    for (int i = 0; i < position; i++){
        prevNode = tmpNode;
        tmpNode = tmpNode -> next;
    }

    tmpNode2 -> prev = prevNode;
    tmpNode2 -> next = tmpNode;

    if (prevNode != nullptr) {
        prevNode -> next = tmpNode2;
    } 
    if (tmpNode != nullptr) {
        tmpNode -> prev = tmpNode2;
    }
}

void deallocateDNodeByValue(int data) {
    Node *tmpNode = head;
    Node *prevNode = nullptr;
    
    while (tmpNode != nullptr) {
        if (tmpNode -> data == data) {
            if (head == tmpNode) {
                head = tmpNode -> next;
                if (head != nullptr) {
                    head -> prev = nullptr;
                }
            }
            else  {
                if (tmpNode == tail) {
                    tail = tmpNode -> prev;
                }

                if (tmpNode -> prev != nullptr) {
                    tmpNode -> prev -> next = tmpNode -> next;
                }
                
                if (tmpNode -> next != nullptr) {
                    tmpNode -> next -> prev = tmpNode -> prev;
                }
            }

            delete tmpNode;
            return;
        }

        prevNode = tmpNode;
        tmpNode = tmpNode ->next;
    }
}

void deallocateDNodeByItem(int item) {
    if (nullptr == head) { // List is empty, nothing to delete
        return;
    }

    Node *tmpNode = head;
    Node *prevNode = nullptr;
    Node *nextNode = nullptr;

    if (0 == item) {
        head = tmpNode -> next;
        if (head != nullptr) {
            head -> prev = nullptr;
        }
        delete tmpNode;
        return;
    }

    for (int i = 0; i < item && tmpNode != nullptr && tmpNode -> next != head; i++){
        prevNode = tmpNode;
        tmpNode = tmpNode -> next;
    }
    if (nullptr == tmpNode) { // node not found
        return;
    }
    nextNode = tmpNode -> next;

    if (prevNode != nullptr) {
        prevNode -> next = nextNode;
    }
    if (nextNode != nullptr) {
        nextNode -> prev = prevNode;
    }

    delete tmpNode;
}

void deallocateLastDNode() {
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
        tail = prevNode; // Update the tail to the new last node
    } 
    else {
        // if prevNode is nullptr, it means we are deleting the only node in the list
        head = tail = nullptr;
    }
    delete tmpNode;
}

void deallocateFirstDNode() {
    if (nullptr == head) {
        return; // List is empty, nothing to delete
    }

    Node *tmpNode = head;
    head = head -> next;

    if (head != nullptr) {
        head -> prev = nullptr;
    } 
    else {
        tail = nullptr; // Update tail when there's only one node in the list
    }

    delete tmpNode;
}

