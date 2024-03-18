#include <iostream>
#include "headers\Linked List Header.hpp"
#include "headers\Linked List Header.hpp"
using namespace std;

int timesOccurred(int target_data);
int length();
int isCLL();
int isDLL();
bool isEmpty();

// ============================================================= //

int timesOccurred(int target_data) {
    if (nullptr == head){
        return 0; 
    }
    int counter = 0;
    Node *tmpNode = head;
    do {
        if(target_data == (*tmpNode).data) {
            counter++;
        }
        tmpNode = (*tmpNode).next;
    } while (tmpNode != head && tmpNode != nullptr);

    return counter;
}

int length() {
    if (head == NULL) {
        return 0;
    }

    int length = 0;
    Node *tmpNode = head;
    do {
        length++;
        tmpNode = (*tmpNode).next;
    } while (tmpNode != head && tmpNode != nullptr);
    return length;
}

int isCLL() {
    if (nullptr == head){
        return 0;  // idk what to do here, is an empty list a CLL or a SLL?
    }
    Node* Move1 = head;
    Node* Move2 = head;

    while (Move2 != nullptr && (*Move2).next != nullptr) {
        Move1 = (*Move1).next;
        Move2 = (*(*Move2).next).next;

        if (Move1 == Move2) {
            return 1;
        }
    }

    return -1;
}

int isDLL() {
    if (nullptr == head) {
        return 0;
    }

    Node *tmpNode = head;

    while (tmpNode->next != nullptr && tmpNode->next != head) { // moving through the list forward until we reach the end
        tmpNode = tmpNode->next;
    }

    tmpNode = head; // moving tmpNode back to the head for checking backward

    while (tmpNode != nullptr && tmpNode != head) { // going through the list backwards and checking if each node has a prev pointer or not.
        if (tmpNode->prev == nullptr && tmpNode != head) {
            return -1;
        }
        tmpNode = tmpNode->prev;
    }

    return 1;
}


bool isEmpty(){
    if (nullptr == head) {
        return true;
    }
    return false;
}

void DisplaySLL() {
    Node *tmpNode = head;
    do {
        cout << (*tmpNode).data << " ";
        tmpNode = (*tmpNode).next; // to go through the list
    } while (tmpNode != head && tmpNode != nullptr);
    
    if (isCLL() == 1) {
        cout << "...";
    }
}