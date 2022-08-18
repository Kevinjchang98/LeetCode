class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        nums = []
        
        for item in tokens:
            if item.isnumeric():
                nums.append(int(item))
            elif item[0] == "-" and len(item) > 1:
                nums.append(int(item))
            else:
                match item:
                    case "+":
                        nums.append(nums.pop() + nums.pop())
                    case "-":
                        num1 = nums.pop()
                        num2 = nums.pop()
                        nums.append(num2 - num1)
                    case "/":
                        num1 = nums.pop()
                        num2 = nums.pop()
                        nums.append(int(num2 / num1))
                    case "*":
                        nums.append(nums.pop() * nums.pop())

        return nums.pop()