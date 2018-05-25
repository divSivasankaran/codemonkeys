# Discussion

We present 2 alternative approaches in our solutions and discuss the implications of each approach below:

### [Approach 1](https://github.com/div1090/codemonkeys/blob/master/Cracking%20the%20Coding%20Interview%20Challenges/Linked%20Lists-%20Detect%20a%20Cycle/soln.cpp)

* Use a hash based set to keep track of the nodes you visit.

* Iterate through each node in the linkedlist until you reach the end or the current node has been visited already
 - If the node hasn't been visited, add it to the hash-set.

*Average-case Time Complexity :* **O(n)**

*Worst-case Time Complexity :* **O(n<sup>2</sup>)**

*Worst-case Space Complexity :* **O(n)**

### [Approach 2](https://github.com/div1090/codemonkeys/blob/master/Cracking%20the%20Coding%20Interview%20Challenges/Linked%20Lists-%20Detect%20a%20Cycle/soln.py)

* Use two pointers to iterate through the list

* Pointer1 moves one node at a time

* Pointer2 moves 2 nodes at a time

* There exists a cycle if at any time Pointer1 & Pointer2 are equal. 

* Stop the execution if Pointer1 reaches the end of the linked-list.

*Worst-case Time Complexity :* **O(n)**

*Worst-case Space Complexity :* **O(n)** only to store the linked list. The processing/cycle detection is **O(1)**


# Question

Check out the resources on the page's right side to learn more about linked lists. The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book Cracking the Coding Interview.

A linked list is said to contain a cycle if any node is visited more than once while traversing the list.

Complete the function provided in the editor below. It has one parameter: a pointer to a Node object named that points to the head of a linked list. Your function must return a boolean denoting whether or not there is a cycle in the list. If there is a cycle, return true; otherwise, return false.

Note: If the list is empty,  will be null.

### Input Format

Our hidden code checker passes the appropriate argument to your function. You are not responsible for reading any input from stdin.

### Output Format

If the list contains a cycle, your function must return true. If the list does not contain a cycle, it must return false. The binary integer corresponding to the boolean value returned by your function is printed to stdout by our hidden code checker.

#### Sample Input
 
The following linked lists are passed as arguments to your function:

![Sample Input](https://s3.amazonaws.com/hr-challenge-images/1163/1463778594-900a0ae522-inputs.png)

#### Sample Output
```
0
1
```
#### Explanation

*The first list has no cycle, so we return false and the hidden code checker prints  to stdout.*
*The second list has a cycle, so we return true and the hidden code checker prints  to stdout.*
