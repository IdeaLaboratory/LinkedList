# LinkedList
Linked List, start from scratch. will slowly add on features.

Now we want to sort the linked list.
there are different sorting algorithm we can use, selection / bubble / insertion -sort will be easy t oimplement.
but if we consider about the time and complexity. We know heap sort gives O(nLogn) time complexity and O(1) space complexity.
**However, when you have a linked list heapsort is no longer O(n log n) because it relies on random access to the array, which you do not have in a linked list.
so actual complexity will be O(n* nLogn).

***We will use merge sort instead***