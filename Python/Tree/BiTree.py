"""利用链表（对象）现二叉树"""
from queue import Queue
from stack import Stack


class BiTreeNode():
    def __init__(self,data,left = None,right = None):
        self.data = data
        self.left = left
        self.right = right
class BinTree():
    def __inti__(self):
        self._root = None
    def is_empty(self):
        return self._root is None
    def leftchild(self):
        return self._root.left
    def rightchild(self):
        return self._root.right
    def root(self):
        return self._root
    def set_root(self,node):
        self._root = BiTreeNode(node)
    def set_left(self,leftchild):
        self._root.left = leftchild
    def set_right(self,rightchild):
        self._root.right = rightchild
"""创建二叉树"""
t = BiTreeNode(1,BiTreeNode(2,BiTreeNode(4),BiTreeNode(5)),
               BiTreeNode(3,BiTreeNode(6),BiTreeNode(7)))

"""计算节点个数"""
def count_node(t):
    if t is None:
        return 0
    else:
        return 1+count_node(t.left)+count_node(t.right)

"""计算所有节点的数据和"""
def sum_node(t):
    if t is None:
        return 0
    else:
        return t.data+sum_node(t.left)+sum_node(t.right)

"""二叉树的优先遍历深度遍历"""
# 先根遍历
def preorder(t):
    if t is None:
        pass
    else:
        print(t.data)
        preorder(t.left)
        preorder(t.right)
# 中序遍历
def midorder(t):
    if t is None:
        pass
    else:
        midorder(t.left)
        print(t.data)
        midorder(t.right)
# 后序遍历
def postorder(t):
    if t is None:
        pass
    else:
        postorder(t.left)
        postorder(t.right)
        print(t.data)
"""二叉树的宽度优先遍历"""
def wide_order(t):

    """利用队列实现二叉树的宽度优先遍历"""
    q = Queue()
    q.enqueue(t)
    while not q.is_empty():
        n = q.dequeue()
        if n is None:
            break
        q.enqueue(n.left)
        q.enqueue(n.right)
        print(n.data)

"""二叉树的非递归遍历"""
# 非递归先根遍历
def preorder_nonrec(t):
    s = Stack()
    while t is not None or not s.is_empty():
        while t is not None:
            print(t.data)
            s.push(t.right)
            t = t.left
        t = s.pop()
# 非递归后根遍历
def postorder_nonrec(t):
    s = Stack()
    while t is not None or not s.is_empty():
        while t is not None:
            s.push(t)
            t = t.left if t.left is not None else t.right
        t = s.pop()
        print(t.data)
        if not s.is_empty() and s.top().left == t:
            t = s.top().right
        else:
            t = None
# 非递中根遍历
def midorder_nonrec(t):
    s = Stack()
    while t is not None or not s.is_empty():
        while t is not None:
            s.push(t)
            t = t.left
        if not s.is_empty():
            t = s.pop()
            print(t.data)
            t = t.right


# 设置非递归先序遍历生成器
def preorder_elements(t):
    s = Stack()
    while t is not None or not s.is_empty():
        while t is not None:
            yield t.data
            s.push(t.right)
            t = t.left
        t = s.pop()
if __name__ =="__main__":
    midorder_nonrec(t)
    print("----")
    midorder(t)

