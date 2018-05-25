// This is just a code snippet that shows a sample implementation. Input & output for reading & printing the results are not incldued.

#include <unordered_set>

/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.
*/ 
struct Node {
    int data;
    struct Node* next;
}

bool has_cycle(Node* head) {
    // use a hashable set with the node-addresses as keys to keep track of the nodes we have visted
    std::unordered_set<Node*> visited;
    
    // a boolean variable that keeps track of our current status for cycle-detection
    bool cycle = false;
   
    Node *ptr = head;
    // Iterate through the linked-list until you reach the end of the list 
    while(ptr!=NULL){
        
        // If we have not already visited this particular node, we add it to our hash-set. 
        if(visited.find(ptr)==visited.end())
        {
            visited.insert(ptr);
        }
        // If it already exists, it means this linked-list contains a cycle. So we update our boolean variable and exit the loop.
        else{
            cycle = true;
            break;
        }
        
        // Move to the next node in the linked-list.
        ptr = ptr->next;
    }
    
    return cycle;
}
