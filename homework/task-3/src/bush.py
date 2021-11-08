# bush.py - содержит процедуру ввода параметров для уже созданного кустарника

from typing import Union

import random


class Bush:
    month = [
        'january',
        'february',
        'march',
        'april',
        'may',
        'june',
        'july',
        'august',
        'september',
        'october',
        'november',
        'december'
    ]

    def __init__(self, x: Union[random.Random, str]):
        self.name = ''
        self.month = ''
        if isinstance(x, random.Random):
            self.init_from_random(x)
        if isinstance(x, str):
            self.init_from_string(x)

    # Случайный ввод параметров кустарника
    def init_from_random(self, r: random.Random):
        for i in range(r.randint(1, 128)):
            self.name += chr(ord('a') + r.randint(0, 25))
        self.month = Bush.month[r.randint(0, 11)]

    # Ввод параметров кустарника из строки
    def init_from_string(self, s: str):
        (self.name, self.month) = s.split()

    # Вывод параметров кустарника в виде строки
    def __str__(self):
        return "It is Bush: name = " + self.name + ", bloom month = " + self.month + ". hash = " + str(
            self.hash()) + "\n"

    # Вычисление хеша имени кустарника
    def hash(self):
        vowel_count = 0
        for c in self.name:
            if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u':
                vowel_count += 1
            if c == 'A' or c == 'B' or c == 'I' or c == 'O' or c == 'U':
                vowel_count += 1

        return vowel_count / len(self.name)
