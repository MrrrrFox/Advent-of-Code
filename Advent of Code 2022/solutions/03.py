from FileReading import read_sting_array


def letter_to_value(letter):
    if letter.islower():
        return ord(letter) - 96
    else:
        return ord(letter) - 38


data = read_sting_array("data/03.txt")

# 2.1
data_packs = [[pack[:len(pack)//2], pack[len(pack)//2:]] for pack in data]
errors = [list(set(pack[0]).intersection(pack[1]))[0] for pack in data_packs]
error_codes = list(map(letter_to_value, errors))
print(sum(error_codes))

# 2.2
grouped_data = [data[3*i:3*i+3] for i in range(len(data)//3)]
errors2 = [list(set(pack[0]).intersection(pack[1]).intersection(pack[2]))[0] for pack in grouped_data]
error_codes2 = list(map(letter_to_value, errors2))
print(sum(error_codes2))
