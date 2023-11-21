def find_character(s1, n, pos):
    lengths = [len(s1)]
    total_length = lengths[0]
    
    # Calculate the lengths of the strings in the sequence without actually generating them
    while total_length < pos and len(lengths) < n:
        lengths.append(lengths[-1] - 1)
        total_length += lengths[-1]
    
    # Find which string si the position belongs to and the offset within that string
    while pos <= total_length - lengths[-1]:
        total_length -= lengths[-1]
        lengths.pop()
    
    offset = pos - total_length
    
    # Find the character in si at the given offset
    stack = []
    for char in s1:
        while stack and stack[-1] > char:
            stack.pop()
        stack.append(char)
    
    for _ in range(len(s1) - lengths[-1]):
        stack.pop()
    
    return stack[offset-1]

def solve():
    s = input()
    pos = int(input())
    print(find_character(s, len(s), pos))

T = int(input())
while T > 0:
    solve()
    T -= 1