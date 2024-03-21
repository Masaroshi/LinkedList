#ifndef LL
#define LL

struct Node{
    int data;
    Node* next;
    Node* prev;
};

extern Node *head;
extern Node *tail;

// =============================================================== //

void createSNode(int data);
void createSNodeStart(int data);
void deallocateSNodeByValue(int data);
void deallocateSNodeByItem(int item);
void deallocateLastSNode();
void deallocateFirstSNode();
void SLLtoCLL();
void DisplaySLL();
void SLLtoDLL();

// =============================================================== //

void createDNode(int data);
void createDNodeStart(int data);
void createDNodePosition(int position, int data);
void deallocateDNodeByValue(int data);
void deallocateDNodeByItem(int item);

#endif
