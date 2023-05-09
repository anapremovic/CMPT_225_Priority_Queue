#ifndef EXP_3
#define EXP_3

#include <iostream>
#include "UnrolledLinkedList.h"
#include "LinkedList.h"

#include <random>
#include <time.h>

using namespace std;

// CREDIT TO DAVID MITCHELL FOR TIMING CODE (FROM ASSIGNMENT 2)
double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
    return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
}

int main() {
    const int TOTAL_NUMS = 100000;

    int ar[TOTAL_NUMS]; // array

    UnrolledLinkedList ull; // unrolled linked list

    LinkedList ll; // singly linked list

    // add the same elements to each data structure
    for(int i=0; i < TOTAL_NUMS; i++) {
        int random_number = rand() % 1000; // random number between 1 and 1000

        ar[i] = random_number;
        ull.insert(random_number);
        ll.insertNode(random_number);
    }
    
    // ARRAY TIMING: traverse the entire array
    clock_t start, finish ;
    start = clock(); 
    for(int i=0; i < TOTAL_NUMS; i++) {
        // access the array element (arbitrary operation on it)
        ar[i] = ar[i] * 3 + 16;
    }
    finish = clock(); 
    double total_time_array = elapsed_time(start,finish);

    // UNROLLED LINKED LIST TIMING
    clock_t start2, finish2;
    start2 = clock();

    Node* ull_cur = ull.head; // used to traverse

    while(ull_cur -> next != nullptr) {
        for(int i=0; i < ull_cur->num_elements; i++) { // go through current node's array
            // access the list element (arbitrary operation on it)
            ull_cur->array[i] = ull_cur->array[i] * 3 + 16;
        }

        ull_cur = ull_cur->next; // go to next node
    }
    finish2 = clock(); 
    double total_time_unrolled_linked_list = elapsed_time(start2,finish2);

    // LINKED LIST TIMING
    clock_t start3, finish3 ;
    start3 = clock(); 

    LLNode* ll_cur = ll.head; // used to traverse

    while(ll_cur -> next != nullptr) {
        // access the list element (arbitrary operation on it)
        ll_cur->data = ll_cur->data * 3 + 16;

        ll_cur = ll_cur->next;
    }
    finish3 = clock(); 
    double total_time_linked_list = elapsed_time(start3,finish3);    

    // DISPLAY RESULTS
    cout << "Array: " << total_time_array << " milliseconds" << endl;
    cout << "Unrolled Linked List: " << total_time_unrolled_linked_list << " milliseconds" << endl;
    cout << "Linked List: " << total_time_linked_list << " miliseconds" << endl;

    return 0;
}

#endif