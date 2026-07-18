class Node:
    def __init__(self,key: int,value: int):
        self.key = key
        self.val = value
        self.next = None
        self.prev = None

class LRUCache:

    def __init__(self, capacity: int):
        self.l = {}
        self.cap = capacity
        self.head = None
        self.tail = None

    def remove(self, key:int):
        t = self.l[key]
        next,prev= t.next,t.prev
        if next:
            next.prev = prev
        if prev:
            prev.next = next
        t.next,t.prev = None,None
        self.l.pop(key)
        if self.head == t:
            self.head = next
        if self.tail == t:
            self.tail = prev
        return t


    def get(self, key: int) -> int:
        if key not in self.l:
            return -1
        ans = self.l[key].val

        self.put(key,ans)

        return ans

    def put(self, key: int, value: int) -> None:
        n = None
        skip = False 
        if key in self.l:
            if self.head == self.l[key]:
                skip = True
            n = self.remove(key)
            n.val = value
        else:
            n = Node(key,value)

        if len(self.l) >= self.cap and not skip:
            k = self.head.next
            self.remove(self.head.key)
            self.head = k
            
        n.prev = self.tail
        if self.tail:
            self.tail.next = n
        self.tail = n

        if not self.head:
            self.head = n

        self.l[key] = n

        
            



        
