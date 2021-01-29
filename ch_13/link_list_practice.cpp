/**
 * practice with single linked list
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#include <iostream>
#include <cstdio>
using namespace std;

class Node{
    public:
        int _key;
        int _data;
        Node *_next;

        Node() : _key(0), _data(0), _next(nullptr){
        }
        Node(int k, int d) : _key(k), _data(d){
        }
};

class List{
    public:
        Node *_head;

        List() : _head(nullptr){
        }
        List(Node *n) : _head(n){
        }

        // 1. check if node exitst using key value
        // returning a pointer
        Node *nodeExists(int k){
            Node *temp = nullptr;
            Node *ptr = _head; // <- new ptr looking at _head, we will work with this ptr throught the function
            // loops while the pointer isnt at the end of the list
            while(ptr != nullptr){
                // if the key value that were looking at matches the key value we passed in,
                // then it sets our temp pointer to the pointer value thats looking at the node with
                // the matching key
                if(ptr->_key == k){
                    temp = ptr;
                }
                // makes pointer look at next node
                // in other words, we are "updating" the ptr
                ptr = ptr->_next;
            }
            return temp;
        }

        // 2. append node
        void appendNode(Node *n){
            if(nodeExists(n->_key) != NULL){
                printf("node already exists with key: %d\n",n->_key);
                printf("append another node with different key value.\n");
            }
            else{
                // if appending a second node
                if(_head == nullptr){
                    _head = n;
                    printf("node appended.\n");
                }
                // if appending another node thats not the second one
                else{
                    Node *ptr = _head;
                    while(ptr->_next != nullptr){
                        ptr = ptr->_next;
                    }
                    ptr->_next = n;
                    printf("node appended.\n"); 
                }
            }
        }

        // 3. prepend node
        void prependNode(Node *n){
            if(nodeExists(n->_key) != NULL){
                printf("node already exists with key: %d\n",n->_key);
                printf("append another node with different key value.\n");
            }
            else{
                // making the new node's "_next" ptr point at the same node "_head" is pointing to
                // which is the first node
                n->_next = _head;
                // now make _head point to new node, which is new "first" node
                _head = n;
                printf("node prepended.\n");
            }
        }

        // 4. insert node after particular node
        void insertNodeAfter(int k, Node *n){
            // using "nodeExists" to find the node we want based on the key we passed in
            // storing the node we want into *ptr...
            // basicly, our ptr will point to the same node with key "k"
            Node *ptr = nodeExists(k);
            if(ptr == nullptr){
                printf("no node exists with key: %d\n",n->_key);
            }
            else{
                if(nodeExists(n->_key) != NULL){
                    printf("node already exists with key: %d\n",n->_key);
                    printf("append another node with different key value.\n");
                }
                else{
                    // lets say.. the key we pass in is 2, and out new node has key 4
                    // we know: Node *ptr points to node 2, and ptr->_next points to node 3.
                    // so we make our new node's "_next" point
                    // to node 3 also
                    n->_next = ptr->_next;
                    // now, instead of ptr->_next looking at node 3, we want it to point to our new node 4
                    // which is inserted inbetween node 2 and 3.
                    ptr->_next = n;
                    printf("node inserted after node with key: %d\n", k);
                }
            }
        }

        // 5. delete node by key value
        void deleteNodeByKey(int k){
            if(_head == nullptr){
                printf("linked list already empty, nothing to delete.\n");
            }
            else if(_head != nullptr){
                // case for deleting first node..
                // if keys match, meaning the head node key = key we passed in
                if(_head->_key == k){
                    // make head ptr point to the next node
                    _head = _head->_next;
                    printf("node unlinked with node with key: %d\n", k);
                }
                // case for deleting other nodes..
                else{
                    Node *temp = nullptr;
                    Node *prevPtr = _head;
                    Node *currentPtr = _head->_next;

                    // loops until the end of the list
                    while(currentPtr != nullptr){
                        // if we get to the node we want,
                        // set temp ptr to look at it
                        // set current ptr to look at nothing
                        if(currentPtr->_key == k){
                            temp = currentPtr;
                            // setting current ptr to nullptr stops our loop
                            currentPtr = nullptr;
                        }
                        // if no match, go to next node
                        else{
                            prevPtr = prevPtr->_next;
                            currentPtr = currentPtr->_next;
                        }
                    }
                    if(temp != nullptr){
                        // the key we pass in is 2
                        // prevPtr is looking at node 1
                        // prevPtr->_next is looking at node 2
                        // now, we set prevPtr->_next = temp->_next which is looking at node 3, skipping node 2
                        // therefore unlinking node 2
                        prevPtr->_next = temp->_next;
                        printf("node unlinked with node with key: %d\n", k);
                    }
                    // temp is only != nullptr if we get a match from the first if statement in the while loop
                    else{
                        printf("no node exists with key: %d\n", k);
                    }
                }
            }
        }

        // 6. update node by key
        void updateNodeByKey(int k, int d){
            // sets ptr = node address of key we passed it
            Node *ptr = nodeExists(k);
            // if ptr points to a node
            if(ptr != nullptr){
                ptr->_data = d;
                printf("node data updated.");
            }
            else{
                printf("no node exists with key: %d\n", k);
            }
        }

        // 7. print list
        void printList(){
            if(_head == nullptr){
                printf("linked list is empty.\n");
            }
            else{
                Node *temp = _head;
                while(temp != nullptr){
                    printf("(%d,%d) -> ", temp->_key, temp->_data);
                    temp = temp->_next;
                }
            }
        }
};

int main(){
    List l;
    int option;
    int key1, k1, data1;

    do{
        cout << "\nWhat operation do you want to preform?\nSelect option number. Enter 0 to exit.\n";
        cout << "1. appendNode()\n";
        cout << "2. prependNode()\n";
        cout << "3. insertNodeAfter()\n";
        cout << "4. deleteNodeByKey()\n";
        cout << "5. updateNodeByKey()\n";
        cout << "6. print()\n";
        cout << "7. clear screen\n\n";

        cin >> option;
        Node *n1 = new Node();

        switch(option){
            case 0:
                break;
            case 1:
                cout << "Append node operation -\nEnter key & data to the node to be appended:\n";
                cin >> key1;
                cin >> data1;
                n1->_key = key1;
                n1->_data = data1;
                l.appendNode(n1);
                break;

            case 2:
                cout << "Prepend node operation -\nEnter key & data to the node to be prepended:\n";
                cin >> key1;
                cin >> data1;
                n1->_key = key1;
                n1->_data = data1;
                l.prependNode(n1);
                break;
            
            case 3:
                cout << "Insert node after operation -\nEnter key of existing node after you want to insert this node:\n";
                cin >> k1;
                cout << "Enter key & data to the node to be prepended:\n";
                cin >> key1;
                cin >> data1;
                n1->_key = key1;
                n1->_data = data1;
                l.insertNodeAfter(k1, n1);
                break;

            case 4:
                cout << "Delete node by key operation -\nEnter key of node to be deleted:\n";
                cin >> k1;
                l.deleteNodeByKey(k1);
                break;

            case 5:
                cout << "Update node by key operation -\nEnter key & new data of node to be updated:\n";
                cin >> key1;
                cin >> data1;
                l.updateNodeByKey(key1, data1);
                break;
                
            case 6:
                l.printList();
                break;

            case 7:
                system("cls");
                break;
            
            default:
                cout << "Enter proper operation number\n";
        }

    }while(option != 0);
    return 0;
}
