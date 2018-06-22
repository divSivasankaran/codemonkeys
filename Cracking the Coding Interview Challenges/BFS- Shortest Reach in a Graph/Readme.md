
# Key Idea
A classic Breadth-First-Search algorithm can be used to find all the distances in the given graph.

**Breadth First Search**

This is one common approach to traverse a graph/tree.

Starting with the root node, repeat until no more nodes left in the list of `to_process` nodes.
* Process the current node & add it to the list of `processed` nodes.
* Add all of its neighbors to the list of `to_process` nodes.
* update the distances to all it's neighbors by adding the edge weights to the current node's distance from source
* process all the neighbors

By doing this, we explore one level at a time going deeper in each iteration until you reach the leaves. Hence, the name - breadth-first.

**V:** Number of Vertices/Nodes in the grid
**E:** Number of edges in the grid

*Worst-case Time Complexity:* **O(V+E)**

*Space Complexity:* **O(V)**


## [Question](Question.pdf)
<object data="Question.pdf" type="application/pdf" width="700px" height="700px">    
    <embed src="Question.pdf">
        This browser does not support PDFs. Read it <a href="question.pdf">here</a>.</p>
    </embed>
</object>
