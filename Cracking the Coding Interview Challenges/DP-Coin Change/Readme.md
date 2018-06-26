## Discussion

**Key Idea**

This is similar to the previous problem on Davis Staircase. The only difference being, in the problem with the staircases, we cared about the order in which davis climbed the stairs... i.e., permutations. In this case however, we do not care about the order in which we pick the change... i.e., we need combinations not permutations. The only difference in this approach is to keep in mind the number of ways that will overlap and not double-count them.

For example:
We can split 4 as - 1, 1, 2, 1 and 1, 1, 1, 2. In this problem, both these ways are to be counted only once.

So we just have to take-care of repetitions by fixing and counting one type & discarding all others. This can be done by imposing a simple rule as follows:
**All ways we add to our list will ordered in increasing order. Which means only the first way represented for 4 above will be acceptable, the other one to be discarded.**

Here's the algorithm's pseudo-code:


**Recursion**

Given some number `n`, and a list of `coins` we can break it down as follows:
* Decide the first pick for change by iterating through the list of `coins`
  * Once we have picked the coin at `coins[i]`, the problem is now to find out how many ways we can change `n-coins[i]` in. (This is the recursive step)
  * To enquire about the number of ways to change for `n-coins[i]`, we remove all the coins that are less than `coins[i]` and pass this instead as `coins`.
* Keep track of the number of combinations for each recursive step & sum them up.

**Dynamic Programming**
We also store the mapping of `n` to the possible combinations in a map every time we calculate it. But we do so for each set of coins, which is identified by the smallest denomination in the list of coins.
For example: If we have 4 coins - 1, 2, 5, 10.. in our iterations we will use these variations of the array coins:
* 1, 2, 5, 10
* 2, 5, 10
* 5, 10
* 10

So we will hold a map for each of these variations and refer to it by using the smallest denomination in each variation.

**m** - number of coins

**n** - value to find #ways to change

*Worst-case Time Complexity:* **O(mn)**

*Space Complexity:* **O(mn)**

## [Question](Question.pdf)
<object data="Question.pdf" type="application/pdf" width="700px" height="700px">    
    <embed src="Question.pdf">
        This browser does not support PDFs. Read it <a href="question.pdf">here</a>.</p>
    </embed>
</object>
