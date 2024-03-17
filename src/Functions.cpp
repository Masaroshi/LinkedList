#include <iostream>
#include "headers\Linked List Header.hpp"
#include "headers\Linked List Header.hpp"
using namespace std;

int timesOccurred(int targetData) {
    if (nullptr == head){
        return -1;
    }
    int counter = 0;
    Node *tmpNode = head;
    do {
        if(targetData == (*tmpNode).data) {
            counter++;
        }
        tmpNode = (*tmpNode).next;
    } while (tmpNode != head);

    return counter;
}

bool isCLL() {
    if (nullptr == head){
        return false;
    }
    Node* Check1 = head;
    Node* Check2 = head;

    while (Check2 != nullptr && (*Check2).next != nullptr) {
        Check1 = (*Check1).next;
        Check2 = (*(*Check2).next).next;

        if (Check1 == Check2) {
            return true;
        }
    }

    return false;
}