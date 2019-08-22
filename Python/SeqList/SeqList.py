"""顺序表的实现"""
class LList():
    def __init__(self):
        self.item = []
        self.lenght=0
    # 插入数组
    def linsert(self,location,data):
        self.item.insert(location,data)
        self.lenght+=1
    # 删除数据
    def ldelete(self,value):
        self.item.remove(value)
        self.lenght-=1
    # 根据位置删除数据
    def deleteByloc(self,location):
        self.item.__delitem__(location)
        self.lenght-=1
    # 打印顺序表数据
    def lprint(self):
        print(self.item)
    # 判空操作
    def is_empty(self):
        return self.lenght==0
if __name__ =="__main__":
    ls = LList()
    flag = ls.is_empty()
    if flag:
        print("空列表")
    else:
        print("正常")
    ls.linsert(0, 1)
    ls.linsert(0, 2)
    ls.linsert(0, 3)
    ls.linsert(0, 4)
    ls.lprint()
    print(ls.lenght)
    ls.ldelete(2)
    ls.lprint()
    print(ls.lenght)
    ls.deleteByloc(0)
    ls.lprint()
    print(ls.lenght)
    flag = ls.is_empty()
    if flag:
        print("空列表")
    else:
        print("正常")



