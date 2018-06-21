## Discussion

# Key Idea
A classic Depth-First-Search algorithm can be used to find the region with maximum nodes.

**Depth First Search**

This is one common approach to traverse a graph/tree.

Starting with the root node, repeat until no more nodes left in the list of `to_process` nodes.
* Process the current node & add it to the list of `processed` nodes.
* Add all of its neighbors to the list of `to_process` nodes.
* pick one of the neighbors from `to_process` to be the current node.

By doing this, we explore one branch at a time before re-tracking to explore the other branches. Hence, the name - depth-first.

**Algorithm**

To use DFS to solve this problem, we have two operations:

Process all the nodes in the grid until none is left.

For each node:
* __*Explore:*__ If the current node has value 0 it is not part of a region, just continue to the next node.

* __*ExploreRegion:*__ If the current node is 1, then it belongs to a region, use DFS to explore this region (i.e., until there are no neighbours left with value 1) & keep track of the number of nodes in the region found.

Return the size of the maximum region.
**V:** Number of Vertices/Nodes in the grid
**E:** Number of edges in the grid

For our case with **n** rows and **m** columns:

`V=nm`

ToDo: `E=` *god damn. This is hard.*

*Worst-case Time Complexity:* **O(V+E)**

*Space Complexity:* **O(V)**

## [Question](Question.pdf)
<object data="Question.pdf" type="application/pdf" width="700px" height="700px">    
    <embed src="Question.pdf">
        This browser does not support PDFs. Read it <a href="Question.pdf">here</a>.</p>
    </embed>
</object>
