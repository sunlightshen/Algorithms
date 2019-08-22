"""变形链表的实现（为链表加入头结点和尾结点）"""
class LNode():
    """节点初始化函数"""
    def __init__(self, item, prev = None,next_=None):
        self.item = item
        self.next = next_
        self.prev = prev
class RList():
    def __init__(self):
        self._head = LNode(None,None,None)
        self._rear = LNode(None,None,None)
        self._head.next = self._rear
        self._rear.prev = self._head
        self.size = 0
    """操作函数实现"""

    """插入操作"""
    # 头部插入
    def preappend(self,elem):
        node = LNode(elem)
        node.next=self._head.next
        self._head.next.prev = node
        self._head.next = node
        node.prev = self._head
        self.size+=1
    # 尾部插入
    def append(self,elem):
        node = LNode(elem)
        node.prev = self._rear.prev
        node.next = self._rear
        self._rear.prev.next = node
        self._rear.prev = node
        self.size+=1
    # 任意位置插入元素
    def insert(self,i,elem):
        if i<0 or i>self.size:
            print("error")
        else:
            node = LNode(elem)
            p = self._head
            while i>0:
                p = p.next
                i-=1
            node.next=p.next
            p.next.prev = node
            p.next = node
            node.prev = p
            self.size+=1
    """删除操作"""
    # 尾部删除操作
    def pop_last(self):
        self._rear.prev.prev.next = self._rear
        self._rear.prev = self._rear.prev.prev
        self.size-=1
    # 头部删除操作
    def pop_head(self):
        self._head.next.next.prev = self._head
        self._head.next = self._head.next.next
        self.size-=1
    # 删除任意未位置元素
    def pop(self,i):
        if i<0 or i>self.size:
            print("error!")
        else:
            p = self._head.next
            # 确定删除节点的位置
            while i>0:
                p = p.next
                i-=1
            p.next.prev = p.prev
            p.prev.next = p.next
            self.size-=1
    """遍历操作"""

    # 正序输出
    def printall(self):
        p = self._head.next
        while p is not None and p!=self._rear:
            print(p.item)
            p = p.next
    # 倒序输出
    def printback(self):
        p = self._rear.prev
        while p is not None and p!=self._head:
            print(p.item)
            p = p.prev
    # 元素的汇集
    def for_each(self,proc):
        pCurrent = self._head.next
        while pCurrent is not None and pCurrent is not self._rear:
            proc(pCurrent.item)
            pCurrent = pCurrent.next
    # 定义生成器函数
    def elements(self):
        pCurrent = self._head.next
        while pCurrent is not None and pCurrent is not self._rear:
            yield pCurrent.item
            pCurrent = pCurrent.next

if __name__ =="__main__":
    l = RList()
    l.preappend(1)
    l.preappend(2)
    l.preappend(3)
    l.preappend(4)
    l.append(0)
    l.insert(0,5)
    l.pop(0)
    l.printall()
    print("#####")
    l.printback()
    print("-----")
    print("长度：%d"%(l.size))
    print("8888888888")
    for x in l.elements():
        print(x)
