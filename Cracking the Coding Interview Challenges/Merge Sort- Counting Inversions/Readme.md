## Discussion

**n** - the number of elements in the array

*Average, Best & Worst-case Time Complexity :* **O(n log n)**

*Space Complexity :* **O(n)**

### Key Idea

This problem can be solved by simply sorting the given array and counting the number of swaps performed.

If you use selection sort for example, the solution is quite simple - just count every swap you make. But, it will most certainly fail for cases where `n` is large. This is because the time-complexity for selection sort (and many similar algorithms) are **O(n<sup>2</sup>)**. 
In order to pass all the test cases in hacker-rank, you must use a sorting algorithm with worst time complexity no-greater than  **O(n log n)**. 

So you are left with two options - Heap Sort and Merge Sort, both of which provide worst-case complexity of **O(n log n)**. But Heap Sort is **NOT STABLE**. That is, if two elements are equal, they are not guaranteed to remain in the same order or positions. This will change the number of inversions we might make because the question requires us to swap elements **only if** one is strictly greater than the other. So the only option we have left is to use Merge Sort.

But using merge-sort has a small catch. **You need to be careful to calculate the correct number of inversions *even though you may not be performaning as many inversions*.** More specifically, when you move the top of the `right_sub_array` ahead of the `left_sub_array`, you are performing one operation, but the number of inversions is `size_of(left_sub_array)`

## [Question](https://www.hackerrank.com/challenges/ctci-merge-sort/problem)

Check out the resources on the page's right side to learn more about merge sort. The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book Cracking the Coding Interview.

In an array, `arr` , the elements at indices `i` and `j` (where `i<j`) form an inversion if `arr[i] > arr [j]` . In other words, inverted elements `arr[i]`  and `arr[j]`  are considered to be "out of order". To correct an inversion, we can swap adjacent elements.

For example, consider the dataset `arr = [2,4,1]` . It has two inversions: `(4,1)` and `(2,1)` . To sort the array, we must perform the following two swaps to correct the inversions:

    swap(arr[1], arr[2]) -> swap(arr[0],arr[1)
        
Given `d` datasets, print the number of inversions that must be swapped to sort each dataset on a new line.

### Function Description

Complete the function countInversions in the editor below. It must return an integer representing the number of inversions required to sort the array.

countInversions has the following parameter(s):

* arr: an array of integers to sort .

### Input Format

The first line contains an integer, `d` , the number of datasets.

Each of the next `d`  pairs of lines is as follows:

1. The first line contains an integer, `n` , the number of elements in `arr`.
2. The second line contains `n` space-separated integers, `arr[i]`.

### Constraints

* 1 <= d <= 15
* 1 <= n <= 10<sup>5</sup>
* 1 <= arr[i] <= 10<sup>7</sup>

### Output Format

For each of the `d` datasets, return the number of inversions that must be swapped to sort the dataset.

#### Sample Input
```
2  
5  
1 1 1 2 2  
5  
2 1 3 1 2
```
#### Sample Output
```
0  
4   
```
