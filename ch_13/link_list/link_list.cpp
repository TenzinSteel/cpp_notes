/**
 * linked list
 *
 * Copyright (C) 2021, Tenzin Steel
 */

 #include "list.cpp"
 #include "node.cpp"

 int main(){
     List l1;
     l1.add(100);
     l1.add(200);
     l1.dump();

     for (int i = 3; i < 10; i++){
         l1.add(i * 100);
     }

     l1.dump();
 }