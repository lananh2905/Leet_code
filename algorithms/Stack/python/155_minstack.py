from typing import List

class MinStack:

    def __init__(self):
        self.stack: List[int] = []
        self.min_stack: List[int] = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if(self.min_stack == [] or val <= self.min_stack[-1]):
            self.min_stack.append(val)
        

    def pop(self) -> None:
        
        if(self.min_stack[-1] == self.stack[-1]):
            self.min_stack.pop()
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]