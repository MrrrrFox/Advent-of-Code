
def read_2d_int_matrix_with_group_separator(filename="data/data.txt", group_separator="\n"):
    """
    Reading file as 2D int matrix. Data is written in one column. Rows are separated by group separator.
    :param filename: name of file to read
    :param group_separator: separator between groups
    :return: 2D int matrix
    """
    f = open(filename, 'r').read()
    return [[int(elem) for elem in row.split("\n")] for row in f.split(group_separator)]


def read_sting_matrix(filename="data/data.txt"):
    """
    Reading file as string matrix.
    :param filename: name of file to read
    :return: string matrix
    """
    f = open(filename, 'r')
    return [[elem for elem in row.split()] for row in f]


def read_sting_array(filename="data/data.txt"):
    """
    Reading file as string array.
    :param filename: name of file to read
    :return: string array
    """
    f = open(filename, 'r')
    return [line[:-1] for line in f]

