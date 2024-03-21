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
        return 0;
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
    Node *prevNode = nullptr;
    Node *tmpNode = head;

    tmpNode = head;
    if (tmpNode->next->prev == tmpNode) {
        return 1;
    }
    return -1;
}


bool isEmpty() {
    if (nullptr == head) {
        return true;
    }
    return false;
}

void Display() {
    Node *tmpNode = head;
    do {
        cout << (*tmpNode).data << " ";
        tmpNode = (*tmpNode).next; // to go through the list
    } while (tmpNode != head && tmpNode != nullptr);
    
    if (isCLL() == 1) {
        cout << "...";
    }
    if (isDLL() == 1){
        cout << "<->";
    }
}

void exchangeFirstwLast() {
    if (nullptr == head) {
        return;
    }

    Node *prevNode = nullptr;
    Node *tmpNode  = head;
    
    while (tmpNode -> next != nullptr && tmpNode -> next != head) {
        prevNode = tmpNode;
        tmpNode = tmpNode -> next;
    }

    if (head -> data == tmpNode -> data){
        return;
    }

    swap(head -> data, tmpNode -> data);
}

void exchange(int first, int second) {
    if (nullptr == head) {
        return;
    }
    if (first <= 0 || second <= 0 || first > length() || second > length() || first == second) {
        return;
    }

    Node *prevNode = nullptr;
    Node *tmpNode  = head;
    Node *tmpNode2 = head;

    for (int i = 0; i < first; i++) {
        prevNode = tmpNode;
        tmpNode = tmpNode -> next;
    }
    prevNode = nullptr;
    for (int i = 0; i < second; i++){
        prevNode = tmpNode;
        tmpNode2 = tmpNode2 -> next;
    }

    if (tmpNode -> data == tmpNode2 -> data){
        return;
    }

    swap(tmpNode -> data, tmpNode2 -> data);
}

void reverse() {
    if (nullptr == head){
        return;
    }

    Node *tmpNode = head;
    Node *prevNode = nullptr;
    int *storage = new int[length()];
    int i = 0;

    do {
        storage[i] = tmpNode->data;
        tmpNode = tmpNode->next; // to go through the list
        i++;
    } while (tmpNode != head);

    i -= 1;
    do {
        tmpNode->data = storage[i];
        tmpNode = tmpNode->next;
        i--;
    } while (tmpNode != head && tmpNode != nullptr);

    delete[] storage;
}

void reverseDisplay() {
    if (nullptr == head){
        return;
    }

    Node *tmpNode = head;
    Node *prevNode = nullptr;
    int *storage = new int[length()];
    int i = 0;

    do {
        storage[i] = tmpNode->data;
        tmpNode = tmpNode->next; // to go through the list
        i++;
    } while (tmpNode != head && tmpNode != nullptr);

    for (i -= 1; i >= 0; i--){
        cout << storage[i] << " ";
    }

    delete[] storage;
}

void rotateBy(int NumberofRotates) {
    if (nullptr == head || 0 == NumberofRotates) {
        return;
    }

    Node *tmpNode = head;
    Node *prevNode = nullptr;
    int *storage = new int[length()];
    int i = 0;

    do {
        storage[i] = tmpNode->data;
        tmpNode = tmpNode->next;
        i++;
    } while (tmpNode != head && tmpNode != nullptr);


    if (isCLL() == -1) {
        tail->next = head;
    }

    tmpNode = head;

    for (i = 0; i < length(); i++) {
        tmpNode -> data = storage[(i + NumberofRotates) % length()];
        tmpNode = tmpNode->next;
    }

    tail -> next = nullptr;
    delete[] storage;
}

void modify(int item, int data){
    if (nullptr == head) {
        return;
    }

    Node *tmpNode = head;
    Node *prevNode = nullptr;
    item %= length();
    for (int i = 0; i < item && tmpNode != nullptr; i++){
        prevNode = tmpNode;
        tmpNode = tmpNode -> next;
    }

    tmpNode -> data = data;

}

void removeDuplicates() {
    if (nullptr == head){
        return;
    }
    
    Node *tmpNode = head;
    Node *tmpNode2 = head;

    while (tmpNode != nullptr && tmpNode -> next != head) {
        tmpNode2 = tmpNode;
        
        while (tmpNode2 -> next != nullptr && tmpNode2 -> next != head) {
            if (tmpNode2 -> next -> data == tmpNode -> data) {
                Node *duplicateFound = tmpNode2 -> next;
                tmpNode2 -> next = tmpNode2 -> next -> next;
                delete duplicateFound;
            }
            else {
                tmpNode2 = tmpNode2 -> next;
            }
        }
        
        tmpNode = tmpNode -> next;
    }
    
}

void bubbleSort() {
    Node *tmpNode = head;
    Node *tmpNode2 = head;
    while (tmpNode != nullptr && tmpNode -> next != head) {
        tmpNode2 = tmpNode;

        while (tmpNode2 -> next != nullptr && tmpNode2 -> next != head) {
            if (tmpNode -> data > tmpNode2 -> next -> data) {
                swap(tmpNode -> data, tmpNode2 -> next -> data);
            }
            else {
                tmpNode2 = tmpNode2 -> next;
            }
        }
        
        tmpNode = tmpNode -> next;
    }
}

