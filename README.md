# Abstract Data Type Implementation - Singly Linked List
Implementation work for Data Structure I discipline - ADT Simply Linked List. Environment: Windows 10/ Windows 11.

<h2> Whats is an ADT? </h2>
An ADT, or Abstract Data Type, is a classification for objects that specifies their behavior based on a group of values and operations. Unlike other data types, ADTs do not dictate how these operations must be executed but only focus on what functionalities they should possess. This allows flexibility in implementing ADTs, as different programming languages or systems can provide distinct ways of realizing the specified behaviors.<br>

<h2> Singly Liked List Implementation </h2>
A singly linked list is a linear data structure where each element is a separate object. Each element (or node) of a list consists of two items: the data and a reference to the next node. The last node has a reference to null, indicating the end of the list. The entry point into a linked list is called the head of the list. It should be noted that head is not a separate node, but the reference to the first node. If the list is empty, then the head is a null reference.<br><br>

![singlylinkedlist](https://github.com/brvcelose/adt-singly-linked-list/assets/92281096/c27ffa7a-2638-4ed5-a642-8399164ab99a)<br>

<h2> In the Code: </h2>

1. Node
```
typedef struct slnode_ {
    void *data;
    struct SLNode *next;
} SLNode;
```
2. Head of the list
```
typedef struct sllist_ {
    struct SLNode *first;
} SLList;
```

<h2> Time Complexity </h2>
O(n) for Accessing, insertion, or deletion at the beginning and searching for an element, where n is the number of elements.

<h2> Space Complexity </h2>
O(n), as each element requires space for its data and pointers to the next (and possibly previous) node, resulting in linear space usage proportional to the number of elements.
