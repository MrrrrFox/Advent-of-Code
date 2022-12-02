from FileReading import read_2d_sting_matrix

switcher = {'A': 0, 'X': 0, 'B': 1, 'Y': 1, 'C': 2, 'Z': 2}


def map_rps_to_int(rps_value):
    return switcher[rps_value]


def match_res_1(match_shapes):
    res = 3 if match_shapes[0] == match_shapes[1] else 6 if (match_shapes[0] + 1) % 3 == match_shapes[1] else 0
    return res + match_shapes[1] + 1


def match_res_2(match_shapes):
    res = (match_shapes[0] - 1) % 3 if match_shapes[1] == 0 else 3 + match_shapes[0] if match_shapes[1] == 1 else 6 + (match_shapes[0] + 1) % 3
    return res + 1


data = read_2d_sting_matrix("data/02.txt")
data_int = [list(map(map_rps_to_int, row)) for row in data]

# 2.1
print("Final result with first counting-method:", sum([match_res_1(match) for match in data_int]))

# 2.2
print("Final result with second final and correct counting-method:", sum([match_res_2(match) for match in data_int]))
