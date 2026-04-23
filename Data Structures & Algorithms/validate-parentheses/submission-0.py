class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        
        for c in s:
            if c == '(' or c == '[' or c == '{':
                stack.append(c)
                continue
            
            if len(stack) == 0:
                return False
            
            char = stack.pop()

            if c == ')' and char != '(': return False
            if c == ']' and char != '[': return False
            if c == '}' and char != '{': return False

        return len(stack) == 0