class Node:
    def __init__(self, key=0, value=0):
        self.key = key
        self.value = value
        self.next = None
        self.pre = None

class LRUCache:

    def __init__(self, capacity: int):
        self.cnt = 0
        self.capacity = capacity
        self.h = {}
        self.head, self.tail = Node(), Node()
        self.head.next = self.tail
        self.tail.pre = self.head

    def addToHead(self, node: Node):
        nextNode = self.head.next
        self.head.next = node
        node.next = nextNode
        node.pre = self.head
        nextNode.pre = node

    def cutNode(self, node: Node):
        nextNode = node.next
        preNode = node.pre
        nextNode.pre = preNode
        preNode.next = nextNode

    def get(self, key: int) -> int:
        cur = self.h.get(key)
        
        # node doesn't exist
        if cur is None:
            return -1
        
        # node already exist
        else:
            self.cutNode(cur)
            self.addToHead(cur)
            return cur.value
        


    def put(self, key: int, value: int) -> None:
        cur = self.h.get(key)
        
        # new node
        if cur is None:
            node = Node(key,value)
            self.addToHead(node)
            self.h[key] = node
            self.cnt += 1
            if self.cnt > self.capacity:
                oldestNode = self.tail.pre
                self.cutNode(oldestNode)
                self.h.pop(oldestNode.key)
                self.cnt -= 1
        
        # node already exist
        else:
            cur.value = value
            self.cutNode(cur)
            self.addToHead(cur)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

"""
Comment:
Because I need to get the value in Ｏ(1), I should use hash table. Because I need to move the element from middle position to the front side in Ｏ(1), I should use a doubly linked list. To combine these two data structure, I create a Node class to store the next pointer and pre pointer and the key/value. Then, I allow the value of hash table be the reference of the Node. Then, I build the addToHead method and cutNode method. Then, use these two method and complete the get() and put().
Time Complexity:Ｏ(1), get, put : Ｏ(1)
Space Complexity:Ｏ(capacity)
"""
