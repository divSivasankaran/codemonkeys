# Discussion

### [Approach 1](https://github.com/div1090/codemonkeys/blob/master/Cracking%20the%20Coding%20Interview%20Challenges/Trees%20-%20Is%20This%20a%20Binary%20Tree%3F/soln.py)

* Traverse the binary tree in order and append each of the nodes into an array
* Check if the array elements are sorted

*Worst-case Time Complexities*:

*Traverse in order* : **O(n)**

*Array checking*: **O(n)**

*Additional Space complexity* : **O(n)**

# [Question](https://www.hackerrank.com/challenges/ctci-is-binary-search-tree/problem)

For the purposes of this challenge, we define a binary search tree to be a binary tree with the following properties:

* The value of every node in a node's left subtree is less than the data value of that node.
* The value of every node in a node's right subtree is greater than the data value of that node.
* The value of every node is distinct.

For example, the image on the left below is a valid BST. The one on the right fails on several counts:
- All of the numbers on the right branch from the root are not larger than the root.
- All of the numbers on the right branch from node 5 are not larger than 5.
- All of the numbers on the left branch from node 5 are not smaller than 5.
- The data value 1 is repeated.

![image](./sample1.png) | ![image](./sample2.png)

Given the root node of a binary tree, determine if it is a binary search tree.

## Function Description
Complete the function checkBST in the editor below. It must return a boolean denoting whether or not the binary tree is a binary search tree.

checkBST has the following parameter(s):

* root: a reference to the root node of a tree to test

### Input Format

You are not responsible for reading any input from stdin. Hidden code stubs will assemble a binary tree and pass its root node to your function as an argument.

### Constraints
    0 < data < 10^4
### Output Format

Your function must return a boolean true if the tree is a binary search tree. Otherwise, it must return false.

### Sample Input
![image](./input1.png)
### Sample Output
    Yes
