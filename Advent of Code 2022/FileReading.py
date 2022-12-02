
def read_2d_int_matrix_with_group_separator(filename="data/data.txt", group_separator="\n"):
    """
    Reading file as 2D int matrix. Data is written in one column. Rows are separated by group separator.
    :param filename: name of file to read
    :param group_separator: separator between groups
    :return: 2D int matrix
    """
    f = open(filename, 'r').read()
    return [[int(elem) for elem in row.split("\n")] for row in f.split(group_separator)]


def read_2d_sting_matrix(filename="data/data.txt"):
    """
    Reading file as 2D string matrix.
    :param filename: name of file to read
    :return: 2D string matrix
    """
    f = open(filename, 'r')
    return [[elem for elem in row.split()] for row in f]
