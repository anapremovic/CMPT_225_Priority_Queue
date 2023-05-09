#ifndef UNROLLED_LINKED_LIST
#define UNROLLED_LINKED_LIST

using namespace std;

#define ULL_NODE_CAPACITY 100

/*
ALL CREDIT TO codingninjas:
https://www.codingninjas.com/codestudio/library/unrolled-linked-list
*/

#include<bits/stdc++.h>
#include <iostream>

// class for a node
class Node {
public:
   Node* next; // Pointer to the next of the current node
   int num_elements; //Number of elements in the array at the current node
   int array[ULL_NODE_CAPACITY]; // Array of the current node
   // Constructor
   Node() // n is the size of the array
   {
       next = NULL; // Initialize next to NULL
       num_elements = 0;  // Initially, set the number of elements in the array to 0
   }
};
// Class of unrolled linked list
class UnrolledLinkedList {
public:
   Node *head; // Head of the linked list
   Node *tail; // Tail of the linked list
   //int node_size; // Size of the array of a node
   int tot_nodes; // total number of nodes
   // Parameterized Constructor for the unrolledLinkedList class. This will
   // be used for setting the maximum capacity
   UnrolledLinkedList()
   {
       head = NULL; // Initialize the head and tail to NULL
       tail = NULL;
       tot_nodes = 0; // Initialize the number of nodes to 0
       //node_size = capacity + 1; //Set the node size to capacity +1
   }

   // Function for insertion operation
   void insert(int num){
       tot_nodes++; // Increase the count of total number of nodes by 1
       // Check if the list is empty
       if (head == NULL) { 
           // If the list is already empty, we need to create a new node and
           //set the head and tail to it
           head = new Node(); 
           head->array[0] = num; // In the created node, push the current number at the 
           //0th position of the array
           head->num_elements++; // Increment the number of elements in this node by 1
           tail = head;
           return;
       }
       // If the list is not empty, check if we can add more elements to the last node or not
       if (tail->num_elements + 1 < ULL_NODE_CAPACITY) { // If we can add, push the current number to 
           // the tail's array
           tail->array[tail->num_elements] = num;
           tail->num_elements++;  //Increment the number of elements in tail by 1
       }
       // If we can't add more elements to the last node, we have to create a new node
       else {
           Node *new_node = new Node();
           int j = 0;
           // We move half of the elements from the current node to the new node 
           //such that the length of the current node is equal to the minimum threshold.
           for (int i = tail->num_elements / 2 + 1;i < tail->num_elements; i++)
               new_node->array[j++] = tail->array[i];
           // Update the tail to be equal to this newly created node
           new_node->array[j++] = num;
           new_node->num_elements = j;
           tail->num_elements = tail->num_elements / 2 + 1;
           tail->next = new_node;
           tail = new_node;
       }
   }
   // function for printing the list
   void print()
   {
       cout<<"Unrolled Linked List: "<<endl;
       Node *temp = head;
       // Start from the head node until yor reach the end
       while (temp != NULL) {
           // Print all the elements in the array of the node
           for (int i = 0; i < temp->num_elements; i++)
               cout<<(temp->array[i])<<" ";
           cout<<endl;
           // Move to the next node
           temp = temp->next;
       }
   }
};


#endif