## Discussion

### Approach 1 - Unordered Set (Hash)
For each element perform one of two operations:
* If it doesn't exist in the set, add it.
* If it exists, then delete it.

In the end, there will be only one remaining element in the set, which is the un-paired element that we need to write out.

*Worst-case Time Complexities:*

*Insert :* **O(log n)**, but, __*amortized constant*__ on average.

*Erase :* **O(log n)**

*Overall :* **O(n log n)**, 1 op per element

*Space Complexity:* **O(n)**

### Approach 2 - Bitwise XOR

**XOR Operation**

The XOR Operator `^`, also known as *Exclusive Or* works as follows:

|a|b|a^b|
|-------|
|0|0|0|
|1|0|1|
|0|1|1|
|1|1|0|

**Key Idea**

* When you XOR a number with itself, you will get 0, i.e., `num ^ num = 0`.
* When you XOR 0 with any number, the result with be the number, i.e., `num ^ 0 = num`

In our case, we are guaranteed to have n-1/2 pairs of numbers with just 1 number without a pair. So all we need to do is XOR all the numbers in a serial fashion, the final result will be the number we need. Every other number will cancel itself out :)

*Worst-case Time Complexities:*
*XOR :* **O(1)**
*Overall :* **O(n)**, 1 op per element
*Space Complexity:* **O(n)**

## [Question](Question.pdf)
<object data="Question.pdf" type="application/pdf" width="700px" height="700px">    
    <embed src="Question.pdf">
        This browser does not support PDFs. Read it <a href="Question.pdf">here</a>.</p>
    </embed>
</object>
