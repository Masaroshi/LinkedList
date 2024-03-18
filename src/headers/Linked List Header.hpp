#ifndef SLL
#define SLL

struct Node{
    int data;
    Node* next;
    Node* prev;
};

extern Node *head;
extern Node *tail;

void createSNode(int data);
void deallocateSNodeByValue(int data);
void deallocateSNodeByItem(int item);
void deallocateLastSNode();
void deallocateFirstSNode();
void exchangeFirstwLastSNode();
void exchangeSNode(int first, int second);
void SLLtoCLL();
void DisplaySLL();
void SLLtoDLL();

#endif
