import functools

f = open("C:\\Users\\ajhes\\Documents\\Advent of Code\\d13\\in.txt", "r").read().strip()

#1 true, 0 same -1 false
def validate(p1,p2):
    if isinstance(p1, int) and isinstance(p2, int):
        if p1 < p2:
            return -1
        elif p1 > p2:
            return 1
        else:
            return 0
    elif isinstance(p1, list) and isinstance(p2, list):
        i = 0
        while i < len(p1) and i < len(p2):
            result = validate(p1[i], p2[i])
            if result == 1:
                return 1
            elif result == -1:
                return -1
            i+=1
        if i == len(p1) and i < len(p2):
            return -1
        elif i == len(p2) and i < len(p1):
            return 1
        else:
            return 0
    elif isinstance(p1, int) and isinstance(p2, list):
        return validate([p1], p2)
    elif isinstance(p1, list) and isinstance(p2, int):
        return validate(p1, [p2])



count = 1
packets = []
for group in f.split('\n\n'):
    count += 1
    p1,p2 = group.split('\n')
    p1 = eval(p1)
    p2 = eval(p2)
    packets.append(p1)
    packets.append(p2)
packets.append([[6]])
packets.append([[2]])

packets.sort(key=functools.cmp_to_key(validate))

print((packets.index([[6]]) + 1) * (packets.index([[2]]) + 1))
"""
if validate(p1, p2) == 1:
        ans += count
"""
