#ifndef LINKED_LIST
#define LINKED_LIST

/*
ALL CREDIT TO geeksforgeeks:
https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/
*/

// C++ program for the above approach
#include <iostream>
using namespace std;
 
// Node class to represent
// a node of the linked list.
class LLNode {
public:
    int data;
    LLNode* next;
 
    // Default constructor
    LLNode()
    {
        data = 0;
        next = NULL;
    }
 
    // Parameterised Constructor
    LLNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
 
// Linked list class to
// implement a linked list.
class LinkedList {
    
public:
    LLNode* head;

    // Default constructor
    LinkedList() { head = NULL; }

    // Function to insert a new node at the end of the list
    void insertNode(int data)
    {
        // Create the new Node.
        LLNode* newNode = new LLNode(data);
    
        // Assign to head
        if (head == NULL) {
            head = newNode;
            return;
        }
    
        // Traverse till end of list
        LLNode* temp = head;
        while (temp->next != NULL) {
    
            // Update temp
            temp = temp->next;
        }
    
        // Insert at the last.
        temp->next = newNode;
    }
    
    // Function to delete the
    // node at given position
    void deleteNode(int nodeOffset)
    {
        LLNode *temp1 = head, *temp2 = NULL;
        int ListLen = 0;
    
        if (head == NULL) {
            cout << "List empty." << endl;
            return;
        }
    
        // Find length of the linked-list.
        while (temp1 != NULL) {
            temp1 = temp1->next;
            ListLen++;
        }
    
        // Check if the position to be
        // deleted is greater than the length
        // of the linked list.
        if (ListLen < nodeOffset) {
            cout << "Index out of range"
                << endl;
            return;
        }
    
        // Declare temp1
        temp1 = head;
    
        // Deleting the head.
        if (nodeOffset == 1) {
    
            // Update head
            head = head->next;
            delete temp1;
            return;
        }
    
        // Traverse the list to
        // find the node to be deleted.
        while (nodeOffset-- > 1) {
    
            // Update temp2
            temp2 = temp1;
    
            // Update temp1
            temp1 = temp1->next;
        }
    
        // Change the next pointer
        // of the previous node.
        temp2->next = temp1->next;
    
        // Delete the node
        delete temp1;
    }
};
 

 

// Function to print the
// nodes of the linked list.
// void LinkedList::printList()
// {
//     LLNode* temp = head;
 
//     // Check for empty list.
//     if (head == NULL) {
//         cout << "List empty" << endl;
//         return;
//     }
 
//     // Traverse the list.
//     while (temp != NULL) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//}

#endif