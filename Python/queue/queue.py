"""队列的实现"""
class Queue():
    def __init__(self):
        self._item = []
    # 入队
    def enqueue(self,elem):
        self._item.insert(0,elem)
    # 出队
    def dequeue(self):
        self._item.pop()
    # 返回队头元素
    def head(self):
        return self._item[-1]
    def rear(self):
        return self._item[0]
    # 返回队列长度
    def size(self):
        return len(self._item)
    def is_empty(self):
        return self._item == []
    def printall(self):
        print(self._item)

if __name__ == "__main__":
    q = Queue()
    if q.is_empty():
        print("空队列！")
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    while not q.is_empty():
        print(q.head())
        q.dequeue()