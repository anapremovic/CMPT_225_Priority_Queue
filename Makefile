all: AvlTree BTree LinkedList UnrolledLinkedList dsexceptions exp1 exp3 exp4

AvlTree: AvlTree.h 
	g++ -Wall AvlTree.h

BTree: BTree.h 
	g++ -Wall BTree.h

LinkedList: LinkedList.h
	g++ -Wall LinkedList.h

UnrolledLinkedList: UnrolledLinkedList.h
	g++ -Wall UnrolledLinkedList.h

dsexceptions: dsexceptions.h
	g++ -Wall dsexceptions.h

exp1: exp1.o
	g++ -Wall -o exp1 exp1.o

exp1.o: 
	g++ -Wall -o exp1.o -c exp1.cpp

exp3: exp3.o
	g++ -Wall -o exp3 exp3.o

exp3.o: LinkedList.h UnrolledLinkedList.h
	g++ -Wall -o exp3.o -c exp3.cpp

exp4: exp4.o
	g++ -Wall -o exp4 exp4.o

exp4.o: AvlTree.h BTree.h dsexceptions.h
	g++ -Wall -o exp4.o -c exp4.cpp


clean:
	rm -f exp1 *.o exp3 *.o exp4 *.o