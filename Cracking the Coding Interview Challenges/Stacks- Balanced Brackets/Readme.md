# Discussion

## [Approach 1](https://github.com/div1090/codemonkeys/blob/master/Cracking%20the%20Coding%20Interview%20Challenges/Stacks-%20Balanced%20Brackets/soln.cpp)

* Iterate through each character in the string & check whether it is a left or a right bracket.
* If it is a left bracket -> add it to the stack
  Else check if the top of the stack matches the current character
* If there are too few left braces, or too many left braces, or the right & left brackets don't match, then the expression is not balanced.

A stack follows a Last-In-First-Out policy which is perfect for this question as we want to match the most recently seen left-bracket with each right-bracket we notice.


**n** - length of the input string

*Time Complexity*: **O(n)**

*Space Complexity*: **O(n)**

This is because we only need to iterate through each character in the string. The push and pop operations in a stack are O(1).
There are two helper functions `matcher(char )` and `isLeft(char )` that return the correct matching bracket & help decide if the given character is a left bracket/right brakcet accordingly. Both these functions operate at **O(1)** time-complexity

## [Approach 2]

* Similar to Approach 1, with a few differences in python implementation
* Use stack as data structure to process the input string
* Iterate through input string character by character
* if stack is empty, just add the current character to stack
* else check if top of stack is a match to current character through look-up from a dictionary
    - if it is a match, pop the top of the stack
    - else, add current character to the stack
* after iterating through the input string, if the stack is empty, it implies the expression is balanced. 

# Question

A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].

Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. There are three types of matched pairs of brackets: [], {}, and ().

A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For example, {[(])} is not balanced because the contents in between { and } are not balanced. The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ].

Some examples of balanced brackets are []{}(), [({})]{}() and ({(){}[]})[].

By this logic, we say a sequence of brackets is considered to be balanced if the following conditions are met:

It contains no unmatched brackets.
The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.
Given  strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, print YES on a new line; otherwise, print NO on a new line.

### Input Format

The first line contains a single integer, , denoting the number of strings.
Each line  of the  subsequent lines consists of a single string, , denoting a sequence of brackets.

### Output Format

For each string, print whether or not the string of brackets is balanced on a new line. If the brackets are balanced, print YES; otherwise, print NO.

#### Sample Input
```
3
{[()]}
{[(])}
{{[[(())]]}}
```
#### Sample Output
```
YES
NO
YES
```

#### Explanation

The string {[()]} meets both criteria for being a balanced string, so we print YES on a new line.
The string {[(])} is not balanced, because the brackets enclosed by the matched pairs [(] and (]) are not balanced. Thus, we print NO on a new line.
The string {{[[(())]]}} meets both criteria for being a balanced string, so we print YES on a new line.
