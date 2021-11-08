# plant.py - содержит процедуру ввода параметров для растения

import random

from src.bush import Bush
from src.flower import Flower
from src.tree import Tree


class Plant:
    # Ввод параметров из строки
    @staticmethod
    def create_from_str(s):
        type_name = s.split()[0]
        input_data = ' '.join(s.split()[1:])
        if type_name == "tree":
            return Tree(input_data)
        if type_name == "flower":
            return Flower(input_data)
        if type_name == "bush":
            return Bush(input_data)
        return None

    # Случайный ввод параметров
    @staticmethod
    def create_from_rand(r: random.Random):
        type_index = r.randint(0, 2)
        if type_index == 0:
            return Tree(r)
        if type_index == 1:
            return Flower(r)
        if type_index == 2:
            return Bush(r)
        return None
