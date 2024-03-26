#include <iostream>
#include "../src/headers/Linked List Header.hpp"
#include "../src/headers/Functions.hpp"
using namespace std;

int main(){
    system("CLS");

    cout << "   *****Single Linked List's Functions*****";
    cout << "\ncreateSNode(int data) :: INT -> IO()\n";
    cout << "creates a Node at the end of the single linked list\n";
    createSNode(10);
    createSNode(20);
    createSNode(30);
    createSNode(40);
    createSNode(50);
    createSNode(60);
    createSNode(70);
    Display();

    cout << "\n\ncreateSNodeStart(int data) :: INT -> IO()\n";
    cout << "creates a Node at the start of the single linekd list\n";
    createSNodeStart(5);
    Display();

    cout << "\n\ncreateSNodePosition(int position, int data) :: INT -> INT -> IO ()\n";
    cout << "creates a Node at the selected position: (2, 15)\n"; 
    createSNodePosition(2, 15);
    Display();

    cout << "\n\ndeallocateSNodeByValue(int data) :: INT -> IO()\n";
    cout << "deallocates a Node that has the same value: (60)\n";
    deallocateSNodeByValue(60);
    Display();

    cout << "\n\ndeallocateSNodeByItem(int item) :: INT -> IO()\n";
    cout << "deallocates a Node from the selected position: (0)\n";
    deallocateSNodeByItem(0);
    Display();

    cout << "\n\ndeallocateLastSNode() :: () -> IO()\n";
    cout << "deallocates the last Node\n";
    deallocateLastSNode();
    Display();

    cout << "\n\ndeallocateFirstSNode() :: () -> IO()\n";
    cout << "deallocates the first Node\n";
    deallocateFirstSNode();
    Display();

    cout << "\n\npress Enter to continue...";
    cin.get();
    system("CLS");

    cout << "   *****Double Linked List's Functions*****\n (we have used LLtoDLL() function to turn the linked list to double first!)";
    LLtoDLL();

    cout << "\n\ncreateDNode(int data) :: INT -> IO()\n";
    cout << "creates a Node at the end of the Double linked list\n";
    createDNode(50);
    Display();

    cout << "\n\ncreateDNodeStart(int data) :: INT -> IO()\n";
    cout << "creates a Node at the start of the Double linekd list\n";
    createDNodeStart(10);
    createDNodeStart(0);
    Display();

    cout << "\n\ncreateDNodePosition(int position, int data) :: INT -> INT -> IO()\n";
    cout << "creates a Node at the selected position: (2, 15)\n"; 
    createSNodePosition(3, 30);
    Display();

    cout << "\n\ndeallocateDNodeByValue(int data) :: INT -> IO()\n";
    cout << "deallocates a Node that has the same value: (40)\n";
    deallocateSNodeByValue(40);
    Display();

    cout << "\n\ndeallocateDNodeByItem(int item) :: INT -> IO()\n";
    cout << "deallocates a Node from the selected position: (6)\n";
    deallocateSNodeByItem(6);
    Display();

    cout << "\n\ndeallocateLastDNode() :: () -> IO()\n";
    cout << "deallocates the last Node\n";
    deallocateLastSNode();
    Display();

    cout << "\n\ndeallocateFirstSNode() :: () -> IO()\n";
    cout << "deallocates the first Node\n";
    deallocateFirstSNode();
    Display();

    cout << "\n\npress Enter to continue...";
    cin.get();
    system("CLS");

    cout << "   *****Both worlds Functions*****\nthese functions support both DLL and SLL even if they are Circular\n";

    cout << "\nLLtoDLL() :: () -> IO()\n";
    cout << "turns a linked list to a Double linked list\n";
    LLtoDLL();
    Display();
    cout << "\n                  | this is a sign of a Double linked list.";

    cout << "\n\nLLtoCLL() :: () -> IO()\n";
    cout << "turns a linked list to a Circular linked list\n";
    LLtoCLL();
    Display();
    cout << "\n                 | this is a sign of a Circular linked list.";

    cout << "\ntimesOccurred(int target_data) :: INT -> INT\ncounts the times an input has occurred\n";
    Display();
    cout << "\n" << timesOccurred(30);

    cout << "\n\nlength() :: () -> INT\ncount the total of Nodes in a linked list\n";
    Display();
    cout << "\n" << length();

    cout << "\n\nisCLL() :: () -> INT\nDetermines if the linked list is Circular or not: empty: 0, false: -1, true: 1";
    cout << "\n" << isCLL() << " -> ";
    cout << (1 == isCLL() ? "True" : (-1 == isCLL() ? "False" : "Empty"));

    cout << "\n\nisDLL() :: () -> INT\nDetermines if the linked list is double or not: empty: 0, false: -1, true: 1";
    cout << "\n" << isDLL() << " -> ";
    cout << (1 == isDLL() ? "True" : (-1 == isDLL() ? "False" : "Empty"));

    cout << "\n\nisEmpty() :: () -> BOOL\nDetermines if the linked list is double or not";
    cout << "\n" << isEmpty() << " -> ";
    cout << (true == isEmpty() ? "True" : "False");

    cout << "\n\npress Enter to continue...";
    cin.get();
    system("CLS");

    cout << "   *****Both worlds Functions*****\nthese functions support both DLL and SLL even if they are Circular\n";

    cout <<"\nDisplay() :: () -> ()\nPrints the data's in each Nodes\n";
    Display();

    cout << "\n\nexchangeFirstwLast() :: () -> IO()\nswaps the data's in First and Last Node\n";
    exchangeFirstwLast();
    Display();

    cout << "\n\nexchange(int first, int second) :: INT -> INT -> IO()\nswaps the data's from the first and second selected position Node: (1,2)\n";
    exchange(1,2);
    Display();

    cout <<"\n\nreverse() :: () -> IO()\nreverses the linked list\n";
    reverse();
    Display();

    cout << "\n\nreverseDisplay() :: () -> ()\nprints the linked list reverse(without reversing the linked list)\n";
    reverseDisplay();

    cout << "\n\nrotateBy(int NumberofRotates) :: INT -> IO()\nRotates the linked list by an INT: (2)\n";
    rotateBy(2);
    Display();

    cout << "\n\nmodify(int item, int data) :: INT -> INT -> IO()\nmodifies the value of a selected item: (3, 90)\n";
    modify(3, 90);
    Display();

    cout << "\n\nremoveDuplicates() :: () -> IO()\nsimple! just removes duplicates\n";
    removeDuplicates();
    Display();

    cout << "\n\nbubbleSort() :: () -> IO()\nsorts the list using bubble sort\n";
    bubbleSort();
    Display();

}