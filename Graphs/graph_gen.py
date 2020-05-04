import numpy as np
import random

n = 10

fo = open("graph.txt", "w+")

matrix = np.random.randint(2, size=(n, n))
new_str = matrix
chars_to_remove = "[]"

for character in chars_to_remove:
	new_str = str(new_str).replace(character, "")

str_len = len(new_str)+1
new_str = new_str.rjust(str_len)



fo.write(str(new_str))

fo.close()