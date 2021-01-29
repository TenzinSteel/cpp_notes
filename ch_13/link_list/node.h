/**
 * node header
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#ifndef NODE_H_
#define NODE_H_

struct Node{
    int val;
    Node *next;
    Node(int);
};

#endif // NODE_H_