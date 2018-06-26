## Discussion

### Key Idea

We use recursion and dynamic programming to solve this problem.

**Recursion**

Given some number `n`, we can break it down as follows:
* Decide the first step-count taken by Davis:
  * This could be `i` = 1, 2 or 3. (Iterate through each of these options)
* Once he's taken one step with step-count `i`, the problem is now to find out how many ways he can climb `n-i`. (This is the recursive step)
* Keep track of the number of permutations for each recursive step

**Dynamic Programming**

We also store the mapping of `n` to the possible permutations in a map every time we calculate it, so that we don't re-do the same calculations.



*Worst-case Time Complexity:* **O(n)**

*Space Complexity:* **O(n)** - to store the hash map

## [Question](Question.pdf)
<object data="Question.pdf" type="application/pdf" width="700px" height="700px">    
    <embed src="Question.pdf">
        This browser does not support PDFs. Read it <a href="question.pdf">here</a>.</p>
    </embed>
</object>
