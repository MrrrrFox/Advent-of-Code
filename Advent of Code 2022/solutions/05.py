import copy

f = open('data/05.txt', 'r').read()
data_stacks, data_instructions = f.split("\n\n")

starting_stacks = [[] for _ in range(int(data_stacks[-1])+1)]
for row in data_stacks.split("\n")[:-1]:
    for ind, supply in enumerate(row[1::4]):
        if supply != " ":
            starting_stacks[ind+1].insert(0, supply)




# 5.1
stacks_p1 = copy.deepcopy(starting_stacks)
for instruction in data_instructions.split("\n"):
    instruction_split = instruction.split()
    num_to_move, start_stack, end_stack = int(instruction_split[1]), int(instruction_split[3]), int(instruction_split[5])
    for _ in range(num_to_move):
        stacks_p1[end_stack].append(stacks_p1[start_stack][-1])
        stacks_p1[start_stack].pop()
for stack in stacks_p1[1:]:
    print(stack[-1], end="")
print()

# 5.2
stacks_p2 = copy.deepcopy(starting_stacks)
for instruction in data_instructions.split("\n"):
    instruction_split = instruction.split()
    num_to_move, start_stack, end_stack = int(instruction_split[1]), int(instruction_split[3]), int(instruction_split[5])
    stacks_p2[end_stack].extend(stacks_p2[start_stack][len(stacks_p2[start_stack]) - num_to_move:])
    for _ in range(num_to_move):
        stacks_p2[start_stack].pop()
for stack in stacks_p2[1:]:
    print(stack[-1], end="")
print()
