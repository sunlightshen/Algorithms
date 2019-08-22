"""实现霍夫曼树和霍夫曼编码"""
from PrioQueue import PriQue
from BiTree import BiTreeNode
import BiTree as tb
class HuffmanTree():
    def __init__(self,weights):
        self.weights = weights
        self.HuffQueue = PriQue()
        self.tree = None
        # 本节为改造后的优先级队列，在这里引入了规则函数
        for x in weights:
            self.HuffQueue.enqueue(BiTreeNode(x),self.proc)
    def printall(self):
        self.HuffQueue.printall(self.printnode)
    # 定义比较函数，实际上是对节点上的数据进行比较
    def proc(self,a, b):
        return a.data > b.data
    def printnode(self,a):
        print(a.data)
    def huffman(self):
        # 保证最后弹出的树为对应的Huffman树
        while self.HuffQueue.size()>1:
            x1 = self.HuffQueue.dequeue()
            x2 = self.HuffQueue.dequeue()
            t = x1.data + x2.data
            self.HuffQueue.enqueue(BiTreeNode(t,x1,x2),self.proc)
        return self.HuffQueue.dequeue()
if __name__ == "__main__":
    # 设置权重矩阵
    wgh = [7,5,2,4]
    ht = HuffmanTree(wgh)
    t = ht.huffman()
    tb.preorder(t)


