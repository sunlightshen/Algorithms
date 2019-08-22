"""单向链表的实现"""
class LNode():
    """节点初始化函数"""
    def __init__(self,item,next_=None):
        self.item=item
        self.next=next_
class LList():
    def __init__(self):
        # 定义为私有属性，外部无法访问
        self._head=LNode(None,None)
        self.size=0
    """插入方法实现"""
    def is_empty(self):
        return self._head.next is None
    # 头部插入元素
    def preappend(self,elem):
        node = LNode(elem)
        node.next = self._head.next
        self._head.next=node
        self.size+=1
    # 尾部插入数据
    def append(self,elem):
        pCurrent=self._head
        while pCurrent.next is not None:
            pCurrent=pCurrent.next
        node = LNode(elem)
        node.next = pCurrent.next
        pCurrent.next = node
        self.size+=1
    # 在任意位置插入元素
    def insert(self,i,elem):
        if i<=0:
            self.preappend(elem)
        elif i>=self.size:
            self.append(elem)
        else:
            pCurrent = self._head
            while pCurrent is not None and i>0:
                pCurrent=pCurrent.next
                i-=1
            node = LNode(elem)
            node.next = pCurrent.next
            pCurrent.next = node
        self.size+=1

    def printall(self):
        pCurrent = self._head.next
        while pCurrent is not None:
            print(pCurrent.item)
            pCurrent = pCurrent.next
    # 元素的汇集
    def for_each(self,proc):
        pCurrent = self._head.next
        while pCurrent is not None:
            proc(pCurrent.item)
            pCurrent = pCurrent.next
    # 定义生成器函数
    def elements(self):
        pCurrent = self._head.next
        while pCurrent is not None:
            yield pCurrent.item
            pCurrent = pCurrent.next
    # 筛选生成器
    def filter(self,proc):
        pCurrent = self._head
        while pCurrent is not None:
            if proc(pCurrent.item):
                yield pCurrent.item
            pCurrent = pCurrent.next
    """删除方法实现"""
    # 尾部删除
    def pop(self):
        pCurrent = self._head
        while pCurrent.next.next is not None:
            pCurrent = pCurrent.next
        e = pCurrent.next.item
        # 释放内存
        del pCurrent.next.next
        pCurrent.next =None
        self.size-=1
        return e
    # 删除任意位置元素
    def remove(self,i):
        if i<0 or i>=self.size:
            print("删除位置无效！！！")
        else:
            pCurrent = self._head
            while i>0:
                pCurrent = pCurrent.next
                i-=1
            cur = pCurrent.next
            pCurrent.next = cur.next
        self.size-=1
    # 根据元素值删除(删除所有遇见的值)
    def removeByvalue(self,elem):
        pCurrent = self._head
        while pCurrent.next is not None:
            if pCurrent.next.item==elem:
                pCurrent.next = pCurrent.next.next
                self.size-=1
                continue
            pCurrent = pCurrent.next
    # 根据元素值删除(删除所有遇见的第一个)
    def removeFirstValue(self,elem):
        pCurrent = self._head
        while pCurrent.next is not None:
            if pCurrent.next.item==elem:
                pCurrent.next = pCurrent.next.next
                self.size-=1
                break
            pCurrent = pCurrent.next
if __name__ == "__main__":
    lst = LList()
    lst.preappend(1)
    lst.preappend(2)
    lst.preappend(3)
    lst.preappend(4)
    lst.append(1)
    lst.append(2)
    lst.append(3)
    lst.append(4)
    lst.insert(1,18)
    lst.remove(0)
    s = lst.pop()
    l = lst.pop()
    lst.removeFirstValue(2)
    lst.for_each(print)
    print("链表的长度为%d" %(lst.size))
    print("弹出的值为%d,%d"%(s,l))
    print("运行结束！")
    # 调用生成器函数
    for x in lst.elements():
        print(x)
    def compare(a):
        if a==1:
            return True
        else:
            return False
    print("-----------")
    for x in lst.filter(compare):
        print(x)
