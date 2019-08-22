"""基于列表的栈的定义与实现"""

class Stack():
    def __init__(self):
        self._item = []
    # 入栈
    def push(self,elem):
        self._item.append(elem)
    # 出战
    def pop(self):
        self._item.pop()
    # 返回栈顶元素
    def top(self):
        return self._item[-1]
    # 判断栈是否为空
    def is_empty(self):
        return self._item == []
    # 返回栈的长度
    def size(self):
        return len(self._item)

if __name__ == "__main__":
    stack = Stack()
    if stack.is_empty():
        print("空栈！")
    stack.push(1)
    stack.push(2)
    stack.push(3)
    while not stack.is_empty():
        print(stack.top())
        stack.pop()