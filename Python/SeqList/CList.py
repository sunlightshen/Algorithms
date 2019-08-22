"""循环链表的实现"""
class LNode():
    """节点初始化函数"""
    def __init__(self, item, next_=None):
        self.item = item
        self.next = next_
class CList():
    def __init__(self):
        self._head = LNode(None,None)
        self.size = 0
        self._head.next = self._head

    """定义操操作函数"""

    """插入操作"""
    # 前端插入
    def is_empty(self):
        return self._head.next is None
    def preappend(self,elem):
        node = LNode(elem,self._head)
        node.next = self._head.next
        self._head.next = node
        self.size+=1
    # 尾部插入
    def append(self,elem):
        node = LNode(elem)
        i=0
        pCurrent = self._head.next
        while i<self.size-1:
            pCurrent = pCurrent.next
            i+=1
        node.next = pCurrent.next
        pCurrent.next = node
        self.size+=1
    # 任意位置插入元素
    def insert(self,i,elem):
        if i<0 or i>self.size:
            print("error!")
        else:
            node = LNode(elem)
            pCurrent = self._head
            while i>0:
                pCurrent = pCurrent.next
                i-=1
            node.next = pCurrent.next
            pCurrent.next = node
        self.size+=1
    """删除操作"""
    # 尾部删除
    def pop_last(self):
        i=0
        pCurrent = self._head
        while i<self.size-1:
            pCurrent = pCurrent.next
            i+=1
        e = pCurrent.next.item
        pCurrent.next = pCurrent.next.next
        self.size-=1
        return e
    # 删除任意位置元素
    def pop(self,i):
        if i<0 or i>self.size-1:
            print("error!!")
            return 0
        else:
            pCurrent = self._head
            while i>0:
                pCurrent = pCurrent.next
                i-=1
            e = pCurrent.next.item
            pCurrent.next = pCurrent.next.next
            self.size-=1
            return e


    """遍历操作"""
    def printall(self):
        pCurrent = self._head.next
        i=0
        while i < self.size:
            print(pCurrent.item)
            if pCurrent.next==self._head:
                pCurrent = pCurrent.next.next
            else:
                pCurrent = pCurrent.next
            i+=1
    # 迭代器
    def element(self):
        pCurrent = self._head.next
        i=0
        while i<self.size:
            yield  pCurrent.item
            pCurrent = pCurrent.next
            i+=1
    def for_each(self,proc):
        pCurrent = self._head.next
        i=0
        while i<self.size:
            proc(pCurrent.item)
            pCurrent = pCurrent.next
            i+=1

if __name__ == "__main__":
    clist = CList()
    clist.preappend(1)
    clist.preappend(2)
    clist.preappend(3)
    clist.append(0)
    print("+++++++")
    clist.printall()
    print("------")
    for x in clist.element():
        print(x)
    print("********")
    clist.for_each(print)