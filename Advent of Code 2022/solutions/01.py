from FileReading import read_2d_int_matrix_with_group_separator

data = read_2d_int_matrix_with_group_separator("data/01.txt", "\n\n")

elves_calories = [sum(pack) for pack in data]

# 1.1
print("Calories for Elf carrying the most calories:", max(elves_calories))

# 1.2
print("Calories for top three Elves carrying the most calories:", sum(sorted(elves_calories)[-3:]))
