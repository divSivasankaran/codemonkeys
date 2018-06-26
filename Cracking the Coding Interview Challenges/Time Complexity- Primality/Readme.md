# Key Idea
A number is considered to be prime if it has no factors other than 1 and itself.

So a naive solution to check for primality of a number `n` could simply iterate through all numbers from `2` through `n-1` and check if it is a factor of `n`. If it has no divisors, then we can conclude that `n` is prime. Such a solution would have `O(n)` time-complexity.

Now, if you go back to your lessons from middle school, you will remember that any number can be written as the product of two of its factors.

`n = a * b`, where `a` and `b` are factors of `n`.
Also,
`n = \sqrt{n} * \sqrt{n}`

That means `n` can never have factors that are both greater than `\sqrt{n}`. Because, if it is, that would mean their product would be greater than `n`.

So you just need to iterate until `\sqrt{n}` :)


*Worst-case Time Complexity:* **O(\sqrt{n})**

*Space Complexity:* **O(1)**


## [Question](Question.pdf)
<object data="Question.pdf" type="application/pdf" width="700px" height="700px">    
    <embed src="Question.pdf">
        This browser does not support PDFs. Read it <a href="question.pdf">here</a>.</p>
    </embed>
</object>

Had a fun weekend building on Google Voice Assistant to make online ordering easier with Elayabharath Elango Vanchinathan Venkataramani Nagappan Nachiappan! #runnersup #googleassistant #smartlivinghack
