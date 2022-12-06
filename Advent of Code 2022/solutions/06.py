data = open('data/06.txt', 'r').read()

code_lens = [4, 14]

for code_len in code_lens:
    code = set()
    i = code_len-1
    while len(code) != code_len:
        i += 1
        code = set(data[i - code_len:i])
    print(i)
