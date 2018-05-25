/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

#include <unordered_set>

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    std::unordered_set<Node*> visited;
    bool cycle = false;
    Node *ptr = head;
    while(ptr!=NULL){
        if(visited.find(ptr)==visited.end())
        {
            visited.insert(ptr);
        }
        else{
            cycle = true;
            break;
        }
        ptr = ptr->next;
    }
    return cycle;
}
