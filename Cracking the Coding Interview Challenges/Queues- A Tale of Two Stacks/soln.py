# Queue as 2 stacks:
    # old to new stack : contains items as they come in
    # new to old stack : contains items in reverse order
class MyQueue(object):
    def __init__(self):
        self.old_new = []
        self.new_old = []

    # For dequeueing, need to pop iteratively from old_new and append to new_old
    # if new_old is not empty, top of new_old is the oldest item - so directly read or pop that value
    # if new_old is empty, pop and append
    def peek(self):
        if not self.new_old:
            while self.old_new:
                self.new_old.append(self.old_new.pop())
        value = self.new_old.pop()
        self.new_old.append(value)
        return value

    def pop(self):
        if not self.new_old:
            while self.old_new:
                self.new_old.append(self.old_new.pop())
        value = self.new_old.pop()
        return value

    def put(self, value):
        # add to old_new stack
        self.old_new.append(value)

queue = MyQueue()
t = int(input())
for line in range(t):
    values = map(int, input().split())
    values = list(values)
    if values[0] == 1:
        queue.put(values[1])
    elif values[0] == 2:
        queue.pop()
    else:
        print(queue.peek())
