from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        size = len(tokens)
        if size == 1:
            return int(tokens[0])
        
        # Number: save number
        number = []
        result = 0

        for i in range(size):
            if tokens[i] not in "+-*/":
                number.append(int(tokens[i]))
            else:
                num1 = number.pop()
                num2 = number.pop()

                result = self.calculate(num1, num2, tokens[i])
                number.append(result)

        return result

    def calculate(self, num1: int, num2: int, notation: str) -> int:
        if notation == "+":
            return num1 + num2
        if notation == "-":
            return num2 - num1
        if notation == "*":
            return num1 * num2
        if notation == "/":
            return int(num2 / num1)  # Use int() to truncate towards zero
        return 0