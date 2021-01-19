### Points to Remember

- A nice way to understand a tree is with a recursive explanation.
- Tree and Graph questions may have ambiguous details in interviews, you may end up making incorrect assumptions. Seek clarification from your interviewer when required.

##### Terms
- _Descendant_: All the nodes that can be reached by following a path of child nodes from a particular node are descendants of that node.
- _Ancestor_: An ancestor of a node is any other node that can reach it by following a series of children.
- _Height_: The number of edges in a path from the farthest leaf node to the root node.
- _Diameter_: The number of nodes on the longest path between two leaves in the tree.

##### Types of Binary Trees
- A _Balanced Binary Tree_ does not mean the left and right subtrees are exactly the same size (i.e. not a _Perfectly Balanced Tree_). It means it is balanced to ensure **O(log n)** time for _insert_ and _find_.
- In a _Height Balanced Binary Tree_, the difference between the heights of the left and right subtrees in not more than one. 
- Two common types of balanced trees are _AVL Trees_ and _Red Black Trees_.
- _Complete Binary Tree_: A binary tree in which every level of the tree is fully filled, except possibly the last level, which is filled left to right.
- _Full Binary Tree_: Every node has either zero or two children. No nodes have only one child.
- _Perfect Binary Tree_: A tree which is both _full_ and _complete_. All leaf nodes will be at the same level.

##### Binary Tree Traversal
- In-Order Traversal
    - Left - Node - Right
    - Inorder traversal visits nodes in ascending order in a _Binary Search Tree_.
 - Pre-Order Traversal
    - Node - Left - Right
    - Root is always the first node to be visited.
  - Post-Order Traversal
    - Left - Right - Node
    - Root is always the last node to be visited.
