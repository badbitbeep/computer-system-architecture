# flower.py - содержит процедуру ввода параметров для уже созданного цветка

from typing import Union

import random


class Flower:
    type = [
        'home',
        'garden',
        'wild'
    ]

    def __init__(self, x: Union[random.Random, str]):
        self.name = ''
        self.type = ''
        if isinstance(x, random.Random):
            self.init_from_random(x)
        if isinstance(x, str):
            self.init_from_string(x)

    # Случайный ввод параметров цветка
    def init_from_random(self, r: random.Random):
        for i in range(r.randint(1, 128)):
            self.name += chr(ord('a') + r.randint(0, 25))
        self.type = Flower.type[r.randint(0, 2)]

    # Ввод параметров цветка из строки
    def init_from_string(self, s: str):
        (self.name, self.type) = s.split()

    # Вывод параметров цветка в виде строки
    def __str__(self):
        return "It is Flower: name = " + self.name + ", flower type = " + self.type + ". hash = " + str(
            self.hash()) + "\n"

    # Вычисление хеша имени цветка
    def hash(self):
        vowel_count = 0
        for c in self.name:
            if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u':
                vowel_count += 1
            if c == 'A' or c == 'B' or c == 'I' or c == 'O' or c == 'U':
                vowel_count += 1

        return vowel_count / len(self.name)
