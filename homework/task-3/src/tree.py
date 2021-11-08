# tree.py - содержит процедуру ввода параметров для уже созданного дерева

from typing import Union

import random


class Tree:
    def __init__(self, x: Union[random.Random, str]):
        self.name = ''
        self.age = 0
        if isinstance(x, random.Random):
            self.init_from_random(x)
        if isinstance(x, str):
            self.init_from_string(x)

    # Случайный ввод параметров дерева
    def init_from_random(self, r: random.Random):
        for i in range(r.randint(1, 128)):
            self.name += chr(ord('a') + r.randint(0, 25))
        self.age = r.randint(0, 100)

    # Ввод параметров дерева из строки
    def init_from_string(self, s: str):
        (self.name, self.age) = (s.split()[0], int(s.split()[1]))

    # Вывод параметров дерева в виде строки
    def __str__(self):
        return "It is Tree: name = " + self.name + ", age = " + str(self.age) + ". hash = " + str(
            self.hash()) + "\n"

    # Вычисление хеша имени дерева
    def hash(self):
        vowel_count = 0
        for c in self.name:
            if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u':
                vowel_count += 1
            if c == 'A' or c == 'B' or c == 'I' or c == 'O' or c == 'U':
                vowel_count += 1

        return vowel_count / len(self.name)
