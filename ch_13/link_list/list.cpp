/**
 * link lists
 *
 * Copyright (C) 2021, Tenzin Steel
 */
#include <cstdio>
#include "list.h"

List:: List() : _head(nullptr), _tail(nullptr){
}

// O(1) time complexity because it takes "constant"
// time irrespective of the size of the list
void List:: add(int v){
    // be sure to create nodes on the heap
    Node *np = new Node(v);

    if (_head == nullptr){
        // Be sure to update all the affected atributes
        _head = np;
        _tail = np; 
        return;
    }
    _tail->next = np;
    _tail = _tail->next;
}

void List:: dump(){
    for (Node *np = _head; np != nullptr; np = np->next){
        if (np != _head){
            printf(" -> ");
        }
        printf("%d", np->val);
    }
    printf("\n");
}