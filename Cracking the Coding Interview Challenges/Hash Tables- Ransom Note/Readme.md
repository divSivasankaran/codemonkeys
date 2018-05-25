# Discussion:

### Solution using Map 

*Worst-case Time Complexity :* **O((m+n) log m)**

*Worst-case Space Complexity :* **O(m + n)**

### Solution using hash_map
This gives better average-case complexity, however worst-case is worse than using maps:

*Average-Case Time Complexity :* **O(m + n)**

*Worse Case Time Complexity :*  **O(m<sup>2</sup> + mn)**

Depending on the use-case you may want to evaluate the trade-offs and use the right data-structure.

Note that in c++, the equivalent of a hash table is `std::unordered_map` and `std::map` serves as map. In python however, `dict` is already based on an efficient hash structure.

# Question 

https://www.hackerrank.com/challenges/ctci-ransom-note/problem

Check out the resources on the page's right side to learn more about hashing. The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book Cracking the Coding Interview.

A kidnapper wrote a ransom note but is worried it will be traced back to him. He found a magazine and wants to know if he can cut out whole words from it and use them to create an untraceable replica of his ransom note. The words in his note are case-sensitive and he must use whole words available in the magazine, meaning he cannot use substrings or concatenation to create the words he needs.

Given the words in the magazine and the words in the ransom note, print Yes if he can replicate his ransom note exactly using whole words from the magazine; otherwise, print No.

### Input Format

The first line contains two space-separated integers describing the respective values of  (the number of words in the magazine) and  (the number of words in the ransom note). 
The second line contains  space-separated strings denoting the words present in the magazine. 
The third line contains  space-separated strings denoting the words present in the ransom note.

### Constraints

Each word consists of English alphabetic letters (i.e.,  to  and  to ).
The words in the note and magazine are case-sensitive.
Output Format

Print Yes if he can use the magazine to create an untraceable replica of his ransom note; otherwise, print No.

#### Sample Input 0

6 4
give me one grand today night
give one grand today

#### Sample Output 0

Yes

#### Sample Input 1

6 5
two times three is not four
two times two is four

#### Sample Output 1

No

#### Explanation 1

two should occur two times in the magazine
