values_to_replace = ",-"

f = open('data/04.txt', 'r').read()
for vtr in values_to_replace:
    f = f.replace(vtr, " ")
data = [[int(val) for val in line.split()] for line in f.split('\n')]


# 4.1
full_contains = 0
for pair in data:
    if (pair[0] <= pair[2] and pair[1] >= pair[3]) or (pair[0] >= pair[2] and pair[1] <= pair[3]):
        full_contains += 1
print(full_contains)

# 4.2
any_contains = 0
for pair in data:
    if len(range(max(pair[0], pair[2]), min(pair[1], pair[3])+1)) > 0:
        any_contains += 1
print(any_contains)
