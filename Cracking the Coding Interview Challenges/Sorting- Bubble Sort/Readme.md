
# Discussion

*Worst-case Time Complexity :* **O(n<sup>2</sup>)**

*Worst-case Space Complexity :* **O(n)**

# Question
Consider the following version of Bubble Sort:
```
for (int i = 0; i < n; i++) {
    
    for (int j = 0; j < n - 1; j++) {
        // Swap adjacent elements if they are in decreasing order
        if (a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
        }
    }
    
}
```

### Task 
Given an n-element array,`A`, of distinct elements, sort array `A` in ascending order using the Bubble Sort algorithm above. Once sorted, print the following three lines:

1) `Array is sorted in numSwaps swaps.`, where `numSwaps` is the number of swaps that took place.
2) `First Element: firstElement`, where `firstElement` is the first element in the sorted array.
3) `Last Element: lastElement`, where `lastElement` is the last element in the sorted array.

**Hint**: To complete this challenge, you must add a variable that keeps a running tally of all swaps that occur during execution.

### Input Format 

The first line contains an integer,`n` , denoting the number of elements in array `A`. 
The second line contains `n` space-separated integers describing the respective values of the array.

### Constraints

* 2 <= n <= 600
* 1 <= a<sub>i</sub> <= 2 x 10<sup>6</sup>

### Output Format

You must print the following three lines of output:

1) `Array is sorted in numSwaps swaps.`, where `numSwaps` is the number of swaps that took place.
2) `First Element: firstElement`, where `firstElement` is the first element in the sorted array.
3) `Last Element: lastElement`, where `lastElement` is the last element in the sorted array.

#### Sample Input 0
```
3
1 2 3
```
#### Sample Output 0
```
Array is sorted in 0 swaps.
First Element: 1
Last Element: 3
```
### Explanation 0 
The array is already sorted, so  swaps take place and we print the necessary three lines of output shown above.

#### Sample Input 1
```
3
3 2 1
```
#### Sample Output 1
```
Array is sorted in 3 swaps.
First Element: 1
Last Element: 3
```
