"""双向链表的实现"""

class LNode():
    """节点初始化函数"""
    def __init__(self, item, prev = None,next_=None):
        self.item = item
        self.next = next_
        self.prev = prev
class DList():
    def __init__(self):
        self._head = LNode(None,None,None)
        self.size = 0

    """定义操操作函数"""

    """插入操作"""
    # 前端插入
    def preappend(self,elem):
        node = LNode(elem)
        node.next = self._head.next
        node.prev = self._head
        self._head.next = node
        self.size+=1
    # 尾部插入
    def append(self,elem):
        node = LNode(elem)
        i=0
        pCurrent = self._head
        while i<self.size:
            pCurrent = pCurrent.next
            i+=1
        node.next = pCurrent.next
        node.prev = pCurrent
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
            node.prev = pCurrent
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
        pCurrent.next = None
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
            pCurrent.next.prev = pCurrent
            pCurrent.next = pCurrent.next.next
            self.size-=1
            return e


    """遍历操作"""
    def printall(self):
        pCurrent = self._head.next
        while pCurrent is not None:
            print(pCurrent.item)
            pCurrent = pCurrent.next

    # 迭代器
    def element(self):
        pCurrent = self._head.next
        while pCurrent is not None:
            yield  pCurrent.item
            pCurrent = pCurrent.next
    def for_each(self,proc):
        pCurrent = self._head.next
        while pCurrent is not None:
            proc(pCurrent.item)
            pCurrent = pCurrent.next


if __name__ == "__main__":
    clist = DList()
    clist.preappend(1)
    clist.preappend(2)
    clist.preappend(3)
    clist.append(0)
    clist.insert(3,4)
    e = clist.pop(4)
    clist.printall()
    print("-----")
    print("删除元素：%d" %(e))
    print("*****")
    for x in clist.element():
        print(x)
    print("$$$$$")
    clist.for_each(print)
