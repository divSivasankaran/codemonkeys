# Add two huge numbers

You're given 2 huge integers represented by linked lists. Each linked list element is a number from 0 to 9999 that represents a number with exactly 4 digits. The represented number might have leading zeros. Your task is to add up these huge integers and return the result in the same format.

### Example

For
```
a = [9876, 5432, 1999]
b = [1, 8001]
```
the output should be
```
addTwoHugeNumbers(a, b) = [9876, 5434, 0]
```

*Explanation:* 987654321999 + 18001 = 987654340000.

For
```
a = [123, 4, 5]
b = [100, 100, 100]
```
the output should be
```
addTwoHugeNumbers(a, b) = [223, 104, 105]
```

*Explanation:* 12300040005 + 10001000100 = 22301040105.

### Input/Output

* *Execution time limit:* 4 seconds (py3)

* *Input:* `linkedlist.integer a`, The first number, without its leading zeros.
  * *Guaranteed constraints:*
    * `0 ≤ a size ≤ 104`
    * `0 ≤ element value ≤ 9999``

* *Input:* `linkedlist.integer b`, The second number, without its leading zeros.
  * *Guaranteed constraints:*
    * `0 ≤ b size ≤ 104`
    * `0 ≤ element value ≤ 9999`

* *Output:* `linkedlist.integer`, The result of adding a and b together, returned without leading zeros in the same format.
