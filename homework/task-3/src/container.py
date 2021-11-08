# container.py - содержит класс контейнера

from io import TextIOWrapper
from typing import Union

import random

from plant import Plant


class Container:
    def __init__(self, x: Union[TextIOWrapper, random.Random], size=0):
        self.cont = []
        if isinstance(x, TextIOWrapper):
            self.init_from_file(x)
        else:
            self.init_from_random(x, size)

    # Ввод содержимого контейнера из файла
    def init_from_file(self, f: TextIOWrapper):
        for line in f.readlines():
            self.cont.append(Plant.create_from_str(line))

    # Случайный ввод содержимого контейнера
    def init_from_random(self, r: random.Random, size=0):
        for i in range(size):
            self.cont.append(Plant.create_from_rand(r))

    # Вывод содержимого контейнера в строку
    def __str__(self):
        s = ''
        s += "Container contains " + str(len(self.cont)) + " elements.\n"
        for i in range(len(self.cont)):
            s += str(i) + ": " + str(self.cont[i])
        return s

    # Сортировка контейнера методом Straight Selection
    def sort(self):
        i = 0
        while i < len(self.cont):
            k = i
            j = i + 1
            while j < len(self.cont):
                if self.cont[j].hash() < self.cont[k].hash():
                    k = j
                j += 1
            temp = self.cont[i]
            self.cont[i] = self.cont[k]
            self.cont[k] = temp
            i += 1
