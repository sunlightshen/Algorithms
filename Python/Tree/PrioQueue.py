"""list 实现优先级队列"""
class PriQue():
    def __init__(self,lst = []):
        self._item = list(lst)
        self._item.sort(reverse = True)
    # 对优先级队列进行插入操作
    def enqueue(self,elem,proc):
        i = len(self._item)-1
        while i>=0:
            if proc(elem ,self._item[i]):
                i-=1
            else:
                break
        self._item.insert(i+1,elem)
    # 出队列操作（优先级低先出队列）
    def dequeue(self):
        if self.is_empty():
            print("error! 空队列!")
        else:
            e = self._item.pop()
            return e
    # 返回对头元素(返回优先级最低的元素)
    def peek(self):
        if self.is_empty():
            print("error,空队列！")
        else:
            return self._item[-1]
    def size(self):
        return len(self._item)
    # 队列判空
    def is_empty(self):
        return self._item == []
    def printall(self,proc):
        for x in self._item:
            proc(x)

"""利用堆实现优先级队列"""
class PrioQueue():
    """
        Implementing prprity queue using heaps
    """
    def __init__(self,elist = []):
        self._item = list(elist)
        if self._item:
            self.buildheap()
    def is_empty(self):
        return self._item == []
    def printall(self):
        print(self._item)
    def size(self):
        return len(self._item)
    def peek(self):
        if self.is_empty():
            print("error 空堆！")
        else:
            return self._item[0]
    # 入堆操作
    def enqueue(self,e):
        self._item.append(None)
        self.shiftup(e,len(self._item)-1)
    def shiftup(self,e,last):
        elem ,i ,j = self._item,last,(last-1)//2
        while i>0 and e <elem[j]:
            elem[i] = elem[j]
            i,j = j,(j-1)//2
        elem[i]=e
    # 出堆操作
    def dequeue(self):
        # 每次将堆头元素弹出
        if self.is_empty():
            print("error 空堆！")
        elem = self._item
        e0 = elem[0]
        # 将最后一个元素弹出，插入第一个位置
        e = elem.pop()
        if len(elem)>0:
            self.shiftdown(e,0,len(elem))
        # 将优先级最高的元素返回到树的根节点
        return e0
    # 设置上移函数
    def shiftdown(self,e,begin,end):
        elems,i,j = self._item,begin,2*begin+1
        while j<end:
            if j+1<end and elems[j+1]<elems[j]:
                j+=1
            if e<elems[j]:
                break
            elems[i]=elems[j]
            i,j = j,2*j+1
        elems[i] = e
    # 堆初始化(创建堆)
    def buildheap(self):
        end = len(self._item)

        # 从第二层依次向下进行筛选
        for i in range(end//2,-1,-1):
            self.shiftdown(self._item[i],i,end)

    """实现堆排序（小顶堆）"""
    def heap_sort(self):
        l = PrioQueue(self._item)
        s = []
        while l.size():
        # for i in range(l.size()):
            s.append(l.dequeue())
        return s



if __name__ == "__main__":
    def proc(a,b):
        return a>b
    lst = [9,3,6,7,2,4,7]
    l = PriQue(lst)
    l.printall(print)
    print("---")
    l.enqueue(10,proc)
    l.printall(print)
    ls = PrioQueue(lst)
    # 堆排序实现
    s = ls.heap_sort()
    print("----")
    print(s)






