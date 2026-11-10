"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None:
            return None
        h = {}

        def dfs(cur):
            if cur in h:
                return h[cur]

            # haven't copy node
            copy = Node(cur.val)
            h[cur] = copy
            for n in cur.neighbors:
                copy.neighbors.append(dfs(n))
            
            return copy

        return dfs(node)

"""
Comment:
I use a DFS to traverse the graph, and use a hash table to record the node which was copied. When I traverse a node that was copied, I just return the copy reference in the hash table. After the traversal, I can get the whole copy of the graph.
Time Complexity:Ｏ(V+E)
Space Complexity:Ｏ(V)
"""
