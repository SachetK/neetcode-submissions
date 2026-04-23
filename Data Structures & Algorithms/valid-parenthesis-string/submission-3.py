class Solution:
    def checkValidString(self, s: str) -> bool:
        star_stack = []
        stack = []

        for i, c in enumerate(s):
            if c == '(':
                stack.append(i)
                continue
            
            if c == '*':
                star_stack.append(i)
                continue
            
            if len(stack) == 0:
                if len(star_stack) == 0:
                    return False
                
                star_stack.pop()
            else:
                stack.pop()
        
        while len(stack) > 0:
            if len(star_stack) == 0:
                return False
            
            if stack.pop() > star_stack.pop():
                return False

        return True

            
