#ifndef EXP_1
#define EXP_1

#include <iostream>
#include <time.h>

using namespace std;

// CREDIT TO DAVID MITCHELL FOR TIMING CODE (FROM ASSIGNMENT 2)
double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
    return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
}

int main() {
    const int NUM_ELEMENTS = 1000000;

    int* a1 = new int[NUM_ELEMENTS]();
    int* a2 = new int[NUM_ELEMENTS]();

    double chache_hit_time = 0.0;
    double a1_total_time = 0.0;

    // use the loop that David Mitchell recommended in "Remarks on Each Experiment (1)" -> nested for loop
    // this will prevent the hardware feature that lowers the number of cache misses
    for(int i=0; i < NUM_ELEMENTS; i+=64) {
        for(int j=0; j<16; j++) {
            clock_t start, finish ;
            start = clock();

            // access the element (in an arbitrary way)
            //int temp = a1[i+j];  
            a1[i+j];

            finish = clock(); 
            double cur_time = elapsed_time(start,finish);
            a1_total_time += cur_time;

            //temp++;

            if(j>=1) { // CACHE HITS ONLY
                chache_hit_time += cur_time;
            }
        }    
    }
    
    
    double a2_total_time = 0.0;
    
    for(int i=0; i < NUM_ELEMENTS; i+=64) {
        clock_t start2, finish2 ;
        start2 = clock(); 

        // access the element (in an arbitrary way)
        //int temp = a2[i];
        a2[i];

        finish2 = clock(); 
        a2_total_time += elapsed_time(start2,finish2);

        //temp++;
    }
    

    cout << "Loop that accesses all elements: " << a1_total_time << " milliseconds" << endl;
    cout << "Loop that accesses every 16th element: " << a2_total_time << " milliseconds" << endl;

    cout << "Estimated average time for array access WITHOUT cache misses: " << chache_hit_time/(NUM_ELEMENTS/16)  << " milliseconds" << endl;
    cout << "Estimated average time for array access WITH cache misses: " << a2_total_time/(NUM_ELEMENTS/16)  << " milliseconds" << endl;

    return 0;
}

#endif