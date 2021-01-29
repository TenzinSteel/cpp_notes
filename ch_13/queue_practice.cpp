/**
 * queue practice
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#include <cstdio>
#include <stdlib.h>

struct Node{
    int _data;
    Node *_link;
};

Node *front = nullptr;
Node *rear = nullptr;

class Queue{
    private:
        Node *_front = nullptr;
        Node *_rear = nullptr;

    public:
        Queue(){
        }

        // 1. check to see if queue is empty
        bool isEmpty(){
            if(_front == nullptr && _rear == nullptr){
                 return true;
            }
            else{
                return false;
            }
        }

        // 3. add queue
        void enQueue(int v){
            Node *ptr = new Node;
            ptr->_data = v;
            ptr->_link = nullptr;
            // means we are inserting first node
            if(_front == nullptr){
                _front = ptr;
                _rear = ptr;
            }
            else{
                // link node with new node
                _rear->_link = ptr;
                // update rear pointer
                _rear = ptr;
            }
        }

        // 4. de queue
        void deQueue(){
            if(isEmpty()){
                printf("queue is empty");
            }
            else if(_front == _rear){
                free(_front);
                _front = _rear = nullptr;
            }
            else{
                Node *temp = _front;
                _front = _front->_link;
                free(temp);
            }
        }

        // 5. display
        void display(){
            if(isEmpty()){
                printf("queue is empty");
            }
            else{
                Node *ptr = _front;
                while(ptr != nullptr){
                    printf("data: %d\n",ptr->_data);
                    ptr = ptr->_link;
                }
            }
        }
};

int main(){
    Queue q1;
    q1.enQueue(1);
    q1.enQueue(2);
    q1.enQueue(3);
    q1.enQueue(4);
    q1.display();
    q1.deQueue();
    q1.deQueue();
    q1.display();
}