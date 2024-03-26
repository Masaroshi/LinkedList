#ifndef LL
#define LL

struct Node{
    int data;
    Node* next;
    Node* prev;
};

extern Node *head;
extern Node *tail;


//                        Single Linked List
// =============================================================== //

void createSNode(int data);
void createSNodeStart(int data);
void createSNodePosition(int position, int data);
void deallocateSNodeByValue(int data);
void deallocateSNodeByItem(int item);
void deallocateLastSNode();
void deallocateFirstSNode();

//                       Doubly linked list
// =============================================================== //

void createDNode(int data);
void createDNodeStart(int data);
void createDNodePosition(int position, int data);
void deallocateDNodeByValue(int data);
void deallocateDNodeByItem(int item);
void deallocateLastDNode();
void deallocateFirstDNode();

#endif
