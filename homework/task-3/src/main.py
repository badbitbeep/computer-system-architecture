# main.py - содержит главную функцию,
# обеспечивающую простое тестирование

import sys
import random

from container import Container


def err_message_1():
    print('''
    incorrect command line!
    Waited:
       command -f infile outfile01 outfile02
    Or:
       command -n number outfile01 outfile02
    ''')


def err_message_2():
    print('''
    incorrect qualifier value!
    Waited:
       command -f infile outfile01 outfile02
    Or:
       command -n number outfile01 outfile02
    ''')


if __name__ == "__main__":
    argv = sys.argv
    argc = len(argv)
    if argc != 5:
        err_message_1()
        exit(10)

    print("Start")
    c = Container(random.Random(), 0)

    if argv[1] == "-f":
        f = open(argv[2], 'r')
        if not f:
            print("cannot open file: ", argv[2])
            exit(1)

        c = Container(f)
        f.close()
    elif argv[1] == "-n":
        size = int(argv[2])
        if size < 1 or size > 10000:
            print("incorrect numer of figures = ", size, ". Set 0 < number <= 10000")
            exit(3)

        c = Container(random.Random(), size)
    else:
        err_message_2()
        exit(2)

    # Вывод содержимого контейнера в файл
    out_file1 = open(argv[3], 'w')
    out_file1.write("Filled container:\n")
    out_file1.write(str(c))
    out_file1.close()

    c.sort()
    out_file2 = open(argv[4], 'w')
    out_file2.write("Sorted container:\n")
    out_file2.write(str(c))
    out_file2.close()

    print("Stop")
    exit(0)
