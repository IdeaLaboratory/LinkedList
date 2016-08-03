#1
LinkedList
Linked List, start from scratch. will slowly add on features.

#2
Now we want to sort the linked list.
there are different sorting algorithm we can use, selection / bubble / insertion -sort will be easy t oimplement.
but if we consider about the time and space complexity, We know heap sort gives O(nLogn) time complexity and O(1) space complexity.
**However, when you have a linked list heapsort is no longer O(n log n) because it relies on random access to the array, which you do not have in a linked list.
so actual complexity will be O(n* nLogn).

***We will use merge sort instead***

#3
But before implement merge sort we can quickly implement selection sort.

#4
Implemented function to print all the nodes data

#5
Suppose only a pointer to a node is given. How to be deleted the same from a singly linked list? (to be answered)