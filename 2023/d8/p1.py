from sys import stdin

def main():
    nodes = dict()
    instructions = input()
    input()
    for line in stdin:
        line = line.strip()
        name, _, *content = line.split(' ')
        content[0] = content[0].replace('(', '("').replace(',', '",')
        content[1] = '"' + content[1].replace(')', '")')
        content = eval(''.join(content))
        nodes[name] = content

    current = "AAA"
    i = 0
    total = 0
    while current != "ZZZ":
        total += 1
        ins = instructions[i%len(instructions)]
        current = nodes[current][0 if ins == 'L' else 1]
        i+=1
    print(total)

if __name__ == "__main__":
    main()