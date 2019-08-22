"""循环链表的实现"""
class LNode():
    """节点初始化函数"""
    def __init__(self, item, next_=None):
        self.item = item
        self.next = next_
class JosePhus():
    def __init__(self,k,n):
        self._head = LNode(None,None)
        self.n = n
        self.k = k
        self.size=0
        self._head.next = self._head
        self.jf()
    # 插入数据
    def append(self):
        p = self._head
        i=self.n
        while i>=1:
            node = LNode(i)
            node.next = p.next
            p.next = node
            self.size+=1
            i-=1
    #打印数据
    def jf(self):
        self.append()
        self.printall()
        p = self._head
        while self.size>0:
            j = 0
            while j<self.k-1:
                if p.next == self._head:
                    p = p.next.next
                else:
                    p = p.next
                j+=1
            if p.next ==self._head:
                p = p.next
            print(p.next.item)
            p.next = p.next.next
            if p.next ==self._head:
                p = p.next
            self.size-=1
    def printall(self):
        p = self._head.next
        i = 0
        while i<self.size-1:
            print(p.item,end=',')
            p = p.next
            i+=1
        print('')

if __name__ =="__main__":
    c = JosePhus(4,10)
