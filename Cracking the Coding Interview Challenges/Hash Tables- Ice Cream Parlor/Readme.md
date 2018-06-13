## Discussion

*Worst-case Time Complexity:* **O(n logn)**

*Space Complexity:* **O(n)**

### Key Idea

Store each ice-cream flavor (index) with its cost in a multimap with the cost as the key. We use a multimap to allow multiple flavors with the same cost as the key. One we do this, we can then sort our cost array and search for pairs of numbers (current flavor cost, remaining money) in the map. 

## [Question](Question.pdf)
<object data="Question.pdf" type="application/pdf" width="700px" height="700px">    
    <embed src="Question.pdf">
        This browser does not support PDFs. Read it <a href="Question.pdf">here</a>.</p>
    </embed>
</object>
