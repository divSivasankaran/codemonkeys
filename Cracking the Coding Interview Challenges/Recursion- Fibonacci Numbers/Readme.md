## Discussion

*Worst-case Time Complexity:* **O(n)**
*Space Complexity:* **O(1)**

### Key Idea
This is a classic problem that is often used to introduce the idea of recursion. Fibonacci series is pretty easy and straight-forward to be transformed into a recursive solution.

Consider the formula for `fibonacci(n)` where n>=2:

`fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)`

 Given any number, we can continue calling the `fibonacci(n-1)` & `fibonacci(n-2)`, but we must stop at some point for this function to not regress into an infinite loop. Where do we stop? This is where the base cases come in handy.

```
fibonacci(0)=0
fibonacci(1)=1
```
So all we have to do is continue calling `fibonacci` of `n-1` & `n-2`'s until we reach `n=0`or `n=1` while summing all the results we accummulate along the way :) 

## [Question](Question.pdf)


<object data="Question.pdf" type="application/pdf" width="700px" height="700px">    
    <embed src="Question.pdf">
        This browser does not support PDFs. Read it <a href="Question.pdf">here</a>.</p>
    </embed>
</object>
