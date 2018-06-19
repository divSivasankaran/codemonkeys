# Discussion

## [Approach 1: Using Trie](https://github.com/div1090/codemonkeys/blob/master/Cracking%20the%20Coding%20Interview%20Challenges/Tries-%20Contacts/soln_2.cc)
* Create a trie to store the contacts.
* Each node stores the number of contacts stored in its subtrees.
* Update all the nodes when adding a contact.
* In order to search for a string, traverse the tie and return the number of contacts at that node.

* Time Complexity*:
* *ADD:* **O(m)**
* *FIND:* **O(m)**
*Worst-case Space Complexity* : **O(mn)**


## [Approach 2](https://github.com/div1090/codemonkeys/blob/master/Cracking%20the%20Coding%20Interview%20Challenges/Tries-%20Contacts/soln.cpp)

* Use a hash map & store each substring as a key with its value being the number of times it has been encountered so far. 
* For a search operation all you need to do is return the value of the given query string from the hash map if it exists & 0 otherwise.


*For example:*

If the input string is *"hacker"*, then add the following substrings as keys with value 1 if it doesn't exist and add 1 if it already exists : 
    
    h
    ha
    hac
    hack
    hacke
    hacker


**n** - Number of strings

**m** - Number of characters in the string

*Worst-case Time Complexities for each operation*

* *ADD:* **O(m)**

* *FIND:* **O(1)**

*Space Complexity* : **O(mn)**

# Question

We're going to make our own Contacts application! The application must perform two types of operations:

1) `add name`, where  is a string denoting a contact name. This must store  as a new contact in the application.
2) `find partial`, where  is a string denoting a partial name to search the application for. It must count the number of contacts starting with  and print the count on a new line.
Given `n` sequential *add* and *find* operations, perform each operation in order.

### Input Format

The first line contains a single integer, `n` , denoting the number of operations to perform. 
Each line `i` of the `n` subsequent lines contains an operation in one of the two forms defined above.

### Constraints

* 1 <= `n` <= 10<sup>5</sup>
* 1 <= `|name|` <= 21
* 1 <= `|partial|` <= 21
* It is guaranteed that  and  contain lowercase English letters only.
* The input doesn't have any duplicate  for the  operation.

### Output Format

For each `find partial` operation, print the number of contact names starting with *partial*  on a new line.

#### Sample Input
```
4
add hack
add hackerrank
find hac
find hak
```
#### Sample Output
```
2
0
```

#### Explanation

We perform the following sequence of operations:

1) Add a contact named `hack`.
2) Add a contact named `hackerrank`.
3) Find and print the number of contact names beginning with `hac`. There are currently two contact names in the application and both of them start with `hac`, so we print 2 on a new line.
4) Find and print the number of contact names beginning with `hak`. There are currently two contact names in the application but neither of them start with `hak`, so we print 0 on a new line.
