#ifndef EXP_4
#define EXP_4

#include "AvlTree.h"
#include "BTree.h"

#include <random>
#include <iostream>
#include <time.h>

// CREDIT TO DAVID MITCHELL FOR TIMING CODE (FROM ASSIGNMENT 2)
double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
    return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
}

int main() {
    const int TOTAL_NUMS = 700000; // number of tree elements

    BTree b(2); // B-Tree
    AvlTree<int> a; // AVL Tree

    int array[TOTAL_NUMS]; // array used to access the elements of the trees

    // add the same elements to the trees
    for(int i=0; i < TOTAL_NUMS; i++) {
        int cur = rand() % 100;

        array[i] = cur;
        b.insert(cur);
        a.insert(cur);
    }

    // TIME THE B-TREE OVER 30 TRIALS
    double BTree_times[30];

    for(int m=0; m < 30; m++) {
        // flood the cache
        int cache_flooder[1000000];
        cache_flooder[0] = 1; // remove warning
        cache_flooder[1] = cache_flooder[0]+1;

        // TIME THE B-TREE
        double b_tree_time = 0.0;
        clock_t start, finish ;
        start = clock();
        for(int i=0; i < TOTAL_NUMS; i++) {   
            // access the B-Tree element 
            b.search(array[i]);
        }
        finish = clock(); 
        b_tree_time = elapsed_time(start,finish);

        // add the AVERAGE accessing time from this trial
        BTree_times[m] = b_tree_time/TOTAL_NUMS;
    }

    
    // TIME THE AVL TREE OVER 30 TRIALS
    double AVL_Tree_times[30];

    for(int m=0; m < 30; m++) {
        // flood the cache
        int cache_flooder[1000000];
        cache_flooder[0] = 1; // remove warning
        cache_flooder[1] = cache_flooder[0]+1;

        // TIME THE AVL TREE
        double avl_tree_time = 0.0;
        clock_t start2, finish2 ;
        start2 = clock(); 
        for(int i=0; i < TOTAL_NUMS; i++) {
            // access the AVL Tree element
            a.contains(array[i]);  
        }
        finish2 = clock(); 
        avl_tree_time = elapsed_time(start2,finish2);

        // add the AVERAGE accessing time from this trial
        AVL_Tree_times[m] = avl_tree_time/TOTAL_NUMS;
    }
    
    double btree_total = 0.0;
    double avltree_total = 0.0;
    for(int i=0; i<30; i++) {
        btree_total += BTree_times[i];
        avltree_total += AVL_Tree_times[i];
    }

    // DISPLAY RESULTS
    cout << "Average B Tree access time: " << btree_total/30 *1000 << " microseconds" << endl;
    cout << "Average AVL Tree access time: " << avltree_total/30 *1000 << " microseconds" << endl;
    
    return 0;
}

#endif