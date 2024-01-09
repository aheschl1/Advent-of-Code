from sys import stdin

def notDone(starting):
    for node in starting:
        if node[-1] != 'Z':
            return True
    return False

def main():
    nodes = dict()
    instructions = input()
    starting = set()
    input()
    for line in stdin:
        line = line.strip()
        name, _, *content = line.split(' ')
        content[0] = content[0].replace('(', '("').replace(',', '",')
        content[1] = '"' + content[1].replace(')', '")')
        content = eval(''.join(content))
        nodes[name] = content
        if name[-1] == 'A':
            starting.add(name)

    i = 0
    valid = False
    xs = []
    for node in starting:
        total = 0
        current = node
        while current[-1] != "Z":
            total += 1
            ins = instructions[i%len(instructions)]
            current = nodes[current][0 if ins == 'L' else 1]
            i+=1
        xs.append(total)


    from math import lcm
    print(lcm(*xs))

if __name__ == "__main__":
    main()