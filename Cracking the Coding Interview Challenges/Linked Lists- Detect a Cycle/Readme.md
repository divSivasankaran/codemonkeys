# Discussion




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
